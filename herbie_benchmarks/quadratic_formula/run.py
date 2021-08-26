import sys
sys.path.append("..")
from common import *

# benchmark(
#     lambda: interval(0, 20, 4, neg=1),
#     lambda: interval(0, 20, 4),
#     lambda: interval(0, 20, 4, neg=0),
# )

benchmark(
    lambda: interval(0, 20, 4, neg=1, width=0.05),
    lambda: interval(0, 20, 4, width=0.05),
    lambda: interval(0, 20, 4, neg=0, width=0.05),
)
