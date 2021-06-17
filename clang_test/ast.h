#pragma once

#include <unordered_map>
#include <unordered_set>

#include "clang.h"
#include "utils.h"

class AST{
public:
    explicit AST(FunctionDecl* root) {
        _root = root;
        walk(root);
    }

    FunctionDecl* root() {
        return _root;
    }

    void walk(FunctionDecl* function_decl) {
        walk(function_decl->getBody());
    }

    void walk(Stmt* stmt) {
        if(!stmt) return;

        if(auto* compound_stmt = dyn_cast<CompoundStmt>(stmt)) {
            for(auto* s : compound_stmt->children()) {
                _parent_map[s] = compound_stmt;
                walk(s);
            }
        }

        else if(auto* decl_stmt = dyn_cast<DeclStmt>(stmt)) {
            for(auto* decl : decl_stmt->decls()) {
                auto* var_decl = dyn_cast<VarDecl>(decl);
                if(var_decl->hasInit()) {
                    _parent_map[var_decl->getInit()] = decl_stmt;
                    walk(var_decl->getInit());
                }
            }
        }

        else if(auto* if_stmt = dyn_cast<IfStmt>(stmt)) {
            _parent_map[if_stmt->getCond()] = if_stmt;
            walk(if_stmt->getCond());
            _parent_map[if_stmt->getThen()] = if_stmt;
            walk(if_stmt->getThen());
            if(if_stmt->hasElseStorage()) {
                _parent_map[if_stmt->getElse()] = if_stmt;
                walk(if_stmt->getElse());
            }
        }

        else if(auto* for_stmt = dyn_cast<ForStmt>(stmt)) {
            _parent_map[for_stmt->getBody()] = for_stmt;
            walk(for_stmt->getBody());
        }

        else if(auto* while_stmt = dyn_cast<WhileStmt>(stmt)) {
            _parent_map[while_stmt->getBody()] = while_stmt;
            walk(while_stmt->getBody());
        }

        else if(auto* implicit_cast_expr = dyn_cast<ImplicitCastExpr>(stmt)) {
            _parent_map[implicit_cast_expr->getSubExpr()] = implicit_cast_expr;
            walk(implicit_cast_expr->getSubExpr());
        }

        else if(auto* binary_operator = dyn_cast<BinaryOperator>(stmt)) {
            _parent_map[binary_operator->getLHS()] = binary_operator;
            walk(binary_operator->getLHS());
            _parent_map[binary_operator->getRHS()] = binary_operator;
            walk(binary_operator->getRHS());
        }

        else {
            cerr << stmt->getStmtClassName() << "\n";
        }
    }

    Stmt* get_parent(Stmt* stmt) {
        if(_parent_map.find(stmt) != _parent_map.end()) {
            return _parent_map[stmt];
        }
        return nullptr;
    }

    bool is_root(Stmt* stmt) {
        return _root->getBody() == stmt;
    }

    void replace_stmt(Stmt* old, Stmt* new_) {
        if(is_root(old)) {
            _parent_map.clear();
            root()->setBody(new_);
            walk(root());
            return;
        }

        auto* parent = get_parent(old);

        if(auto* compound_stmt = dyn_cast<CompoundStmt>(parent)) {
            vector<Stmt*> new_statements;
            for(auto & s : compound_stmt->children()) {
                _parent_map.erase(s);
                if(old == s) {
                    new_statements.push_back(new_);
                }
                else {
                    new_statements.push_back(s);
                }
            }
            auto* new_compound_stmt = Utils::create_compound_stmt(new_statements, compound_stmt->getBeginLoc(), compound_stmt->getEndLoc());
            for(auto & s : new_compound_stmt->children()) {
                _parent_map[s] = new_compound_stmt;
            }

            replace_stmt(compound_stmt, new_compound_stmt);
        }

        else if(auto* decl_stmt = dyn_cast<DeclStmt>(parent)) {
            for(auto & d : decl_stmt->decls()) {
                auto* var_decl = dyn_cast<VarDecl>(d);
                if(var_decl->hasInit()) {
                    if(var_decl->getInit() == old) {
                        _parent_map.erase(old);
                        var_decl->setInit(dyn_cast<Expr>(new_));
                        _parent_map[new_] = decl_stmt;
                        break;
                    }
                }
            }
        }

        else if(auto* implicit_cast_expr = dyn_cast<ImplicitCastExpr>(parent)) {
            _parent_map.erase(old);
            implicit_cast_expr->setSubExpr(dyn_cast<Expr>(new_));
            _parent_map[new_] = implicit_cast_expr;
        }

        else if(auto* if_stmt = dyn_cast<IfStmt>(parent)) {
            _parent_map.erase(old);
            if(old == if_stmt->getThen()) {
                if_stmt->setThen(new_);
                _parent_map[new_] = if_stmt;
            }
            else if(old == if_stmt->getCond()) {
                if_stmt->setCond(dyn_cast<Expr>(new_));
                _parent_map[new_] = if_stmt;
            }
            else if(if_stmt->hasElseStorage() && old == if_stmt->getElse()) {
                if_stmt->setElse(new_);
                _parent_map[new_] = if_stmt;
            }
            else {
                throw;
            }
        }

        else {
            cerr << "Unable to handle " << parent->getStmtClassName() << " as parent class!\n";
            throw;
        }
    }

