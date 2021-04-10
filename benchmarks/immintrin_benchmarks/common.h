#pragma once

#include "igen_dd_lib.h"

#define LEN 1024

extern double* X;
extern dd_I* Y;

void verify();
void benchmark();
