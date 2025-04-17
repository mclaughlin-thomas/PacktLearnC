# Chapter 13
# Using Pointers

A pointer is a variavle that holds a value; that value is the location (or memory address) of another value!

The pointer data type has two important roles.

1. It identifies the variable identifier as a pointer

2. It specifies the kind of value that will be accessed at the location held by the pointer.

It is important to learn how to verbally differentiate the address of notation, and the target of notation.

--------------

Four main uses of pointers

1. Overcome the call-by-value restriction in function parameters:

pointers expand the flexibility of function calls by allowing variavle function parameters

2. As an alternative to array subscripting:

pointers allow access to array elements wo subscripting

3. To manage C strings:

pointers allow easier allocation and manipulation of C strings.

4. For dynamic data structures:

pointers allow memory to be allocated at runtime for useful dynamic structures, such as linked lists, tress, and dynamically sized arrays.

this chapter will go over 1. 

2 will be covered in ch14

3 will be covered in ch15

4 will be covered in ch18

Pointers allow our programs to model real world objects that are dynamic- that is, their size or numebrs of elements is not kown when the program is written, and their size or the number of elements will change as the program runs.

## Introducing Pointers

### A pointer is a variable whose value is the location of some other variable.

A variabel identifies a value storeed at a fixed location. It consists of a type and an identifier. Implicit in the definition is its location. The location is fixed and cannot be changed! The value is stored at that location.

The varaiable identifier, then, is our assigned name for the lcoation of that value.

We rarely, if ever, care about the specific value of that location- in fact we never do.

We only usually care about the name of the location of our variable identifier.

A pointer variable, like any other variable, also identifies a value stored at a fixed location. It also consists of a type and an identifier. The value it holds, however, is the location of another variable or named location.

For pointer variables, this means that a pointer's value can be initialized to one named location (address) and then later reassigned to another named location (address).

## Understanding Direct Addressing and Inderect Addressing

### When we use a non-pointer value, we are, infact, accessing the value directly through the variable's identifier (its location). This is direct addressing!

When we use a pointer variable to access a value at its assigned named location (a variable in a different location), we are accessing that variable through the pointer variable. This is indirect addressing.

# Understanding Memory and Memory Addressing

First, it is essential to understand that everything that runs on a computer is in memory...

Second, once we understand that everything is in memory, we must know that each byte of memory is addressable...

To a running program, memory is seen as a continuous block of bytes, each having its own address from 1 to the largest unsigned int value available on that computer. The 0 address has a special meaning, which we will see later on in this chapter. An address, then, is the nth byte in the range of all possibly addressable bytes on the computer.

## Managing and Accessing Memory

C ways for a program to allocated, release, and access virtual memoory in our physical address space; it is then up to our OS to manage the physical memory.

The OS swaps vmem in and our of physical memory as needed. In this way, our program is only concerned with the virtual memory address space.

Lastly, every time we run our program, the memory addresses within it will likely change. This is why we are concerned with named locations and never specific memory addresses

To summarize, we now know the following:

• Memory is seen as one large contiguous block.
 
• Everything in a computer is stored somewhere in memory or is accessible via a memory location.

• Every byte in a computer's memory has an address.
 
• Named locations (variables) are fixed addresses in memory

## Exploring Some Analogies in the Real World

In our first analogy, John, Mary, Tom, and Sally each own a different thing that they will give to us when we ask them for it. John owns a book, Mary owns a cat, Tom owns a song, and Sally owns a bicycle. If you want, say, a song, you ask Tom. If you want a bicycle, you ask Sally. If we want something, we go directly to the owner of it. That is direct addressing.

Now, say that we don't know who each of them is or what they own. Instead, there is someone else we know – say, Sophia – who knows each person and what they own. To get something that we want, we have to go to Sophia, who then goes to the proper person, gets what they own, and gives it to us. Now, to get a book, we go to Sophia, who then goes to John to get the book and gives it to us. To get a cat, we again go to Sophia, who then goes to Mary to get the cat and gives it to us. We still don't know anyone but Sophia, but we don't care because we can still get everything indirectly through Sophia. This is indirect addressing.

John, Mary, Tom, and Sally are similar to variables. When we want the things they hold, we go directly to them. Sophia is similar to a pointer variable.

------------

Firgure 13.1!

In this figure, our memory is seen as a linear stream of bytes. The addresses are not shown here since we dont care about them for this example. There are three variavles, length, width and height. They each are 4 bytes, which means they are 32 bits (4 * 8 = 32 bits). Their values contained in those spaces are 40, 20, and 10 respectively. There is a pointer variable too, pDimension. This pDimension variables takes up 8 bytes (8*8 = 64 bits) and points to the location named height! The value of pDimension is the address of the height named location. We never need to be concerned with the actual value of the pointer. Instead we should be concerned with the named location is points to.

