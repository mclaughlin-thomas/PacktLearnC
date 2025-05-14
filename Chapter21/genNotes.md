# Chapter 21
# Exploring Formatted Input

## Introducing Streams

In simplest terms, a stream is a sequence of bytes transferred in one direction from its source to its target.

As discussed previously about the abstract concept of an execution stream, or the flow of compiled CPU instructions from memory to the CPU.

An execution stream is created when we successfully compile our source code files into an executable file.

It is then initiated when the program is invoked from the command line and flows until the program stops.

In the console, the input stream transfers bytes—in this case, characters—from the keyboard to our program's memory. The console's output stream transfers characters from our program's memory to the screen.

All streams consist of bytes flowing from one device to another device.

Nearly all of the coordination between devices in a stream is handled by the C runtime library or by the operating system.

Each stream is represented internally by a pointer to a complex data structure called a FILE. 

FILE, which contains the information needed to control the stream!

This includes its current state and associated data buffer.

Wen program executionm begins, the C runtime library creates three file streams for us and automaticallly connects them to our program as follows:

```
#include <stdio.h>
FILE* stdin;  /* standard input: the keyboard      */
FILE* stdout;  /* standard output: the screen       */
FILE* sterr;     /* standard error output: the screen */
```

We rarely have to deal with the internal workings of these stream structures. We can, by means of redirection, connect stdin, stdout, and stderr to files or another device without affecting the contents of our program.

[table streams]

"
Whenever we speak of printf(), we are also speaking of its related functions—fprintf() and sprintf(). So, except for the different streams used in each of these functions, what is said for one will apply to all three. Likewise, whenever we speak of scanf(), we are also speaking of its related functions— fscanf() and sscanf(). So, except for the different streams used in each of these functions, what is said for one will apply to all three.
"

## Understanding the Standard Output Stream

The standard output, stdout, stream is a pointer to a complex file structure named stdout!!!

This stream sends all characters to the console screen formatted by the printf function!!!

We can think of this stream as a never ending flow of characters from our program to the screen.

Control characters aer involved like CR carriage return, NL newline, and others.

The console program simply prints them out or interprets these control characters and changes the position of where the next character will be shown on the screen.

Some complications...

The flow of characters in the stream are typically buffered...

That is, they are sent to a memory location, a character array of a fixed size, before being sent to the screen.

"
The buffer coalesces, or groups, output to the screen so that numerous characters are output at once and not one at a time. The buffer is flushed or sent to the screen either when the buffer is full, when a new line is encountered in the stream, or when our program exits.
"

By default, all FILE streams are buffered!!!!

We can see how it affects program behavior in the program buffer.c

Here, we use sleep function declareed in unistd.h header file to put the program into an idle state for 5 seconds.

Flushing is important!!!

"Given that the sleep() function comes after the second printf() function, you might have expected to see its output before the program slept (or went idle) for 5 seconds. Instead, what actually happened is that without CR, the buffer is not flushed until the very last printf() function. This experiment shows how CR flushes the output buffer immediately, whereas a lack of \n or CR, as in the second printf() function, prevents that string from being flushed until a CR character is encountered or until the program exits"

The buffer is flushed when the program exits.

// add \n to line 5 and the buffer will be flushed  immediately

## Understanding the Standard Input Stream

The standard input, stdin, stream is a pointer to a complex FILE structure named stdin!!!

This stream reads any characters typed from the keyboard to be formatted by the scanf function!! Simple enough...

By default this stream is buffered, much like the output stream...

For input, this means that characters are sent ot the buffer and the buffer is not flushed until the buffer is full OR until CR is encountered in the input stream...

As we enter characters, program control is maintained by the console and is not returned to our program until the buffer is flushed.

The processing of the input characters then appears to be as if they were received one at a time.

In reality its more complicated than this...

The console has two modes of processing: Cooked Mode and Raw Mode.

"
Cooked mode uses buffered input and is the default mode unless it is explicitly changed. It also means that we can alter our input in the buffer until we type in the CR key. Backspace and Delete work as expected in this mode, so we can edit our input in the buffer before the buffer is flushed to our program. The console is managing the buffer in this mode. Even for single-character input, we must enter CR for it to leave the buffer and be passed to our program.

