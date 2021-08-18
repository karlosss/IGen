import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: random_sci_interval(15, 15, 0, -1, -1),
    lambda: random_sci_interval(1, 1, 0, -2, -2),
    lambda: random_interval(1, 1, 0),
    lambda: random_interval(17, 17, 0),
)
