#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "clang.h"
#include "basic_block.h"
#include "utils.h"
#include "ast.h"

class HerbieVisitor : public RecursiveASTVisitor<HerbieVisitor> {
private:
    ASTContext *astContext;
    AST* ast;

    unordered_set<Expr*> _arith_exprs;

    void _find_arithmetic_exprs(Stmt* stmt) {
        if(!stmt) return;

        if(auto* integer_literal = dyn_cast<IntegerLiteral>(stmt)) {
            _arith_exprs.insert(integer_literal);
        }
        else if(auto* floating_literal = dyn_cast<FloatingLiteral>(stmt)) {
            _arith_exprs.insert(floating_literal);
        }
        else if(auto* decl_ref_expr = dyn_cast<DeclRefExpr>(stmt)) {
            _arith_exprs.insert(decl_ref_expr);
        }

        else if(auto* implicit_cast_expr = dyn_cast<ImplicitCastExpr>(stmt)) {
            _find_arithmetic_exprs(implicit_cast_expr->getSubExpr());
            if(contains(_arith_exprs, implicit_cast_expr->getSubExpr())) {
                _arith_exprs.erase(implicit_cast_expr->getSubExpr());
                _arith_exprs.insert(implicit_cast_expr);
            }
        }
        else if(auto* bop = dyn_cast<BinaryOperator>(stmt)) {
            if(!bop->isAssignmentOp()) {
                _find_arithmetic_exprs(bop->getLHS());
            }
            _find_arithmetic_exprs(bop->getRHS());
            if((bop->isAdditiveOp() || bop->isMultiplicativeOp()) &&
                contains(_arith_exprs, bop->getLHS()) &&
                contains(_arith_exprs, bop->getRHS())
            ) {
                _arith_exprs.erase(bop->getRHS());
                _arith_exprs.erase(bop->getLHS());
                _arith_exprs.insert(bop);
            }
        }
        else if(auto* uop = dyn_cast<UnaryOperator>(stmt)) {
            _find_arithmetic_exprs(uop->getSubExpr());
            if(contains(_arith_exprs, uop->getSubExpr())) {
                _arith_exprs.erase(uop->getSubExpr());
                _arith_exprs.insert(uop);
            }
        }

        else if(auto* compound_stmt = dyn_cast<CompoundStmt>(stmt)) {
            for(auto* child : compound_stmt->children()) {
                _find_arithmetic_exprs(child);
            }
        }
        else if(auto* if_stmt = dyn_cast<IfStmt>(stmt)) {
            _find_arithmetic_exprs(if_stmt->getCond());
            _find_arithmetic_exprs(if_stmt->getThen());
            if(if_stmt->hasElseStorage()) {
                _find_arithmetic_exprs(if_stmt->getElse());
            }
        }
        else if(auto* for_stmt = dyn_cast<ForStmt>(stmt)) {
            _find_arithmetic_exprs(for_stmt->getBody());
        }
        else if(auto* while_stmt = dyn_cast<WhileStmt>(stmt)) {
            _find_arithmetic_exprs(while_stmt->getBody());
        }
        else if(auto* decl_stmt = dyn_cast<DeclStmt>(stmt)) {
            // do nothing - declarations and initializations are split into two statements
        }
        else if(auto* paren_expr = dyn_cast<ParenExpr>(stmt)) {
            _find_arithmetic_exprs(paren_expr->getSubExpr());
            if(contains(_arith_exprs, paren_expr->getSubExpr())) {
                _arith_exprs.erase(paren_expr->getSubExpr());
                _arith_exprs.insert(paren_expr);
            }
        }
        else if(auto* return_stmt = dyn_cast<ReturnStmt>(stmt)) {
            _find_arithmetic_exprs(return_stmt->getRetValue());
        }
        else if(auto* call_expr = dyn_cast<CallExpr>(stmt)) {
            const auto & func_name = call_expr->getDirectCallee()->getNameAsString();
            if(func_name == "sqrt") {
                _find_arithmetic_exprs(call_expr->getArg(0));
                if(contains(_arith_exprs, call_expr->getArg(0))) {
                    _arith_exprs.erase(call_expr->getArg(0));
                    _arith_exprs.insert(call_expr);
                }
            }
            else {
                for(auto* child : call_expr->arguments()) {
                    _find_arithmetic_exprs(child);
                }
            }
        }
        else {
            cerr << "<HerbieVisitor> unknown statement type: " << stmt->getStmtClassName() << "\n";
        }
    }

public:
    explicit HerbieVisitor(CompilerInstance *CI)
            : astContext(&(CI->getASTContext())) // initialize private members
    {}

    virtual bool VisitFunctionDecl(FunctionDecl* function_decl) {
        ast = new AST(function_decl);
        _arith_exprs.clear();
        _find_arithmetic_exprs(function_decl->getBody());

        // replace arithmetic expressions with placeholders
        ofstream herbie;
        herbie.open("herbie_vals.txt", ios_base::app);

        static int i = 1;
        for(auto* expr : _arith_exprs) {
            if(!expr->getType()->isFloatingType()) continue; // ignore non-floating expressions

            herbie << Utils::dump_to_string(expr) << "\n";
            auto* placeholder = clang::StringLiteral::Create(*astContext, "<{[HERBIE-" + to_string(i) + "]}>", clang::StringLiteral::StringKind::Ascii, false, QualType(), expr->getBeginLoc());
            ast->replace_stmt(expr, placeholder);
            i++;
        }
        herbie.close();
        return true;
    }
};