## Declaring the Pointer Type, Naming Pointers, and Assigning Addresses

Three basic aspects of pointers:

1. We can declare a variable of the pointer type.

2. We can assign an already-declared named location to it.

3. We can perform a limited number of operations on pointers.

A pointer should only be assigned a value that is an already-declared and named location. This means that a pointer must point to something that already exists in memory.

A pointer is a variable. Therefore, it has a type and an identifying name. It is distinguished as a pointer at declaration with the * notation.

syntax:

type * identifier;

where type is either an intristic type or custom type

where * indicates a pointer to the given type

where identifer is the name of the pointer variable

The actual type of a pointer variable is not just type but also type*

 - > this is what distinguishes a direct variable from an indirect variable.

 

A pointer must have a type for the thing it points to. A pointer type can be any intrinsic type (such as int, long, double, char, and byte) or any already-defined custom type (such as an array, struct, and typedef).

The pointer's value (an address) can be any named location that has that type.

---------

example of an integer pointer is the following:
 
int height;

int width;

int length;

int* pDimension;


pDimension cannot hold the address of a variable of the float, double, or char types (to name just three) – only int. The type of pDimension is int*

---------

## Naming pointers

... Of the four shown, the p- shorthand prefix is probably the most common and easiest to both type (with your keyboard) and read. This convention will be used for the remainder of this book. So, when we see, say, pDimension, we know immediately that it is a variable that is a pointer. This will help us to correctly assign and access it.

## Assigning Pointer Values (addresses)

A pointer has no meaningful value until one is assigned to it.

Any variable declaration merely states what value the variable is capable of holding. We must assign a meaningful value to the pointer

### A pointer variable holds the address of another named location. This is the target of the pointer.

### A pointer points to another variable's location. That variable's value is its target.


------

The way to assign an address value to a pointer is to use the & operator and the variable identifier, as follows:

int  height;

int* pDimension;

pDimension = &height;

This assigns the address of the height named location to the pDimension pointer variable. As previously mentioned, we don't care about the specific value of &height. But now, we know that pDimension points to the same memory location as height. Another way to express this is that height is the current target of pDimension.

## Operatins with Pointers

At this point the only operations that work reasonably with pointers are the following:

- Assignment

- Accessing pointer targets

- Limited pointer arithmetic

- Comparison of pointers

We will check out each of them but also look into the NULL special pointer value (the zeroth address), or a null pointer, and the void* special, unspecified pointer type, or a void pointer type.

## Assigning Pointer Values

.... 

## Differentiating between the NULL pointer and void*

A pointer should always have an assigned value.

Its value should NEVER be unknown.

But there are times when a proper address cannot be assigned or the desired address may currently be unknown. For these types of instances, we have a constant NULL pointer. The value is defined in stddef.h and represents a value of 0. It is defined as follows:

#define NULL ((void*)0)

Here (void*) specifies a pointer to the void type.

The void type represents no type!

It is a type that is unknown or a non-existent value.

You CANNOT assign a variable to have the void type, but a function can return void (nothing).

Basically, when we declare a pointer variable but do not yet have a target for it, it is best to assign the value of NULL to the pointer variable. This way we can test for NULL and know that the pointer variable is not in use.

If we do not initialze a pointer variavle to null, IT MAY HAVE A RANDOM VALUE WE CANNOT DIFFERNTIATE FROM A VALID MEMORY ADDRESS.

The NULL pointer is the way to be certain.

## Accessing Pointer Targets

A pointer has to know the type of the value that it poitns to so that it can correectly get the correct number of bytes for that value.

Without an associated type, pointer access will not know how manyy bytes to use when returning a value.

### To access a value indirectly via a pointer variavle, we must first dereference the pointer- that is to say we must use the address stored in the pointer variable to go and get the value it points to, or we go to its target.

To assign a value to the pointer's target, we use the * operator

--------- 

int  height;

...

int* pDimension = &height;

...

height = 10;

...

*pDimension = 15;


height is assigned a value of 10 directly through that variable identifier. In the next statement, 15 is assigned to the target of pDimension. Because pDimension points to height, that now has a value of 15 via *pDimension. Referenced in two different ways, height and *pDimension are the same memory location

Note that the * operator is used in both the pointer declaration and in the pointer dereferencing.

--------- 
---------

Pointer dereferencing can also be used to access values:


pDimension = &height; // stores address of variable height in the pointer pDimension 

int aMeasure;

...

aMeasure = height;

...

aMeasure = *pDimension; 

