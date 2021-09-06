import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: intervals(
        numbers=[
            (r(-10, 10), r(-10, 10), 0.5),
        ],
        width=0.05
    )
)