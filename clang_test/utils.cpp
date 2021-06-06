#include "utils.h"

ASTContext* Utils::_ast_context = NULL;

VarDecl* Utils::get_variable_declaration(Expr* expr) {
    if(auto *decl = dyn_cast<DeclRefExpr>(expr)) {
        if(auto *var_decl = dyn_cast<VarDecl>(decl->getDecl())) {
            return var_decl;
        }
    }
    throw;
}

Expr* Utils::get_parent(Expr* expr) {
    DynTypedNodeList cast = _ast_context->getParents(*expr);
    return const_cast<Expr*>(cast[0].get<Expr>());
}


ImplicitCastExpr* Utils::get_parent_of_var_usage(DeclRefExpr* var_usage) {
    Expr* parent = get_parent(var_usage);
    if(auto *cast_expr = dyn_cast<ImplicitCastExpr>(parent)) {
        return cast_expr;
    }
    throw;
}


BinaryOperator* Utils::get_assign_expr(Expr* expr) {
    return dyn_cast<BinaryOperator>(_get_assign_expr(expr));
}


Expr* Utils::_get_assign_expr(Expr* expr) {
    DynTypedNodeList par = _ast_context->getParents(*expr);
    Expr* par_expr = const_cast<Expr*>(par[0].get<Expr>());
    if(auto* bop = dyn_cast<BinaryOperator>(par_expr)) {
        if(bop->isAssignmentOp()) {
            return bop;
        }
    }
    return _get_assign_expr(const_cast<Expr*>(par[0].get<Expr>()));
}


string Utils::dump_to_string(Stmt* stmt) {
    string str;
    raw_string_ostream os(str);
    stmt->printPretty(os, nullptr, PrintingPolicy(LangOptions()), 0, "\n", _ast_context);
    return str;
}

