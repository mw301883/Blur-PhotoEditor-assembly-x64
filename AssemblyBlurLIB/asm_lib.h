#pragma once

#ifdef ASSEMBLY_BLUR_LIB_EXPORTS
#define ASSEMBLY_BLUR_LIB_API __declspec(dllexport)
#else
#define ASSEMBLY_BLUR_LIB_API __declspec(dllimport)
#endif

extern "C" ASSEMBLY_BLUR_LIB_API int Calc();