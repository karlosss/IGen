#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "clang.h"

class Utils{
public:
    static void init(ASTContext* ast_context) {
        Utils::ast_context = ast_context;
    }
    static VarDecl* get_variable_declaration(Expr* expr);
    static bool is_assign_stmt(Stmt* stmt);
    static string dump_to_string(Stmt* stmt);

    static CompoundStmt* create_compound_stmt(const vector<Stmt*> & statements, SourceLocation begin_loc, SourceLocation end_loc);

    static ASTContext* ast_context;
};

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

template<class K, class V>
bool contains(const unordered_map<K, V> & m, const K & k) {
    return m.find(k) != m.end();
}

template<class K>
bool contains(const unordered_set<K> & s, const K & k) {
    return s.find(k) != s.end();
}
