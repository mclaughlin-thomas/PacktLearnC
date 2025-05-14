#include <stdio.h>

enum { kBufferSize = 80};

// safe_gets uses fgets() and then removes the trailing '\n'
// from the character buffer/input string.
// Like fgets(), safe_gets() returns either the pointer
// to the string to indicate success or
// NULL to indicate invalid input, EOF, or some other error.  
char* safe_gets(char* buf, int size )  {
    if( fgets( buf , size , stdin ) )  {   // fgets() preserves '\n'
        for( int i = 0; i < size ; i++ )  {  // Find the last '\n'.
            if( '\n' == buf[i] )  {            // Found it.
                buf[i] = '\0';    // Replace '\n' with '\0'
                break;
            }
        }
        return buf;   // fgets() succeeded; return the string pointer.
    }
    else {
        return NULL;  // fgets() failed; return NULL to indicate failure.
    }
}

int main( void )  {
    char stringBuffer[ kBufferSize ] = {0};
    // UNSAFE: Do Not Ever Use gets().
    //         gets() removed in C11 and later, but may still
    //         be available.
    //         Even if available, do not use gets().
    printf( "Enter a string: " );
    gets( stringBuffer );
    // 32:5: error: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Werror=implicit-function-declaration]
    // 32 |     gets( stringBuffer );
    // |     ^~~~
    // |     fgets
    // cc1: all warnings being treated as errors
    puts( "You entered: " );
    puts( stringBuffer );

    // SAFE: Instead, use fgets() & removed trailing '\n'
    //       Or, use safe_gets() given above.
    //       Or, if available, use gets_s() in C11 and later.
    printf( "\nEnter another string: " );
    safe_gets( stringBuffer , kBufferSize );
    puts( "You entered: " );
    puts( stringBuffer );

    return 0;
}