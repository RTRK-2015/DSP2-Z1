#ifndef VEZBA6D_FIR_H_
#define VEZBA6D_FIR_H_


Int16 fir_basic(Int16* input, Int16* coeffs, Int16 *z, unsigned short order, unsigned short nx, Int16* output);
Int16 fir_circular(Int16* input, Int16 *coeffs, Int16 *z, unsigned short order, unsigned short *p_state, unsigned short nx, Int16 *output);

#endif /*VEZBA6D_FIR_H_*/
