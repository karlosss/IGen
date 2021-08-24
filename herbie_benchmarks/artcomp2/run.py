import sys
sys.path.append("..")
from common import *

# benchmark(
#     lambda: random_sci_interval(1, 10, 5, -15, -15),
#     lambda: random_sci_interval(1, 10, 5, -10, -10),
# )

# benchmark(
#     lambda: random_sci_interval(1, 10, 5, -15, -15, perc_width=0.05),
#     lambda: random_sci_interval(1, 10, 5, -10, -10, perc_width=0.05),
# )

# benchmark(
#     lambda: random_interval(3, 3, 0),
#     lambda: random_interval(10, 20, 5),
# )

benchmark(
    lambda: random_interval(3, 3, 0, perc_width=0.05),
    lambda: random_interval(10, 20, 5, perc_width=0.05),
)
