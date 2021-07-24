import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: random_interval(3, 3, 0),
    lambda: random_interval(10, 20, 1, exclude_zero=True, perc_width=0.02),
)
