#include "clang.h"
#include "frontend_action.h"
#include "llvm/Support/raw_ostream.h"

int main(int argc, const char** argv) {
    remove("herbie_vals.txt");
    remove("herbie_ir.txt");

    error_code ec;
    raw_fd_ostream herbie_ir("herbie_ir.txt", ec);

    CommonOptionsParser op(argc, argv, MyToolCategory);
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());
    int result = Tool.run(newFrontendActionFactory<ExampleFrontendAction>().get());
    auto fid = rewriter.getSourceMgr().getMainFileID();
    rewriter.getEditBuffer(fid).write(herbie_ir);
    return result;
}
