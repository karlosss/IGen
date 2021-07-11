class ASTNode:
    def to_infix(self):
        return self._to_infix(parenthesized=False)

    def _to_infix(self, parenthesized=True):
        raise NotImplementedError

    def to_prefix(self):
        raise NotImplementedError


class ConstNode(ASTNode):
    def __init__(self, val):
        self.val = val

    def _to_infix(self, parenthesized=True):
        return str(self.val)

    def to_prefix(self):
        return str(self.val)


class VarNode(ASTNode):
    def __init__(self, name):
        self.name = name

    def _to_infix(self, parenthesized=True):
        return self.name

    def to_prefix(self):
        return self.name


class OperatorNode(ASTNode):
    operator_name = None
    priority = None


class BinaryOperatorNode(OperatorNode):
    def __init__(self, lhs, rhs):
        self.lhs = lhs
        self.rhs = rhs

    def to_prefix(self):
        return "({} {} {})".format(self.operator_name, self.lhs.to_prefix(), self.rhs.to_prefix())

    def _to_infix(self, parenthesized=True):
        res = "{} {} {}".format(self.lhs._to_infix(parenthesized=self.lhs.priority < self.priority if hasattr(self.lhs, "priority") else True),
                                self.operator_name,
                                self.rhs._to_infix(parenthesized=self.rhs.priority < self.priority if hasattr(self.rhs, "priority") else True))
        return "({})".format(res) if parenthesized else res


class AndNode(BinaryOperatorNode):
    operator_name = "&&"
    priority = 1


class OrNode(BinaryOperatorNode):
    operator_name = "||"
    priority = 1


class EqNode(BinaryOperatorNode):
    operator_name = "=="
    priority = 2


class NotEqNode(BinaryOperatorNode):
    operator_name = "!="
    priority = 2


class GtNode(BinaryOperatorNode):
    operator_name = ">"
    priority = 2


class LtNode(BinaryOperatorNode):
    operator_name = "<"
    priority = 2


class GtOrEqNode(BinaryOperatorNode):
    operator_name = ">="
    priority = 2


class LtOrEqNode(BinaryOperatorNode):
    operator_name = "<="
    priority = 2


class PlusNode(BinaryOperatorNode):
    operator_name = "+"
    priority = 3


class MinusNode(BinaryOperatorNode):
    operator_name = "-"
    priority = 3


class MulNode(BinaryOperatorNode):
    operator_name = "*"
    priority = 4


class DivNode(BinaryOperatorNode):
    operator_name = "/"
    priority = 4


class UnaryOperatorNode(OperatorNode):
    def __init__(self, op):
        self.op = op

    def to_prefix(self):
        return "({} {})".format(self.operator_name, self.op.to_prefix())

    def _to_infix(self, parenthesized=True):
        res = "{}{}".format(self.operator_name,
                            self.op._to_infix(parenthesized=self.op.priority < self.priority if hasattr(self.op, "priority") else True))
        return "({})".format(res) if parenthesized else res


class NotNode(UnaryOperatorNode):
    operator_name = "!"
    priority = 5


class UnaryMinusNode(UnaryOperatorNode):
    operator_name = "-"
    priority = -99  # always parenthesize


class TernaryOperatorNode(OperatorNode):
    priority = 99  # max priority to never wrap in additional parentheses

    def __init__(self, cond, if_true, if_false):
        self.cond = cond
        self.if_true = if_true
        self.if_false = if_false

    def to_prefix(self):
        raise AssertionError("Unable to convert ternary operator to prefix form")

    def _to_infix(self, parenthesized=True):
        return "({} ? {} : {})".format(self.cond._to_infix(parenthesized=False),
                                       self.if_true._to_infix(parenthesized=False),
                                       self.if_false._to_infix(parenthesized=False),
                                       )


class FunctionNode(ASTNode):
    fn_name = None
    arity = None

    def __init__(self, *args):
        if len(args) != self.arity:
            raise ValueError("{}: expected {} arguments, {} provided".format(self.fn_name, self.arity, len(args)))
        self.args = args

    def to_prefix(self):
        return "({} {})".format(self.fn_name, " ".join([x.to_prefix() for x in self.args]))

    def _to_infix(self, parenthesized=True):
        return "{}({})".format(self.fn_name, ", ".join([x._to_infix(parenthesized=False) for x in self.args]))


class PowNode(FunctionNode):
    fn_name = "pow"
    arity = 2


class SqrtNode(FunctionNode):
    fn_name = "sqrt"
    arity = 1


class CbrtNode(FunctionNode):
    fn_name = "cbrt"
    arity = 1


class ExpNode(FunctionNode):
    fn_name = "exp"
    arity = 1


class LnNode(FunctionNode):
    fn_name = "log"
    arity = 1
