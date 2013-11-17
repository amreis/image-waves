#include "ffthandler.h"

FftHandler::FftHandler()
{

}

fftw_complex* FftHandler::Run2dFft(char *array, int nRows, int nCols)
{
    fftw_complex *out;
    double *in;
    delete array;
    in = GetDoubleArray(array, nRows, nCols);
	out = (fftw_complex*) fftw_malloc(nRows*nCols*sizeof(fftw_complex));
    fftw_plan plan = fftw_plan_dft_r2c_2d(nRows, nCols,
            in, out, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
}

double* FftHandler::GetDoubleArray(char *array, int nRows, int nCols)
{
    double *resultingArray =
            (double*) new double[nRows*nCols];
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
            resultingArray[i*nCols+j] = (double)array[i*nCols + j];
		}
	}
	return resultingArray;
}
