#pragma once

#ifdef ASSEMBLY_BLUR_LIB_EXPORTS
#define ASSEMBLY_BLUR_LIB_API __declspec(dllexport)
#else
#define ASSEMBLY_BLUR_LIB_API __declspec(dllimport)
#endif

extern "C" ASSEMBLY_BLUR_LIB_API int wavg_calc_asm(int v1, int v2, int v3, int v4, int v5,
	int v6, int v7, int v8, int v9, int w1, int w2, int w3, int w4, int w5, int w6,
	int w7, int w8, int w9);