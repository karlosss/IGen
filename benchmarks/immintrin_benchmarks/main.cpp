#include "common.h"
#include "register.h"

int main(int argc, char** argv){
    // flush denormals to zero
    _mm_setcsr( _mm_getcsr() | (1<<15) | (1<<6));

    init();
//    verify();
//    if(argc == 2 && string(argv[1]) == "--no-benchmark") return 0;
    benchmark();
    return 0;
}