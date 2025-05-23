# Chapter 24
# Working With Multi-File Programs

## Using Header Files for Declarations and Source Files for Definitions

"Whenever the preprocessor sees the #include directive, which must be followed by a filename, it opens that file and reads it into the input stream for compilation at that location, just as if we had typed in the contents of the file ourselves. The filename must be surrounded by either < and > or " and ". Each of these has a special meaning to the preprocessor. The angle brackets tell the preprocessor to look in predefined locations that are relative to the compiler for the given filename, while the quotation marks tell the preprocessor to look in the current directory for the filename."

## Creating Source Files

We can basically put anything and everyting in a source file. We user source files primarily to define functions and we put all the rest, or almost all of the rest in a header file to be included in the source file.

"A source file can be laid out in any number of ways. We can define all the functions before they are called and have the main() function at the very end, or we can use function prototypes at the top of the program and place our function definitions in any order, with the main() function typically appearing immediately after the function prototypes. However, there are perfectly good reasons to keep some things in the source file only; we will explore these reasons fully in Chapter 25, Understanding Scope."

Since we know what a source file with everything in it looks like, let's focus on which things go into a header file and which things do not.

## Thinking About Multiple Source Files

But how should we think about organizing such a complex program into smaller source files and corresponding header files?

The simplest and most effective guideline is to organize each source file around an individual data structure. The header file defines the structure and function prototypes that manipulate that data structure. The source file contains the definitions of the functions that manipulate that data structure. Those functions are specific to that data structure.

-----------
header example

```
// list.h
#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void add(Node** head, int value);
void printList(const Node* head);

#endif
```

-----------------

source example

```
// list.c
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void add(Node** head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(const Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

```

---------------

## Creating Header Files

Header files are used for the following reasons:

- Remove the clutter of function prototypes and the declaration of custom types from the source file. They are moved to a header file to be included in the source file

- For the functions that are called from a different source file, including the header file with those fucntion prototypes provides access to those function. So, simply including the header file makes them available within that program.

- For custom data types that are used in other source files, including the header file with those custom data type declarations make those custom types known within the other source files.

- "Header files help you organize all of the C Standard Library header files, as well as our header files, into a single header file. An example of this would be a source file that includes, say, the stdio.h, stdlib.h, and string.h header files, while another source file includes, say, the stdio.h, math.h, and unistd.h header files. Note that stdio.h is needed in both source files but the other standard headers are only needed in one source file. We could create a single header file – say, commonheaders.h – that includes all of those headers and itself, which is then included in each of the source files."

__There are some very simple rules to follow for the contents of header files. These are driven by the fact that a given header file may be used in more than one file.__

A simple guideline on when to create a header file at all is as follows:

Only create a header file when it will be used in two or more files.

Another way to put this is like so: 

Everything in a .h file should be used in at least two.c files

__So what goes in a header file? Here are examples.__

- function prototypes

- custom type definitions (enums and structs)

- preprocessor directives like #define and #include

- Anything that defines a type but does not allocate memory, like typedef declarations and struct type defined by the typedef and enum types should be in here...extern declarations are references to variables that are defined (allocated) in source files. The variables are not allocated in the header file but the extern declaration makes them visible in the same way that function prorotypes make functions visible. We will check this out in CH25.

Conversely, what does NOT go into a header file? There are two main categories:

1. Anything that allocates memory, such as variable declarations and constant declarations

2. Function definitions.

When we have a constant or variable declared, memory is allcoated. This occurs regardless of whether the variavle is an intrinsic or custom type. If a variable is declared in a header file and that header file is included multiple times, the compiler will try to allocate memory each time using the same name.

This results in the compiler being unable to determine which memory is being referenced by the variable identifier. This is called a name clash.

## Revisiting the Preprocessor

The preprocessor processes the source text of a C program before the program is read by the compiler.

The preprocessor is controlled via single-line preprocessor directives and transforms the source text by interpreting macros embedded in the source text to substitute, add, or remove text based on the given directives. The resulting  preprocessed source text MUST be a valid C program.

