#include <stdio.h>
#include <stdlib.h>

void Usage( char* exec )  {
    printf( " usage: %s <argument1> <argument2> ...<argumentN>\n" ,exec );
    exit(1);
}

int main(int argc, char *argv[] )  {
    if( 1 == argc )  {
        printf( " No arguments given on command line.\n\n" );
        Usage( argv[0] );
        return 0;    
    }

    printf( "argument count = [%d]\n" , argc );
    printf( "executable = [%s]\n" , argv[0] );
    
    for( int i = 1 ; i < argc ; i++ )  {
        printf( "argument %d = [%s]\n" , i , argv[i] );
    }

    putchar( '\n' );
    return 0;
}
