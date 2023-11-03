// AssemblyBlurLIB.cpp : Definiuje eksportowane funkcje dla biblioteki DLL.
//

#include "pch.h"
#include "framework.h"
#include "AssemblyBlurLIB.h"


// To jest przykład wyeksportowanej zmiennej
ASSEMBLYBLURLIB_API int nAssemblyBlurLIB=0;

// To jest przykład wyeksportowanej funkcji.
ASSEMBLYBLURLIB_API int fnAssemblyBlurLIB(void)
{
    return 0;
}

// To jest konstruktor wyeksportowanej klasy.
CAssemblyBlurLIB::CAssemblyBlurLIB()
{
    return;
}