    void remove_stmt(Stmt* to_remove) {
        auto* parent = get_parent(to_remove);

        if(auto* compound_stmt = dyn_cast<CompoundStmt>(parent)) {
            _parent_map.erase(to_remove);

            vector<Stmt*> new_statements;
            for(auto & s : compound_stmt->children()) {
                if(to_remove != s) {
                    new_statements.push_back(s);
                }
            }
            auto* new_compound_stmt = Utils::create_compound_stmt(new_statements, compound_stmt->getBeginLoc(), compound_stmt->getEndLoc());
            replace_stmt(compound_stmt, new_compound_stmt);

        }

        else if(auto* decl_stmt = dyn_cast<DeclStmt>(parent)) {
            for(auto & d : decl_stmt->decls()) {
                auto* var_decl = dyn_cast<VarDecl>(d);
                if(var_decl->hasInit()) {
                    if(var_decl->getInit() == to_remove) {
                        _parent_map.erase(to_remove);
                        var_decl->setInit(nullptr);
                        break;
                    }
                }
            }
        }

        else if(auto* implicit_cast_expr = dyn_cast<ImplicitCastExpr>(parent)) {
            _parent_map.erase(to_remove);
            implicit_cast_expr->setSubExpr(nullptr);
        }

        else if(auto* if_stmt = dyn_cast<IfStmt>(parent)) {
            _parent_map.erase(to_remove);
            if(to_remove == if_stmt->getThen()) {
                if_stmt->setThen(nullptr);
            }
            else if(if_stmt->hasElseStorage() && to_remove == if_stmt->getElse()) {
                if_stmt->setElse(nullptr);
            }
            else {
                throw;
            }
        }

        else {
            cerr << "Unable to handle " << parent->getStmtClassName() << " as parent class!\n";
            throw;
        }

    }

    void insert_stmt_after(Stmt* to_insert, Stmt* after) {
        auto* parent = get_parent(after);
        if(auto* compound_stmt = dyn_cast<CompoundStmt>(parent)) {
            vector<Stmt*> new_statements;
            for(auto & s : compound_stmt->children()) {
                new_statements.push_back(s);
                if(s == after) {
                    new_statements.push_back(to_insert);
                }
            }
            auto* new_compound_stmt = Utils::create_compound_stmt(new_statements, compound_stmt->getBeginLoc(), compound_stmt->getEndLoc());

            replace_stmt(compound_stmt, new_compound_stmt);
        }
        else {
            cerr << "Can only insert into CompoundStmt!\n";
            throw;
        }
    }

    void insert_stmt_before(Stmt* to_insert, Stmt* before) {
        auto* parent = get_parent(before);
        if(auto* compound_stmt = dyn_cast<CompoundStmt>(parent)) {
            vector<Stmt*> new_statements;
            for(auto & s : compound_stmt->children()) {
                if(s == before) {
                    new_statements.push_back(to_insert);
                }
                new_statements.push_back(s);
            }
            auto* new_compound_stmt = Utils::create_compound_stmt(new_statements, compound_stmt->getBeginLoc(), compound_stmt->getEndLoc());

            replace_stmt(compound_stmt, new_compound_stmt);
        }
        else {
            cerr << "Can only insert into CompoundStmt!\n";
            throw;
        }
    }

private:
    unordered_map<Stmt*, Stmt*> _parent_map;
    FunctionDecl* _root;
};
