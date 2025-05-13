# Chapter 20
# Exploring Formatted Output

## Getting Input From the Command Line

## The Special Features of main()

The main() function is a special C function with the following unique properties:

- main cannot be called by any other function

- main is the first function called when program is invoked to begin execution

- when we return from the main function, execution stops! And the program is terminated

- there are only two forms of the main function prototype!
    - Has NO arguments!
    - Has EXACTLY TWO arguments, an int value and a char* array

## The Two Forms of main()

default main

int main( void ) { ... }

second form of main

int main( int argc , char* argv[] ) { ... }

Here, we have the following:

• argc is the short name for the argument count.

• argv is the short name for the argument vector

When we declare main the second way, the cli interpreter processes the command line and populates those two variables outlined above, then passing them into the main function.

It should be noted that argc and argv are arbitrary names. You might want to use alternative names in main(), as follows:

int main( int argumentCount, char* argumentVector[] ) { ... }

What is significant is that the first parameter is an int value (with a name that we choose) and the second parameter is an array of char* (also with a name that we choose). argc and argv are merely common names used in the main() function declaration.

----------------

We also see main written like this which is similar to the main fcn signature with argc and argv

int main( int argc, char** argv ) { ... }

This is equivalent to the last way due to the interchangeability of pointer notation and array notation.

## Using argc and argv

When we invoke a program, we see the following:

- Memory is allocated in the program space

- Command line arguments are procesed into function parameters that are passed into main, or ignored if those parameters are absent

- The execution begins with a call to main!

Some notes ...

Every argument from the command line is broken up into strings.

And.. a pointer to the beginning of each string is placed in argv, and the argc counter is incremented.

The program name itself is always placed in argv[0]. So... argc will ALWAYS be at least 1.

Each argument we pass via the command line is separated by whitespace. We can make a single argument of several space separated words by enclosing the group of words in either 'words words ' or "words words".

## Simple Use of argc and argv