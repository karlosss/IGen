#include <iostream>



double benchFun(void (*fn)()) {
    myInt64 start, end;

    for(int i = 0; i < WARMUP_ITER; ++i){
        fn();
    }

    start = start_tsc();
    fn();
    end = stop_tsc(start);

    return end;
}

int main() {
    std::cout << benchFun()
}
