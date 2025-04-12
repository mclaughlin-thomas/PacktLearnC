#include <stdio.h>

enum suit {
    eSpade = 4,
    eHeart = 3,
    eDiamond = 2,
    eClub = 1
};

int main( void ) {
    enum suit s = eClub;
    printf( "%d\n" , s);
    return 0;
}
