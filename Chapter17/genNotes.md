# Chapter 17
# Understanding Memory Allocation and Lifetime

In this Chapter we will go over the various ways in which memory is allocated.

The different mechanismsfor memory allocation are called storage classes.

## Defining Storage Classes

C provides a number of storage classes. These fall into the following two general categories:

1. Fixed Storage Allocation:

Fixed storage allocation means that memory is allocated in the location where it is declared. 

All fixed storage is named; we have called these variables identifiers, or just variables.

Fixed storage includes both the automatic storage class and the static storage class. We have been using automatic storage for every variable thus far.

When you declare a variable and—optionally—initialize it, you are using automatic storage. We will introduce static storage later in this chapter.

2. Dynamic Storage Allocation:

Dynamic storage allocation means that memory is allocated upon demand and is only referenced via a pointer. The pointer may be a fixed, named pointer variable, or it may be a part of another dynamic structure.

Two properties of storage classes are their visibility—or scope—within a program or statement block, and their lifetime, or how long that memory exists as the program runs.

Within the genera category of fixed storage, there are two subcategories!

1. Internal Storage Allocation:

This is storage that is declared within the context of a function block or compund statement - in other words, declared between { and }. Internal storage has both a limited scope and a limited lifetime.

2. External Storage Allocation:

External storage is storage that is declared outside of any function block. It has a much broader scope and al ifetime greater than that of internal storage.

-------------------

dynamic storage allocation is unnamed; it can only be accessed via pointers.

Dynamic memory allocation will be introduced and explored in the next chapter.

## Automatic Storage

Automatic storage is memory that is allocated by the compiler at precisely the point when a literal value, variable, array, or structure is declared.

In all cases except literal values, when this storage class is allocated, it is given a name—its variable name—along with its data type. Even a pointer to another, already allocated memory location is given a name.

## Dynamic Storage

This is memory that is unnamed but is accessed soley indirectly via pointers.

There are special library functions to allocate and deallocate dynamic memory.

## Understanding Internal Versus External Storage Classes

In the storage class or fixed or named memory, C has explicit mechanisms to allcate that memnory.

These correlate to the following four C keywords:

------------

auto

static

register

extern

------------

auto keyword represents the automatic storage class

static keyword specifies the static storage class.

------------

These keywords precede a variable specification as follows:

<storage class> [const] <data type> <name> [= <initial value>];

In this specification, the following applies:

• <storage class> is one of these four keywords: auto, static, register, and extern.

• [const] is an optional keyword to indicate whether the named memory can be changed after initialization. If const is present, an initial value must be supplied.

• <data type> is an intrinsic or custom data type.

• <name> is the variable or constant name for the value and data type.

• [= <initial value>] is an optional initial value or values to be assigned to the named memory location. If const is present, the value in that memory cannot be changed; otherwise, it can be reassigned another value.


### When <storage class> is omitted, the auto keyword is assumed. So, all of our programs up to this point have been using auto memory variables by default. Function parameters are also auto memory variables and have all the same properties as those we explicitly declare in the body of functions or in compound statements.

register keyword was used in older versions of C to signal to the compiler to store a value in one of the registers of the CPU for quick access to that value.

Compilers have become so much more sophisticated that this keyword is ignored, except in some very specialized C compilers.

The extern keyword has to do with the scope of external variables declared in other files. We will return to the use of this keyword in Chapter 25, Understanding Scope. 

## Internal or Local Storage Classes

In previous chapters we have been usin automatic, fixed storage in the preceding chapters, but we have also been using the subclass of internal storage! Internal storage is memory that is allocated either with a compound statement ( between { and } ) or as a function parameter.

### Internal memory includes loop variables that are allcoated when the loop is entered and deallocated when the loop is exited or completed.

Internal memory variables are only accessible within the compound statement where they've been declared, and any subcompound statement is declared within that compound statement.

Their scope is limited to their enclosing { and }.

They are not accessible from any other function or any function that calls them. Therefore, they are often referred to as local memory because they are strictly local to the code block within which they are declared.

## External or Global Storage Classes

External storage is memory that is declared outside of any function body including main().

Such variables could potientially be accessed from any part of the program.

These variables are often called global variables.

Global variables should be used sparingly and with great care. 

## The Lifetime of Automatic Storage

When we consider the storage classes we should not only consider when they are created and accessed, but also when they are deallocated or destroyed. This is their lifetime-from creation to destruction.

Internal variables are destroyed and no longer accessible when that compound statement or function is exited.

Consider the doSomething() function. The aReal, aNumber, d1, d2, n1, and n2 variables are created when the function is called. All of them are destroyed after the function returns its d2 value. The i loop variable is created when we enter the loop and is destroyed when we exit that outer loop.

Automatic, external variables are created when the program is loaded into memory. They exist for the lifetime of the program. When the program exits (the main() function block returns), they are destroyed.

## Exploring the Statric Storage Class

Sometimes it is desirable to allocate memory in such a way that it can hold a value beyond the lifetime of automatic memory variables.

An example of this might be a routine that could be called from anywhere within a program that returns a continuously increasing value each time it is called, such as a page number or a unique record identifier. 

As with the automatic storage class, it can exist as both internal and external storage.

## Internal Static Storage

When a variable is declared within a function block with the static keyword, that variable is accessible only from within that function block when the function is called.

The inititial value of the static value is assigned at compile time and is not re-evaluated at runtime.

So... The value assigned to the static variable must be known at compile time and cannot be an expression or variable.

------ example ------

Example pageCounter.c

// see the pageNo varaible be 1 everytime

This program also demonstrates how to concatenate multiple string literals together into a single string literal. Such concatenation can also be done when a string array is initialized. Note that there is no comma between the two string literals. This is useful for printing multiple lines of text such that the text of each can be easily aligned.

------ example ------

## External Static Storage

Because an internal static variable can only be initialized by the compiler, we need another mechanism to safely store a value that we might want to initialize, or seed, ourselves. For this, we can use an external static variable.

External static variables can only be accessible by any other variable or code block, including functinon blocks, within the file they are created.

The static attribute prevents them from having external visibility outside the file where they are declared.

Ideally, then, the code for the external static variable and the function that accesses it should be in a single, seperate .c file as follows:

---------

  // seriesGenerator.c

static int seriesNumber = 100; // default seed value

void seriesStart( int seed )  {

   seriesNumber = seed;

}

int series( void )  {

   return seriesNumber++;

}

---------

To then use these functions we would need to include a header file with the function prototypes for it:

---------

// seriesGenerator.h

void seriesStart( int seed );

int  series( void );

---------

---------

// main.c

#include "seriesGenerator.h"

int main() {
    seriesStart(500);
    printf("%d\n", series());  // prints 500
    printf("%d\n", series());  // prints 501
}

---------

seriesNumber has external static storage: it lives across the whole program but cannot be accessed directly from main.c

---------

A static variable inside a function keeps its value between function calls (internal linkage).

A static variable outside any function (i.e., at file scope) keeps its value across function calls too—but it’s hidden from other files (external static storage).



## The Lifetime of Static Storage

