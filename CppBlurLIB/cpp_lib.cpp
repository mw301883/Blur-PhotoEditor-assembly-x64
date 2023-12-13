#include "pch.h"
#include "cpp_lib.h"

int wavg_calc_cpp(int values[16], int weigths[16]) {

	int wavg = values[0] * weigths[0];
	wavg += values[1] * weigths[1];
	wavg += values[2] * weigths[2];
	wavg += values[3] * weigths[3];
	wavg += values[4] * weigths[4];
	wavg += values[5] * weigths[5];
	wavg += values[6] * weigths[6];
	wavg += values[7] * weigths[7];
	wavg += values[8] * weigths[8];
	wavg = wavg / (weigths[0] + weigths[1] + weigths[2] + weigths[3] + weigths[4]
		+ weigths[5] + weigths[6] + weigths[7] + weigths[8]);

	return wavg;
}