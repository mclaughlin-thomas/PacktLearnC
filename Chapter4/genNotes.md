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