preprocessor.png for preprocessor directives

```
The main feature of the preprocessor is that it largely performs textual substitution. Herein lies both its power and its danger. It does textual substitution, but it doesn't understand C syntax or any syntax at all.
```

## The dangers of the Preprocessor

It is not a programming language! It provides programming-like commands, and because of that it can be tempting to use it as a programming language. But, because it is merely a simple macro processor that does not understand syntax, the result of its output can be very misleading, resulting in code that compiles but behaves unpredictably.

The following are some guidelines for using and not using the preprocessor effectively:

• If you can write a function in C, do that instead of using a preprocessor macro.

• You may also want to consider using the inline C declaration. inline provides a suggestion to the compiler to place the body of the function wherever it is called as if a textual substitution were done. This has the advantage of preserving all type checking, as well as eliminating the overheadof a function call. inline becomes useful in very high-performance programming situations.

• Use the preprocessor as a last resort for performance. Eliminating statements or function calls as a means of improving performance is known as central processing unit (CPU) cycle trimming and is highly subject to even minor variations in system configurations. Therefore, strive to pick the best, most efficient algorithm before resorting to cycle trimming

• Prefer const <type> <variable> = <value>; over #define <name> <literal>. In the former case, type information is preserved, whereas in the latter case, there is no type information, so we can never be certain if the macro will be used properly

• Prefer enum { <constantValue> = <value>, ... } over #define <name> <literal>. You may want to declare an array size, say, in a structure, but the compiler won't allow you to use a const int value. Many consider C's array definition a deficiency of the language, so many programmers use #define largely for this reason. Rather than drag the preprocessor into it, you can declare an identifier in an enum block and give it a constant value. We will see how this works in the program at the end of this chapter

• It is tempting to write macro symbols that appear as functions with parameters. Because you don't know how the macro will be used, unexpected and unpredictable behavior may occur.

• Control the use of included headers with simple preprocessor directives.

The preprocessor is essential to controlling the use of header files. When a header file is included in a source file, its content is copied into the source file at compile time. If the header file is also included in another header file, as often happens, it will be included in the source file. This will cause name clashes. The way to prevent this is to use three preprocessor directives in the header file, as follows:

```
#ifndef _SOME_HEADER_FILE_H_
#define _SOME_HEADER_FILE_H_
// contents of header file
...
...
...
#endif
```

The first directive tests whether the _SOME_HEADER_FILE_H_ macro has already been defined. If so, this means that this particular header file would have already been processed at least once, and all of the text of the file is ignored until the last directive, #endif, which should be the last line of the header file.

The first directive tests whether the _SOME_HEADER_FILE_H_ macro has not already been defined. If it has not, the next directive defines it, and the rest of the header file text is inserted into the source file. The next time this file is encountered by the preprocessor, the macro will have been defined and this test will fail, excluding all the text until the #endif directive.

__This method ensures that a header file will always only be included once__. To use this method effectively, the macro symbol for the header file should be unique. Typically, using the filename with all caps and underscores in the manner shown is effective and guarantees uniqueness.

## Debugging With the Preprocessor

So, we have seen two instances of using the preprocessor effectively: for #include files and limiting redundant processing of #include files. The last simple and effective use for the preprocessor is as a tool for debugging large and/or complex programs of multiple files.

Using conditional directives, we can easily control what source code is inserted into the source file or excluded from the source file. Consider the following directives:

```
...
#if TEST_CODE
   // code to be inserted and executed in final program
   fprintf( stderr, "This is a test. We got here.\n" );
#endif
...
```

If the TEST_CODE macros is defined and has a nonzero value, the statements within the #if and #endif directives will be included in the source file. For this code to be included, we can dfine the macro in a couple of ways. First it can be defined in the main source file with the following code:

```
#define TEST_CODE 1
```

This statement defines that the TEST_CODE macros must have a value of 1 (nonzero implies true).  If we wanted to turn off the test code but keep the macros in place we would change that line to this:

