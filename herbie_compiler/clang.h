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
#include "clang/Analysis/CFG.h"

using namespace clang;
using namespace llvm;
using namespace std;
using namespace clang::tooling;

extern llvm::cl::OptionCategory MyToolCategory;
extern Rewriter rewriter;