In raw mode, each individual character is received by the console, and control is immediately returned to our program to process that single character. The character buffer is a single character only. No input processing is done by the console, so no editing is possible in this mode. We will see how to put the terminal in raw mode and perform single-character processing after we introduce the scanf() function. 
"

Basically in Cooked Mode our terminal manages the buffer, not our program. And our buffer is not sent to our program until we hit enter (\n or CR)

Basically in Raw Mode, each keypress is immediately sent to the program. The buffer holds just one character at a time.

## Revisiting the Console Output with printf and fprintf

The function prototypes for printf() and fprintf() look like this:

```
int  printf(                const char* format , ... );
int fprintf( FILE* stream , const char* format , ... );
```

Spaces have been added to emphasize the common parts of each function. We can see the console output with printf(), as follows:

```
int myAge = 1;
printf( "Hello, World! I am %d today!\n" , myAge );
```

This is, in fact, a shorthand form of the fprintf() function using stdout for the file stream parameter, as follows:

```
int myAge = 1;
fprintf( stdout , "Hello, World! I am %d today!\n" , myAge );
```

"If you are so inclined, you could replace every printf( … ) statement in every program we have seen so far with its equivalent form, fprintf( stdout , … ), and all the programs would execute exactly as before. But please don't bother doing this; we have better things to do!"

## Exploring the Console Input With scanf

The function prototypes for scanf() and fscanf() look like this:

```
int  scanf(                const char* format , ... );
int fscanf( FILE* stream , const char* format , ... );
```

Again, spaces have been added to emphasize the common parts of each function. For the console input, we can use scanf() and fscanf() interchangeably. These two function calls are equivalent, as shown here:

```
scanf(        "%d" , &anInteger );
fscanf( stdin, "%d" , &anInteger );
```

Whitespace has been added to emphasize where the functions differ. The scanf(…) function is shorthand for fscanf( stdin , … ) when input is received from the console.

One major difference between scanf and printf is that we must pass the address of the varaibel to be assigned or a pointer to the variable we wish to give a value to the function.

In C, funciton parameters are passed by a copy, so with printf we only need a copy of the value to the output since printf does not change any values; it only displays them.

But! for scanf to be able to change the value of the variable passed into it, we must instead pass the address of that variable.

Apart from that one difference, the format specifiers for scanf() are identical, but fewer in number than the format specifiers for printf().

... For instance, the '1', '2', and '5' characters are received from the input stream, converted into 125 (a number) with the %d format specifier, and then assigned/ copied to the specified variable. It should be noted that the input stream is not necessarily a valid string because of a lack of the NULL terminating character. 

## Reading Numerical Input with scanf

readNumbers.c

then readNumbersResult.c

In this program, instead of ignoring the result returned from scanf(), we capture it by assigning it to a variable, and then we use that value to determine which input values have been read. If numScanned is 0, no values have been successfully interpreted by scanf(). If numScanned is 1, only the first inputvalue was successfully interpreted and assigned by scanf().

## Reading String and Character Input with scanf

One way to read a string is to use scanf with the %s specifier.

The %s specifier assigns a sequence of nonwhitespace characters to the given array.

As with numbers, leading whitespace is skipped.

Whitespace can be space, \t, \n, \r, \f or \v

Conversion stops on the first occurence of whitespace after one or more instances of nonwhitespace or at the maximum field width, if specified.

Otherwise, the array to which the input string is assigned must be large enough to hold the string plus the terminating NULL character.

readString.c

-------------------
In the previous program all characters up to the first space character or whitespace are read in.

The next program can read a character in and also use whitespace between input values.

The following program will read a character without whitespace and with whitespace in the format specifier.

readChar.c

## Using Internal Data Conversion

It should be fairly obvious that the ability of printf to convert binary values into strings and of scanf to convert strings into binary values is very powerful.

## Using sscanf and sprintf to Convert Values Into and From Strings

When using sscanf to interpret a string buffer into values, the string buffer is already known or has been allocated elsewhere.

sscanf converts the string into the desired values assigning them to variables. The sizes of these variables are known by their data type.

On the other hand, when using sprintf to convert into characters, the final output buffer size required is rarely known.

"We can either exercise great care to allocate a specific array size or, more commonly, we can simply allocate an array that is reasonably larger than expected, ignoring any unused or even unneeded buffer space."

internalFormatting.c

