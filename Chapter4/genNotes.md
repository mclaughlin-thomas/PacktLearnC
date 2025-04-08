# Chapter 4
# Using Variabless and Assignments

The values a program manipulates must both be accessible and assignable.

Accessible means that a value must reside somewhere in computer memory and should be retrievable.

Assignable means that a given value, or a result of a calculation, must be stored somewhere in memory to be retrieved and/or changed later.

Each value that can be accessed and assigned has a data type and a named location where it is stored. --> These can be either variables or constants.

Variables hold values that are accessible and assignable. Their values may change during the execution of a program.

Constant variables are variabels that don't chage their value once they are given a value.

Variables, whether they are constant or variable, receive their values via assignment.

Assignment is a simple expression.

Literal values or literals are values that are encoded in the program and can never change.

## Understanding Data Types and Values

When a value is given an explicit type, the compiler assigns a type to that value. A value of one type can also be converted into another type, either implicitly by how it is used or explicitly with typecasting.

## Introducing Variables

A variable is a location in memory that holds a value of a specified type that can vary over the life of the variable, identified by its name!!!

When a variable is defined with both a type and an identifier, its life begins!

The variables life ends, that is when it identifies is deallocated- when the block it was declared ends.

Three components essential:
1. A unique identifier or name
2. Type
3. A value

A variable is created by declaring it. This is also called defining a variable.

When we declare a variable, we specify the data type to be stored in the variable and the name, or identifier of the variable. This identifier is the location of the value in memory. When we declare a variable with just a data type and identifier, it does not have a known value yet.

A variable should always have some known starting value, even if it is zero.

The fist value that is fiven to a variable is called initialization.

Initialization can occur when the value is created or any time before we access the variable for use. If we do not give the variable an initial value, we can never be sure what value it might have from one access to the next.

## Naming Variables

An identifier, or name, in C is a sequence of capital letters and lowercase lessers and digits and underscore.

Identifiers cannot begin with a digit.

## Introducing Explicit Types of Variables

The format of a variable declaration is as follows:

type identifier;

The values of the variables do not have any value yet.. That we made.

## Using Explicit Typing with Initialization

A better format for a variable decvlaration is one hwere the variable is initialized or given a starting value when it is declared, such as the following:

type identifier1 = value1;

type identifier2 = value2;

Can also do this:

type identifier1 = value1 , identifier2 = value2 , ... ;

Initialization is a form of assignment; we are assigning a starting value to each variable.

## Literal Constants

## Defined Values

Another way to define constants is to use the #define preprocessor directive.

This takes the form of:

#define symbol text

Where symbol is an identifier and text is a literal or a previously defined symbol. Symbol names are typically in all upercase and underscores are used to distinguish them from variable names.

----

#define INCHES_PER_FOOT 12

#define FEET_PER_YARD    3

feet  = inches / INCHES_PER_FOOT;

yards = feet / FEET_PER_YARD;

----


When the preprocessing phase of compilation encounters a definition such as this, it carries out a textual substitution. It simply replaces the symbol with the text.

There is no type associated with the symbol and there is no way to verify that the actual use of a symbol matches its intended use.

For this reason, the use of these kinds of constants is discouraged.

Because #define enables textual substitution, there are many other ways it can be and is used. This feature is so powerful it must be used with utmost caution!

Many of the original reasons for relying on the preprocessor are no longer valid.

## Explicitly Typed Constants

C has a much safer way to clear named constants, other than by using the preprocessor.

This is done by adding the const keyword to a variable declaration.

const type identifier = value;

The constant variable loses its ability to change after the statement is evaluated.


----

const float kInchesPerFoot = 12.0;

const float kFeetPerYard   =  3.0;    

feet  = inches / kInchesPerFoot;

yards = feet / kFeetPerYard;

----

This is considered safer because the constant's type is known and any incorrect use of this type or invalid conversion from this type to some other type will be flagged by the compiler.

## Naming Constant Variables

:/

## Using Types and Assignments

Now we have variables to hold values of a specified type that we can also retrieve and manipulate by their identifiers.

:/

## Assignment by the Function Return Value

A function is a statement that can return the result of its execution to its caller.

When the function has a data type that is not void, the function is replaced with its returned value, which can then be assigned to a variable of a compatible type.

----

double inchesToFeet( double );

int main( void )  {

  double inches = 1024.0;

  double feet = 0.0;

  feet = inchesToFeet( inches );

  printf( "%12.3g inches is equal to %12.3g feet\n" , inches , feet );

  return 0;

}

----

## Questions

Answer the following questions to test your knowledge of this chapter:

1. What are the three components of a variable?

Identifier, Value, Type

2. What are the various types of constant values?

Literal Constants (like 3.14, 'A')

Defined Constants (things created with #define)

Explicitly Typed Constants (declared with const when defining variable)