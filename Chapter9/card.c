#include <stdio.h>
#include <stdbool.h>

enum Suit  {
    eClub    = 1,
    eDiamond,
    eHeart,
    eSpade
};

enum Face  {
    eOne   = 1,
    eTwo,
    eThree,
    eFour,
    eFive,
    eSix,
    eSeven,
    eEight,
    eNine,
    eTen,
    eJack,
    eQueen,
    eKing,
    eAce
};

struct Card {
    enum Suit suit;
    int       suitValue;
    enum Face face;
    int       faceValue;
    bool      isWild;
};

int main ( void )  {
    struct Card card;
    printf( " enum Suit is %lu bytes\n" , sizeof( enum Suit ) );
    printf( " enum Face is %lu bytes\n" , sizeof( enum Face ) );
    printf( " int is %lu bytes\n" , sizeof( int ) );
    printf( " bool is %lu bytes\n" , sizeof( bool ) );
    printf( "struct Card is %lu bytes\n" , sizeof( struct Card ) );
    printf( " card is %lu bytes\n" , sizeof( card ) );
    return 0;
}

// The card variable is the overall name for a variable of five components—suit, suitValue, face,
// faceValue, and isWild. When the card variable is declared, enough space must be allocated
// to hold all the values of the components within it. If we assume that the enum types are 4 bytes and
// bool is 1 byte, then the result of sizeof( card ) would be 17. So, each time a variable of the
// struct Card type is declared, 17 bytes would be allocated for it

// THis is not the case though. We actually have 20 bytes. This is because od something behind the scenes called structure allignement, where
// a given structure is paeed with enough space so that it contains an even multiple of its largest component. In the case of struct Card, it
// is padded with 3 bytes so that it will occupy an even multiple of 4, with 4 bytes being the largest size of any component in struct Card.
