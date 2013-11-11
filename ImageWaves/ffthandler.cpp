#include "ffthandler.h"

FftHandler::FftHandler()
{

}

fftw_complex* FftHandler::Run2dFft(char *array, int nRows, int nCols)
{
	fftw_complex *in, *out;
	in = GetComplexArray(array, nRows, nCols);
	out = (fftw_complex*) fftw_malloc(nRows*nCols*sizeof(fftw_complex));
	fftw_plan plan = fftw_plan_dft_2d(nRows, nCols,
			in, out, FFTW_FORWARD, FFTW_ESTIMATE);
}

fftw_complex* FftHandler::GetComplexArray(char *array, int nRows, int nCols)
{
	fftw_complex *resultingArray = 
			(fftw_complex*) fftw_malloc(nRows*nCols*sizeof(fftw_complex));
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			resultingArray[i*nCols+j][0] = (double)array[i*nCols + j];
		}
	}
	return resultingArray;
}
