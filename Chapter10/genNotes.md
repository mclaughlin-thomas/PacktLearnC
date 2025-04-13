# Chapter 10
# Creating Custom Data Types with typedef

C lets us define our own types from enumerations (enums) and structures (structs).

C lets us redefine types for the convenience of naming and to provide clarity about how to use the redefined type.

This redefined type becomes a synonym for the original type.

Intrinsic data types are built into the language and are always available.

We use the typedef keyword to create a synonym for the base type.

typedef aType aNewType;

Here aType is an intrisic or custom type and aNewType is now a synonym for aType.

REMEMBER, when enums and structs are defined, no memory is allocated. Likewise the typedef specifiers do not allocate any memory. Memory allocation does not happen until we declare a variable of the new type, regardless of whether it is an enum, struct, or a type that has been defined via typedef.

We may develop ourselves a Standard Set of typeded specifiers that you use frequently and consistently in the programs you write.We will see, later in this chapter, that we can
put them in a file so that they don't have to be repeatedly edited in our programs.


## Simplifying the use of enum types with typedef

The syntax for using typedef in enumerations has three forms.

The first form is a two-part definition where, in the first part, the enumeration is defined, and in the second part, the typedef specifier creates a synonym for it, as follows:

enum name { enumeration1, enumeration2, … , enumerationN };

typedef enum name synonym_name;

The second form defines both the enumeration and synonyms for it in one statement,
as follows:

typedef enum name { enumeration1, enumeration2, … ,

enumerationN } synonym1, synonym2, …;

There is an even shorter form, the third form, where name is omitted and we only have the synonyms for our unnamed or anonymous custom type.

------------

typedef enum { eOne , eTwo , eThree , ... } Face;

typedef enum { eSpade , eHeart , ... }     Suit;

------------

We have created two anonymous enumerations that are now only known as a type by their synonyms – Face and Suit. Regardless of which method we use to create synonyms for enum Face and enum Suit, we can now declare variables using our new synonyms, as follows:

------------

Face face;

Suit suit;

------------

## Simplifying the use of struct types with typedef

The situation is quite different, however, when typedef is thrown into the mix. The syntax for
using typedef in structure definitions has three forms.

The first form is a two-part definition, where first the structure is defined and then the typedef specifier creates a synonym for it, as follows:

struct name { type component1; type component2; … ; type

componentN }; typedef struct name synonym_name;

-- -- -- 

struct Card { Face face; Suit suit; ... };

typedef struct Card Card;

The second form defines both the structure and synonyms for it in one statement, as follows:

typedef struct name {

  type component1;

  type component2;

  … ;

  type componentN;

} synonym1, synonym2, …;

There is an even shorter form where name is omitted and we only have the synonyms for our unnamed or anonymous custom type. The following code snippet shows this:

typedef struct { Face face; Suit suit; ... } Card;

We have created an anonymous struct that is now only known as a type by its synonym, Card. Regardless of which method we use to create synonyms for struct Card, we can now declare variables using our new synonyms, as follows:

Card c1 , c2 , c3, c4, c5;

Of the three ways given to create structs defined via typedef, the last method is the most common. Once the synonyms for a custom type are defined, there is rarely a need to use the struct name custom type; this, however, is not a strict rule, and all three forms can be used depending on what best fits the situation

## Exploring Some More Useful Compiler Options

Up until now, we have been compiling our programs with just the -o output_file option. Our compiler, whether gcc,  clang, or icc has a bewildering array of options.

gcc --help

man gcc

Wow...

Some of these options are for the compiler only; others are passed on to the linker only. They are there for both very specialized system software configurations and for the compiler and linker writers. 

The most important of these options, and the one we will use from now on, is -std=c17 or -std=c11. The -std switch tells the compiler which version of the C standard to use.

Nearly all compilers now support the newest standard, C17, and even the next standard, C23. 

Another very important compiler switch is -Wall. The -W switch allows you to enable an individual warning or all warnings that the compiler encounters. Without that switch, the compiler may only report the most serious warnings. More often, especially when learning, we want to see all of them.

It is also a very good idea to treat all warnings as errors with the -Werror switch. Any warning conditions encountered by the compiler will then prevent further processing (the linker will not be invoked) and no executable output file will be created.

There are many reasons why using  -Wall with -Werror is always the best practice.

Given these considerations, our standard command line for compilation will be as follows:

cc source.c -std=c17 -Wall -Werror -o source

## Using a Header File for Custom Types and the Typedef Specifiers

It is appropriate to explore how collect these custom types into our own header file and include them in our program.

We have seen stuff like these before

#include <stdio.h>

#include <stdbool.h>

These are predefined header files that provide standard library function prototypes - the typedef specifiers, enumerations, and structures - related to those  function prototypes.

When a header file is enclosed in < and > the compiler will look in a predefined list of places for those files. It then opens them and inserts them into the source file just as if they had been copied and pasted into the source file.

Let's crate our own header file, say card.h. Where do we put it? We could find hte location of the predefined header files and save ours there. But, thats not a good idea. Instead we can enclose our header file with " and ", this will tell the compiler to look in the same dir as the source .c file before it starts looking elsewhere for a given file.

As a general convention, each C source file has an associated header file. In that header file are the funciton prototypes and any custom types used within the source file that are specific to it. 

Here are the basic guidelines:

- put anything in a header that does not allocate memory (variables) and does not define functions

- put anything into the source file that allocates memory or defines functions

Running car5.c w card.h with:

gcc card5.c -o card5 -Wall -Werror -std=c17