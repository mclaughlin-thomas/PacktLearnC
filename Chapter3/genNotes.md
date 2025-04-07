# Chapter 3
# Working With Basic Data Types

Everything in a computer is a sequence of bits. C's basic data types enable the compiler to tell the computer how to interpret bits of data. Intrinsic data types are predefined, and they are built into the language.

A bit plus a data type type results in a meaningful value. Data type not only leads to meaningful value but aldo helps determine what kind of operations on that value make sense.

## Understanding Data Types
A single bit is off (0) or on (1).
Eight bits in byte.
Byte is the basic unit of data.
Bytes are treated single, or as pairs called 16-bit words, or as qudruples to form 32-bit words, or as octets to form 64-bit words.

Our C compiler will generate binary instructions from our C statements.

Both Instructions and Addresses deal with data.

Instructions manipulate data and move it around

Addresses are required for the instructions to be able to featch the data and then store the data.

Inbetween fetching and storing, Instructions manipulate it.

How the computer Interprets the pattern of 1s and 0s is entirely dependent upon the context givent to them by the computer language and the programmer.

Programmers provide guidelines to the compiler and subsequently the CPI on how to interpret the sequence of bits. We do this in C by explicitly assigning a data type to the data we want to manipulate. The data type of a value provides the context to correctly interpret a sequence of bits.

C is strongly typed. That means, every value MUST havea type associated with it.

C also does automatic or implicit conversions from one type into another, but the rules are fairly specifi compared to other programming languages.

We can also perform manual, or explicit, conversions with Type Casting

In C, these are the 5 basic and intrinsic data types:

Whole numbers: These numbers can represent a positive only range of values or range that includes both positive and negative values.

Numbers with Fractions OR Decimal Numbers: All numbers between whole numbers like 1/2 or .79 or 1.79 ,. ..... 

Characters: These are the basis of C strings. Some languages have a sperate string type. In C, strings are a special case of arrays of characters- they are not a data type but a special arrangement of contiguous character values.

Boolean Values: Represent Yes or NO, more precisely, TRUE or FALSE. These can be of any size depending on the preference of the compiler and the machine's preferred whole number size.

Addresses: These are the location of bytes in a computer's memory. C offers the direct addressing of values in memory. Many languages do not allow direct addressing. Pointers will be covered later. Ch13

## Bytes and Chunks of Data

Smallest data value in C is a bit; however, bit operations tend to be very expensive and not all that common for most computer problems. In this book, we will not go into bit operations.

The basic data value in C is a byte. The set of values a byte can represent is 256 or 28 values. These values range from 0 to 255 or 28-1.

A byte can either represent a positive integer ranging from 0 to 255, or 28-1, or a negative integer ranging from -128 to 127. In either case, there are only 256 unique combos of 1s and 0s.

A byte is the smallest of the chunks of data since each byte in memory can be addressed directly.

"Later in this chapter, we'll create the sizes_ranges.c program to confirm and verify the sizes and ranges of integers on your machine. This program will be handy to run whenever you are presented with a new system on which to develop C programs."

## Representing Whole Numbers

The basic whole number type is an integer, or just int.

Integers can either be positive only: unsigned

Or, Integers can be negative and positive, called signed.

To be explicit, the default type is signed int, where the signed keyword is optional

## Representing Positive and Negative Whole Numbers

When negative numbers needed, we specify them with the signed keyword.

A signed integer is: signed int.

The natural use for signed integers is when we want to express a direction relative to zero, either larger or smaller.

By default, and without any extra specifiers, integers are signed.

A signed int uses one of the bits to indicate whether the remaining bits are positive or negative.

Its the MSB thats usually the sign bit.

## Specifying Different Sizes of Integers

Integers can be specified to have various sizes for their data chunk.

The smallest chunk is a single byte.

This is called the char type.

In some languages, a byte is actually called a byte; unfortunately, this is not the case in C.

The int, unsigned, long, and unsigned long types are guaranteed to be at least 4 bytes but might be longer depending on the machine.

The long long and unsigned long long types are guaranteed to be at least 8 bytes but might be longer depending on the machine.

