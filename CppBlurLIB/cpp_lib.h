#pragma once

#ifdef CPP_BLUR_LIB_EXPORTS
#define CPP_BLUR_LIB_API __declspec(dllexport)
#else
#define CPP_BLUR_LIB_API __declspec(dllimport)
#endif

extern "C" CPP_BLUR_LIB_API int wavg_calc_cpp(int values[16], int weigths[16]);