#include "clang.h"
#include "frontend_action.h"

int main(int argc, const char** argv) {
    CommonOptionsParser op(argc, argv, MyToolCategory);
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());
    int result = Tool.run(newFrontendActionFactory<ExampleFrontendAction>().get());
    auto fid = rewriter.getSourceMgr().getMainFileID();
    rewriter.getEditBuffer(fid).write(outs());
    return result;
}
