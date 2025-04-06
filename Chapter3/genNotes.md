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