// dereference the pointer to get the value it points to and store   that in aMeasure



---------

main.c example

In this program, the %2lu format specifier prints out two digits of an unsigned long value since that is the type of value that sizeof() returns. To print an address in hexadecimal format, we use the %p format specifier, which prints a long hexadecimal value prepended with 0x to indicate that it's a hex value. 

...

This is an important consideration – we cannot foresee exactly how the compiler will order variables in memory. It is for this reason that we must always use named memory locations (variables). Even though we declare variables in one way, we cannot guarantee the compiler will honor that order.

## Understanind the void* Type

There will be times when the type of a pointer is not known. This occurs primarily in C library functions.

For this reason, the void* pointer type represents a generic, as yet unspecified pointer - in other words, a pointer whose type is not known at declaration. Any pointer type can be assigned to a pointer variable of the void* type. However, before that pointer variable can be accessed, the type of the data being accessed must be specified through the use of a casting operation.

void* aPtr = NULL;  // we don't yet know what it points to.

...

aPtr = &height;     // it has the address of height, but no // type yet.

...

int h = *( (int*)aPtr ); // with casting, we can now go to that // address and fetch an integer value.

In the last statement, there is quite a bit going on. First, we must cast void* aPtr to int* aPtr. Having done that, we can then get the target of the integer pointer to get the value of height, which is the correct number of bytes for int. Casting tells the compiler exactly how many bytes to fetch and exactly how to interpret those bytes. 

## Pointer Arithmetic

Even though pointers are integers, only certain arithmetic operations are possible.

Be aware that adding values to pointers is not quite the same as adding values to integers.

Adding 1 to an integer value gives us the next integer value, for example 9+1=10.

But, adding 1 to a pointer increases the pointer value by the value multiplied by the size of bytes of the pointer's target type.

Using the preceding diagram, adding 1 to pDimension actually adds 4 to the address of pDimension because 4 equals sizeof(int). So, if pDimension = 0x328d2720, then pDimension + 1 = 0x328d2724.

Pointer arithmetic actually only makes sense in the context of arrays...

## Comparing Pointers

We can carry out comparison operations on pointers for the following:

- Is the pointer equal or not equal to NULL?

- Is a pointer equal to or not equal to a named location?

- Is one pointer equal or not equal to another pointer?

In each case, we can either check for equality (==) or inequality (!=). Because we can never be certain of the variable ordering in memory, it makes no sense whatsoever to test whether one pointer is greater than (>) or less than (<) another pointer.

If we consistently apply the guideline to always assign a value to a pointer, even if that value is NULL, we can then make the following comparisons:
### if( pDimension == NULL ) printf("pDimension points to nothing!\n");
### if( pDimension != NULL ) printf("pDimension points tosomething!\n");

Both of the preceding comparisons can be shortened to the following

### if( !pDimension ) printf( "pDimension points to nothing!\n" );
### if( pDimension ) printf( "pDimension points to something!\n" );

If pDimension has a non NULL value alone in a comparison expression, it will evaluate to TRUE.If pDimension has a NULL value in a comparison expression, it will evaluate to FALSE

---------

We can check if it points to named location by:

if( pDimension == &height ){

    printf( "pDimension points to height.\n" );

}

if( pDimension != &height ){

    printf( "pDimension does not point to height!\n" );

}

---------

## Verbalizing Pointer Operations

Chart!

## Variable Function Arguments

Function parameters in C are call by value.

In other words, when a function is defined to take parameters, the values that the function body receives through them are COPIES of the values given at the function call.

One advantage of call by value is that we can modify the copies of values passed into the function and the original values remain unchanged. One disadvantag of call by value is that for parameters that are very large arrays or structures, this copying is significantly inefficient and may even cause the program to crash.

However, that is quite cumbersome. It is also unnecessary. There is a better way of doing this with pointers, which we will explore in the last section of this chapter, Using pointers to structures.

## Passing Values By Reference

If we wanted to change the values of parameters so that they are also changed after the function returns, we can use pointers to do so.

We will assign the address of the values that we want to modify to pointer variables and then pass the pointer variables into the function. The addresses will be copied into the function body, and we can dereference them to get the values we want.

THIS IS CALLED PASSING BY REFERENCE.

-----------

double RectPerimeter( double* pH , double *pW )  {

   *pH += 10.0;

   *pW += 10.0;

   return 2*( *pW + *pH ) ;

}

int main( void )  {

   double  height = 15.0;

   double  width  = 22.5;

   double* pHeight = &height;

   double* pWidth  = &width;

   double  perimeter = RectPerimeter( pHeight , pWidth );

}

-----------

