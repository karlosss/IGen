from expr_ast import *


def _eval_const(node):
    if not hasattr(node, "eval_const"):
        for child in node.children:
            _eval_const(child)
    else:
        res = node.eval_const()
        if res is None:
            for child in node.children:
                _eval_const(child)
        else:
            if not node.is_root():
                node.replace(ConstNode(res))
                _eval_const(node.parent)


def eval_const(ast):
    _eval_const(ast.root)
    if hasattr(ast.root, "eval_const"):
        res = ast.root.eval_const()
        if res is not None:
            ast.root = ConstNode(res)
    return ast
