#pragma once

static inline ddi_4 _igen_dd_permute_no_unused_vals_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 _b;
    _b.f[0] = _mm256_permute4x64_pd(b.f[0], 0b01001110);
    _b.f[1] = _mm256_permute4x64_pd(b.f[1], 0b01001110);
    _b.f[2] = _mm256_permute4x64_pd(b.f[2], 0b01001110);
    _b.f[3] = _mm256_permute4x64_pd(b.f[3], 0b01001110);

    return _igen_dd_no_unused_vals_mm256_add_pd(a, _b);
}
