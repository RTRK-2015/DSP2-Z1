//////////////////////////////////////////////////////////////////////////////
// * File name: main.c
// *
// * Description:  Vezba 1 - Interpolacija i decimacija
// *
// * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
// * Copyright (C) 2011 Spectrum Digital, Incorporated
// *
//////////////////////////////////////////////////////////////////////////////

#include "tistdtypes.h"
#include <cstdio>
#include "ezdsp5535.h"
#include "math.h"
#include "signal.h"
#include "filter_coeff.h"
#include "processing.h"

#define M1 4
#define L1 4

#define L2 3
#define M2 4

#define L3 4
#define M3 3

/*
 *
 *  main( )
 *
 */
void main( void )
{
	/*Int16 dec1[SIGNAL1_LENGTH / M1];
	Int16 dec2[SIGNAL1_LENGTH / M1];*/
	/*Int16 int1[SIGNAL2_LENGTH * L1];
	Int16 int2[SIGNAL2_LENGTH * L1];
	Int16 int3[SIGNAL2_LENGTH * L1];*/
	Int16 res1[SIGNAL2_LENGTH * L2 / M2];
	Int16 res2[SIGNAL2_LENGTH * L3 / M3];
	Int16 res3[SIGNAL2_LENGTH * L2 / M2];
	Int16 res4[SIGNAL2_LENGTH * L3 / M3];
	Int16 z[N_COEFF] = { 0 };

	printf("\n Vezba 1 - Interpolacija i decimacija \n");
	
	/*downsample(signal1, dec1, M1, SIGNAL1_LENGTH);
	decimate(signal1, dec2, M1, SIGNAL1_LENGTH);*/

	/*upsample(signal2, int1, L1, SIGNAL2_LENGTH);
	interpolate(signal2, int2, L1, SIGNAL2_LENGTH);
	upsample_fir(signal2, lp_filter, z, N_COEFF - 1, SIGNAL2_LENGTH, int3, L1);*/

	resample(signal2, res1, L2, M2, SIGNAL2_LENGTH);
	resample(signal2, res2, L3, M3, SIGNAL2_LENGTH);
	resample_fir(signal2, lp_filter, z, N_COEFF - 1, SIGNAL2_LENGTH, res3, L2, M2);
	resample_fir(signal2, lp_filter, z, N_COEFF - 1, SIGNAL2_LENGTH, res4, L3, M3);

	printf( "\n***Program has Terminated***\n" );
	SW_BREAKPOINT;
}

