# Chapter 26
# Building Multi-File Programs with Make

As programs are made up of multiple source code files, especially when the number of files is greater than five or six, compiling such programs becomes even more of a challenge.

What the creators needed, and what they also created, was a build-system, called make. Build systems ease the burden of compiling and linking a large and complex set of source files, library files, and other components reliably in a working program.

-------------
Instead of a single command, in order to compile each file separately, we will use the following series
of commands:

```
Cc –c card.c -Wall –Werror –std=c17
cc –c hand.c -Wall –Werror –std=c17
cc –c deck.c -Wall –Werror –std=c17
cc –c dealer.c -Wall –Werror –std=c17
cc card.o hand.o deck.o dealer.o -o dealer
```

In the preceding sequence, the –c options tell the compiler to only generate an object file, which will have a <file>.o extension, where <file> is the base name of the source file. For each command, we must give the same compiler options. Doing so is good practice; mixing different compiler options can lead to some very unusual behaviors and bugs that are very difficult to track down.

Once card.o, hand.o, deck.o, and dealer.o have been created, we can then issue the final command, which links all the object files together along with the C runtime library and creates an executable program called dealer.

With a single-line command, the compiler and linker were invoked together – we never saw the intermediate object files. In the latter case, we invoked the compiler alone and then invoked the linker separately.

-------------

## Introducing the Make Utility

make is a unix program that orchestrates the building of all the parts- one or more source files, other generated files, libraries, and other processes - needed to create a valid program.

make is rule based!

By default make operates on a file named 

``` makefile ``` or ``` Makefile ```

where the rules are specified by us!

Let’s create a simple makefile with a single rule:

```
dealer: card.c hand.c deck.c dealer.c
    cc card.c hand.c deck.c dealer.c -o dealer -Wall -Werror -std=c17
```

This rule creates the target dealer and has a single action that is identical to the single-line command we’ve been using.

then just do ```make``` in terminal.

if we run ```make``` again we see this:

"make

make: 'dealer' is up to date."

I will now change this makefiles name to makefile.1

You can  indicate which makefile with this

```make -f <your makefile>```


## Using Macros

make provides a macro facility. This is similar to C’s preprocessor directives. Unlike preprocessor macros, make has a number of predefined macros. We’ll encounter just a few of them here. If you want to see the full list (and “full” is an understatement), use the following command: ```make –p```

"The two predefined macros we’ll use are CC for which compiler to call and CCFLAGS for compiler options. With this in mind, modify your makefile to define and use these macros as follows:

```
CC      = gcc
CCFLAGS = -Wall -Werror -std=c17
dealer: card.c hand.c deck.c dealer.c
    $(CC) card.c hand.c deck.c dealer.c -o dealer $(CCFLAGS)
```
"

## Using Special Macros

• $@: The filename representing the target

• $<: The filename of the first dependency

• $^: A space-separated list of all dependencies; duplicates are removed

makefile.3

## Creating Rules-Targets, Dependencies, and Actions

```
<target1> <target2> ... : <dependency1> <dependency2> ...
	<action1>
	<action2>
	...
```

Again, remember that each action line begins with <tab>. 

We can have quite a few dependencies. In our current makefile, if we change any header file, nothing happens. Lets fix this. We can make all of the header files dependencies for dealer. Lets make makefile.4 as follows:

```
CC      = gcc
CCFLAGS = -Wall -Werror -std=c17

dealer: card.c hand.c deck.c dealer.c card.h hand.h deck.h
	$(CC) $^ -o $@ $(CCFLAGS) 
```

when trying this we get an error!

We cannot use @^ with header files because make has auto rules that it tries to use to build .o files from the .c and .h files. Lets modify it as follows:

```
CC      = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS    = card.c hand.c deck.c dealer.c
INCS    = card.h hand.h deck.h

dealer: $(SRCS) $(INCLS)
	$(CC) -o $@ $(SRCS) $(CCFLAGS)
```

Above is makefile.4 ^

For very simple projects, this makefile is almost quite enough. Any change to a header would trigger a rebuild of all files. If that’s not an issue, we’d be done.

However, what if we had a larger project and not all source files depended on all header files (actually, quite common)? To get both a reliable and efficient build, we would have to add explicit rules for each object file, as follows:

```
CC      = gcc
CCFLAGS = -Wall -Werror -std=c17
LDLIBS  =
dealer: card.o hand.o deck.o dealer.o
	$(CC) -o $@ $^ $(LDLIBS)
card.o: card.c card.h
	$(CC) -c card.c $(CCFLAGS)
hand.o: hand.c hand.h card.h
	$(CC) -c hand.c $(CCFLAGS)
deck.o: deck.c deck.h card.h
	$(CC) -c deck.c $(CCFLAGS)
dealer.o: dealer.c deck.h hand.h card.h
	$(CC) -c dealer.c $(CCFLAGS)
```

We’ve added the built-in LDLIBS macro and set it to nothing in case we need it later. For now, this is only a placeholder for when we have a project that requires additional libraries.

## Creating Useful Rules That Have Only Actions

Rules that have only actions and no dependencies are useful because they can do additional work for us that might otherwise be tedious or error-prone. These are called phony rules. They are phony because they typically don’t generate anything!!!

They have a target, but that target may actually be a file in a very large project. To prevent confusion, they are preceded by the following line:
```
.PHONY: <target>
```

Here are two common utility rules. Add these to the end (after all other rules) of your makefile and save it:

```
.PHONY: clean
clean:
	rm -f *.o dealer
.PHONY: run
run:
	./dealer
```

The clean rule deleates any object file and executable file from any prior builds.

The run rule runs the built program. Here its a very simple action.

You can now invoke these rules with ```make clean``` and ```make run```. Make dealer, run it (you should see it output exactly what we saw in Chapter 24, Working with Multi-File Programs), and then make it clean.

makefile.6

``` make -f makefile.6``` to compile again...

``` make -f makefile.6 clean``` to clean

``` make -f makefile.6 run```

## Pattern Rules and %

A pattern rule is a shortcut for a file of one type – say, an object file – that is created from a source file, or a source file and a header file. A pattern rule looks like the rules we’ve seen so far, except the stem of the file is represented by the % character.

The stem of a file is that part before its extension. The stem for card.c is card. That stem is the same for card.h and card.o. So, we can replace the following rule:

```
card.o : card.c card.h
	$(cc) -c card.c
```

to the following

```
o : %.c %.h
	$(CC) -c $<
```

WAIT!!! nowhere in the new rule does the stem card appear! So... This rule can apply to any .o target that has .c and .h files as dependencies.

So now with this rule, we do not need an explicit rule for each target but can use just one rule for all files of this pattern.

## Built-in Functions

Functions in make appear quite different than C functions. They have following the general format:
```$(<function_name> , <parameter1> , <parameter2> , ... )```

So, the function and its parameters appear within $(...). The function return value, whether a string or a list, becomes the macro value.

One extremely useful function is the wildcard function, as shown here: 

```$(wildcard , *.x)```

Above, wildcard is the function and *.x is the filename pattern to match in the current directory.

The result of this function is a space-separated list of filenames that match the *.x pattern. We can then use this to build a list of, say, source files, header files, or object files. We will do this in our last solution, makefile.7.

Another frequently used function is patsubst, which searches for a pattern in text and replaces it with another pattern. This has the following form:

```$(patsubst, search-pattern , replace-pattern, text)```

This way, we can change every *.c filename to a *.o filename.

Look at makefile.7!
