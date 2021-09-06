import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: intervals(
        numbers=[
            (r(0, 0), r(0, 0), 0.5),
            (r(0, 0), r(0, 0), 0.5),
        ],
        conditions=[
            lambda x, y: abs(x) < 2*3.14,
            lambda x, y: abs(y) < 2*3.14,
        ]
    )
)
