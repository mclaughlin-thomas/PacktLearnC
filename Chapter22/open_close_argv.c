#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>  // for errno

void usage( char* cmd )  {
    fprintf( stderr ,"usage: %s inputFileName outputFileName\n" , cmd );
    exit( EXIT_SUCCESS );
}

int main( int argc, char *argv[] )  {
    FILE* inputFile  = NULL;
    FILE* outputFile = NULL;

    if( argc != 3 ){
        usage( argv[0] );
    }

    if( NULL == ( inputFile = fopen( argv[1] , "r") ) )  {
        fprintf( stderr, "input file: %s: %s\n", argv[1], strerror(errno));
        exit( EXIT_FAILURE );
    }

    if( NULL == ( outputFile = fopen( argv[2] , "w" ) ) )  {
        fprintf( stderr, "output file: %s: %s\n", argv[2], strerror(errno));
        exit( EXIT_FAILURE );
    }
    
    fprintf( stderr , "%s opened for reading.\n" , argv[1] );
    fprintf( stderr , "%s opened for writing.\n" , argv[2] );
    fprintf( stderr , "Do work here.\n" );

    fprintf( stderr , "Closing files.\n" );
    fclose(  inputFile );
    fflush( outputFile );
    fclose( outputFile );
    fprintf( stderr , "Done\n" );
    return 0;
}