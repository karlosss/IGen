#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"

using namespace std;

void mm256_storeu_pd_base(double* in, double* out){
    __m256d a0 = _mm256_loadu_pd(in);
    __m256d a1 = _mm256_loadu_pd(in+4);
    __m256d a2 = _mm256_loadu_pd(in+8);
    __m256d a3 = _mm256_loadu_pd(in+12);

    _mm256_storeu_pd(out+100, a0);
    _mm256_storeu_pd(out+104, a1);
    _mm256_storeu_pd(out+108, a2);
    _mm256_storeu_pd(out+112, a3);
}

void mm256_storeu_pd_verify(dd_I* in, dd_I* out){
    ddi_4 a0 = _igen_dd_mm256_loadu_pd(in);
    ddi_4 a1 = _igen_dd_mm256_loadu_pd(in+4);
    ddi_4 a2 = _igen_dd_mm256_loadu_pd(in+8);
    ddi_4 a3 = _igen_dd_mm256_loadu_pd(in+12);

    _igen_dd_mm256_storeu_pd(out+100, a0);
    _igen_dd_mm256_storeu_pd(out+104, a1);
    _igen_dd_mm256_storeu_pd(out+108, a2);
    _igen_dd_mm256_storeu_pd(out+112, a3);
}


void mm256_storeu_pd_benchmark(dd_I* in, dd_I* out){

}
