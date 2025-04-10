#include <stdio.h>
#include <math.h>

int main( void ) {
  double y = 1 / 0.0;
  printf( " 1 / 0.0 = %f\n" , y );
  
  y = -1/0.0;
  printf( "-1 / 0.0 = %f\n" , y );
  
  y = log( 0 );
  printf( "log( 0 ) = %f\n" , y );
  
  y = sqrt( -1 );
  printf( "Square root of -1 = %f\n" , y );
  return 0;
}

//when compiling must link library, -lm
// gcc infnan.c -lm -o infnan
