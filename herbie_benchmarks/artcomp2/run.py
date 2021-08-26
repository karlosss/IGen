import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: interval(0, 5, 4),
    lambda: interval(50, 5, 4),
)
