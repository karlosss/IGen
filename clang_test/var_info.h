#pragma once

#include "clang.h"


struct VarInfo{
    VarDecl* declaration;
    Expr* assigned_value;
    Stmt* assign_stmt;
    vector<DeclRefExpr*> usages;

    VarInfo(VarDecl* declaration, Stmt* assign_stmt, Expr* assigned_value) {
        this->declaration = declaration;
        this->assigned_value = assigned_value;
        this->assign_stmt = assign_stmt;
    }

    bool should_inline() {
        return usages.size() == 1;
    }
};