```
#define TEST_CODE 0
```

Alternate way!!!

Instead we can define the macro on the command line for compilation as follows:

cc myProgram.c -o myProgram -Wall -Werror -std=c11 __-D TEST_CODE=1__

-D option defines the TEST_CODE macro and gives it the value 1.

When I have to test a wide variety of features in a very complex program, I use a set of macros, such as the following:

```
#if defined DEBUG
 #define DEBUG_LOG 1
 #define DEBUG_LOG_ALIGN 0
 #define DEBUG_LOG_SHADOW 0
 #define DEBUG_LOG_WINDOW 0
 #define DEBUG_LOG_KEEPONTOP 1
 #define DEBUG_LOG_TIME 1
#else
 #define DEBUG_LOG 0
 #define DEBUG_LOG_ALIGN 0
 #define DEBUG_LOG_SHADOW 0
 #define DEBUG_LOG_WINDOW 0
 #define DEBUG_LOG_KEEPONTOP 1
 #define DEBUG_LOG_TIME 0
#endif
```

This set of macro definitions existed alone in a header file. Then, I could turn a whole set of debugging macro symbols on or off via the command line by simply adding -D DEBUG to the command-line options. Sprinkled throughout this program, which consisted of over 10,000 lines of code in approximately 230 files, were #if defined DEBUG_LOG_xxx ... #endif directives with a few lines of code to provide logging as the program was executing. I've found this rudimentary method, sometimes called __caveman debugging__, to be effective. 

A similar mechanism can be used to insert one set of statements or another set of statements into the source file. Consider the following directives:

```
...
#if defined TEST_PROGRAM
   // code used to test parts of program
   ...
#else
   // code used for the final version of the program (non-testing)
   ..
#endif
```

Any further discussion of debugging is beyond the scope of this book.

We now have four effective yet simple uses for the preprocessor, as follows:

• To include header files

• To limit redundant processing of header files

• For caveman debugging

• To exclude a set of statements with #if 0 ... #endif when we are experimenting with our program

## Building a Multi-File Program

In all of our single-file programs, we used the following command line to build them:

```
cc <sourcefile>.c -o <sourcefile> -Wall -Werror -std=c17
```

In the two-file program from Chapter 23, Using File Input and File Output, we used the following command line to build it:

```
cc <sourcefile_1>.c <sourcefile_2>.c -o <programname> <additional options>
```

The compiler command line can take multiple source files and compile them into a single executable. In this program, we have four source files, so to compile this program, we need to put each source file on the command line, as follows:

```
cc card.c hand.c deck.c dealer.c -o dealer <additional options>
```

The order of the list of source files does not matter. The compiler will use the results of the compilation of each file and build them into a single executable named dealer..

```
gcc dealer.c card.c hand.c deck.c -o dealer -Wall -Werror -std=c17


-----------
Example header file and source file

```
// deck.h
#ifndef _DECK_H_
#define _DECK_H_
#include "card.h"
enum {
  kCardsInDeck = 52
};
typedef struct  {
  Card  ordered[  kCardsInDeck ];
Creating a multi-file program 581
  Card* shuffled[ kCardsInDeck ];
  int   numDealt;
  bool  bIsShuffled;
} Deck;
void  InitializeDeck(   Deck* pDeck );
void  ShuffleDeck(      Deck* pDeck );
Card* DealCardFromDeck( Deck* pDeck );
void  PrintDeck(        Deck* pDeck );
#endif 
```

Example source file

```
// deck.c
#include "dealer.h"
bool bRandomize = true;  // default if not set elsewhere

void InitializeDeck(   Deck* pDeck )  {
  // function body here
  ...
 }
void ShuffleDeck(      Deck* pDeck )  {
 // function body here
  ...
}
Card* DealCardFromDeck( Deck* pDeck )  {
 // function body here
  ...
}
void PrintDeck(        Deck* pDeck )  {
 // function body here
  ...
}
```