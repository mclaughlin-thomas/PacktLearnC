# Chapter 12
# Working With Multi-Dimensional Arrays


## Revisiting 1D arrays

An array of one dimension is a block, or contiguous grouping, of a specified data type accessed via a base name; each element is then accesed via an offset fro mthat base name. That offset is also called the index.

int array1D[5] = { 1 , 2 , 3 , 4 , 5 };

Here, array1D has five integers, initialized to the values of 1 through 5 for the values at the zeroth through fourth offsets. array1D is a block of five integers; they are contiguous (or side by side) so that the block takes up 5 * sizeof(int) bytes of memory. The array has five elements, with offsets from the base to each element in the range of 0..4.

## Declaring arrays of two dimensions

Just as in declaring a 1D array, [ and ] are used to specify each dimension. array2D is declared using numeric literals for its two dimensions, as follows:

int array2D[4][5];

## Initializing arrays of two dimensions

We can initialize array2D at the declaration stage in several ways, as follows:

int array2D[4][5] = {0};

array2D is initialized with all of its elements set to 0. Note that we can initialize this  array because it is a constant-length array (CLA) definition. 

