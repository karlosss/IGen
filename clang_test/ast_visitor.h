#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "clang.h"
#include "basic_block.h"
#include "utils.h"

class ExampleVisitor : public RecursiveASTVisitor<ExampleVisitor> {
private:
    ASTContext *astContext;

    unordered_set<DeclRefExpr*> _find_usages_in_stmt(Stmt* stmt) {
        unordered_set<DeclRefExpr*> usages;
        __find_usages_in_stmt(stmt, usages);
        return usages;
    }

    void __find_usages_in_stmt(Stmt* stmt, unordered_set<DeclRefExpr*> & usages) {
        if(auto *bop = dyn_cast<BinaryOperator>(stmt)) {
            if(!bop->isAssignmentOp()) {
                __find_usages_in_stmt(bop->getLHS(), usages);
            }
            __find_usages_in_stmt(bop->getRHS(), usages);
        }

        else if(auto *cast = dyn_cast<ImplicitCastExpr>(stmt)) {
            __find_usages_in_stmt(cast->getSubExpr(), usages);
        }

        else if(auto *decl_expr = dyn_cast<DeclRefExpr>(stmt)){
            usages.insert(decl_expr);
        }

        else if(auto *decl_stmt = dyn_cast<DeclStmt>(stmt)) {
            for(auto & decl : decl_stmt->decls()) {
                if(auto* var_decl = dyn_cast<VarDecl>(decl)) {
                    if(var_decl->hasInit()) {
                        __find_usages_in_stmt(var_decl->getInit(), usages);
                    }
                }
            }
        }
    }

    bool _is_assign_stmt(Stmt* stmt) {
        if(auto *bop = dyn_cast<BinaryOperator>(stmt)) {
            if(bop->isAssignmentOp()) {
                return true;
            }
        }

        else if(auto *decl_stmt = dyn_cast<DeclStmt>(stmt)) {
            for(auto & decl : decl_stmt->decls()) {
                if(auto* var_decl = dyn_cast<VarDecl>(decl)) {
                    if(var_decl->hasInit()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    VarAssignInfo* _get_assign_info(Stmt* stmt) {
        if(!_is_assign_stmt(stmt)){
            cerr << "Not an assign statement!\n";
            stmt->dump();
            throw;
        }

        VarAssignInfo* info = new VarAssignInfo();

        if(auto *bop = dyn_cast<BinaryOperator>(stmt)) {
            info->assign_stmt = bop;
            info->value = bop->getRHS();
            auto* var = dyn_cast<DeclRefExpr>(bop->getLHS())->getDecl();
            info->var = dyn_cast<VarDecl>(var);
        }

        else if(auto *decl_stmt = dyn_cast<DeclStmt>(stmt)) {
            for(auto & decl : decl_stmt->decls()) {
                if(auto* var_decl = dyn_cast<VarDecl>(decl)) {
                    if(var_decl->hasInit()) {
                        info->assign_stmt = decl_stmt;
                        info->value = var_decl->getInit();
                        info->var = var_decl;
                    }
                }
            }
        }

        return info;
    }

    vector<Stmt*> _get_statements(CFGBlock* bb) {
        vector<Stmt*> out;
        for(auto stmt_iter = bb->begin(); stmt_iter != bb->end(); ++stmt_iter) {
            out.push_back(const_cast<Stmt*>(stmt_iter->getAs<CFGStmt>()->getStmt()));
        }
        return out;
    }

    VarDecl* _get_decl(DeclRefExpr* x) {
        return dyn_cast<VarDecl>(x->getDecl());
    }

    void _traverse_cfg(CFGBlock* entry) {
        auto block_info = unordered_map<CFGBlock*, BlockInfo>();
        auto var_access = unordered_map<DeclRefExpr*, VarAccessInfo>();
        auto block_var_assign = unordered_map<VarDecl*, VarAssignInfo*>();


        queue<CFGBlock*> q;
        q.push(entry);

        while(!q.empty()) {
            auto* bb = q.front();
            q.pop();

            if(!contains(block_info, bb)) {
                block_info[bb] = {};
            }

            block_var_assign.clear();

            auto statements = _get_statements(bb);
            for(auto & stmt : statements) {
                // first analyze variable usages in statements (rhs of assignments)
                auto usages = _find_usages_in_stmt(stmt);
                for(auto & usage : usages) {
                    // if the variable was assigned before in the same block, use the value
                    if(contains(block_var_assign, _get_decl(usage))) {
                        auto* possible_values = new unordered_set<VarAssignInfo*>();
                        possible_values->insert(block_var_assign[_get_decl(usage)]);
                        var_access[usage].possible_values = possible_values;
                    }
                    // otherwise use the value at entry
                    else {
                        var_access[usage].possible_values = block_info[bb].values_at_entry[_get_decl(usage)];
                    }
                    // (one of those two cases must always happen, otherwise the variable would be undefined)
                }
                // then analyze if a new variable is assigned in the statement and if so, process it
                if(_is_assign_stmt(stmt)) {
                    auto info = _get_assign_info(stmt);
                    block_var_assign[info->var] = info;
                }
            }
            // add all from the entry
            block_info[bb].values_at_exit
            // update those that occured within the block
            ...

            // push all successors

        }

        // analyze entry block for statements
        for(auto & succ : entry->succs()) {
            auto statements = _get_statements(succ);
            for(auto & stmt : statements) {
                auto usages_in_stmt = _find_usages_in_stmt(stmt);
                cerr << "usages in stmt " << Utils::dump_to_string(stmt) << ":\n";
                for(auto usage : usages_in_stmt) {
                    usage->dump();
                    usage->getDecl()->dump();
                }
                cerr << "\n\n";
//            if(auto* decl_ref_expr = dyn_cast<DeclRefExpr>(stmt)) {
//                decl_ref_expr->dump();
//            }
            }
        }
    }

public:
    explicit ExampleVisitor(CompilerInstance *CI)
            : astContext(&(CI->getASTContext())) // initialize private members
    {
        Utils::init(astContext);
        rewriter.setSourceMgr(astContext->getSourceManager(),
                              astContext->getLangOpts());
    }

    virtual bool VisitFunctionDecl(FunctionDecl *func) {
        // dirty trick to make rewriter not segfault on no other edits
        rewriter.ReplaceText(func->getNameInfo().getSourceRange(), func->getNameInfo().getSourceRange());

        cerr << "Traversing function " << func->getNameAsString() << "\n";

        if(!func->hasBody()) {
            cerr << "Function " << func->getNameAsString() << " has no body!\n";
            throw;
        }

        auto cfg = CFG::buildCFG(func, func->getBody(), astContext, CFG::BuildOptions());
        cfg->dump(LangOptions(), true);
        CFGBlock* entry = &(cfg->getEntry());
        _traverse_cfg(entry);

        return true;
    }

    virtual bool VisitStmt(Stmt* stmt) {
        stmt->dump();
        return true;
    }
};
