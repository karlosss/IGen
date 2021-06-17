#pragma once

#include "utils.h"


class VarInfo {
public:
    VarInfo() {}
    VarInfo(Stmt* assign_stmt) {
        if(assign_stmt) {
            auto* bop = dyn_cast<BinaryOperator>(assign_stmt);
            _assign_stmt = bop;
        }
        else {
            _assign_stmt = nullptr;
        }
    }

    Expr* value() {
        return _assign_stmt->getRHS();
    }

    VarDecl* assigned_variable() {
        return Utils::get_variable_declaration(_assign_stmt->getLHS());
    }

    BinaryOperator* assign_stmt() {
        return _assign_stmt;
    }

    bool is_ambiguous() {
        return !_assign_stmt;
    }
private:
    BinaryOperator* _assign_stmt;
};