"Apart from the use of I/O buffers (character arrays), this program is nearly identical to read2NumbersUsingResult.c, which we created at the beginning of this chapter. Instead of reading 1234 and 5678.9012 from the input stream, these values are now found in the sIn[] array buffer. Instead of writing to stdout, values are output to the sOut[] array buffer, whose size is a generous 80 characters, or about the length of a standard console line. Remember that sOut[] can hold a string of up to 79 characters, with the 80th character being the required NULL character. "

"This program introduces the puts() function, which is a simplified version of printf(). puts() simply prints the given string to stdout and is the equivalent of printf( "%s\n" ). The input counterpart to puts() is gets(), which we will encounter a little later in this chapter."

"We can see that sscanf() was able to convert and correctly assign two values. We can also see that sprintf() formatted those values into a string of 33 characters. Note that this count of 33 characters does not include the NULL character"

## Converting Strings Into Numbers With atoi and atod

We don't always need the specificity or flexibility that the strto<type>() functions provide. The following program demonstrates the conversion of strings into an integer and double:

```
#include <stdio.h>
#include <stdlib.h>
int main( void )  {
  int     anInteger   = -1;
  double  aDouble     = -1.0;
  
  char sInteger[] = "1234" ;
  char sDouble[]  = "5678.9012";
  
  printf( "As strings: integer=\"%s\" double=\"%s\"\n" ,
          sInteger , sDouble );
  anInteger = atoi( sInteger );
  aDouble   = atof( sDouble );
  printf( "As values: integer=[%d] double=[%lf]\n\n" ,
           anInteger , aDouble );
  return 0;
}
```

## Exploring Unformatted I/O

Not every string input needs to be converted into some binary value. Often we simply need to read or write strings w/o any additional formatting....


## Getting the String I/O To/From the Console

To read and write a line of text there are puts and gets console functions and their stream equivalents fputs and fgets

The puts and fputs functions write the given string ot the output stream or file adding newline to the end!

gets and fgets read from the input stream or file until eof or newline is encountered.

The newline character, if encountered is retained by fgets but gets discards newline.

With gets, no limit for the number of chracters to be read can be specified.

On the other hand, fgets must be given the max number of chracters to read, it will read up to that limit until eof or newline is encountered.

## Using the Simple I/O of Strings With gets and puts

readString2.c

gets has no bounds checking and can cause buffer overflow, and is deprecated in C99 and removed in C11

Use fgets instead of gets.

scanf can read formatted input like integers strings, etc.

issues with scanf: stops at space or newline, so "John Smith" becomes "Johh"

errors with gets in C11...

## Understanding Why Using gets can be dangerous

Big difference between gets and fgets.

The following function prototypes for these two functions highlight their differences:

```
char*  gets( char* str );
char* fgets( char* str , int size , FILE* stream );
```

"From this, we see that gets() requires no limits on how many characters it reads; therefore, gets() has the potential to read an infinite amount of input. On the other hand, fgets() must be given a maximum number of characters to be read in the size parameter. fgets() will read up to size-1 characters unless EOF or <newline> is encountered. Specifying a maximum size for processing is known as a bounds-checking interface. The total size of the data to be processed by such a function is bound by the given size. "

"Because there are no limits on the length of the string to gets(), it has the potential to read beyond the size of the string buffer. If this happens, in a best-case scenario, mayhem will ensue and the program will crash. In a worst-case scenario, malicious input could be devised such that the program does not crash and causes control to extend beyond the program. This is called a buffer overrun and is a big security risk, which is why gets() is unsafe."

"One solution is to completely replace any gets() function with the safe_gets() wrapper function. Another solution is to write a custom function that performs one or more actions appropriate to the current need. We will do this in the following section."

## Summary

We went over how a stream is a flow of bytes from a source to a destination.

For the console, the streams are the pre-defined stdin, stdout, and stderr variables.

After we went over streams, we went into input stream format specifiers.

All of the examples we went over that talked about input stream format specifiers expanded our abililty to convert various forms of input data streams.

We also went into methods of internal formatted data conversion.

These involved sscanf, ssprint, atoi, atof

Then, we went over unformatted IO with fputs and fgets, as these were demonstrated in nameSorter.c

"In the next chapter, we will expand our knowledge of file streams. We will see how they are similar to stdin, stdout, and stderr, but we will also see why we need to learn how to create, open, read, write, and perform other manipulations that are unique to files."
