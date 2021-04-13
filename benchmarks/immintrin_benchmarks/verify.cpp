#include <iostream>
#include <cstring>

#include "igen_dd_lib.h"
#include "common.h"

using namespace std;

#define OK     "\033[1;32mOK\033[0m"
#define FAIL   "\033[1;31mFAIL\033[0m"


void verify() {
    dd_I in_backup[LEN]; // original input
    dd_I out_backup[LEN]; // original output
    dd_I base_out[LEN]; // output of base function

    for(auto it = functions.begin(); it != functions.end(); ++it){
        cout << "Verify " << it->first << endl;

        memcpy(in_backup, in, LEN*sizeof(dd_I));
        memcpy(out_backup, out, LEN*sizeof(dd_I));

        // run base function
        fesetround(FE_UPWARD);
        it->second[0].verify_fn();
        fesetround(FE_TONEAREST);

        memcpy(base_out, out, LEN*sizeof(dd_I));

        // verify optimized functions against base function
        for(int i = 1; i < it->second.size(); ++i){
            memcpy(in, in_backup, LEN*sizeof(dd_I));
            memcpy(out, out_backup, LEN*sizeof(dd_I));

            fesetround(FE_UPWARD);
            it->second[i].verify_fn();
            fesetround(FE_TONEAREST);

            // compare results
            bool fail = false;
            for(int j = 0; j < LEN; ++j){
                u_ddi base = {.v = base_out[j]};
                u_ddi tested = {.v = out[j]};
                fesetround(FE_UPWARD);
                double base_lo = base.lh + base.ll;
                double base_hi = base.uh + base.ul;
                double tested_lo = tested.lh + tested.ll;
                double tested_hi = tested.uh + tested.ul;
                fesetround(FE_TONEAREST);
                // check if tested interval is included in the base interval
                if(base_lo > tested_lo || base_hi < tested_hi){
                    fail = true;
                    break;
                }
            }
            cout << "    " << it->second[i].name << "... ";
            cout << (fail ? FAIL : OK) << endl;
        }
    }

    memcpy(in, in_backup, LEN*sizeof(dd_I));
    memcpy(out, out_backup, LEN*sizeof(dd_I));
}
