import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
    lambda: random_sci_interval(-10, 10, 5, -2, 30),
)
