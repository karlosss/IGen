#include <iostream>

#include "random_range.cpp"
#include "common.h"
#include "test_include.h"

using namespace std;


double* X;
dd_I* Y;
std::vector<fn_t> functions;


void add_function(void (*base_fn)(double*, double*), void (*fn)(dd_I*, dd_I*), const string & name, int ops ) {
    fn_t f;
    f.base_fn = base_fn;
    f.fn = fn;
    f.name = name;
    f.ops = ops;
    functions.push_back(f);
}


void register_functions() {
    add_function(mm256_blend_pd_base , mm256_blend_pd, "mm256_blend_pd" , 200);
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