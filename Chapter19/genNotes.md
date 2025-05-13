# Chapter 19
# Exploring Formatted Output

## Overview

In this chapter, we will explore, primarily through examples, the various ways
in which printf() can format values.

## Printing Pointer Values

The last bit of code prints out the value of a pointer using two different methods, as follows:

```
printf( "\nPointer Output\n" );
printf( " %%p [%p] pointer\n" , &smallInt );
printf( " %%#lx [%#lx] using hex\n\n" , (unsigned long)&smallInt );
```
## Summary

I skipped a lot here. Appears boring.