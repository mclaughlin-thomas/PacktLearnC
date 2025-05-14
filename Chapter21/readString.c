#include <stdio.h>

enum { kBufferSize = 80 };

int main( void )  {
    char stringBuffer[ kBufferSize ] = {0};
    printf( "Enter a string: " );
    scanf(  "%s" , stringBuffer );
    printf( "Processed string: [%s]\n", stringBuffer );
    return 0;
}

//Try running with these

//


// Anything up to the white space<return>
// Every_thing%before;any:white'space\(will%be read into an
// array.)<return>
//        Skipping initial white space.<return>