#include <stdio.h>
#include <unistd.h>
int main( void )  {
    printf( "You'll see this immediately.\n" "Now count to 5 slowly.\n");
    printf( "Then this will appear ..."); // add \n to this line and the buffer will be flushed  immediately
    sleep( 5 );
    printf( "when the buffer is finally flushed.\n" );

    return 0;
}