import sys
sys.path.append("..")
from common import *

# benchmark(
#     lambda: random_interval(0, 0, 5, exclude_zero=True),
#     lambda: random_sci_interval(1, 10, 5, 145, 150),
#     lambda: random_sci_interval(1, 10, 5, 165, 170),
# )

# benchmark(
#     lambda: random_sci_interval(1, 10, 5, 50, 60),
#     lambda: random_sci_interval(1, 10, 5, 50, 60),
#     lambda: random_sci_interval(-10, -1, 5, 50, 60),
# )

benchmark(
    lambda: random_interval(0, 0, 5, exclude_zero=True, perc_width=0.05),
    lambda: random_sci_interval(1, 10, 5, 145, 150, perc_width=0.05),
    lambda: random_sci_interval(1, 10, 5, 165, 170, perc_width=0.05),
)

# benchmark(
#     lambda: random_sci_interval(1, 10, 5, 50, 60, perc_width=0.05),
#     lambda: random_sci_interval(1, 10, 5, 50, 60, perc_width=0.05),
#     lambda: random_sci_interval(-10, -1, 5, 50, 60, perc_width=0.05),
# )
