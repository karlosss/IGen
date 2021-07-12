from math import prod


class AST:
    def __init__(self, root):
        self.root = root

    def to_infix(self):
        return self.root.to_infix()

    def to_prefix(self):
        return self.root.to_prefix()


class EvalConstMixin:
    def eval_const(self):
        raise NotImplementedError


class ASTNode:
    def __init__(self):
        self.children = []
        self.id = None
        self.parent = None

    def to_infix(self):
        return self._to_infix(parenthesized=False)

    def _to_infix(self, parenthesized=True):
        raise NotImplementedError

    def to_prefix(self):
        raise NotImplementedError

    def replace_child(self, i, child):
        self.children[i] = child
        child.parent = self

    def insert_child(self, child, pos=None):
        if pos:
            self.children.insert(pos, child)
        else:
            self.children.append(child)

    def remove_child(self, pos):
        self.children.pop(pos)

    def is_root(self):
        return self.parent is None

    def is_leaf(self):
        return len(self.children) == 0

    def replace(self, node):
        if self.is_root():
            raise ValueError("Cannot replace root")
        self.parent.children[self.id] = node
        node.parent = self.parent
        node.id = self.id


class ConstNode(ASTNode):
    def __init__(self, val):
        super().__init__()
        self.val = val
        self.children = []

    def _to_infix(self, parenthesized=True):
        return str(self.val)

    def to_prefix(self):
        return str(self.val)


class VarNode(ASTNode):
    def __init__(self, name):
        super().__init__()
        self.name = name
        self.children = []

    def _to_infix(self, parenthesized=True):
        return self.name

    def to_prefix(self):
        return self.name


class OperatorNode(ASTNode):
    operator_name = None
    priority = None


class BinaryOperatorNode(OperatorNode):
    def __init__(self, lhs, rhs):
        super().__init__()
        self.children = [lhs, rhs]
        lhs.id = 0
        lhs.parent = self
        rhs.id = 1
        rhs.parent = self

    def to_prefix(self):
        return "({} {} {})".format(self.operator_name, self.children[0].to_prefix(), self.children[1].to_prefix())

    def _to_infix(self, parenthesized=True):
        res = "{} {} {}".format(self.children[0]._to_infix(
            parenthesized=self.children[0].priority < self.priority if hasattr(self.children[0], "priority") else True),
                                self.operator_name,
                                self.children[1]._to_infix(
            parenthesized=self.children[1].priority < self.priority if hasattr(self.children[1], "priority") else True))
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


class PlusNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "+"
    priority = 3

    def eval_const(self):
        if all([isinstance(c, ConstNode) for c in self.children]):
            return sum([c.val for c in self.children])
        else:
            return None


class MinusNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "-"
    priority = 3

    def eval_const(self):
        if all([isinstance(c, ConstNode) for c in self.children]):
            return self.children[0] - self.children[1]
        else:
            return None


class MulNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "*"
    priority = 4

    def eval_const(self):
        if all([isinstance(c, ConstNode) for c in self.children]):
            return prod([c.val for c in self.children])
        else:
            return None


class DivNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "/"
    priority = 4

    def eval_const(self):
        if all([isinstance(c, ConstNode) for c in self.children]):
            return self.children[0] / self.children[1]
        else:
            return None


class UnaryOperatorNode(OperatorNode):
    def __init__(self, op):
        super().__init__()
        self.children = [op]
        op.id = 0
        op.parent = self

    def to_prefix(self):
        return "({} {})".format(self.operator_name, self.children[0].to_prefix())

    def _to_infix(self, parenthesized=True):
        res = "{}{}".format(self.operator_name,
                            self.children[0]._to_infix(
            parenthesized=self.children[0].priority < self.priority if hasattr(self.children[0], "priority") else True))
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
        super().__init__()
        self.children = [cond, if_true, if_false]
        cond.id = 0
        cond.parent = self
        if_true.id = 1
        if_true.parent = self
        if_false.id = 2
        if_false.parent = self

    def to_prefix(self):
        raise AssertionError("Unable to convert ternary operator to prefix form")

    def _to_infix(self, parenthesized=True):
        return "({} ? {} : {})".format(self.children[0]._to_infix(parenthesized=False),
                                       self.children[1]._to_infix(parenthesized=False),
                                       self.children[2]._to_infix(parenthesized=False),
                                       )


class FunctionNode(ASTNode):
    fn_name = None
    arity = None

    def __init__(self, *args):
        super().__init__()
        args = list(args)
        if len(args) != self.arity:
            raise ValueError("{}: expected {} arguments, {} provided".format(self.fn_name, self.arity, len(args)))
        self.children = args
        i = 0
        for child in self.children:
            child.id = i
            child.parent = self
            i += 1

    def to_prefix(self):
        return "({} {})".format(self.fn_name, " ".join([x.to_prefix() for x in self.children]))

    def _to_infix(self, parenthesized=True):
        return "{}({})".format(self.fn_name, ", ".join([x._to_infix(parenthesized=False) for x in self.children]))


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
