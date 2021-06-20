#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "clang.h"
#include "basic_block.h"
#include "utils.h"
#include "ast.h"

class ExampleVisitor : public RecursiveASTVisitor<ExampleVisitor> {
private:
    ASTContext *astContext;
    AST* ast;

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

        else if(auto *implicit_cast_expr = dyn_cast<ImplicitCastExpr>(stmt)) {
            __find_usages_in_stmt(implicit_cast_expr->getSubExpr(), usages);
        }

        else if(auto *decl_ref_expr = dyn_cast<DeclRefExpr>(stmt)){
            usages.insert(decl_ref_expr);
        }

        else {
            // empty
        }
    }

    vector<Stmt*> _get_statements(CFGBlock* bb) {
        vector<Stmt*> out;
        for(auto stmt_iter = bb->begin(); stmt_iter != bb->end(); ++stmt_iter) {
            out.push_back(const_cast<Stmt*>(stmt_iter->getAs<CFGStmt>()->getStmt()));
        }
        return out;
    }

    void _traverse_cfg(CFGBlock* entry) {
        unordered_map<CFGBlock*, BlockInfo> block_info;
        // possible values (pointers to assignments) of a variable usage
        unordered_map<DeclRefExpr*, unordered_set<BinaryOperator*>> possible_values;
        // set of variable usages which an assignment can influence
        unordered_map<BinaryOperator*, unordered_set<DeclRefExpr*>> reach;

        queue<CFGBlock*> q;
        q.push(entry);
        block_info[entry] = BlockInfo();

        while(!q.empty()) {
            auto* bb = q.front();
            q.pop();

            auto bb_statements = _get_statements(bb);

            // get the initial variable values from block entry
            auto assigned_values = block_info[bb].possible_values_at_entry;

            for(auto* stmt : bb_statements) {
                auto usages = _find_usages_in_stmt(stmt);
                for(auto* usage : usages) {
                    // for each variable usage in the statement, determine which values it can hold
                    // (either those from block entry, or the one which was assigned in the block)
                    auto* var_decl = Utils::get_variable_declaration(usage);
                    possible_values[usage] = assigned_values[var_decl];
                    for(auto* item : possible_values[usage]) {
                        // also update the reach of the respective assignment to the just-found usage
                        reach[item].insert(usage);
                    }
                }
                if(Utils::is_assign_stmt(stmt)) {
                    // in case the value is (re)assigned in the block, clear all potential previous values, as it
                    // now has only the assigned one
                    auto* bop = dyn_cast<BinaryOperator>(stmt);
                    assigned_values[Utils::get_variable_declaration(bop->getLHS())].clear();
                    assigned_values[Utils::get_variable_declaration(bop->getLHS())].insert(bop);
                }
            }
            // remember values at exit and use them as entry values for successors
            block_info[bb].possible_values_at_exit = assigned_values;

            // merge the entry values with all successors and process those where necessary
            for(auto succ : bb->succs()) {
                auto successor = &*succ;
                bool push = false;

                if(!contains(block_info, successor)) {
                    // the successor has not been seen yet
                    block_info[succ] = BlockInfo();
                    push = true;
                }
                for(auto & x : block_info[bb].possible_values_at_exit) {
                    if(!contains(block_info[successor].possible_values_at_entry, x.first)) {
                        // in the successor, there is no value for the variable
                        block_info[successor].possible_values_at_entry[x.first] = x.second;
                        push = true;
                    }
                    else {
                        auto & possible_values_for_var_at_entry = block_info[successor].possible_values_at_entry[x.first];
                        // if we add any new possible values, we also need to reprocess the block
                        for(auto* val : x.second) {
                            if(!contains(possible_values_for_var_at_entry, val)) {
                                possible_values_for_var_at_entry.insert(val);
                                push = true;
                            }
                        }
                    }
                }
                if(push) q.push(successor);
            }
        }

//        for(auto & x : possible_values) {
//            cerr << "Values for " << x.first << ":\n";
//            for(auto* y : x.second) {
//                cerr << "    " << Utils::dump_to_string(y) << "\n";
//            }
//        }
//        for(auto & x : reach) {
//            cerr << "Reach of " << Utils::dump_to_string(x.first) << ":\n";
//            for(auto* y : x.second) {
//                cerr << "    " << y << "\n";
//            }
//        }

        _inline_expressions(possible_values, reach, 1);
    }

    void _inline_expressions(const unordered_map<DeclRefExpr*, unordered_set<BinaryOperator*>> & possible_values,
                             const unordered_map<BinaryOperator*, unordered_set<DeclRefExpr*>> & reach,
                             unsigned int inline_policy) {
        unordered_set<DeclRefExpr*> can_be_inlined;
        for(auto & x : possible_values) {
            // only those with an unambiguous value can be inlined
            if(x.second.size() == 1) {
                can_be_inlined.insert(x.first);
            }
        }

        for(auto & x : reach) {
            if(x.second.size() <= inline_policy) {
                bool assign_used = false;
                // iterate over all usages provided there is fewer of them than the inline policy says
                for(auto & y : x.second) {
                    if(contains(can_be_inlined, y)){
                        // if the usage can be inlined, inline it
                        ast->replace_stmt(y, x.first->getRHS());
                    }
                    else {
                        // otherwise, the usage is important and cannot be removed after inlining
                        assign_used = true;
                    }
                }
                if(!assign_used) {
                    ast->remove_stmt(x.first);
                }
            }
        }
    }

public:
    explicit ExampleVisitor(CompilerInstance *CI)
            : astContext(&(CI->getASTContext())) // initialize private members
    { }

    virtual bool VisitFunctionDecl(FunctionDecl *function_decl) {
        cerr << "Traversing function " << function_decl->getNameAsString() << "\n";

        ast = new AST(function_decl);

        if(!function_decl->hasBody()) {
            cerr << "Function " << function_decl->getNameAsString() << " has no body!\n";
            throw;
        }

        auto cfg = CFG::buildCFG(function_decl, function_decl->getBody(), astContext, CFG::BuildOptions());
//        cfg->dump(LangOptions(), true);
        CFGBlock* entry = &(cfg->getEntry());
//        function_decl->getBody()->dump();
        _traverse_cfg(entry);

        return true;
    }
};
