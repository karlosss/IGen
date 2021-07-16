import decimal

from expr_ast import *


def __simplify(node, predicate, replacement):
    if predicate(node):
        new_node = replacement(node)
        node.replace(new_node)
        __simplify(new_node, predicate, replacement)
    else:
        for child in node.children:
            __simplify(child, predicate, replacement)


def _simplify(ast, predicate, replacement):
    if predicate(ast.root):
        ast.root = replacement(ast.root)
        _simplify(ast, predicate, replacement)
    else:
        for child in ast.root.children:
            __simplify(child, predicate, replacement)


def simplify_unminus(ast):
    _simplify(ast,
              lambda node: isinstance(node, UnaryMinusNode) and isinstance(node.children[0], UnaryMinusNode),
              lambda node: node.children[0].children[0]
              )


def simplify_mul_1_0(ast):
    simplify_unminus(ast)

    # simplify 0
    _simplify(ast,
              lambda node: isinstance(node, MulNode) and (
                      (isinstance(node.children[0], ConstNode) and node.children[0].val == 0) or
                      (isinstance(node.children[1], ConstNode) and node.children[1].val == 0)),
              lambda node: ConstNode(decimal.Decimal(0))
              )

    # simplify +1
    _simplify(ast,
              lambda node: isinstance(node, MulNode) and (
                      (isinstance(node.children[0], ConstNode) and node.children[0].val == 1) or
                      (isinstance(node.children[1], ConstNode) and node.children[1].val == 1)),
              lambda node: node.children[0] if isinstance(node.children[1], ConstNode) and node.children[1].val == 1
              else node.children[1]
              )
    # simplify -1
    _simplify(ast,
              lambda node: isinstance(node, MulNode) and (
                      (isinstance(node.children[0], UnaryMinusNode) and isinstance(node.children[0].children[0], ConstNode) and node.children[0].children[0].val == -1) or
                      (isinstance(node.children[1], UnaryMinusNode) and isinstance(node.children[1].children[0], ConstNode) and node.children[1].children[0].val == -1)),
              lambda node: UnaryMinusNode(node.children[0]) if isinstance(node.children[1], UnaryMinusNode) and isinstance(node.children[1].children[0], ConstNode) and node.children[1].children[0].val == -1
              else UnaryMinusNode(node.children[1])
              )

    simplify_unminus(ast)


def simplify_functions(ast):
    # simplify square root - power
    _simplify(ast,
              lambda node: isinstance(node, SqrtNode) and isinstance(node.children[0], PowNode) and isinstance(node.children[0].children[1], ConstNode),
              lambda node: PowNode(node.children[0].children[0], ConstNode(node.children[0].children[1].val / decimal.Decimal(2)))
              )
    _simplify(ast,
              lambda node: isinstance(node, PowNode) and isinstance(node.children[0], SqrtNode) and isinstance(node.children[1], ConstNode),
              lambda node: PowNode(node.children[0].children[0], ConstNode(node.children[1].val / decimal.Decimal(2)))
              )

    # simplify cube root - power
    _simplify(ast,
              lambda node: isinstance(node, CbrtNode) and isinstance(node.children[0], PowNode) and isinstance(node.children[0].children[1], ConstNode),
              lambda node: PowNode(node.children[0].children[0], ConstNode(node.children[0].children[1].val / decimal.Decimal(3)))
              )
    _simplify(ast,
              lambda node: isinstance(node, PowNode) and isinstance(node.children[0], CbrtNode) and isinstance(node.children[1], ConstNode),
              lambda node: PowNode(node.children[0].children[0], ConstNode(node.children[1].val / decimal.Decimal(3)))
              )

    # simplify power ** 1
    _simplify(ast,
              lambda node: isinstance(node, PowNode) and isinstance(node.children[1], ConstNode) and node.children[1].val == decimal.Decimal(1),
              lambda node: node.children[0]
              )

    # simplify exp - log
    _simplify(ast,
              lambda node: isinstance(node, ExpNode) and isinstance(node.children[0], LnNode),
              lambda node: node.children[0].children[0]
              )
    _simplify(ast,
              lambda node: isinstance(node, LnNode) and isinstance(node.children[0], ExpNode),
              lambda node: node.children[0].children[0]
              )


def eval_const(ast):
    _simplify(ast,
              lambda node: hasattr(node, "eval_const") and node.eval_const() is not None,
              lambda node: ConstNode(node.eval_const())
              )


def simplify(ast):
    simplify_mul_1_0(ast)
    simplify_functions(ast)
    eval_const(ast)
