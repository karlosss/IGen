#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "clang.h"
#include "basic_block.h"
#include "utils.h"
#include "ast.h"

class SplitDeclAndDefVisitor : public RecursiveASTVisitor<SplitDeclAndDefVisitor> {
private:
    ASTContext *astContext;
    AST* ast;

public:
    explicit SplitDeclAndDefVisitor(CompilerInstance *CI)
            : astContext(&(CI->getASTContext())) // initialize private members
    {}

    virtual bool VisitFunctionDecl(FunctionDecl* function_decl) {
        ast = new AST(function_decl);
        return true;
    }

    virtual bool VisitDeclStmt(DeclStmt* decl_stmt) {
        vector<pair<VarDecl*, Expr*>> inits;
        for(auto & decl : decl_stmt->decls()) {
            auto* var_decl = dyn_cast<VarDecl>(decl);
            // only care about floating types
            if(!var_decl->getType()->isFloatingType()) continue;

            if(var_decl->hasInit()) {
                inits.push_back(make_pair(var_decl, var_decl->getInit()));
                ast->remove_stmt(var_decl->getInit());
            }
        }

        for(auto it = inits.rbegin(); it != inits.rend(); it++) {
            auto* decl_ref_expr = DeclRefExpr::CreateEmpty(*astContext, false, false, false, 0);
            decl_ref_expr->setDecl(it->first);
            decl_ref_expr->setType(it->first->getType());
            auto* bop = BinaryOperator::CreateEmpty(*astContext, false);
            bop->setLHS(decl_ref_expr);
            bop->setRHS(it->second);
            bop->setOpcode(BO_Assign);
            bop->setType(it->first->getType());
            ast->insert_stmt_after(bop, decl_stmt);
        }
        return true;
    }

    virtual bool VisitIfStmt(IfStmt* if_stmt) {
        if(auto* compound_stmt = dyn_cast<CompoundStmt>(if_stmt->getThen())) {
            // empty
        }
        else {
            ast->replace_stmt(
                    if_stmt->getThen(),
                    Utils::create_compound_stmt({if_stmt->getThen()}, if_stmt->getThen()->getBeginLoc(), if_stmt->getThen()->getEndLoc())
            );
        }

        if(if_stmt->hasElseStorage()) {
            if(auto* compound_stmt = dyn_cast<CompoundStmt>(if_stmt->getElse())) {
                // empty
            }
            else {
                ast->replace_stmt(
                        if_stmt->getElse(),
                        Utils::create_compound_stmt({if_stmt->getElse()}, if_stmt->getElse()->getBeginLoc(), if_stmt->getElse()->getEndLoc())
                );
            }
        }
        return true;
    }
};
