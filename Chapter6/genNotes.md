# Chapter 6
# Exploring Conditional Program Flow

The following topics will be covered in this chapter:

• Understanding various conditional expressions

• Using if()… else… to determine whether a value is even or odd

• Using a switch()… statement to give a message based on a single letter

• Determining ranges of values using if()… else if()… else if()… else…

• Exploring nesting if()… else… statements

• Understanding the pitfalls of nesting if()… else… statements

## Using a switch()

Syntax of switch

----------------------

switch( expression ) {

 case constant-1 : statement-1

 case constant-2 : statement-2

 …

 case constant-n : statement-n

 default : statement-default

}

----------------------


The next part of the statement is called the case-statement block, which contains one or more case clauses and an optional default: clause. In the casestatement block, the result is compared to each of the constant values in each case clause. When they are equal, the code pathway for that case clause is evaluated. These are indicated by the case <value>: clauses. When none of the specified constants matches the result, the default pathway is executed, as indicated by the default: clause.

Always a good idea to have the default clause even though it is optional.