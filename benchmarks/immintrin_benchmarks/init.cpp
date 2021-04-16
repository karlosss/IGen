#include <iostream>
#include <unordered_map>

#include "random_range.cpp"
#include "common.h"
#include "test_include.h"

using namespace std;

unordered_map<string, vector<fn_t>> functions;


// allocate globals
ddi_4* in_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4));
ddi_4* out_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4));
dd_I* in_ddi = (dd_I*) aligned_alloc(32, LEN*sizeof(dd_I));
dd_I* out_ddi = (dd_I*) aligned_alloc(32, LEN*sizeof(dd_I));
int* in_int0_15 = (int*) aligned_alloc(32, LEN*sizeof(int));
int* out_int0_15 = (int*) aligned_alloc(32, LEN*sizeof(int));


void add_function(const string & base_name, const string & name,
                  void (*verify_fn)(), void (*latency_fn)(), void (*gap_fn)(),
                  int latency_ops, int gap_ops) {
    fn_t fn;
    fn.verify_fn = verify_fn;
    fn.latency_fn = latency_fn;
    fn.gap_fn = gap_fn;
    fn.name = name;
    fn.latency_ops = latency_ops;
    fn.gap_ops = gap_ops;

    if(functions.find(base_name) != functions.end()){
        functions[base_name].push_back(fn);
    }
    else{
        functions[base_name] = {fn};
    }
}


void register_functions() {
    // first one is the baseline function that is used to verify against
//    add_function("mm256_blend_pd", "base", mm256_blend_pd_fb_verify, mm256_blend_pd_fb_lat, mm256_blend_pd_fb_gap, 16, 12);
//    add_function("mm256_blend_pd", "opt", mm256_blend_pd_opt_verify, mm256_blend_pd_opt_lat, mm256_blend_pd_opt_gap, 16, 12);

    add_function("mm256_add_pd", "base", mm256_add_pd_fb_verify, mm256_add_pd_fb_lat, mm256_add_pd_fb_gap, 16, 12);
    add_function("mm256_add_pd", "opt", mm256_add_pd_opt_verify, mm256_add_pd_opt_lat, mm256_add_pd_opt_gap, 16, 12);
}


void init() {
    // initialize all in- and out- arrays here
    for (int i = 0; i < LEN; ++i) {
        // ddi4
        for(int j = 0; j < 4; ++j){
            in_ddi4[i].f[j] = _ia_set_epsilon_dd(getRandomDouble(10, 20), 0);
        }
        out_ddi4[i] = in_ddi4[i];

        // ddi
        in_ddi[i] = _ia_set_epsilon_dd(getRandomDouble(10, 20), 0);
        out_ddi[i] = in_ddi[i];

        // int0_15
        in_int0_15[i] = getRandomInt(0, 15);
        out_int0_15[i] = in_int0_15[i];
    }

    register_functions();
    cout << functions.size() << " functions registered." << endl;
}