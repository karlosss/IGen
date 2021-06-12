#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "clang.h"
#include "basic_block.h"
#include "utils.h"

class NoSegfaultVisitor : public RecursiveASTVisitor<NoSegfaultVisitor> {
private:
    ASTContext *astContext;


public:
    explicit NoSegfaultVisitor(CompilerInstance *CI)
            : astContext(&(CI->getASTContext())) // initialize private members
    { }

    virtual bool VisitFunctionDecl(FunctionDecl* function_decl) {
        // dirty trick to make rewriter not segfault on no other edits
        rewriter.ReplaceText(function_decl->getNameInfo().getSourceRange(), function_decl->getNameInfo().getSourceRange());
        return true;
    }
};
