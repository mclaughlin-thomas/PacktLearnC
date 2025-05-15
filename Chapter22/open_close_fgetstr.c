#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>  // for errno

char* safe_gets(char* buf, int size )  {
    if( fgets( buf , size , stdin ) )  {
        for( int i = 0; i < size ; i++ )  {
            if( '\n' == buf[i] )  {
                buf[i] = '\0';
                break;
            }
        }
        return buf;
    }
    else {
        return NULL;
    }
}
int main( void ) {
    FILE* inputFile;
    FILE* outputFile;
    printf( "FILENAME_MAX on this system is %d bytes\n" ,FILENAME_MAX );  // FILENAME_MAX is defined in stdio.h
    char* inputFilename  = (char*)calloc( FILENAME_MAX , 1 );
    char* outputFilename = (char*)calloc( FILENAME_MAX , 1 );
    fprintf( stdout , "Enter name of input file: " );
    safe_gets( inputFilename , FILENAME_MAX );
    inputFile = fopen( inputFilename , "r" );

    if( NULL == inputFile ) {
        fprintf( stderr, "input file: %s: %s\n", inputFilename , strerror( errno ) );
        exit( EXIT_FAILURE );
    }
    
    fprintf( stdout , "Enter name of output file: " );
    safe_gets( outputFilename , FILENAME_MAX );
    outputFile = fopen( outputFilename , "w" );

    if( NULL == outputFile ) {
        fprintf( stderr, "input file: %s: %s\n", outputFilename , strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    fprintf( stdout,"\"%s\" opened for reading.\n",inputFilename  );
    fprintf( stdout,"\"%s\" opened for writing.\n",outputFilename );
    fprintf( stderr , "Do work here.\n" );

    fprintf( stderr , "Closing files.\n" );
    fclose(  inputFile );
    fflush( outputFile );
    fclose( outputFile );
    free( inputFilename );
    free( outputFilename );
    fprintf( stderr , "Done.\n" );

    return 0;
}