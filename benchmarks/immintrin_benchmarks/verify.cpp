#include <iostream>
#include <cstring>

#include "common.h"
#include "benchmark_macros.h"

using namespace std;

#define OK     "\033[1;32mOK\033[0m"
#define FAIL   "\033[1;31mFAIL\033[0m"


void verify() {
    ddi_4* in_backup_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4)); // original input
    ddi_4* out_backup_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4)); // original output
    ddi_4* base_out_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4)); // output of base function

    dd_I* in_backup_ddi = (dd_I*) aligned_alloc(32, LEN*sizeof(dd_I));
    dd_I* out_backup_ddi = (dd_I*) aligned_alloc(32, LEN*sizeof(dd_I));
    dd_I* base_out_ddi = (dd_I*) aligned_alloc(32, LEN*sizeof(dd_I));

    int* in_backup_int0_15 = (int*) aligned_alloc(32, LEN*sizeof(int));
    int* out_backup_int0_15 = (int*) aligned_alloc(32, LEN*sizeof(int));
    int* base_out_int0_15 = (int*) aligned_alloc(32, LEN*sizeof(int));

    for(auto it = functions.begin(); it != functions.end(); ++it){
        cout << "Verify " << it->first << endl;

        // make a backup of the data so the functions later can have clean data to operate
        memcpy(in_backup_ddi4, in_ddi4, LEN*sizeof(ddi_4));
        memcpy(out_backup_ddi4, out_ddi4, LEN*sizeof(ddi_4));
        memcpy(in_backup_ddi, in_ddi, LEN*sizeof(dd_I));
        memcpy(out_backup_ddi, out_ddi, LEN*sizeof(dd_I));
        memcpy(in_backup_int0_15, in_int0_15, LEN*sizeof(int));
        memcpy(out_backup_int0_15, out_int0_15, LEN*sizeof(int));

        // run base function
        fesetround(FE_UPWARD);
        it->second[0].verify_fn();
        fesetround(FE_TONEAREST);

        // store the outputs of the base function as those will be used for comparison
        memcpy(base_out_ddi4, out_ddi4, LEN*sizeof(ddi_4));
        memcpy(base_out_ddi, out_ddi, LEN*sizeof(dd_I));
        memcpy(base_out_int0_15, out_int0_15, LEN*sizeof(int));

        // verify optimized functions against base function
        for(int i = 1; i < it->second.size(); ++i){
            // restore from backup so that the function has clean data to operate
            memcpy(in_ddi4, in_backup_ddi4, LEN*sizeof(ddi_4));
            memcpy(out_ddi4, out_backup_ddi4, LEN*sizeof(ddi_4));
            memcpy(in_ddi, in_backup_ddi, LEN*sizeof(dd_I));
            memcpy(out_ddi, out_backup_ddi, LEN*sizeof(dd_I));
            memcpy(in_int0_15, in_backup_int0_15, LEN*sizeof(int));
            memcpy(out_int0_15, out_backup_int0_15, LEN*sizeof(int));

            fesetround(FE_UPWARD);
            it->second[i].verify_fn();
            fesetround(FE_TONEAREST);

            // compare results (base out vs. out)
            bool fail = false;
            for(int j = 0; j < LEN; ++j){
                // ddi4
                for(int k = 0; k < 4; ++k){
                    u_ddi base = {.v = base_out_ddi4[j].f[k]};
                    u_ddi tested = {.v = out_ddi4[j].f[k]};
                    fesetround(FE_UPWARD);
                    double base_lo = base.lh + base.ll;
                    double base_hi = base.uh + base.ul;
                    double tested_lo = tested.lh + tested.ll;
                    double tested_hi = tested.uh + tested.ul;
                    fesetround(FE_TONEAREST);
                    // check if tested interval is included in the base interval
                    if(base_lo != tested_lo || base_hi != tested_hi){
                        fail = true;
                        break;
                    }
                }

                // ddi
                u_ddi base = {.v = base_out_ddi[j]};
                u_ddi tested = {.v = out_ddi[j]};
                fesetround(FE_UPWARD);
                double base_lo = base.lh + base.ll;
                double base_hi = base.uh + base.ul;
                double tested_lo = tested.lh + tested.ll;
                double tested_hi = tested.uh + tested.ul;
                fesetround(FE_TONEAREST);
                // check if tested interval is included in the base interval
                if(base_lo != tested_lo || base_hi != tested_hi){
                    fail = true;
                }

                // int
                if(base_out_int0_15[j] != out_int0_15[j]){
                    fail = true;
                }

                if(fail) break;
            }
            cout << "    " << it->second[i].name << "... ";
            cout << (fail ? FAIL : OK) << endl;
        }
    }

    // restore from backups so that we exit the verification with clean data
    memcpy(in_ddi4, in_backup_ddi4, LEN*sizeof(ddi_4));
    memcpy(out_ddi4, out_backup_ddi4, LEN*sizeof(ddi_4));
    memcpy(in_ddi, in_backup_ddi, LEN*sizeof(dd_I));
    memcpy(out_ddi, out_backup_ddi, LEN*sizeof(dd_I));
    memcpy(in_int0_15, in_backup_int0_15, LEN*sizeof(int));
    memcpy(out_int0_15, out_backup_int0_15, LEN*sizeof(int));

    free(in_backup_ddi4);
    free(out_backup_ddi4);
    free(base_out_ddi4);
    free(in_backup_ddi);
    free(out_backup_ddi);
    free(base_out_ddi);
    free(in_backup_int0_15);
    free(out_backup_int0_15);
    free(base_out_int0_15);
}
