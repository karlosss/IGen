#include "utils.h"

ASTContext* Utils::ast_context = nullptr;

VarDecl* Utils::get_variable_declaration(Expr* expr) {
    if(auto *decl = dyn_cast<DeclRefExpr>(expr)) {
        if(auto *var_decl = dyn_cast<VarDecl>(decl->getDecl())) {
            return var_decl;
        }
    }
    throw;
}

//void Utils::replace_stmt(AST* ast, Stmt* old_stmt, Stmt* new_stmt) {
//    auto parent = ast->get_parent(old_stmt);
//
//    if(ast->is_root(old_stmt)) {
//        ast->root()->setBody(new_stmt);
//    }
//
//    else if(auto* if_stmt = dyn_cast<IfStmt>(parent)) {
//        // check if the parent is then or else branch
//        if(old_stmt == if_stmt->getThen()) {
//            if_stmt->setThen(new_stmt);
//        }
//        else if(old_stmt == if_stmt->getElse()) {
//            if_stmt->setElse(new_stmt);
//        }
//        else {
//            throw;
//        }
//    }
//
//    else if(auto* for_stmt = dyn_cast<ForStmt>(parent)) {
//        for_stmt->setBody(new_stmt);
//    }
//
//    else if(auto* compound_stmt = dyn_cast<CompoundStmt>(parent)) {
//        vector<Stmt*> new_statements;
//        for(auto & stmt : compound_stmt->children()) {
//            if(stmt == old_stmt) {
//                new_statements.push_back(new_stmt);
//            }
//            else {
//                new_statements.push_back(old_stmt);
//            }
//        }
//        auto* new_compound_stmt = CompoundStmt::Create(*_ast_context, ArrayRef<Stmt*>(new_statements), compound_stmt->getBeginLoc(), compound_stmt->getEndLoc());
//        replace_stmt(ast, compound_stmt, new_compound_stmt);
//    }
//
//    else {
//        cerr << "Cannot handle " << parent->getStmtClassName() << " as parent class!\n";
//        throw;
//    }
//    ast->walk(parent);
//}
//
//
//void Utils::insert_into_compound_after_stmt(AST* ast, CompoundStmt* compound, Stmt* insert, Stmt* after) {
//
//    // build vector of new statements, inserting the extra one
//    vector<Stmt*> new_statements;
//    for(auto & stmt : compound->children()) {
//        new_statements.push_back(stmt);
//        if(stmt == after) {
//            new_statements.push_back(insert);
//        }
//    }
//
//    auto* new_compound_stmt = CompoundStmt::Create(*_ast_context, ArrayRef<Stmt*>(new_statements), compound->getBeginLoc(), compound->getEndLoc());
//
//    replace_stmt(ast, compound, new_compound_stmt);
//}


Expr* Utils::_get_assign_expr(Expr* expr) {
    DynTypedNodeList par = ast_context->getParents(*expr);
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
    stmt->printPretty(os, nullptr, PrintingPolicy(LangOptions()), 0, "\n", ast_context);
    return str;
}