To remedy things being different sizes deoending on the target cpu, C99 added integer types that specify the exact width, the fastest width, and the minimum width integer values.

• The int<n>_t or uint<n>_t forms for exact width integer types

• The Int_least<n>_t or uint_least<n>_t forms for the smallest width of an integer
(this might be larger)

• The Int_fast<n>_t or uint_fast<n>_t forms for the fastest width for an integer
in that implementation

intmax_t is largest possible integer.

## Representing Numbers with Fractions

Rational numbers are represented as p/q where p is the numerator and q is the denominator, are most naturally used to measure things.

A rational number is represented on the computer with the following form:

significand x baseexponent

Here, both the significand and the exponent are signed integers and the base depends on the floating-point implementation.

The size of each depends on the number of bytes for a given rational number type.

There are no unsigned components.

This provides a very large range of numbers, from positive to negative, as well as very small fractional values.

Type         |   # Bytes

float        |   4

double       |   8

long double  |   16


Real numbers are somewhere on the number line. But complex numbers are not.

There are types for complex numbers <types listed here>

Float, Double, and long double form the most frequently used data types of this group.

## Representing Single Characters

To specify a single character, use char.

Usually, the signed char and unsigned char types are not used for single characters but to represent small integer values.

C was made before unicode and UTF-8.

The character set they use is ASCII.

All the necessary characters for prinitng control, device control, and printable characters and punctuation could be represented in 7 bits.

## Representing Boolean true/false

Boolean values only evaluate to true or false.

Before C99, there was no explicit type for a boolean. A value for any type that is 0 (exactly 0), is considered as evaluating to a boolean false. But, any value other than exactly 0 evaluated to a boolean true.

Since C99, a bool type was added, which when evaluated, will always evaluate to only 0 or 1.

When we include the stdbool.h file, we are able to use the bool type as well.

As a general rule, it is always more reliable to test for zero-ness or flase, than to rely on the compiler's implementation for interpreting Boolean true values from other types.

## Understanding the Sizes of Data Types

C provides a way for programmers to ascertain the sizes of each of the data types on a given system with the sizeof () operator.

## The sizeof() Operator

sizeOf() operator is a built-in function that takes a C data type as its parameter and returns the number of bytes for that data type.

Any programmer needs to know the sizes of the data types on a given system to ensure the data type used will appropriately hold the ranges of values they expect to encounter.

EX program for sizeOf()
sizes_ranges1.c

stdio.h declares among other things, the function prototype for printf().

stdint.h declares the sizes, in bytes of each of the intrinsic data types. stdint.h deines the fixed-width integer types.

stdbool.h defines the bool data true and false values. These are part of the C standard library.


## Ranges of Values
Extending program now to show ranges of each data type. These ranges are defined in two header files, limits.h for integer limmits and float.h for real number limits.

To implement this, add another function.

"Some of the numbers that appear after % in the format specifier string might appear mysterious. These will be explained in exhaustive detail in Chapter 19, Exploring Formatted Output"

## Summary
There are only 5 data types: integers, real numbers, characters, Booleans, and Pointers.

Additionally, characters and Booleans can be considered special cases of integers. The fifth type, pointer, is really just another special case of an integer, but with some specialized operations and implicit behavior.

## Questions
Q : For each of the four intrinsic types, identify each sub-type.

1. Whole Numbers, Integers

- char
- int
- short
- long
- long long

Standardized types from <stdint.h>

Exact Width
- int8_t, uint8_t
- int16_t, uint16_t
- int32_t, uint32_t
- int64_t, uint64_t

Minimum Width
- int_least8_t, uint_least8_t
- etc...

Fastest Width
- int_least8_t, uint_least8_t
- ...

Largest Possible
- intmax_t
- uintmax_t

2. Floating Point, Real Numbers
- float
- double
- long double

Also some types for complex numbers in complex.h

3. Characters
Essentailly small integers

- char
- signed char
- unsigned char

Often used to represent ASCII strings in C strings

4. Boolean Values
Boolean types represent true or false values.
- _Bool, built in type
- bool, defined in <stdbool.h> as a macro for _Bool

Only has two values 0 false, 1 true.
