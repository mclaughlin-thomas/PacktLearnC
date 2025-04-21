# Chapter 15
# Working With Strings

In C, a string is an array with two special properties.

1. The string is made up of only characters

2. The string must conclude with an essential terminating character - the NUL character.

## Characters - The Building Blocks of Strings

In C each array element in a string is a character from a character set called ASCII.

One special control character is NUL, which has a value of 0. This is known as the null character, or '\0'. It is a special character value that terminates a properly formated C string.

Omitting this character will cause the C string to be formed improperly.

ASCII was based on older standards and was developed around the same time that C was invented. It consists of 128 character values, which can be represented with a single signed char value.

The lowest valid ASCII value is 0, while the highest valid ASCII value is 127 (there's that off-by-one thing again that we first saw in Chapter 7, Exploring Loops and Iteration). Each value in this range has a single, specific character meaning.

Non valid ASCII value? 

-> The exception to this is the End-of-File (EOF) indicator, which has a value of –1.

0-31: Control Characters

32-63: Punctuation and Numerals

64-95: Uppercase letters and more punctuation

96-127: Lowercase Letters

BE CAREFUL WITH CONTROL KEYS! THERE IS NO REASON TO EVER USE THEM EXCEPT IN PROGRAMS THAT COMMUNICATE WITH OTHER DEVICES AVOID THE TEMPTATION TO USE THEM!

## Exploring C Strings

The terminating Character is sometimes called a sentinel.

The NUL character will be used as a sentinel when we loop through string elements. The sentinel will indicate that we have encountered every element of the string.

Where we use 'x' (single quotes) to indicate a single character, we use "Hello" (double quotes) to indicate a string literal, which is constant and cannot be changed. When double quotes are used to define a string, the NUL terminator is automatically added to and included in the array of characters.

A minor weakness of C strings is that they are not always efficient. To get the size of a string, for instance, the entire string must be traversed to find its end. This is how the strlen() function works; it traverses the entire string, counting each character before the first '\0' character it encounters. Often, this traversal may be done multiple times.

## Declaring and Initializing a String

The first way is to declare a character array with a specified size, as follows:

char aString[8];

The next way to declare a string is similar to the first method but instead, we don't specify the size of the array, as follows:

char anotherString[];

The last way to declare a string is to declare a pointer to char, as follows:

char * pString;

Initialize

1. We can declare an empty string – that is, a string with no printable characters – as follows:
  
  char string0[8] = { 0 };

2. Next, we can declare a string and initialize the array with individual characters, as follows:
  
  char string1[8] = { 'h' , 'e' , 'l' , 'l', 'o' , '\0' }; 

3. Thankfully, the creators of C have given us an easier way to initialize a string, as follows:
 
 char string[8] = "hello";

4. The creators of C didn't stop there. Again, thankfully, they provided an easier way to do this, as follows:
  
  char string3[]  = "hello";

A pointer to a character is declared and initialized with a string literal, as follows:
  
  char* string4 = "hello";


## Passing a String to a Function

The first way is to pass the string explicitly, giving the array size of the string, as follows:

Func1( char[8] aStr );

This parameter declaration allows a string of up to seven characters, as well as the terminating NUL  character ('\0'), to be passed into Func1(). The compiler will verifythat the array being passed in has exactly 8 char elements. This is useful when we are working with strings of a limited size

The next way is to pass the string without specifying the char array size, as follows:

Func2( char[] aStr );
Func3( int size, char[] aStr ); 

In Func2(), only the string name is passed. Here, we are depending on the fact that there is '\0', a NUL  character in aStr. To be safer, the size of the string, as well as the string itself, can be passed into the function, as is done in Func3().

Lastly, we can pass a pointer to the beginning of the string. The pointer may point to either an array of characters or it may point to a string literal:

Func4( char* pStr );

## Empty Strings Versus Null Strings

When a string contains no printable characters, it is called an empty string. Following are examples

char* emptyString1[1] = { '\0' };

char* emptyString2[100] = { 0 };

char* emptyString3[8] = { '\0' , 'h' , 'e' , 'l' , 'l' , 'o' ,'\0' } ;

When an array reference or pointer to a string is null (nothing), it is called a null string. 

char  nullString1[];

char* pNullString2 = NULL;

The first null string is an uninitialized character array declaration. The second null string is a pointer to the character where the pointer value is NULL. pNullString2 will be a null string until a valid string address is assigned to it.

An empty string and a null string are not the same! One is an array with at least one '\0',
the NUL character; the other is nothing at all – nothing has been allocated or the null string reference is NULL (it points to nothing).

## Common Operations on Strings - the Standard Library

The C standard library provides some useful operations on strings. These are declared in the string.h header file.

Copy, append, and cut strings:

strcat (): concatenates two strings, it has terminating '\0' at end.

strcpy(): copies one string to another including the terminating '\0' character

strtok(): breaks a string into tokens or substrings

Compare Strings:

strcmp(): compare two strings

Search Characters in Strings:

strchr(): locates a character in the string. Finds first occurence

strrchr(): locates a character in a string in reverse. Finds the last occurence of the desired character in a string

strpbrk(): locates any set of characters in a string

Substring:

strstr(): locates subbstring in string.

## Safer String Operations

• Copy and append strings:

strncat():

Concatenates two strings. This appends a copy of up to N characters of one null-terminated string to the end of a target null-terminated string, then adds a terminating `\0' character. The target string must have sufficient space to hold the result. 

strncpy():

Copies up to N characters of one string to another. Depending on the size of the destination, the destination string may either be filled with the nul characters or may not be null-terminated.

• Compare strings:

strncmp():

Compares two strings. Lexicographically, it compares no more than N characters of two null-terminated strings.