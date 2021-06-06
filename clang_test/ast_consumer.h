#ifndef CLANG_AST_VISITOR_AST_CONSUMER_H
#define CLANG_AST_VISITOR_AST_CONSUMER_H

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

using namespace clang;
using namespace llvm;
using namespace std;
using namespace clang::tooling;

class ExampleASTConsumer : public ASTConsumer {
private:
    ExampleVisitor *visitor; // doesn't have to be private

public:
    // override the constructor in order to pass CI
    explicit ExampleASTConsumer(CompilerInstance *CI)
            : visitor(new ExampleVisitor(CI)) // initialize the visitor
    { }

    // override this to call our ExampleVisitor on each top-level Decl
    virtual bool HandleTopLevelDecl(DeclGroupRef DG) {
        // a DeclGroupRef may have multiple Decls, so we iterate through each one
        for (DeclGroupRef::iterator i = DG.begin(), e = DG.end(); i != e; i++) {
            Decl *D = *i;
            visitor->TraverseDecl(D); // recursively visit each AST node in Decl "D"
            auto* d = dyn_cast<FunctionDecl>(D);
            visitor->TraverseFuncEnd(d);
        }
        return true;
    }
};

#endif //CLANG_AST_VISITOR_AST_CONSUMER_H
