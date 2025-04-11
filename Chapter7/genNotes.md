# Chapter 7
# Exploring Loops and Iterations

There are two general types of continuation expressions used for looping statements, as follows:
• Counter-controlled looping, where the number of iterations is dependent upon a count of some kind. The desired number of iterations is known beforehand. The counter may be increasing or decreasing.

• Condition- or sentinel-controlled looping, where the number of iterations is dependent upon some condition to remain true for the loop to continue. The actual number of iterations is not known. A sentinel is a value that must attain a certain state before the loop completes.

This chapter mainly covers counter-controlled looping. When we get to chapter on input from files we will get into sentinel-controlled looping.

C has some additional looping control mechanisms like break.

## for

The for()… statement has the following syntax:

for( counter_initialization ; continuation_expression ; counter_increment ){

statement_body

} 

## do while

The do…while() statement has the following syntax:

do statement_body while( continuation_expression );

The only difference between this and while is that in the do while the statement_body is executed before continuation_expression.

## Understanding Unconditional Branching - the dos and don'ts of goto
goto statement is an immediate and unconditional transfer of program execution to the specified label within a function block. goto causes execution to jump to the label.

The goto statement has two parts:

goto label_identifier;

The creators of C felt there was occasionally, albeit rarely, a need for goto, and so they left it in the language. goto in C is restrained in terms of where it can "go to"... Funny guy here.

Unlike the old days you cannot use goto in a label inside another function.

You CANNOT use goto out of the current function.

You CANNOT use goto in another program

You CANNOT use goto somewhere in the runtime library or into system code.

You CAN use the goto statement to only jump to a label within the same function.

goto is handy in the case of deeply nested if else statements or deeply nested looping statements where you just need to get out and move on. It should be considered rarely necessary. It can be handy at times in high-performance computing. So, we'll respect it.

-----------------

t sumNviaGoto_Do( int N ) {

 int sum = 0;

 int num = 0;

begin_loop:

 sum += (num+1);

 num++;

 if( num < N ) goto begin_loop; // loop!

 // else fall-through out of loop.

end_loop:

 return sum;

}

-----------------

use goto wisely!

## Further Controlling Loops with break and continue
Instead of using goto to get out of sticky situations inside deeply nested statements, the creators of C created two very controlled goto-like mechanisms. These are break and continue.

break jumps out of and to the end of the enclosing statement block.

continue is used for looping which goes immediately to the next iteration of the looping statement, skipping any statements that would otherwise be executed in the loop after the continue mechanism.

Care must be exercised when using the continue statement to ensure that the loop counter update is performed and not bypassed due to the continue statement.

