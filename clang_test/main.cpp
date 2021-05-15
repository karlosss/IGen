#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "clang/Driver/Options.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ParentMapContext.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"

using namespace clang;
using namespace llvm;
using namespace std;
using namespace clang::tooling;

typedef string FuncName;
typedef string VarName;

Rewriter rewriter;

FuncName current_function;
unordered_set<VarName> global_variables;
int numFunctions = 0;
llvm::cl::OptionCategory MyToolCategory("my-tool options");

template<typename K>
void print_map(std::unordered_map<K, vector<DeclRefExpr*>> const &m)
{
    for (auto const &pair: m) {
        errs() << "{" << pair.first << ": ";
        for(int i = 0; i < pair.second.size(); ++i) {
             pair.second[i]->dump();
        }
        errs() << "}\n";
    }
}

template<class K, class V>
bool contains(const unordered_map<K, V> & m, const K & k) {
    return m.find(k) != m.end();
}

template<class K>
bool contains(const unordered_set<K> & s, const K & k) {
    return s.find(k) != s.end();
}

template<class K, class V>
vector<pair<K,V>> sort_map(const unordered_map<K,V> & map) {
    // create an empty vector of pairs
    std::vector<std::pair<K, V>> vec;

    // copy key-value pairs from the map to the vector
    std::copy(map.begin(),
              map.end(),
              std::back_inserter<std::vector<pair<K, V>>>(vec));

    // sort the vector by increasing the order of its pair's second value
    // if the second value is equal, order by the pair's first value
    std::sort(vec.begin(), vec.end(),
              [](const pair<K, V> &l, const pair<K, V> &r)
              {
                  if (l.second != r.second) {
                      return l.second < r.second;
                  }

                  return l.first < r.first;
              });

    // print the vector
    return vec;
}

struct VarInfo{
    VarName name;
    BinaryOperator* assign_expr;
    DeclRefExpr* usage;
    bool should_inline;
    VarInfo(const VarName & name, BinaryOperator* assign_expr) {
        this->name = name;
        this->assign_expr = assign_expr;
        usage = nullptr;
        should_inline = false;
    }
};

class ExampleVisitor : public RecursiveASTVisitor<ExampleVisitor> {
private:
    ASTContext *astContext; // used for getting additional AST info
    unordered_map<VarName, int> pos_map;
    vector<VarInfo> assignments;
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
            int pos = pos_map[get_variable_name(decl)];
            if(assignments[pos].usage == nullptr) {
                // first usage
                assignments[pos].usage = decl;
                assignments[pos].should_inline = true;
            }
            else {
                // second and following usages
                assignments[pos].should_inline = false;
            }
        }
    }

    string get_variable_name(Expr* expr) {
        if(auto *decl = dyn_cast<DeclRefExpr>(expr)) {
            if(auto *var_decl = dyn_cast<VarDecl>(decl->getDecl())) {
                return var_decl->getName().str();
            }
        }
        throw;
    }

    Expr* get_parent(Expr* expr) {
        DynTypedNodeList cast = astContext->getParents(*expr);
        return const_cast<Expr*>(cast[0].get<Expr>());
    }

    ImplicitCastExpr* get_parent_of_var_usage(DeclRefExpr* var_usage) {
        DynTypedNodeList cast = astContext->getParents(*var_usage);
        return const_cast<ImplicitCastExpr*>(cast[0].get<ImplicitCastExpr>());
    }

    BinaryOperator* get_assign_expr(Expr* expr) {
        return dyn_cast<BinaryOperator>(_get_assign_expr(expr));
    }

    Expr* _get_assign_expr(Expr* expr) {
        DynTypedNodeList par = astContext->getParents(*expr);
        Expr* par_expr = const_cast<Expr*>(par[0].get<Expr>());
        if(auto* bop = dyn_cast<BinaryOperator>(par_expr)) {
            if(bop->isAssignmentOp()) {
                return bop;
            }
        }
        return _get_assign_expr(const_cast<Expr*>(par[0].get<Expr>()));
    }

    string dump_to_string(Stmt* stmt) {
        string str;
        raw_string_ostream os(str);
        stmt->printPretty(os, nullptr, PrintingPolicy(LangOptions()), 0, "\n", astContext);
        return str;
    }

