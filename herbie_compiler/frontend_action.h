#pragma once

#include "clang.h"
#include "ast_consumer.h"

class ExampleFrontendAction : public ASTFrontendAction {
public:
    virtual std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef file) override {
        return (std::unique_ptr<ASTConsumer>) new HerbieASTConsumer(&CI); // pass CI pointer to ASTConsumer
    }
};