## Passing Addresses to Functions w/o Pointer Variables

We can actually go a step further and remove the pointer variables in main() and then pass the desired addresses directly in each function call.

We'll still need the pointer variables as function parameters in the funciton definition, just not in the main() function body.

look @ pointers3.c !

## Pointers to Pointers

We can have a pointer point to another pointer.

This is called double indirection.

When using a pointer to a pointer to a variable, we must doubly dereference our starting pointer to get the desired value!

look @ pointers4.c !

## Using Pointers to Structures

A pointer points to the first byte of a target data type.

Recall that a structure is a named location that holds a collection of named values.

The structure as a whole is named as are each of the member elements of that structure.

Declaring a pointer to a structure variable is no different than declaring a pointer to any other variable. The variable must already have been declared (that is, allocated). The pointer address is the first byte allocated to the structure, just as for any other variable.

------------

For this exploration, we'll use a Date structure type, representing the numerical day, month, and year. It is defined as follows:

typedef struct {

   int day;

   int month;

   int year;

} Date;


We can then declare variables of that type, as follows:

Date anniversary;

We can then assign values to anniversary, as follows:

anniversary.month = 8;

anniversary.day   = 18;

anniversary.year  = 1990;

Now, we can declare a pointer to this structure variable, as follows:

Date* pAnniversary = &anniversary;

At this point, pAnniversary points to the structure variable as a whole, very much like other variables. Unlike intrinsic variables, we are not just interested in the structure as a whole; we are more interested in each of the structure variable's elements.

------------

## Accessing Structures and their Elements Via Pointers

To access one of the anniversary elements via the pointer, we might consider using
*pAnniversary.month. However, because the. operator has higher precedence than the * operator,
the element reference will fail evaluation and will be inaccessible. 

We can change the evaluation order with parentheses, as follows:

(*pAnniversary).day     // <--  anniversary.day;

(*pAnniversary).month   // <--  anniversary.month;

(*pAnniversary).year    // <--  anniversary.year;

Because accessing structure elements via pointers is quite common, an alternative syntax to access structure elements via pointers is available. This is done using the --> operator and appears as follows:

pAnniversary->day     // <--  (*pAnniversary).day;

pAnniversary->month   // <--  (*pAnniversary).month;

pAnniversary->year    // <--  (*pAnniversary).year;

The alternative syntax uses two fewer characters, which is a slight improvement.

## Using Pointers to Structures in Functions

Now we can use an indirect refernce (a pointer!!!) to a structure variable as easily as we can with a direct reference (a variable identifier) to a structrure variable, we can use the indirect reference in funciton parameters to avoid the uneccesary copying of structures to temporary function variables. We can use the structure pointer in function parameters as follows:

void printDate (Date* pDate);

We declare the pointer to the structure type in the function declaratio. We then define the function accessing each element like this:

void printDate( Date* pDate )  {

   int m, d , y;

   m = pDate->month;

   d = pDate->day;

   y = pDate->year;

   printf( "%4d-%2d-%2d\n" , y , m , d );

   // or

   printf( %4d-%2d-%2d\n" , pDate->year , pDate->month , pDate->day );

}


We can then call printDate like this:

Date anniversary = { 18 , 8 , 1990 };

Date* pAnniversary = &anniversary;

printDate( pAnniversary );

// or

printDate( &anniversary );

As we saw earlier, we can call printDate() using a pointer variable, pAnniversary, or by using the &anniversary variable reference, without using a pointer variable

## Questions

1. Does a pointer variable have a value? If so, what is that value?

A pointer variable has a value that is an address. That value can be 0 (NULL) up to the largest addressable byte in memory. 

2. Does a pointer have a type? 

A pointer either has the type for the value it points to, or it has a void* type, which is unknown and must be provided to access the value it points to.

3. What is the target of a pointer?

The target of a pointer is either NULL (no target) or the location of an already-allocated memory location (such as an intrinsic variable, a structure variable, or an array variable).

4. When a variable is passed via a function parameter, what is copied? When a pointer is passed via a function parameter, what is copied?

When any variable is passed via a function parameter, its value is copied to be used in the
function body. For non-pointer variables, the values may be used directly. For pointer variables, the address is used to access the target value.

5. What is dereferencing a pointer?

De-referencing a pointer means using the address it contains to get or set a value at that address. A pointer variable only contains an address.

6. What is addressable via a pointer? What is not?

A pointer CAN address any allocated piece of memory in a program's memory space. This can
be a variable, a structure variable and its members, an array and its elements, a function, or
a device. A pointer CANNOT address any intermediate values, say, from complex expressions,
literal values, enumerated definitions and constants, or structure definitions that have not been allocated in memory.