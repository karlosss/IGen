import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: interval(0, 10, 4),
)

# benchmark(
#     lambda: interval(0, 10, 4, width=0.05),
# )