public:
    explicit ExampleVisitor(CompilerInstance *CI)
        : astContext(&(CI->getASTContext())) // initialize private members
    {
        rewriter.setSourceMgr(astContext->getSourceManager(),
            astContext->getLangOpts());
    }

    void TraverseFuncEnd(FunctionDecl *d) {
        auto pos = sort_map(pos_map);
        for(int i = 0; i < pos.size(); ++i) {
            if(assignments[pos[i].second].should_inline) {
                ImplicitCastExpr* par = get_parent_of_var_usage(assignments[pos[i].second].usage);
                par->setSubExpr(assignments[pos[i].second].assign_expr->getRHS());

                statements_to_remove.insert(assignments[pos[i].second].assign_expr);
            }
        }

        auto* body = dyn_cast<CompoundStmt>(d->getBody());
        vector<Stmt*> statements;
        for(auto it = body->children().begin(); it != body->children().end(); ++it){
            if(!contains(statements_to_remove, *it)) {
                // improve *it in herbie here
                statements.push_back(*it);
            }
        }

        auto* new_body = CompoundStmt::Create(*astContext, ArrayRef<Stmt*>(statements), body->getBeginLoc(), body->getEndLoc());
        rewriter.ReplaceText(d->getBody()->getSourceRange(), dump_to_string(new_body));
        d->setBody(new_body);
    }

    virtual bool VisitFunctionDecl(FunctionDecl *func) {
        numFunctions++;
        string func_name = func->getNameInfo().getName().getAsString();
        // dirty trick to make rewriter not segfault on no other edits
        rewriter.ReplaceText(func->getNameInfo().getSourceRange(), func->getNameInfo().getSourceRange());
        errs() << "** Traversing " << func_name << "\n";
        current_function = func_name;
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

        else if(auto *decl = dyn_cast<DeclRefExpr>(st)) {
            if(auto *var_decl = dyn_cast<VarDecl>(decl->getDecl())){
                if(var_decl->hasGlobalStorage()) {
                    errs() << "    Found global variable " << get_variable_name(decl) << "\n";
                    global_variables.insert(get_variable_name(decl));
                }
            }
            return true;
        }

        else if(auto *bop = dyn_cast<BinaryOperator>(st)) {
            if(bop->isAssignmentOp()) {
                find_usages_in_expr(bop->getRHS());

                VarName assigned_var_name = get_variable_name(bop->getLHS());

                if(contains(pos_map, assigned_var_name)) {
                    if(assignments[pos_map[assigned_var_name]].should_inline) {
//                        errs() << "Rewriting ";
//                        assignments[pos_map[assigned_var_name]].usage->dumpPretty(*astContext);
//                        errs() << " (";
//                        get_assign_expr(assignments[pos_map[assigned_var_name]].usage)->dumpPretty(*astContext);
//                        errs() << ") with ";
//                        assignments[pos_map[assigned_var_name]].assign_expr->getRHS()->dumpPretty(*astContext);
//                        errs() << "\n";

                        ImplicitCastExpr* par = get_parent_of_var_usage(assignments[pos_map[assigned_var_name]].usage);
                        par->setSubExpr(assignments[pos_map[assigned_var_name]].assign_expr->getRHS());

                        statements_to_remove.insert(assignments[pos_map[assigned_var_name]].assign_expr);

//                        errs() << "assignment: ";
//                        get_assign_expr(par)->dumpPretty(*astContext);
//                        errs() << "\n";
                    }
                }

                assignments.push_back(VarInfo(get_variable_name(bop->getLHS()), bop));
                pos_map[get_variable_name(bop->getLHS())] = assignments.size()-1;
            }
            return true;
        }

        return true;
    }
};

class ExampleASTConsumer : public ASTConsumer {
private:
    ExampleVisitor *visitor; // doesn't have to be private

public:
    // override the constructor in order to pass CI
    explicit ExampleASTConsumer(CompilerInstance *CI)
        : visitor(new ExampleVisitor(CI)) // initialize the visitor
        { }

    // override this to call our ExampleVisitor on each top-level Decl
    virtual bool HandleTopLevelDecl(DeclGroupRef DG) {
        // a DeclGroupRef may have multiple Decls, so we iterate through each one
        for (DeclGroupRef::iterator i = DG.begin(), e = DG.end(); i != e; i++) {
            Decl *D = *i;
            visitor->TraverseDecl(D); // recursively visit each AST node in Decl "D"
            auto* d = dyn_cast<FunctionDecl>(D);
            visitor->TraverseFuncEnd(d);
        }
        return true;
    }
};

class ExampleFrontendAction : public ASTFrontendAction {
public:
    virtual std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef file) override {
        return (std::unique_ptr<ASTConsumer>) new ExampleASTConsumer(&CI); // pass CI pointer to ASTConsumer
    }
};

int main(int argc, const char **argv) {
    // parse the command-line args passed to your code
    CommonOptionsParser op(argc, argv, MyToolCategory);
    // create a new Clang Tool instance (a LibTooling environment)
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction (explained below)
    int result = Tool.run(newFrontendActionFactory<ExampleFrontendAction>().get());

    errs() << "\nFound " << numFunctions << " functions.\n\n";
    // print out the rewritten source code ("rewriter" is a global var.)
    auto fid = rewriter.getSourceMgr().getMainFileID();
    rewriter.getEditBuffer(fid).write(outs());
    return result;
}
