# Chapter 5
# Exploring Operators and Expressions

% modulo, provides integer remainder of the division of two ints.

C does not have an exponent operator. We have to use the pow library function.

To use that function you must include the math.h header file.

We can be tempted to use the preprocessor (#define ...), but we shouldnt. If you find yourself being pulled by such temptations, take a look at ch24: Using Preprocessor Effectively.

4 Types of Invalid Outputs
- NaN
- Infinity
- Underflow
- Overflow

NaN occurs when the result of operation is an undefined or unrepresentable number.

Inf occurs when the result of an operation is inexpressibly large number or infinity.

A NaN result also occurs wen the data types are real but the result is a complex number. A NaN can also occur where discontinuities appear in inverse trigonometric functions.

infnan.c

## Understanding Underflow
Underflow occurs when the result of an arithmetic operation is smaller than the smallest value that can be represented by the type specified.

For ints, if its unsigned, that means less than 0.

## Understanding Overflow

Overflow ocurs when the result of an arithmetic operation is greater than the value that can be represented for the type specified.

This could occur with both the addition and multiplication of two extremely large numbers or the division of very large numbers by an extremely small number-.

## Exploring Type Conversion
C provides mechanisms that allow you to convert one type of value into another type of the same value. When there is no loss of precision – in other words, when the conversion of values results in the same value – C operates without complaining. But, when there is a possible loss of precision, or if the resulting value is not identical to the original value, then the C compiler does not provide any such warning.

So what happens when we do something like int * float?

When C encounters an expression of mixed types, it first performs an implicit conversin of the smallest data type, in bytes to match the number of bytes in the largest data type size, in bytes. The conversion occurs in such a way that the value with the narrow range would be converted into the other with a wider range of values.

## Using Explicit Type Conversion - Casting

Implicit casting we can get unexpected results. To avoid this, we can use an explicit, but temporary, type change. We do this by casting.

When we explicitly cast a variable to another type, its value is temporarily converted into the desired type and then used. The type of the variable and its value does not change!

Any expression can be prefixed by (type) to change its explicit type to the indicated type for the lifetime of the expression. The lifetime is only a single statement.

casting.c

## Introducing Operations on Characters

- char - char yields int: distance between characters
- char + int yields char: The char that is the specified distance from OG character
- char - int yields char: The char that is the specified distance from OG character

## Logical Operators

A boolean value is either true or false.

To handle boolean values, C implicitly converts any zero value into the boolean false, and implicitly converts any non-zero value into the Boolean true value. This implicit conversion comes in handy a lot, but it has to be used with care.

However, when we use #include <stdbool.h>, the official bool types and true and false values are available to us.

Boolean Operators

|| Binary logical OR operator

&& Binary logical AND operator

^ Binary logical XOR operator

! Uniary logical NOT operator

These are logical operators whose results aree always boolan true (non-zero), or false (exactly zero).

## Bitwise Operators

Bitwise operators manip bit patterns.

&: Bitwise AND

|: Bitwise OR

^: Bitwise XOR

<<: Bitwise shift left

>>: Bitwise shift right

~: Bitwise complement

## Conditional Operator

Ternary operator:

testExpression ? ifTrueExpression : ifFalseExpression

## Compound Operators

+= 

-=

*=

...

bitwise ones too

<<=

&=

...

## Postfix versus

prefixed, ++ comes before expression is evaluated

postfixed, ++ comes after the expression is evaluated

prepost.c

## Order of Operations and Grouping

Group of operations, which one goes first? This is known as Order of Evaluation. Not all operations are left to right