#include <iostream>
#include <unordered_map>

#include "random_range.cpp"
#include "common.h"
#include "test_include.h"

using namespace std;

dd_I in[LEN];
dd_I out[LEN];

unordered_map<string, vector<fn_t>> functions;


void add_function(const string & base_name, const string & name,
                  void (*verify_fn)(), void (*latency_fn)(), void (*gap_fn)(),
                  int ops) {
    fn_t fn;
    fn.verify_fn = verify_fn;
    fn.latency_fn = latency_fn;
    fn.gap_fn = gap_fn;
    fn.ops = ops;

    if(functions.find(base_name) != functions.end()){
        functions[base_name].push_back(fn);
    }
    else{
        functions[base_name] = {fn};
    }
}


void register_functions() {
    // first one is the baseline function that is used to verify against
    add_function("mm256_blend_pd", "base", mm256_blend_pd_fb_verify, nullptr, nullptr, 16);
    add_function("mm256_blend_pd", "opt", mm256_blend_pd_opt_verify, nullptr, nullptr, 16);
}


void init() {
    for (int i = 0; i < LEN; ++i) {
        double dbl = getRandomDouble(10, 20);
        in[i] = _ia_set_epsilon_dd(dbl, 0);
        out[i] = in[i];
    }

    register_functions();
    cout << functions.size() << " functions registered." << endl;
}