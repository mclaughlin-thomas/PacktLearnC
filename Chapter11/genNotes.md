# Chapter 11
# Working with Arrays

An array is a collection of two or more values, all of which have the same type and share a common base name. It makes no ssense to have an array of just one value; that would simply be a variable.

Syntax:

dataType arrayIdentifier[numberOfElements];

Here, dataType is any intrinsic or custom type

An array whose size is defined by a constant expression we call a constant-length array. All the elements of the array are contiguous (or side by side) so that the size of the array is the size of each element multiplied by the number of elements in the array. Once an array is declared, its size is fixed and cannot be changed.

int anArray [10];

^ an array with 10 elements. Wow.

This declaration creates 10 variables, each accessed via a single name, anArray, and an offset to each element within the range 0...9

## Initializing Arrays

The most basic way to initialize a constant-length array is to set all of its values to the same value at the time of definition. We set all the array elements to the same value, as follows:

int anArray[10] = {0};

int secondArray[ ARRAY_SIZE ] = {2};

int thirdArray[ eArraySize ] = {100};

All the values of each array are set to the same value given within { and }

## Variable-Length Arrays
VLAs (Variable-Length Array), is an array whose size is not known until runtime.

Pg 231.

## Accessing Array Elements

We access an element of an array via its base name and an index into the array.

arrayName [index]

Wow.

float anArray[10];

aFloat = anArray[ 9 ];             // Access last element.

Now, it may seem odd that even though we declared an array of 10 elements, the index of the last element is not 10 but 9. To fully understand array indexing, it is critical to understand that the index is really an offset from the base name. We will henceforth use the array offset term whenever an index is intended. The first element of an array, therefore, has an offset of 0.

## Using Functions that Operate on Arrays

Even with function parameters, array elements can be passed into them as with regular variables, as follows:

--------------

#include <math.h>

int anArray[10] = {0};

anArray[3] = 5;

anArray[3] = pow( anArray[3] , 2 );

--------------

We could write a function that operations on anArray, as follows:

int find10Min( int anArray[10] );

This function prototype specifies that the function definition will only take arrays of size 10 and no other. 

We want to create functions that operate on all elements of an array, regardless of its size. But how do we use arrays of unknown sizes as parameters to functions? We can do this; arrays of unknown sizes can be passed as arguments to functions. We are specifying a VLA to do this. To pass an array of unknown size as a function parameter, we must declare that the function parameter is a VLA, as follows:

int findMin( int size, int anArray[] );

int findMax( int size, int anArray[] );

double findMean(   int size , int anArray[*] );

double findStdDev( int size , int anArray[*] );

In the last two function prototypes, [*] is equivalent to [] but explicitly states that the size of thearray given is a VLA and will be known at runtime. The [*] syntax can only be used in function prototypes, not in function definitions. 

C does not store the size of an array.

Now, it might be assumed that C will copy the entire array into the called function as it does with other variables; however, it does not. Since that is not the case, arrays as parameters might appear to violate the rules of passing function parameters by copy, but they do not. How this mechanism works will become clear in Chapter 14, Understanding Arrays and Pointers. 

For now, we will take as given the fact that the array name is a named reference to a memory location and that the named reference is being copied into the function

## array.c array3.h

In this program, two arrays – array1 and array2 – are dynamically defined and initialized. Note that when the functions that expect an array argument are called, only the array name is given. The details of the array are provided in the function prototype. Then, information about each of them is calculated and printed.

Provided VLA logic did not work.

gcc array.c -o array -Wall -Werror -std=c17 -lm