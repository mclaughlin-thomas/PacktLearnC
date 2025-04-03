In this chapter, we will cover the following topics:

• Writing your first C program

• Understanding the program development cycle

• Creating, typing into a text editor, and saving your C program

• Compiling your first C program

• Running your program, verifying its result, and, if necessary, fixing it

• Exploring different commenting styles and using them

• Employing guided chaos, followed by careful observation for deeper learning

-------------------

Two main types of development environments.

Interpreted.

Compiled.

Interpreted: Like python or Ruby. Each line is evaluated and executed as it is
entered.

Compiled: Like C or C++. All files compiled at once, and if no errors are found,
the program can be run as a whole. Compiled programs tend to execute faster.

## Edit
Programs are generated from text files whose filenames use predefined file extensions.
These are known as source files or source code files.
In C, .c indicates a C source file. A .h indicates a header file.
The C compiler treats .c and .h differently.

To modify C files we need a plain text editor, like Nano, Vim, Vi, gedit, and more.

## Compile
A compiler is a program that takes some input source code, like our .c and .h files and translates the source code into machine language. IT ALSO links together all the predefined parts required to enable the program to run on our specific computer hardware and OS. It generates an executable file that consists of machine language.

We know that machine language is a set of instructions for the CPU that knows how to fetch from the program execution stream and execute on the computer one by one.

Every computer has its own machine language or instruction set.

When we compile our programs, we use the compiler to process our source files. We either get a success and get our executable, OR, we get an error and no executable.

A good, complete program consists of our compiled source code AND predefined compiled routines that come with our OS.

The predefined program code is often called the runtime library.

Think how text is sent to screen. How text is sent to the console is likely to be different for each OS.

We as programmers are often shielded from the minutiae of machine language, but also from the varying implementation details of the computer itself.

## Many C Compilers for Every OS

You can learn C on many computer platforms. Common compilers in use on Unix and Linux OS are either the GNU Compiler Collection (GCC) or the LLVM compiler project, Clang. For Windows, GCC is available via the Cygwin project or the MinGW project...

## Installing a Compiler on Linux

For Debian

    sudo apt-get install build-essential

Then verify the installation

    cc --version

## Run

Once your program compiles successfully, you will get an executable file. This executable file will be named a.out unless we give it a name.

Running an executable file is performed by invoking it from the command line.

When that program is invoked, the executable is loaded into the computers memory and then becomes the CPU's program execution stream.

Once it is loaded into memory, the CPU begins at the special reserved keyword known as main(), and continues until either return; or a closing '}' character is encountered. The program is then stoped and the executable is then unloaded from memory.

To run executable type 
./a.out

## Creating program
touch hello1.c
// put hello world in...
gcc hello1.c
// we now have a.out
./a.out
//this ran the program!
