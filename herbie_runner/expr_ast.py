from decimal_arith import add, sub, mul, div, sqrt, cbrt, pow, InexactResult


class AST:
    def __init__(self, root):
        self.root = root

    def to_infix(self):
        return self.root.to_infix(par=False)

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

    def to_infix(self, par=True):
        raise NotImplementedError

    def to_prefix(self):
        raise NotImplementedError

    def is_root(self):
        return self.parent is None

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

    def to_infix(self, par=True):
        return str(self.val)

    def to_prefix(self):
        return str(self.val)


class VarNode(ASTNode):
    def __init__(self, name):
        super().__init__()
        self.name = name
        self.children = []

    def to_infix(self, par=True):
        return self.name

    def to_prefix(self):
        return self.name


class OperatorNode(ASTNode):
    operator_name = None


class BinaryOperatorNode(OperatorNode):
    priority = None
    associative = None

    def __init__(self, lhs, rhs):
        super().__init__()
        self.children = [lhs, rhs]
        lhs.id = 0
        lhs.parent = self
        rhs.id = 1
        rhs.parent = self

    def to_prefix(self):
        return "({} {} {})".format(self.operator_name, self.children[0].to_prefix(), self.children[1].to_prefix())

    def to_infix(self, par=True):
        lhs_par = self.children[0].priority < self.priority if hasattr(self.children[0], "priority") else True
        if hasattr(self.children[1], "priority"):
            rhs_par = self.children[1].priority < self.priority or (
                    self.children[1].priority == self.priority and not self.associative)
        else:
            rhs_par = True

        res = "{} {} {}".format(self.children[0].to_infix(par=lhs_par),
                                self.operator_name,
                                self.children[1].to_infix(par=rhs_par))
        return res if not par else "({})".format(res)


class AndNode(BinaryOperatorNode):
    operator_name = "&&"
    priority = 2
    associative = True

    def to_infix(self, par=True):
        lhs_par = self.children[0].priority < self.priority if hasattr(self.children[0], "priority") else True
        if hasattr(self.children[1], "priority"):
            rhs_par = self.children[1].priority < self.priority or (
                    self.children[1].priority == self.priority and not self.associative)
        else:
            rhs_par = True

        if isinstance(self.children[0], OrNode):
            lhs_par = True
        if isinstance(self.children[1], OrNode):
            rhs_par = True

        res = "{} {} {}".format(self.children[0].to_infix(par=lhs_par),
                                self.operator_name,
                                self.children[1].to_infix(par=rhs_par))
        return res if not par else "({})".format(res)



class OrNode(BinaryOperatorNode):
    operator_name = "||"
    priority = 2
    associative = True

    def to_infix(self, par=True):
        lhs_par = self.children[0].priority < self.priority if hasattr(self.children[0], "priority") else True
        if hasattr(self.children[1], "priority"):
            rhs_par = self.children[1].priority < self.priority or (
                    self.children[1].priority == self.priority and not self.associative)
        else:
            rhs_par = True

        if isinstance(self.children[0], AndNode):
            lhs_par = True
        if isinstance(self.children[1], AndNode):
            rhs_par = True

        res = "{} {} {}".format(self.children[0].to_infix(par=lhs_par),
                                self.operator_name,
                                self.children[1].to_infix(par=rhs_par))
        return res if not par else "({})".format(res)


class EqNode(BinaryOperatorNode):
    operator_name = "=="
    priority = 3


class NotEqNode(BinaryOperatorNode):
    operator_name = "!="
    priority = 3


class GtNode(BinaryOperatorNode):
    operator_name = ">"
    priority = 3


class LtNode(BinaryOperatorNode):
    operator_name = "<"
    priority = 3


class GtOrEqNode(BinaryOperatorNode):
    operator_name = ">="
    priority = 3


class LtOrEqNode(BinaryOperatorNode):
    operator_name = "<="
    priority = 3


class PlusNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "+"
    priority = 4
    associative = True

    def eval_const(self):
        if isinstance(self.children[0], ConstNode) and isinstance(self.children[1], ConstNode):
            return add(self.children[0].val, self.children[1].val)
        else:
            return None


class MinusNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "-"
    priority = 4
    associative = False

    def eval_const(self):
        if isinstance(self.children[0], ConstNode) and isinstance(self.children[1], ConstNode):
            return sub(self.children[0].val, self.children[1].val)
        else:
            return None


class MulNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "*"
    priority = 5
    associative = True

    def eval_const(self):
        if isinstance(self.children[0], ConstNode) and isinstance(self.children[1], ConstNode):
            return mul(self.children[0].val, self.children[1].val)
        else:
            return None


class DivNode(EvalConstMixin, BinaryOperatorNode):
    operator_name = "/"
    priority = 5
    associative = False

    def eval_const(self):
        if isinstance(self.children[0], ConstNode) and isinstance(self.children[1], ConstNode):
            try:
                return div(self.children[0].val, self.children[1].val)
            except InexactResult:
                return None
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


class NotNode(UnaryOperatorNode):
    operator_name = "!"

    def to_infix(self, par=True):
        return "{}{}".format(self.operator_name, self.children[0].to_infix(par=True))


class UnaryMinusNode(EvalConstMixin, UnaryOperatorNode):
    operator_name = "-"

    def to_infix(self, par=True):
        return "({}{})".format(self.operator_name, self.children[0].to_infix(par=True))

    def eval_const(self):
        if isinstance(self.children[0], ConstNode):
            return ConstNode(-self.children[0].val)
        else:
            return None


class TernaryOperatorNode(OperatorNode):
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

    def to_infix(self, par=True):
        return "({} ? {} : {})".format(self.children[0].to_infix(par=False),
                                       self.children[1].to_infix(par=False),
                                       self.children[2].to_infix(par=False),
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

    def to_infix(self, par=True):
        return "{}({})".format(self.fn_name, ", ".join([x.to_infix(par=False) for x in self.children]))


class PowNode(EvalConstMixin, FunctionNode):
    fn_name = "pow"
    arity = 2

    def eval_const(self):
        if isinstance(self.children[0], ConstNode) and isinstance(self.children[1], ConstNode):
            try:
                return pow(self.children[0].val, self.children[1].val)
            except (InexactResult, AssertionError):
                return None
        else:
            return None


class SqrtNode(EvalConstMixin, FunctionNode):
    fn_name = "sqrt"
    arity = 1

    def eval_const(self):
        if isinstance(self.children[0], ConstNode):
            try:
                return sqrt(self.children[0].val)
            except (InexactResult, AssertionError):
                return None
        else:
            return None


class CbrtNode(EvalConstMixin, FunctionNode):
    fn_name = "cbrt"
    arity = 1

    def eval_const(self):
        if isinstance(self.children[0], ConstNode):
            try:
                return cbrt(self.children[0].val)
            except (InexactResult, AssertionError):
                return None
        else:
            return None


class ExpNode(FunctionNode):
    fn_name = "exp"
    arity = 1


class LnNode(FunctionNode):
    fn_name = "log"
    arity = 1
