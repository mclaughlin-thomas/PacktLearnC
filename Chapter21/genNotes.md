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

