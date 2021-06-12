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
            if(var_decl->hasInit()) {
                inits.push_back(make_pair(var_decl, var_decl->getInit()));
                ast->remove_stmt(var_decl->getInit());
            }
        }

        for(auto it = inits.rbegin(); it != inits.rend(); it++) {
            auto* decl_ref_expr = DeclRefExpr::CreateEmpty(*astContext, false, false, false, 0);
            decl_ref_expr->setDecl(it->first);
            auto* bop = BinaryOperator::CreateEmpty(*astContext, false);
            bop->setLHS(decl_ref_expr);
            bop->setRHS(it->second);
            bop->setOpcode(BO_Assign);
            ast->insert_stmt_after(bop, decl_stmt);
        }
        return true;
    }

    virtual bool VisitDeclRefExpr(DeclRefExpr* decl_ref_expr) {
        return true;
    }
};
