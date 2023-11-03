// CppBlurLIB.cpp : Definiuje eksportowane funkcje dla biblioteki DLL.
//

#include "pch.h"
#include "framework.h"
#include "CppBlurLIB.h"


// To jest przykład wyeksportowanej zmiennej
CPPBLURLIB_API int nCppBlurLIB=0;

// To jest przykład wyeksportowanej funkcji.
CPPBLURLIB_API int fnCppBlurLIB(void)
{
    return 0;
}

// To jest konstruktor wyeksportowanej klasy.
CCppBlurLIB::CCppBlurLIB()
{
    return;
}
