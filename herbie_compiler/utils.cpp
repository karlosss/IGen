#include "utils.h"

ASTContext* Utils::ast_context = nullptr;

VarDecl* Utils::get_variable_declaration(Expr* expr) {
    if(auto *decl = dyn_cast<DeclRefExpr>(expr)) {
        if(auto *var_decl = dyn_cast<VarDecl>(decl->getDecl())) {
            return var_decl;
        }
    }
    cerr << expr->getStmtClassName() << "\n";
    throw;
}

bool Utils::is_assign_stmt(Stmt* stmt) {
    if(auto *bop = dyn_cast<BinaryOperator>(stmt)) {
        return bop->isAssignmentOp();
    }
    return false;
}

string Utils::dump_to_string(Stmt* stmt) {
    string str;
    raw_string_ostream os(str);
    stmt->printPretty(os, nullptr, PrintingPolicy(LangOptions()), 0, "\n", ast_context);
    return str;
}

CompoundStmt* Utils::create_compound_stmt(const vector<Stmt*> & statements, SourceLocation begin_loc, SourceLocation end_loc) {
    return CompoundStmt::Create(*ast_context, ArrayRef<Stmt*>(statements), begin_loc, end_loc);
}
