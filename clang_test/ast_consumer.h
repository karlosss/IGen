#pragma once

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

#include "ast_visitor.h"
#include "split_decl_and_def_visitor.h"
#include "no_segfault_visitor.h"
#include "utils.h"

using namespace clang;
using namespace llvm;
using namespace std;
using namespace clang::tooling;

class ExampleASTConsumer : public ASTConsumer {
private:
    ExampleVisitor *visitor;
    SplitDeclAndDefVisitor *split_decl_and_def_visitor;
    NoSegfaultVisitor *no_segfault_visitor;

public:
    // override the constructor in order to pass CI
    explicit ExampleASTConsumer(CompilerInstance *CI)
            : visitor(new ExampleVisitor(CI)),
            split_decl_and_def_visitor(new SplitDeclAndDefVisitor(CI)),
            no_segfault_visitor(new NoSegfaultVisitor(CI))
    {
        Utils::init(&(CI->getASTContext()));
        rewriter.setSourceMgr(CI->getASTContext().getSourceManager(), CI->getASTContext().getLangOpts());
    }

    // override this to call our ExampleVisitor on each top-level Decl
    virtual bool HandleTopLevelDecl(DeclGroupRef DG) {
        // a DeclGroupRef may have multiple Decls, so we iterate through each one
        for (DeclGroupRef::iterator i = DG.begin(), e = DG.end(); i != e; i++) {
            Decl *D = *i;
            no_segfault_visitor->TraverseDecl(D);
            split_decl_and_def_visitor->TraverseDecl(D);
            D->getBody()->dump();
            cerr << Utils::dump_to_string(D->getBody()) << "\n";
//            visitor->TraverseDecl(D);

//            auto* d = dyn_cast<FunctionDecl>(D);
//            d->getBody()->dump();
        }
        return true;
    }
};
