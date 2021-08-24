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

#include "inline_visitor.h"
#include "split_decl_and_def_visitor.h"
#include "utils.h"
#include "herbie_visitor.h"

using namespace clang;
using namespace llvm;
using namespace std;
using namespace clang::tooling;

class HerbieASTConsumer : public ASTConsumer {
private:
    InlineVisitor *inline_visitor;
    SplitDeclAndDefVisitor *split_decl_and_def_visitor;
    HerbieVisitor *herbie_visitor;
public:
    // override the constructor in order to pass CI
    explicit HerbieASTConsumer(CompilerInstance *CI)
            : inline_visitor(new InlineVisitor(CI)),
            split_decl_and_def_visitor(new SplitDeclAndDefVisitor(CI)),
            herbie_visitor(new HerbieVisitor(CI))
    {
        Utils::init(&(CI->getASTContext()));
        rewriter.setSourceMgr(CI->getASTContext().getSourceManager(), CI->getASTContext().getLangOpts());
    }

    // override this to call our InlineVisitor on each top-level Decl
    virtual bool HandleTopLevelDecl(DeclGroupRef DG) {
        // a DeclGroupRef may have multiple Decls, so we iterate through each one
        for (DeclGroupRef::iterator i = DG.begin(), e = DG.end(); i != e; i++) {
            Decl *D = *i;
            if(!D->hasBody()) continue;
            split_decl_and_def_visitor->TraverseDecl(D);
            rewriter.ReplaceText(D->getBody()->getSourceRange(), Utils::dump_to_string(D->getBody()));
            inline_visitor->TraverseDecl(D);
            rewriter.ReplaceText(D->getBody()->getSourceRange(), Utils::dump_to_string(D->getBody()));
            herbie_visitor->TraverseDecl(D);
            rewriter.ReplaceText(D->getBody()->getSourceRange(), Utils::dump_to_string(D->getBody()));
        }
        return true;
    }
};
