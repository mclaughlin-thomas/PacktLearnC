#include <stdio.h>
#include <inttypes.h>
#include <float.h>

// gcc Overflow_Underflow.c -lm -o infnan

// uint16_t is an unsigned 16-bit integer 
// and int16_t is a signed 16-bit integer. Overflow occurs when we add 1 to the largest
// possible 16-bit unsigned integer. Underflow occurs when we subtract 1 from the smallest 16-bit signed
// integer; note how the value became positive.

int main( void )  {
  uint16_t biggest  = UINT16_MAX;
  uint16_t overflow = biggest + 1;
  printf( "Biggest=%d and overflow=%d\n" ,biggest , overflow );
  // The ramifications are imense
  
  int16_t  smallest  = INT16_MIN;
  int16_t  underflow = smallest - 1;
  printf( "Biggest=%d and underflow=%d\n" ,smallest , underflow );
  
  float    fBiggest  = FLT_MAX;
  float    fOverflow = fBiggest * 2;
  printf( "FloatBiggest = %g FloatOverflow (FloatBiggest * 2) =%g\n" , fBiggest , fOverflow );
  
  float    fSmallest  = FLT_MIN;
  float    fUnderflow = fBiggest / fSmallest;
  printf( "FloatSmallest = %g FloatUnderflow (FloatBiggest/FloatSmallest) = %g\n", fSmallest , fUnderflow );
  return 0;
}