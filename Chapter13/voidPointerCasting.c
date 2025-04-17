#include <stdio.h>


int main( void)  {
    int height = 10;
    void* aPtr = NULL;
    aPtr = &height; // get address of height and store in void pointer
    int h = *(int*)aPtr; // cast void* to int*, then dereference to get the int value
    printf( "             height = [%d]\n" , height );
    printf( "        *(int*)aPtr = [%d]\n" , *(int*)aPtr );
    printf( "                  h = [%d]\n" , h );
    printf( "   sizeof( height ) = %lu\n" , sizeof( height ) );
    printf( "sizeof(*(int*)aPtr) = %lu\n" , sizeof( *(int*)aPtr ) );
    *(int*)aPtr = 3; // cast void* to int* and assign 3 to the memory location it points to
    printf( "        *(int*)aPtr = [%d]\n" , *(int*)aPtr );
    printf( "             height = [%d]\n\n" , height );
    return 0;
  }

//      height = [10]
// *(int*)aPtr = [10]
//           h = [10]
// sizeof( height ) = 4
// sizeof(*(int*)aPtr) = 4
// *(int*)aPtr = [3]
//      height = [3]
