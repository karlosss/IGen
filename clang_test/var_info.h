#pragma once

#include <unordered_map>

#include "clang.h"


struct VarInfo{
    VarDecl* declaration;
    // value - assign statement
    unordered_map<Expr*, Stmt*> possible_values;

    VarInfo(VarDecl* declaration) {
        this->declaration = declaration;
    }

    void add_possible_value(Expr* value, Stmt* assign_stmt) {
        possible_values[value] = assign_stmt;
    }
};
