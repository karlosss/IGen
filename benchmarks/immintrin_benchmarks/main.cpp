#include <string>

#include "common.h"

int main(int argc, char** argv){
    // flush denormals to zero
    _mm_setcsr( _mm_getcsr() | (1<<15) | (1<<6));

    init();

//    if(argc == 2 && std::string(argv[1]) == "--no-verify"){
//        benchmark();
//        return 0;
//    }
//
//    if(argc == 2 && std::string(argv[1]) == "--no-benchmark"){
//        verify();
//        return 0;
//    }

    verify();
//    benchmark();
    return 0;
}