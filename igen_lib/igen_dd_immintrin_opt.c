#include "igen_dd_immintrin_opt.h"

static ddi_4 _igen_dd_op_mm256_blend_pd(ddi_4 a, ddi_4 b, int imm8);

ddi_4 blend(ddi_4 a, ddi_4 b, int imm8) {
    return _igen_dd_op_mm256_blend_pd(a, b, imm8);
}
