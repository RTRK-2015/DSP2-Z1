
#include "tistdtypes.h"
#include "math.h"
#include "fir.h"

Int16 fir_basic(Int16* input, Int16 *coeffs, Int16 *z, unsigned short order, unsigned short nx, Int16* output)
{
	int i, ii;
    Int32 accum;
    
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
		accum = 0;
		for (ii = 0; ii < order; ii++)
		{
			accum += ((Int32)coeffs[ii] * z[ii]);
		}

		output[i] = accum >> 15;
	}
    return 0;
}

Int16 fir_circular(Int16* input, Int16 *coeffs, Int16 *z, unsigned short order, unsigned short *p_state, unsigned short nx, Int16 *output)
{
    int i, ii;
    unsigned short state;
    Int32 accum;

    state = *p_state;               /* copy the filter's state to a local */

    for(i = 0; i < nx; i++)
    {
		/* store input at the beginning of the delay line */
		z[state] = input[i];
		if (++state >= order)
		{         /* incr state and check for wrap */
			state = 0;
		}

		/* calc FIR and shift data */
		accum = 0;
		for (ii = order - 1; ii >= 0; ii--)
		{
			accum += ((Int32)coeffs[ii] * z[state]);
			if (++state >= order) /* incr state and check for wrap */
			{
				state = 0;
			}
		}
		output[i] = accum >> 15;
    }

    *p_state = state;               /* return new state to caller */
    return 0;
}
