#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum {
  kListMax   = 100,
  kStringMax =  80
};

typedef char string [ kStringMax ];

void addName(    string* names , string newOne , int* listSize );
void printNames( string* names , int listSize );

void removeNewline( string s ) {
    int len = strlen( s );
    s[ len-1 ] = '\0';
}

// 1. Use fgets() for user input,
// 2. remove trailing '\n', and
// 3. return length of string or 0 if failure or empty.
int getName(char* buf, int size )  {
    if( fgets( buf , size , stdin ) )  {     /* 1 */
        int len;
        for( len = 0; len < size ; len++ )  {  /* 2 */
            if( '\n' == buf[len] )  {
                buf[len] = '\0';
                break;
            }
            if( '\0' == buf[len] ){
                break;
            }
        }
        return len;                            /* 3 */
    }
    else {
        return 0;
    }
}
int main( void )  {
    string newName;
    string nameList[ kListMax ];
    int    numNames = 0;

    while( printf( "Name: %d: ", numNames+1 ), fgets( newName , kStringMax , stdin ), removeNewline( newName ) , strlen( newName ) > 0 ) {
        addName( nameList , newName , &numNames );
    }
    
    printNames( nameList , numNames );
    return 0;
}

void printNames( string *names , int numEntries )  {
    printf("\nNumber of Entries: %d\n\n" , numEntries );

    for( int i = 0 ; i < numEntries ; i++ )  {
        fputs( names[i] , stdout );
        fputc( '\n' , stdout );
    }
}

void addName( string* names , string newName , int* pNumEntries)  {
    if( *pNumEntries >= kListMax )  {  // List is full.
        puts( "List is full!" );
        return;
    }
    else {
        int  k     = 0;
        bool found = false;

        while( !found && k < *pNumEntries ){
            found = (strcmp( newName, names[ k++ ] ) < 0);
        }
        if( found )  {
            k-- ;  // newName goes before k.
            for( int j = *pNumEntries ; j > k ; j-- )  {
                strcpy( names[ j ] , names[ j-1 ] );
            }
        }
        strcpy( names[ k ] , newName ); // Insert newName at k-th position.
        (*pNumEntries)++;
    }
    return;
}
