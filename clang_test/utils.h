#pragma once

#include <unordered_set>
#include <unordered_map>

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

class Utils{
public:
    static void init(ASTContext* ast_context) {
        Utils::_ast_context = ast_context;
    }
    static VarDecl* get_variable_declaration(Expr* expr);
    static Expr* get_parent(Expr* expr);
    static ImplicitCastExpr* get_parent_of_var_usage(DeclRefExpr* var_usage);
    static BinaryOperator* get_assign_expr(Expr* expr);
    static string dump_to_string(Stmt* stmt);
private:
    static ASTContext* _ast_context;

    static Expr* _get_assign_expr(Expr* expr);
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
