#include <iostream>

#include "random_range.cpp"
#include "common.h"
#include "test_include.h"

using namespace std;


double* X;
dd_I* Y;
std::vector<fn_t> functions;


void add_function(void (*base_fn)(double*, double*),
                  void (*verify_fn)(dd_I*, dd_I*),
                  void (*benchmark_fn)(dd_I*, dd_I*),
                  const string & name,
                  int ops ) {
    fn_t f;
    f.base_fn = base_fn;
    f.verify_fn = verify_fn;
    f.benchmark_fn = benchmark_fn;
    f.name = name;
    f.ops = ops;
    functions.push_back(f);
}


void register_functions() {
    add_function(mm256_loadu_pd_base , mm256_loadu_pd_verify, mm256_loadu_pd_benchmark, "mm256_loadu_pd" , 16);
    add_function(mm256_load_pd_base , mm256_load_pd_verify, mm256_load_pd_benchmark, "mm256_load_pd" , 16);
    add_function(mm256_storeu_pd_base , mm256_storeu_pd_verify, mm256_storeu_pd_benchmark, "mm256_storeu_pd" , 16);
    add_function(mm256_store_pd_base , mm256_store_pd_verify, mm256_store_pd_benchmark, "mm256_store_pd" , 16);
    add_function(mm256_blend_pd_base , mm256_blend_pd_verify, mm256_blend_pd_benchmark, "mm256_blend_pd" , 16);
}


void init() {
    X = (double *) aligned_alloc(32, LEN * sizeof(double));
    Y = (dd_I *) aligned_alloc(32, LEN * sizeof(dd_I));
    for (int i = 0; i < LEN; ++i) {
        X[i] = getRandomDouble(10, 20);
        Y[i] = _ia_set_dd(-X[i], 0, X[i], 0);
    }

    register_functions();
    cout << functions.size() << " functions registered." << endl;
}