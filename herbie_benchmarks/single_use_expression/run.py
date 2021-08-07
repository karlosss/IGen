import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: random_sci_interval(-10, 10, 5, -30, 30),
)
