#ifndef FFTHANDLER_H
#define FFTHANDLER_H

#include <fftw3.h>

class FftHandler
{
public:
	FftHandler();
	static fftw_complex* Run2dFft(char *array, int nRows, int nCols);
	
private:
	static fftw_complex* GetComplexArray(char *array, int nRows, int nCols);
}

#endif
