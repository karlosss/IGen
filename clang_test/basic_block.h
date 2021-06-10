#pragma once

#include <unordered_map>
#include <vector>

#include "clang.h"
#include "var_info.h"


struct VarAssignInfo{
    Stmt* assign_stmt;
    VarDecl* var;
    Expr* value;
    // usages
};

struct BlockInfo{
    unordered_map<VarDecl*, unordered_set<VarAssignInfo*>*> values_at_entry;
    unordered_map<VarDecl*, unordered_set<VarAssignInfo*>*> values_at_exit;
};

struct VarAccessInfo{
    unordered_set<VarAssignInfo*>* possible_values;
};
