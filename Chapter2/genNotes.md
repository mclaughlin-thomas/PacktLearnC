# Chapter 2
# Understanding Program Structure

The \ punctuation mark has special significance when it is part of a string.

A digraph in C is a two-character sequence, which means something more than either of the characters alone.

Symbol, Meaning
\a alert

\b backspace

\f Form Feed

\n newline

\r Carriage Return

\t Horizontal Tab

\v Bertical Tab

\' Single Quote

\" Double Quote

\? Question Mark

\\  Backslash itself

## Understanding Delimiters

Delimiters are characters that are used to separate smaller parts of the program from another. These smaller parts are called tokens.

A Token is the smallest complete C language element.
A token is either a single character or sequence of characters predefined by the C language, such as int or return.

When a token is predefined by C, it cannot be used except in a prescribed way.

These tokens are called keywords.

Is main() a keyhword, No. But every C program must have a single function named main. This is the starting point or program's entry point.

3 types of delimiters we will go over:

Single Delimiters

paired, symmetric Delimitrers

Asymmetric Delimiters that begin w one character and end w another.

examples:

int main()
return 0;

In bothm the space character is used to separate one keyword or token from another.

A keyword is a predefined word that has special meaning,=.

Delimiters, including <space>, facilitate interpreting text in the program compilation stream into tokens. Otherwise, when spaces are not needed to separate tokens, they are optional and are considered whitespace.

First line of c example. Begins with @ and ends with a newline. That is an example of asymmetric delimiteer pair.

That line is a preprocessor directive.

The preprocessor is the very first part of the compiler phase where directives are interpreted.

## Introducing Statements

Each statement forms a complete unit of computational logic.
Statements in C are the basic building blocks of programs.

- Simple Statements: ends with ; return 0 is a simple statement

- Block Statements: begin with { and ends with }

- Complex Statements: Consists of a keyword, a parenthetical expression, and one or more block statements

- Compound Statements: Made up of simple statements and/or complex statements that consist of multiple statements.=

- Return Statement: causes execution in the current function to end; execution then returns to the caller.

- Function Call Statement: Just as the main () is called by the system to be executed, we too can call functions that have already been defined or that we have defined in our program. For example, the printf() function to do some work for us.

- Function Definition Statement: A function definition is a complex statement that consists of several parts. The main () function is a function definition

- Preprocessor Directive: This begins with # and ends with <newline>. It does not perform a compution, it insteads is a command for the compiler to process our C file in a specified way. Preprocessor directives do not follow C syntax, but they are included in the language. We can think of them as outside of C syntacx. They direct the compiler to do extra, prepatory stuff before the compiler gets down to the actual work of compiling the program

## Understanding Function Definitions

Functions are important. Each function that we create has the following parts:

1. Function Identifier: This is the name of the function. It should match what it does closely

2. Function result type or return value type: Functions can return a value to the caller. If a value type is specified, the funciton MUST return a value of that type to the caller

3. Function Block: A block that is directly associated with the function name and parameter list where additional statements are added to perform the work of the function

4. Return Statement: Primary mechanism to return a value of the specified type from the called function to its caller

5. Function Parameter List: Optional list of values that are passed into the function.


An exception to using all uppercase names is for names used in preprocessor directives. Here, by convention, preprocessor directive names tend to take all uppercase letters separated by underscores. 

A function statement can return a value to its caller. It does so from within its function block. The caller is not required to use the returned value and can ignore it. In Hello world!, the printf() function call returns a value but we ignore it.

You may be wondering why we define our functions with specific numbers of parameters, and yet the printf() function can take multiple parameters. This is called a variadic function. C provides a mechanism to do this.

---------------------

Functions are called and have a caller.

The called function, or callee, returns to its caller.

----------------------

## Order of execution

When a program executes it finds main() and begins executing statements in the main() function block. Whenever a function call statement is encountered, several actions occur:
1. If there are function parameters, the actual values that are found in the function call statement
are assigned to the function parameter names.
2. Program execution jumps to that function and begins executing statements in that function block.
3. Execution continues until either a return statement is encountered or the end of the block is
encountered (the closing }).
4. Execution jumps back, or returns, to the calling function and resumes from that point.

## Understanding Function Declarations

For a compiler to recognize f function call when it sees it, it must already know about the function.

C provides a way to declare a function so that the compiler knows just enough about the function to be able to process a call to the function before it processes the function definition. These are called function declarations or function prototypes.

"They tell the compiler the function's name, the return type, and the
parameter list. They have no function body. Note that instead of the function body, they end with ;"

If the function prototype differs from the function def seen later, we will get a compiler error.

Here, functions are defined in the order that they are called. An ordering such as this is sometimes called top-down implementation since the functions that are called first also appear first in the program file.

For the compiler to be able to process functions in a top-down manner, function prototypes are
required.

------------------- 
## On printf

printf( "%s, %s!\n" , greeting , who );

%s: A format specifier for a string. It tells printf to insert a string (i.e., a char*) at that spot.

The first %s will be replaced by greeting.

The second %s will be replaced by who.

, and ! are just literal characters—they appear exactly as typed.

\n is a newline character, meaning it moves the cursor to the beginning of the next line.

-------------------

Questions
Answer the following questions to test your knowledge of this chapter:

3. Can you name the five parts of a function definition?

        Identifier, Result, Block, Statement, Parameter List.
4. What is another name for a function declaration?

        Function Prototype.
5. What is the difference between the function declaration and the function definition?

        Function Declaration (Prototype) is really just for our compiler with no logic. Function Definition is where our actual logic.
6. Is a return statement always required? If not, why not?
        
        No.