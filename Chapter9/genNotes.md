# Chapter 9
# Creating and Using Structures

A structure is a user-defined type.

There may be multiple values in a structure and they may be of the same type or different types.

A structure is a collection of info representing a complex object.

C is not an OOP language.

## Declaring Structures


The syntax for defining a structured type is shown here:

--------------

struct name  {

  type componentName1;

  type componentName2;

  … ;

  type componentNameN;

};

--------------

--------------

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

struct Card card;


our struct Card enumeration no whas enough info to accurately reflect a playing card's suit and face.

Finally, we declare a card variable of struct Card, again using the convention that the custom
data type name has an uppercase name while an instance of that type has a lowercase name.

--------------


// The card variable is the overall name for a variable of five components—suit, suitValue, face,
// faceValue, and isWild. When the card variable is declared, enough space must be allocated
// to hold all the values of the components within it. If we assume that the enum types are 4 bytes and
// bool is 1 byte, then the result of sizeof( card ) would be 17. So, each time a variable of the
// struct Card type is declared, 17 bytes would be allocated for it

// THis is not the case though. We actually have 20 bytes. This is because od something behind the scenes called structure allignement, where
// a given structure is paeed with enough space so that it contains an even multiple of its largest component. In the case of struct Card, it
// is padded with 3 bytes so that it will occupy an even multiple of 4, with 4 bytes being the largest size of any component in struct Card.

The padding within a structure can occur at the end or even in between components. These holes can appear between two consecutive components or after the last component. For the most part we dont have to care about how padding occurs within a structure.

Because of padding thats used to align structures, we cannot compare two structures as whole entitties for comparison. If padding is present in a structure, the contents of that padding may be undefined, depending on how it is initialized. Therefore, even two structures that have identical component values, the values in the padding are highly unlikely to be equal.

## Initializing Structures and Accessing Structure Elements

Once a structure is defined, we can declare variables of that type. The variables of that structure type must be initialized before use. C gives us a number of ways to do this, depending on the needs of the situation.

Given the definition of struct Card, we can initialize a variable of that type in one of three ways, as outlined here:

• At the time of declaration

struct Card c1 = { eHeart , (int) eHeart , eKing, (int) eKing , false };

• After declaration, the entire structure, in toto

struct Card card2 = card1;

• After declaration, component by component

When doing this, it is a good idea to first nullify,
or zero, the entire structure at its definition. Each component is accessed using . notation,
which specifies a given component of the structure. This initialization would look like this:

struct Card card3 = {0}; // Entire structure is
                         // zero-d.
card3.suit = eSpade;
card3.suitValue = (int)eSpade;
card3.face = eAce;
card3.faceValue = (int)eAce;
card3.isWile = true;

## Performing Operations on Structures - Functions

Except for assignment, there are no intrinsic operations for structures. To perform any operation on asingle structure or with two structures, a function must be written to perform the desired operation. 

bool isEqual( struct Card c1 , struct Card c2 )  {

  if( c1.suit != c2.suit ) return false;

  if( c1.face != c2.face ) return false;

  return true;

}


int handValue = card1.faceValue + card2.faceValue;

if( handValue > 21 ) {
  // you lose

} else {
 
  // decide if you want another card

}

## Structures of Structures

A structure can contain components of any type. Even other structures.

How we represent a hand of 5 cards?

struct Hand {

  int cardsDealt;

  struct Card c1;

  struct Card c2;

  struct Card c3;

  struct Card c4;

  struct Card c5;

}

Or we could do this 

struct Hand {
  
  int cardsDealt;

  struct Card c1, c2, c3, c4, c5;

};

Given the structure definition we have seen, each component would be accessed as before, like this: struct Hand h = {0};

Then, we can access each of the card components directly, as follows:

h.c1.suit      = eSpade;

h.c1.suitValue = (int)eSpade;

h.c1.face      = eTwo;

h.c1.faceValue = (int)eTwo;

h.c1.isWild    = false;

h.cardsDealt++;

## Initializing Structures with Functions

struct Hand addCard( struct Hand oldHand , struct Card card)  {
  
  struct Hand newHand = oldHand;
  
  switch( newHand.cardsDealt ){
    
    case 0:

      newHand.c1 = card;  newHand.cardsDealt++;  break;

    case 1:

      newHand.c2 = card;  newHand.cardsDealt++;  break;

    case 2:

      hewHand.c3 = card;  newHand.cardsDealt++;  break;

    case 3:

      hewHand.c4 = card;  newHand.cardsDealt++;  break;

    case 4:

      hewHand.c5 = card;  newHand.cardsDealt++;  break;

    default:

      // Hand is full, what to do now?

      // ERROR --> Ignore new card.

      newHand = oldHand;

      break;

  }

  return newHand;

}



The call to this function would, therefore, look like this:

struct Card aCard;

struct Hand myHand;

...

aCard  = getCard( ... );

myHand = addCard( myHand , aCard );


lastly, a structure CANNOT contain a scomponent of its own type.

This is illegal:

truct Hand {
    
    int cardCount

    struct Hand myHand;   /* NOT VALID */

};


This code is not valid because a structure cannot contain a component that is itself. Now, take a lookat the following code:

struct Hand {
  
  int cardCount;

  struct Hand * myHand;   /* OK */

}

This is valid because the component is a pointer reference to the same type of structure. The type of myHand is struct Hand *, which points to a different variable of the struct Hand type. We will explore this feature in more detail in Chapter 13, Using Pointers.

## Stepping Stone to OOP

At core of all OO languages are objects. Objects are collections of data like C structures, and also operations on that data that are specific to that object, similar to how C functions oprate on a structure.

Sometimes, the internals of the object are completely hidden to the outside program and its components are only available through functions with access to them, called accessors. 

So, data structures and functions that manipulate them become the basis for OOP. Data and operations being used on that data, when combined into a self-contained cohesive unit, are called a class. A data object may be a derivative of a more general classification of objects, much like a square is a derivative of the more general shape classification. In this case, the square class derives certain general properties from the shape class. Such a derivation is called inheritance and is also common to all OOP languages. Methods, also called member functions, are functions that only operate on the data contained within the class, also called member data.

