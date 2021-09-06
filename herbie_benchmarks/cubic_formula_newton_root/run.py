import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: interval(0, 50, 4),
    lambda: interval(0, 50, 4),
    lambda: interval(0, 50, 4),
    lambda: interval(0, 50, 4),
)
