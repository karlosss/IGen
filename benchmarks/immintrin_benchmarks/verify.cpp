#include <iostream>
#include <cstring>

#include "igen_dd_lib.h"
#include "common.h"

using namespace std;

#define OK     "\033[1;32mOK\033[0m"
#define FAIL   "\033[1;31mFAIL\033[0m"


void verify() {
    for(int i = 0; i < functions.size(); ++i){

        cout << "Verify " << functions[i].name << "... ";

        double* x = (double*) aligned_alloc(32, LEN * sizeof(double));
        dd_I* y = (dd_I*) aligned_alloc(32, LEN * sizeof(dd_I));

        memcpy(x, X, LEN*sizeof(double));
        memcpy(y, Y, LEN*sizeof(dd_I));

        functions[i].base_fn(X, x);
        functions[i].fn(Y, y);

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
        free(x);
        free(y);
    }
}
