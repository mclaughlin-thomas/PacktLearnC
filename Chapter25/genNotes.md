# Chapter 25
# Understanding Scope

The visibility of functions and variables is known as scope. The scope of a variable or function depends upon several factors within a program: its __visibility, its extent, and its linkage__.

As we will see, visibility is but one component of a variable's scope. The other components of scope are extent (or the lifetime of the variable) and linkage (or in which file the variable exists).

## Exploring Visibility

Types of visibility:

Block/Local Scope: Internal variables. Visibility is limited to boundaries of the block where they are declared.

Function Parameter Scope: This scope occurs in function parameters, the function parameters are actually within the block scope of the function body.

File Scope (also called external variables): A variable declared outside any function parameter or block is visible to all other functions and blocks in that file.

Global Scope (also called program scope): Is when an external variable in one file is specially referenced in other files to make it visible to them.

Static Scope: This is when a variable has a block scope with a function but whose extent or lifetime differs from automatic variables.

## Exploring Extent

The scope is also determined by the lifetime or extent of the variable.

Lifetime was explored in CHAPTER 17: MEMORY ALLOCATION AND LIFETIME

The extent of a variable begins when a variable is created and ends when the variable is deallocated or destroyed.

A variable extent is also specified by a storage class, or how it is allocated, used, and subsequently deallocated.

There are 5 storage classes:


• auto: This is the default storage class when no other storage class is specified. When an auto variable is declared within a block, it has an internal variable extent. When an auto variable is declared outside of a block, it has an external variable extent.

• register: This is equivalent to auto but it provides a suggestion to the compiler to put the variable in one of the registers of the central processing unit (CPU). This is often ignored by modern compilers.

• extern: Specifies that the variable has been defined (its memory has been allocated) in another file; in that other file, the variable must be an external variable. Therefore, its extent is the life of the program.

• static: A variable declared with this class has the visibility of the block scope but the extent of an external variable—that is, the life of the program; whenever that block is re-entered, the static variable retains the value it was last assigned. 

• typedef: Formally, this is a storage class, but when used, a new data type is declared and no storage is actually allocated. A typedef scope is similar to a function scope, described later in this chapter

## Exploring Linkage

"In a single source file program, the concept of linkage doesn't really apply since everything is contained within the single source file (even if it has its own header file). However, when we employ multiple source files in a program, a variable's scope is also determined by its linkage. Linkage involves declarations within a single source file—or compilation unit."

"A compilation unit is essentially a single source file and its header file. That source file may be a complete program or it may be just one among several or many source files that make up a final executable. __Each source file is preprocessed and compiled individually in the compilation phase.__ __The result of this is an intermediate object file.__ An object file knows about external functions and variables via header declarations but defers the resolution of their actual addresses until later.

__When all source files have been successfully compiled into object files, the link phase is entered.__ In the link phase, the addresses of functions in other files or libraries are resolved and the addresses of external global variables are resolved. When all unresolved addresses have been successfully resolved (linked together), the object files are then combined into a single executable."

"In the dealer.c program, there were four source files. Each of those four files was an individual compilation unit. At compile time, each of those source files was compiled into four separate object files. Those four object files were then linked together and combined to form a single executable."

## Understanding Variable Scope

"Finally, it is possible to create an unnamed block anywhere with any other block that begins with { and ends with }. C is very consistent in its treatment of blocks, regardless of where they appear."

"Variables declared within a block are created, accessed, and modified within that block. When that block completes, they are deallocated and are no longer accessible; the space they occupied is gone, to be reused by something else in the program."

## Understanding Function Parameter Scope

Function parameter scope is the same as block scope.

The block in this case is the function body

```
double decimalSum( double d1 , double d2 )  { // d1 and d2 important!
    double d3; // IMPORTANT
    d3 = d1 + d2 ;
    return d3;
}
```

d1 and d2 are function parameters and are part of the function body, therefore they have the block scope of the function. d3 also has the block scope of the function. All variabels go out of scope when the function returns to its caller.

## Understanding File Scope

```
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int listMax   = 100; // important
const int stringMax =  80; // important
...
```

here listMax and stringMax variables are declared as external variables outside of any function block. It has scope that is visible throughout this file.

Now if this was multifile program the other files couldnt access this. Next section, on globals, will go over this.

## Understanding Global Scope

"To make external variables in one file available to another file, we need to declare them with the extern storage class in the file that wants to access them. Suppose nameSorter.c is part of a sortem.c program and sortem.c needs to access those values. This would be done with the following declaration:"

```
#include <...>
#include "nameSorter.h"
extern const int listMax;
extern const int stringMax;
...
```

"The other way is to put the extern declarations in a header file. To do this, we would modify nameSorter.h, as follows:"

```
#ifndef _NAME_SORTER_H_
#define _NAME_SORTER_H_

extern const int listMax;
extern const int stringMax;
...

#endif
```

## Understanding Scope for Functions

The scoping rules for functions are considerably simpler than for variables.

"We have already seen how we can define functions in such a way that prototypes are not needed. We simply define them before they are ever called. Most often, however, it is far more convenient to simply declare function prototypes at the beginning of source files. When this is done, functions can be called from anywhere within the file, and there is no need to worry about whether a function has been declared before calling it."

"So, we can make functions global to all source files in a program. But can we make certain functions only apply to a given source file? The answer is: certainly. We do this with information hiding, through scope rules."

## Understanding Scope and Information Hiding

"We have seen how to cross linkage boundaries with functions by including header files with their prototypes. If we wanted to limit a function's scope to only its compilation unit, we could do that in one of two ways.  The first way is to remove from the header file any function prototypes we do not want to cross the linkage scope."

Basically dont put the function in the header file.

In a file called nameList.c, let’s say you have 7 functions but only 3 need to be used by other files:

AddName()

DeleteNames()

PrintNames()

Only put these 3 function prototypes in nameList.h.
// nameList.h
void AddName(NameList* pNames, char* pNameToAdd);
void DeleteNames(NameList* pNames);
void PrintNames(FILE* outputDesc, NameList* pNames);

The other way is to declare private functions only inside the .c file.

```
// nameList.c
#include "nameList.h"

NameList* CreateNameList(void);
ListNode* CreateListNode(char* pNameToAdd);
bool IsEmpty(void);
void OutOfStorage(void);
```

This way they are only visible within the nameList.c

## Exploring Static Specifier for Functions

As seen earlier, we can use the static storage class keyword for variables. When used with function prototypes or function definitions, it takes a different purpose.

With function prototypes, the static keyword indicates that the function will also be defined later with the static specifier, as follows:

```
#include "nameList.h"
static NameList*  CreateNameList();
static ListNode*  CreateListNode( char* pNameToAdd );
static bool       IsEmpty();
static void       OutOfStorage( void );

NameList* CreateNameList( void ) {
...
}

```

The static keyword in the function means that the function will not be exported to the linker!

In other words, the static keyword in both the prototype and definition prevents the functino from ever being called globally from any other file; it can ONLY be called from the file within the file where it is declared.