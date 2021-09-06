import sys
sys.path.append("..")
from common import *

benchmark(
    lambda: intervals(
        numbers=[
            (r(-308, 308), r(-308, 308), 0.5),
            (r(-308, 308), r(-308, 308), 0.5),
        ],
        width=0.05
    )
)
