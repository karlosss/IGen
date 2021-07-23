import pyparsing
import decimal
from expr_ast import *


class _AstHandler:
    def __init__(self, tokens):
        self.tokens = tokens[0]

    def ast(self):
        raise NotImplementedError


class _VariableHandler(_AstHandler):
    variable_map = {}
    reverse_variable_map = {}

    def ast(self):
        if self.tokens not in self.variable_map:
            self.variable_map[self.tokens] = "x{}".format(len(self.variable_map))
        self.reverse_variable_map[self.variable_map[self.tokens]] = self.tokens
        return VarNode(self.variable_map[self.tokens])


class _NumberHandler(_AstHandler):
    def ast(self):
        return ConstNode(decimal.Decimal(str(self.tokens)))


class _BinaryOperatorHandler(_AstHandler):
    def ast(self):
        lhs = self.tokens[:-2]
        op = self.tokens[-2]
        rhs = self.tokens[-1]
        if len(lhs) == 1:
            out_lhs = lhs[0].ast()
        else:
            out_lhs = _BinaryOperatorHandler([lhs]).ast()

        if op == "+":
            return PlusNode(out_lhs, rhs.ast())
        elif op == "-":
            return MinusNode(out_lhs, rhs.ast())
        elif op == "*":
            return MulNode(out_lhs, rhs.ast())
        elif op == "/":
            return DivNode(out_lhs, rhs.ast())
        else:
            raise AssertionError("Unknown binary operator: {}".format(op))


class _UnaryOperatorHandler(_AstHandler):
    def ast(self):
        op = self.tokens[0]
        if op == "sqrt":
            return SqrtNode(self.tokens[1].ast())
        elif op == "cbrt":
            return CbrtNode(self.tokens[1].ast())
        elif op == "exp":
            return ExpNode(self.tokens[1].ast())
        elif op == "log":
            return LnNode(self.tokens[1].ast())
        elif op == "-":
            return UnaryMinusNode(self.tokens[1].ast())
        else:
            raise AssertionError("Unknown unary operator: {}".format(op))


def infix_to_ast(input_string):
    print("<infix_to_ast> " + input_string.strip())

    real = pyparsing.Regex(r'[+-]?(?:\d+(?:[eE][+-]?\d+)|(?:\d+\.\d*|\.\d+)(?:[eE][+-]?\d+)?)')
    integer = pyparsing.Word(pyparsing.nums)
    number = real | integer
    number.setParseAction(_NumberHandler)

    variable = pyparsing.Combine(pyparsing.Word(pyparsing.alphas) +
                                 pyparsing.Optional(pyparsing.Word(pyparsing.alphanums))
                                 )
    variable.setParseAction(_VariableHandler)

    operand = number | variable

    plus_minus = pyparsing.oneOf("+ -")
    unary_plus_minus_sqrt = pyparsing.oneOf("+ - sqrt")
    times_divide = pyparsing.oneOf("* /")

    expr = pyparsing.infixNotation(
        operand,
        [
            (unary_plus_minus_sqrt, 1, pyparsing.opAssoc.RIGHT, _UnaryOperatorHandler),
            (times_divide, 2, pyparsing.opAssoc.LEFT, _BinaryOperatorHandler),
            (plus_minus, 2, pyparsing.opAssoc.LEFT, _BinaryOperatorHandler),
        ]
    )

    return (AST(expr.parseString(input_string)[0].ast()),
            _VariableHandler.variable_map,
            _VariableHandler.reverse_variable_map)


def _build_ast_from_prefix(root, variable_map):
    if isinstance(root, str):
        if root.startswith("x"):
            return VarNode(variable_map[root])
        else:
            return ConstNode(decimal.Decimal(root))
    elif len(root) == 2:
        if root[0] == "not":
            return NotNode(_build_ast_from_prefix(root[1], variable_map))
        elif root[0] == "sqrt":
            return SqrtNode(_build_ast_from_prefix(root[1], variable_map))
        elif root[0] == "cbrt":
            return CbrtNode(_build_ast_from_prefix(root[1], variable_map))
        elif root[0] == "exp":
            return ExpNode(_build_ast_from_prefix(root[1], variable_map))
        elif root[0] == "log":
            return LnNode(_build_ast_from_prefix(root[1], variable_map))
        elif root[0] == "-":
            return UnaryMinusNode(_build_ast_from_prefix(root[1], variable_map))
        else:
            raise AssertionError("Unknown function: {}".format(root[0]))
    elif len(root) == 3:
        if root[0] == "+":
            return PlusNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "-":
            return MinusNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "*":
            return MulNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "/":
            return DivNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "<":
            return LtNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "<=":
            return LtOrEqNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == ">":
            return GtNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == ">=":
            return GtOrEqNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "==":
            return EqNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "!=":
            return NotEqNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "or":
            return OrNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "and":
            return AndNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        elif root[0] == "pow":
            return PowNode(_build_ast_from_prefix(root[1], variable_map), _build_ast_from_prefix(root[2], variable_map))
        else:
            raise AssertionError("Unknown function: {}".format(root[0]))
    elif len(root) == 4:
        if root[0] == "if":
            return TernaryOperatorNode(_build_ast_from_prefix(root[1], variable_map),
                                       _build_ast_from_prefix(root[2], variable_map),
                                       _build_ast_from_prefix(root[3], variable_map))
        else:
            raise AssertionError("Unknown function: {}".format(root[0]))
    else:
        raise AssertionError("Unknown function: {}".format(root[0]))


def prefix_to_ast(input_string, variable_map):
    print("<prefix_to_ast> " + input_string, variable_map)

    func_name = pyparsing.oneOf("+ - / * sqrt cbrt pow log exp if < > <= >= == != not and or")
    real = pyparsing.Regex(r'[+-]?(?:\d+(?:[eE][+-]?\d+)|(?:\d+\.\d*|\.\d+)(?:[eE][+-]?\d+)?)')
    integer = pyparsing.Word(pyparsing.nums)
    variable = pyparsing.Combine("x" + pyparsing.Word(pyparsing.nums))
    terminal = pyparsing.Combine(pyparsing.Optional("-") + (real | integer | variable))

    expression = pyparsing.Forward()
    expression << (terminal | (
            pyparsing.Suppress("(") +
            pyparsing.Group(func_name + pyparsing.OneOrMore(expression | terminal)) +
            pyparsing.Suppress(")")
    ))

    res = expression.parseString(input_string)
    if isinstance(res[0], str):
        return AST(_build_ast_from_prefix(res[0], variable_map))
    return AST(_build_ast_from_prefix(res[0].asList(), variable_map))
