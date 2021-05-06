#include "random_range.cpp"
#include "common.h"

using namespace std;

// allocate globals
ddi_4 in_ddi4[32*LEN] __attribute__((aligned(32)));
ddi_4 out_ddi4[32*LEN] __attribute__((aligned(32)));
ddi_2 in_ddi2[32*LEN] __attribute__((aligned(32)));
ddi_2 out_ddi2[32*LEN] __attribute__((aligned(32)));
dd_I in_ddi[32*LEN] __attribute__((aligned(32)));
dd_I out_ddi[32*LEN] __attribute__((aligned(32)));
int in_int0_15[32*LEN] __attribute__((aligned(32)));
int out_int0_15[32*LEN] __attribute__((aligned(32)));
int in_bool[32*LEN] __attribute__((aligned(32)));
int out_bool[32*LEN] __attribute__((aligned(32)));


void init() {
    initRandomSeed();

    // initialize all in- and out- arrays here
    for (int i = 0; i < LEN; ++i) {
        // ddi4
        for(int j = 0; j < 4; ++j){
            in_ddi4[i].f[j] = getRandomDDI();
        }
        out_ddi4[i] = in_ddi4[i];

        // ddi2
        for(int j = 0; j < 2; ++j){
            in_ddi2[i].f[j] = getRandomDDI();
        }
        out_ddi2[i] = in_ddi2[i];

        // ddi
        in_ddi[i] = getRandomDDI();
        out_ddi[i] = in_ddi[i];

        // int0_15
        in_int0_15[i] = getRandomInt(0, 15);
        out_int0_15[i] = in_int0_15[i];

        // bool
        in_bool[i] = getRandomInt(0, 1);
        out_bool[i] = in_bool[i];
    }
}