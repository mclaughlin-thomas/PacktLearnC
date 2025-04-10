#include <stdio.h>
int main( void ) {
  int numerator   =  33;
  int denominator =   5;
  double result   = 0.0;
    
  result = numerator / denominator;
  printf( "Truncation: %d / %d = %.2g\n" , numerator , denominator , result );
  

  // When the int
  // result is assigned to a double, the fractional part has already been lost. In the second and third
  // division statements, we guarantee that the operation is done on double values by casting either
  // one of them to double. The other value is then implicitly converted to double. The result is a
  // double, so when it is assigned to a double, there is no truncation.

  // So author stated implicit casting can be problematic, then gave example where he used implicit casting
  // in combination with explicit.

  result = (double) numerator / denominator;
  printf( "No truncation: %.2f / %d = %.2f\n" , (double)numerator , denominator , result );
  result = numerator / (double)denominator;
  printf( "%d / %.2f = %.2f\n" ,numerator , (double)denominator , result );

  return 0;
}