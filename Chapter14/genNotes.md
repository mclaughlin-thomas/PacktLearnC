# Chapter 14
# Understanding Arrays and Pointers

C arrays and pointers are closely related, in fact they are often interchangeable. But arrays and pointers are not identical.

## Understanding Array Names and Pointers

We can accesss arays via indices, but sometimes it can be more convenient to access array elements via a pointer equivalent.

--------------

const int arraySize = 5;

int       array[5] = { 1 , 2 , 3 , 4 , 5 };

int*      pArray1  = NULL;

int*      pArray2  = NULL;

We declared a contiguous block of arraySize or 5, which are elements that are integers.

We do not use arraySize in the array declaration because that would make the array a variable-length array (VLA) that annot be initialized this way.

Theres two pointers to integers there too pArray1 and pArray2.

The name of the array represents the location or address of its zeroth element.

This should sound similar to pointers—in fact, it is. Without [ and ], the array name is treated just like a pointer.

- 

It is better to think of the array name as a special variable location that is the beginning of the array block. Because the array name alone is treated as an address, we can do the following:

pArray1 = array;

The value of pArray1 is now the address of the zeroth element of array[].

We can also be more explicit when we assign the address of the zeroth element, as follows:

pArray2 = &array[0];

Here, the target of pArray2 is the zeroth element of array[]. To be even more explicit, we could have written this with parentheses, as follows:

pArray2 = &(array[0]);

Because of precedence rules, parentheses are not needed; the operator precedence of [ ] is higher than & and is, therefore, evaluated first.

## Understanding Array Elements and Pointers

Individual elements of an array can be accessed either with array notation or via pointers.

array[0] = 1;  // first element (zeroth offset)

easy way...

## Accessing Array Elements Via Pointers

*(pArray1 + 0) = 1;  // first element (zeroth offset)

*(pArray1 + 1) = 2;  // second element (first offset)

*(pArray1 + 2) = 3;  // third element (second offset)

Since pArray is a pointer, the * go-to address notation must be used to access the value at the address of that pointer. In the second through fifth elements, we must first add an offset value and then go to that computed address.

When you write pArray1 + 1, you're not adding 1 byte — you're adding 1 element, and the compiler automatically scales that by the size of the type the pointer points to.

pArray1 + 1

What this actually means under the hood is:

(pArray1 + 1 * sizeof(int))

## Operations on Arrays Using Pointers

### Using Pointer Arithmetic

An integer value in pointer arithmetic represents the element to which the pointer points.

When an integer is added to a pointer, the integer is automatically converted into the size of the pointer element in bytes and added to the pointer.

Even though pointers are nearly identical to integers—they are positive, whole numbers that can be added, subtracted, and compared—they are treated slightly differently from integers when pointer arithmetic is performed. 

pointer + integer → pointer

integer + pointer → pointer

pointer – integer → pointer

pointer – pointer → integer

### Using the Increment Operator

*pArray1++ = 1;  // first element (zeroth offset)

*pArray1++ = 2;  // second element (first offset)

Because we use the ++ postfix, pArray is incremented after the value of pArray is used in the statement.

### Passing Arrays as Function Pointers Revisited

So now we can understand how array names and pointers to arrays are passed in function arguments. If arrays wer passed by values in a function parameter, the entire array might then be copied into the function body and this is inefficient.

However, the array itself is not passed by a value; the reference to it is copied.

The reference is then used within the function to access array elements.

This reference is the pointer value - an address!

So the array values themselves are not copied, only the address of the zeroth element.

C then converts the array named location (without []) to a pointer value, &array[0], and then uses that to access array from within the function body.

### Interchangeability of Array Names and Pointers

The real power of being able to interchange an array name with a pointer is when we use an array name (or a pointer to an array) as a parameter to be passed into a function.

In this section, we will explore the four possible ways of using an array in a function parameter, as follows:

• Pass an array name in a parameter and then use array notation in the function.

• Pass a pointer to an array in a parameter and then use the pointer in the function.

• Pass an array name in a parameter and use that as a pointer in the function.

• Pass a pointer to an array in a parameter and use array notation in the function.

Look @ array_pointers_funcs.c !

## Introducing an Array of Pointers to Arrays

Before finishing this chapter, it is worth introducing the concept of an array of pointers to arrays. This may be thought of as an alternate 2D array. 

-------------

int* arrayPtr[3] = {NULL};

...

int array1[5];

int array2[5];

int array3[5];

arrayPtr[0] = array1;

arrayPtr[1] = array2;

arrayPtr[2] = array3;

3x5 matrix!

-------------


## Questions


1. Are array notation and pointers identical?

   No, but they are close.

2. When you increment an array index by 1, what does that do?

   The next element is used!

3. When you increment a pointer to an array element by 1, what does that do?

   The address is incremented by the size of the data type of the array element.

4. Is this array always contiguous: int arr[3][5]?

   Yep, when declared this way they will be contiguous.

5. Are the elements of an array of pointers to other arrays always contiguous?
   
   The elements of an array of pointer to other array may be contiguous but that would only be by chance. There is no guarantee that subarrays will be contiguous to each other.

6. If we pass a pointer to an array as a function parameter, must we use pointer notation to 
access the elements of the array?

   No, we can access the array elements using a pointer or array notation.

7. Does C remember the size of any array?

   Nope