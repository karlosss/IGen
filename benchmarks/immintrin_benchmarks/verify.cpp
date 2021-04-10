#include <iostream>
#include <cstring>

#include "igen_dd_lib.h"

#include "random_range.cpp"
#include "common.h"
#include "test_include.h"

using namespace std;

double* X;
dd_I* Y;

#define OK     "\033[1;32mOK\033[0m"
#define FAIL   "\033[1;31mFAIL\033[0m"

struct fn_t {
    void (*base_fn)(double*);
    void (*fn)(dd_I*);
    string name;
    int ops;
};

vector<fn_t> functions;

void add_function(void (*base_fn)(double*), void (*fn)(dd_I*), const string & name, int ops ) {
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


void verify() {
    // generate random doubles
    X = (double*) aligned_alloc(32, LEN * sizeof(double));
    Y = (dd_I*) aligned_alloc(32, LEN * sizeof(dd_I));
    for(int i = 0; i < LEN; ++i) {
        X[i] = getRandomDouble(10, 20);
        Y[i] = _ia_set_dd(-X[i], 0, X[i], 0);
    }

    register_functions();
    cout << functions.size() << " functions registered." << endl;

    // verify results
    for(int i = 0; i < functions.size(); ++i){

        cout << "Verify " << functions[i].name << "... ";

        double* x = (double*) aligned_alloc(32, LEN * sizeof(double));
        dd_I* y = (dd_I*) aligned_alloc(32, LEN * sizeof(dd_I));

        memcpy(x, X, LEN*sizeof(double));
        memcpy(y, Y, LEN*sizeof(dd_I));

        functions[i].base_fn(x);
        functions[i].fn(y);

        bool fail = false;
        for(int j = 0; j < LEN; ++j){
            u_ddi v = {.v = y[j]};
            double lo = v.lh + v.ll;
            double hi = v.uh + v.ul;
            if(x[j] < lo || x[j] > hi) {
                fail = true;
                break;
            }
        }
        cout << (fail ? FAIL : OK) << endl;
    }
}
