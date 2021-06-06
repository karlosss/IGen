#!/bin/bash

> out.txt

for i in $(seq 26 1 38)
do
    for j in $(seq $i 1 38)
    do
        sed "$i s|//||; $j s|//||" register.h > register.h.replaced
	scp register.h.replaced kjilek@cascade.inf.ethz.ch:~/igen/benchmarks/immintrin_benchmarks/register.h
	echo =======================================
	echo ======================================= >> out.txt
	echo $i $j
	echo $i $j >> out.txt
	ssh kjilek@cascade.inf.ethz.ch 'cd ~/igen/benchmarks/immintrin_benchmarks && make &>/dev/null && ./immintrin' >> out.txt
    done
done
