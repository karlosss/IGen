#pragma once

#include <unordered_map>
#include <vector>

#include "clang.h"
#include "var_info.h"


struct BlockInfo {
    unordered_map<VarDecl*, unordered_set<BinaryOperator*>> possible_values_at_entry;
    unordered_map<VarDecl*, unordered_set<BinaryOperator*>> possible_values_at_exit;
};
