/*
 * processing.c
 *
 *  Created on: 29.02.2016.
 *      Author: Dejan Bokan (dejan.bokan@rt-rk.com)
 */

#include "processing.h"
#include "filter_coeff.h"
#include "signal.h"
#include "fir.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void downsample(Int16 *input, Int16 *output, int M, int N)
{
	int i;
	for (i = 0; i < N / M; ++i)
		output[i] = input[M * i];
}

void decimate(Int16 *input, Int16 *output, int M, int N)
{
	Int16 z[N_COEFF] = { 0 };
	Int16 *tmp = (Int16*)malloc(N * sizeof(Int16));

	if (tmp == NULL)
	{
		printf("TMP NULL");
		return;
	}

	fir_basic(input, lp_filter, z, N_COEFF - 1, N, tmp);
	downsample(tmp, output, M, N);

	free(tmp);
}

void upsample(Int16 *input, Int16 *output, int L, int N)
{
	int i;
	for (i = 0; i < N; ++i)
	{
		int j;

		output[L * i] = input[i];

		for (j = 1; j < L; ++j)
			output[L * i + j] = 0;
	}
}

void interpolate(Int16 *input, Int16 *output, int L, int N)
{
	Int16 z[N_COEFF] = { 0 };
	Int16 *tmp = (Int16*)malloc(N * L * sizeof(Int16));

	if (tmp == NULL)
	{
		printf("TMP NULL");
		return;
	}

	upsample(input, tmp, L, N);
	fir_basic(tmp, lp_filter, z, N_COEFF - 1, L * N, output);

	free(tmp);
}

void resample(Int16 *input, Int16 *output, int L, int M, int N)
{
	Int16 z[N_COEFF] = { 0 };
	Int16 *tmp1 = (Int16*)malloc(L * N * sizeof(Int16));
	Int16 *tmp2 = (Int16*)malloc(L * N * sizeof(Int16));

	if (tmp1 == NULL)
	{
		printf("TMP1 NULL");
		return;
	}
	if (tmp2 == NULL)
	{
		printf("TMP2 NULL");
		return;
	}

	upsample(input, tmp1, L, N);
	fir_basic(tmp1, lp_filter, z, N_COEFF - 1, L * N, tmp2);
	downsample(tmp2, output, M, L * N);

	free(tmp1);
	free(tmp2);
}


Int16 upsample_fir(Int16* input, Int16 *coeffs, Int16 *z, unsigned short order, unsigned short nx, Int16* output, int L)
{
	int i, ii, iz, j;

    for(i = 0; i < nx; i++)
	{
		/* shift delay line */
		for (ii = order - 2; ii >= 0; ii--)
		{
			z[ii + 1] = z[ii];
		}

		/* store input at the beginning of the delay line */
		z[0] = input[i];


		/* calc FIR */

		for (j = 0; j < L; ++j)
		{
			Int32 accum = 0;

			for (ii = j, iz = 0; ii < order; ii += L, iz++)
			{
				accum += ((Int32)coeffs[ii] * z[iz]);
			}

			output[L * i + j] = accum >> 15;
		}
	}
    return 0;
}


Int16 resample_fir(
	Int16* input,
	Int16 *coeffs,
	Int16 *z,
	unsigned short order,
	unsigned short nx,
	Int16* output,
	int L,
	int M)
{
	int i, ii, iz, j = L, io = 0;

    for(i = 0, io = 0; i < nx; i++)
	{
		/* shift delay line */
		for (ii = order - 2; ii >= 0; ii--)
		{
			z[ii + 1] = z[ii];
		}

		/* store input at the beginning of the delay line */
		z[0] = input[i];

		for (j = j - L; j < L; j += M)
		{
			Int32 accum = 0;

			for (ii = j, iz = 0; ii < order; ii += L, iz++)
			{
				accum += ((Int32)coeffs[ii] * z[iz]);
			}

			output[io++] = accum >> 15;
	}
    return 0;
}
