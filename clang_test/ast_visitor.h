#ifndef CLANG_AST_VISITOR_AST_VISITOR_H
#define CLANG_AST_VISITOR_AST_VISITOR_H

#include <iostream>
#include "unordered_set"
#include "fstream"

#include "clang.h"
#include "var_info.h"
#include "utils.h"

class ExampleVisitor : public RecursiveASTVisitor<ExampleVisitor> {
private:
    ASTContext *astContext;
    vector<VarInfo> assignments; // each variable chronologically gets an ID assigned
    unordered_map<VarDecl*, int> pos_map; // reverse lookup for ID given the variable declaration
    unordered_set<Stmt*> statements_to_remove;

    void find_usages_in_expr(Expr* expr) {
        if(auto *bop = dyn_cast<BinaryOperator>(expr)) {
            find_usages_in_expr(bop->getLHS());
            find_usages_in_expr(bop->getRHS());
        }

        else if(auto *cast = dyn_cast<ImplicitCastExpr>(expr)) {
            find_usages_in_expr(cast->getSubExpr());
        }

        else if(auto *decl = dyn_cast<DeclRefExpr>(expr)){
            int pos = pos_map[Utils::get_variable_declaration(decl)];
            assignments[pos].usages.push_back(decl);
        }
    }

    void handle_assignment(VarDecl* variable, Stmt* assign_stmt, Expr* assigned_value) {
        find_usages_in_expr(assigned_value);

        if(contains(pos_map, variable)) {
            if(assignments[pos_map[variable]].should_inline()) {
                for(auto & usage : assignments[pos_map[variable]].usages) {
                    ImplicitCastExpr* par = Utils::get_parent_of_var_usage(usage);
                    par->setSubExpr(assignments[pos_map[variable]].assigned_value);
                    statements_to_remove.insert(assignments[pos_map[variable]].assign_stmt);
                }
            }
        }

        assignments.push_back(VarInfo(variable, assign_stmt, assigned_value));
        pos_map[variable] = assignments.size()-1;
    }

public:
    explicit ExampleVisitor(CompilerInstance *CI)
            : astContext(&(CI->getASTContext())) // initialize private members
    {
        Utils::init(astContext);
        rewriter.setSourceMgr(astContext->getSourceManager(),
                              astContext->getLangOpts());
    }

    void TraverseFuncEnd(FunctionDecl *d) {
        auto pos = sort_map(pos_map);
        for(auto & p : pos) {
            if(assignments[p.second].should_inline()) {
                for(auto & usage : assignments[p.second].usages) {
                    ImplicitCastExpr* par = Utils::get_parent_of_var_usage(usage);
                    par->setSubExpr(assignments[p.second].assigned_value);
                    statements_to_remove.insert(assignments[p.second].assign_stmt);
                }
            }
        }

        auto* body = dyn_cast<CompoundStmt>(d->getBody());
        vector<Stmt*> statements;
        ofstream herbie;
        herbie.open("herbie.txt");
        int i = 0;
        for(auto it = body->children().begin(); it != body->children().end(); ++it){
            if(!contains(statements_to_remove, *it)) {
                if(auto *bop = dyn_cast<BinaryOperator>(*it)) {
                    if(bop->isAssignmentOp()) {
                        herbie << Utils::dump_to_string(bop->getRHS()) << "\n";
                        auto* placeholder = clang::StringLiteral::Create(*astContext, "<{[HERBIE-" + to_string(i) + "]}>", clang::StringLiteral::StringKind::Ascii, false, QualType(), bop->getRHS()->getBeginLoc());
                        bop->setRHS(placeholder);
                        i++;
                    }
                }
                else if(auto *decl_stmt = dyn_cast<DeclStmt>(*it)) {
                    for (auto decl = decl_stmt->decl_begin(); decl != decl_stmt->decl_end(); ++decl) {
                        if(auto* var_decl = dyn_cast<VarDecl>(*decl)) {
                            if(var_decl->hasInit()) {
                                herbie << Utils::dump_to_string(var_decl->getInit()) << "\n";
                                auto* placeholder = clang::StringLiteral::Create(*astContext, "<{[HERBIE-" + to_string(i) + "]}>", clang::StringLiteral::StringKind::Ascii, false, QualType(), var_decl->getInit()->getBeginLoc());
                                var_decl->setInit(placeholder);
                                i++;
                            }
                        }
                    }
                }
                statements.push_back(*it);
            }
        }

        herbie.close();

        auto* new_body = CompoundStmt::Create(*astContext, ArrayRef<Stmt*>(statements), body->getBeginLoc(), body->getEndLoc());
        rewriter.ReplaceText(d->getBody()->getSourceRange(), Utils::dump_to_string(new_body));
        d->setBody(new_body);
    }

    virtual bool VisitFunctionDecl(FunctionDecl *func) {
        string func_name = func->getNameInfo().getName().getAsString();
        // dirty trick to make rewriter not segfault on no other edits
        rewriter.ReplaceText(func->getNameInfo().getSourceRange(), func->getNameInfo().getSourceRange());
        errs() << "** Traversing " << func_name << "\n";
        return true;
    }

    virtual bool VisitStmt(Stmt *st) {
        /* Check that the statement is in the main file. If not, it is most likely in a header file*/
        SourceManager& SM = rewriter.getSourceMgr();
        if (!SM.isInMainFile(st->getBeginLoc())) {
            /* The current location is not in the main file. Do not process.
             * (It is most likely in a header file.) */
            return true;
        }

//        else if(auto *decl = dyn_cast<DeclRefExpr>(st)) {
//            if(auto *var_decl = dyn_cast<VarDecl>(decl->getDecl())){
//                if(var_decl->hasGlobalStorage()) {
//                    errs() << "    Found global variable " << get_variable_name(decl) << "\n";
//                    global_variables.insert(get_variable_name(decl));
//                }
//            }
//            return true;
//        }

        else if(auto *decl_stmt = dyn_cast<DeclStmt>(st)) {
            for (auto decl = decl_stmt->decl_begin(); decl != decl_stmt->decl_end(); ++decl) {
                if(auto* var_decl = dyn_cast<VarDecl>(*decl)) {
                    if(var_decl->hasInit()) {
                        handle_assignment(var_decl, decl_stmt, var_decl->getInit());
                    }
                }
            }
        }

        else if(auto *bop = dyn_cast<BinaryOperator>(st)) {
            if(bop->isAssignmentOp()) {
                handle_assignment(Utils::get_variable_declaration(bop->getLHS()), bop, bop->getRHS());
            }
            return true;
        }

        return true;
    }
};

#endif //CLANG_AST_VISITOR_AST_VISITOR_H
