#include "pch.h"
#include "cpp_lib.h"

int wavg_calc_cpp(int v1, int v2, int v3, int v4, int v5,
	int v6, int v7, int v8, int v9, int w1, int w2, int w3, int w4, int w5, int w6,
	int w7, int w8, int w9) {

	int wavg = v1 * w1;
	wavg += v2 * w2;
	wavg += v3 * w3;
	wavg += v4 * w4;
	wavg += v5 * w5;
	wavg += v6 * w6;
	wavg += v7 * w7;
	wavg += v8 * w8;
	wavg += v9 * w9;
	wavg = wavg / (w1 + w2 + w3 + w4 + w5 + w6 + w7 + w8 + w9);

	return wavg;
}