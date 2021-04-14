#include "common.h"

int main(int argc, char** argv){
    // flush denormals to zero
    _mm_setcsr( _mm_getcsr() | (1<<15) | (1<<6));

    init();
    verify();
    benchmark();
    return 0;
}