# Chapter 18
# Using Dynamic Memory Allocation

Not all data can be allocated statically or automatically.

Sometimes, the nuumber of items to be manipulated is not known before hand; that number can only be known at runtime and can vary.

In the last chapter we discussed automatic and static memory allocation.

Very nice feature of C: dynamic memory allocation and manipulation.

Dynamic memory is unnamed, so it can only be manipulated via pointers.

Furthermore, dynamic memory has a diferent lifetime than either automatic or static memory.

## A Brief Tour of C's memory layout

When a program is invoked to be run, the system first performs a number of steps before main is called.

A rough outline follows:

1. OS creates a new process and allocates memory space for the process
2. System device addresses and system executables are mapped into the memory space
3. The program code is loaded into the memory space
4. Global variables, static variables, and string constants are loaded into memory, these addresses will not change over the life of the program
5. Other required initialization happens. This includes setting the starting heap address and the starting heap stack address.
6. Main is called and the execution of the program begins

[image]

The C runtime then divvies up the memory given to it into segments, each for a specific use. It consists of the following segments:

----------------------

System Memory: 

Consists of system memory and system programs, as well as the addresses for all of the devices on the computer. This segment is mapped for all running programs so that there is only ever one copy of the system code in the overall system memory space. The system exclusively manages this memory.

Program Code:

This is where the compiled program is loaded and executed. Fcn definitions--the executable part of each function--are located here.

Global and Static Memory:

After program is loaded, global and static variables are allocated and initialized as well as string literals

The Call Stack:

When your program makes a function call, its parameters, any automatic variables declared within it, and its return value are allocated in this segment or pushed onto the stack. The call stack grows from high memory to lower memory, and then to the heap space, as one function calls another and that function calls yet another. When a function returns, its memory is popped off the stack (deallocated). Think of a stack of plates—you put a plate on top of the stack one after the other; then, you take them off the stack one at a time in the reverse order they were placed on the stack. 

The Heap:

When your program allocates dynamic memory, it is allocated from this segment. Heap space grows from low memory to higher memory, toward the stack space. Most allocations here are done somewhat randomly using the best fit allocation scheme. That is, the lowest available space is allocated, if possible. When that memory is deallocated, it becomes available for other allocations of the same or smaller size

----------------------

Each program lives in its own memory space.

The system space is common to all programs.

Once your program is loaded into this memory space and the global and static variables have been allcoated, the system calls the main function and starts execution.

When we call functions, the execution jumps to the memory address of that function and pushes its parameters, automatic variables, and return values onto the call stack.

When the function completes, it pops its memory off the stack and returns execution to the location in the program space where it was called.

All dynamic memory allocations are made from within the heap segment of the program memory space.

## Allocating and Releasing Dynamic Memory

Dynamic memory is allocated and deallocated only at very explicit points by a program.

This does not happen automatically or by accident or by chance; we make this happen when we call specific C Standard Library calls to allocate and deallocate dynamic memory

## Allocating Dynamic Memory

Memory allocation routines are declared in stdlib.h and are a part of the C runtime library.

There are two similar allocation routines: malloc and calloc, which are used to allocate a new block of memory from the heap.

The main difference between the two is that calloc clears the memory block it allocates whereas malloc only allocates it.

There is a third, called realloc, which resizes an existing block of heap memory.

These functions have these prototypes

```void* malloc( size_t size );```

```void* calloc( size_t count , size_t size );```

```void* realloc( void *ptr , size_t size);```

size_t is also in stlib.h

```type unsigned int size_t;```

Each of these functions returns a void* pointer to a block of memory in the heap space.

Recall that void* is a pointer type that is an unknown or generic type; a pointer of the void* type must be cast to the required pointer type before you can use that pointer.

Notice!!! malloc takes a single size parameter, while calloc takes the count AND size parameters.

The total ammount of memory allocated for malloc is size.

The total amount of memory allocated for calloc is count multiplied by size.

Very often count is 1 and size is the total memory to allocate.

If neither function can find memory in the heap space, the returned pointer will be NULL.

It is good practice to check wheter these routines were successful.

----------------

The following code shows how each allocates memory for a single Card structure:

```
Card* pCard1 = (Card*)malloc( sizeof( Card ) );
if( NULL == pCard1 ) ...                      // out of memory
error
Card* pCard2 = (Card*)calloc( 1 , sizeof( Card ) );
if( NULL == pCard2 ) ...                      // out of memory
error
```

If we wanted to allocate memory for, say, five cards, we would use the following code:

```
Card* pHand1 = (Card)malloc( 5 * sizeof( Card ) );
if( NULL == pHand1 ) ... // out of memory error
Card* pHand2 = (Card*)calloc( 5 , sizeof( Card ) );
if( NULL == pHand2 ) ... // out of memory error
```

In the second example, we got 5 cards contiguously in dynamic memory. This is similar to an array... Well it is similar. Instead of an automatic array declared with Card hand1 [5] and Card hand2 [5], both of which allocate blocks of memory to hold 5 cards on the stack, pHand1 and pHand2 both point to contiguous blocks of memory in the heap space.

Recall how array names and pointers to arrays are interchangeable. With these allocations, we can now refer to individual cards in the heap space (allocated previously) with pHand1[3] and pHand2[i]. This is simply astounding! We can access arrays in either the stack space or the heap space using array notation or pointer notation

## Releasing Dynamic Memory

When we are done with the heap memory we have allocated, we release it with a call to free().

This function returns the allocated memory to the available heap pool of memory.

This call does not have to occur within the same function where the memory was allocated.

The prototype is in stdlib.h for free and follows:

```void  free( void* ptr );```

The pointer being passed to free has to contain a value that originated from one of the calls to malloc, calloc or realloc.

There is no need to cast the void* pointer argument.

If ptr is NULL, then free does nothing.

We could release the memory allocated in last subsection by:

```
free( pCard1 );
free( pCard2 );
free( pHand1 );
free( pHand2 );
```

Allocated dynamic memory can be freed in any order; it does not have to be freed in the same order it was allocated.

## Accessing Dynamic Memory

Once we have allocated dynamic memory, we can access it via the pointer that is returned by the allocation functions as we would with any other pointer!

With each of the previous examples, we could use that dynamic memory as follows

```
InitializeCard( pCard1 , spade , ace , kNotWild );
InitializeCard( pCard2 , heart , queen , kNotWild );
```

pCard1 and pCard2 are pointers to individual Card structures. Therefore, we can use them just like we used the pointers in carddeck.c using automatic variables.

## The Lifetime of Dynamic Memory

Heap memory has a lifetime that begins when the memory is allocated.

Once allocated, that memory exists until the free function is called to release that memory.

Allocated and releasing memory is called memory management within a program.

Alternatively, all memory is deallocated when the program exits, both in terms of fixed memory and dynamic memory.

It is generally considered a sloppy practice to ignore memory management of dynamic memory, especially for large, complex programs or for programs that are likely to run for a long time.

## Special Considerations for Dynamic Allocation

Dynamic memory allocation does not come without a cost.

In this case, the cost is typically conceptual complexity.

This also takes the form of added management of heap memory and awareness of the potential pitfalls of potential memory leaks.

## Heap Memory Management

When we ignore memory management or do not address it fully, we might encounter a common dynamic memory problem known as memory leaks

## Memory Leaks

One of the main challenges of heap management is to prevent memory leaks.

A memory leak is when a block of memory is allocated and the pointer to it is lost!! :(

When the pointer to said block of memory is lost it cannot be released until the program quits.

The following is an example of a memory leak:

```
Card* pCard = (Card*)calloc( 1 , sizeof( Card ) );
...
pCard = (Card*)calloc( 1 , sizeof( Card ) );  // <-- Leak!
```
In this example, pCard first points to one block of heap memory. Later, pCard is assigned to another block of heap memory. The first block of memory is allocated but has not been freed. After pCard is given another address, there is nothing pointing to the first block of heap memory. Without a pointer to it, it cannot be accessed nor can it be freed; the first block of heap memory is leaked. 

To not have a leak, first call free before reassigning pCard as follows:

```
Card* pCard = (Card*)calloc( 1 , sizeof( Card ) );
...
free( pCard );
pCard = (Card*)calloc( 1 , sizeof( Card ) );
```

A more subtle leak is as follows:

```
struct Thing1 {
  int size;
  struct Thing2* pThing2
}
struct Thing1* pThing1 = (struct Thing1*)calloc(1,sizeof(Thing1) );
Thing1->pThing2 = (struct Thing2*)calloc( 1,sizeof(Thing2) );
...
free( pThing1 );  // <-- Leak!
```

Above, the Thing1 structure dynamically allocated Thing2 structure.

We allocated heap memory for Thing1 which is pointed to by pThing1.

We then allocated heap memory for Thing2, which is pointed to by pThing2, which is in Thing1.

Later, when we want to release pThing1, we realize the mistake.

What happened to the pointer to pThing2?

It is gone, which means whatever pThing pointed to cannot be accessed again. We have leaked the memory of pThing2.

The correct way to relase it is:

```
free( pThing1->pThing2 );
free( pThing1 );
```

A third subtle leak:

```
Card* aCard = CreateCard( ... );
PrintCard( aCard );
aCard = CreateCard( ... );  // <-- Leak!
PrintCard( aCard );
```

Here, each tie the CreateCard function is called, it allocates more heap memory.

But, when it is called multiple times, the pointer to the allocated memory can be overwritten as it is in the sequence of CreateCard and PrintCard.

The CreateCard function has added the burden on the caller of being responsible for either calling free before reusing a card or to somehow keep track of te various pointer values that are returned as follows:

```
Card* aCard = CreateCard( ... );
PrintCard( aCard );
free( aCard );
aCard = CreateCard( ... );
PrintCard( aCard );
free( aCard )
Card* pHand = (Card*)calloc( 5 , sizeof( Card* ) );
for( int i = 0 ; i<5 ; i++ )  {
  pHand[i] = CreateCard( ... );
  PrintCard( pHand[i] );
}
...
for( int i = 0 ; i<5 ; i++ )
  free( pHand[i] );
free( pHand );
```

In the second group of statements, an array of five pointers to Card is allocated. Note that this is not the same as allocating memory for five Card structures; CreateCard() does the allocation for a Card one at a time in a loop. Using a loop, five cards are created in the heap space and printed. Later, a loop is used to properly release the Card memory allocated in CreateCard(), which is pointed to by each element of pHand. Finally, pHand (a block of five pointers) is released. Simply being aware of possible memory leaks and what might cause them goes a long way when it comes to recognizing and preventing them from happening in the first place.

## The Linked List Dynamic Data Structre

[linked list image]

create linklisttester.c

## Linked List Structures

We need two structures for the linked list in the image.

A linked list header structure and a list node structure.

```
#include <stdio.h>
#include <stdbool.h>

typedef int  ListData;

//typedef struct _Node ListNode;
typedef struct _Node {
  ListNode*  pNext;
  ListData*  pData;
} ListNode;

typedef struct {
  ListNode*  pFirstNode;
  int        nodeCount;
} LinkedList;

int main( void )  {
    //cc
  
    return 0;
}
```

## Declaring Operations on a Linked List

1. Create a new LinkedList header that allocates and properly initializes the header record.

2. Create a new ListNode element that allocates and properly initializes the node element. Once created, the node still isn't part of the list.

3. Delete a node. This doesn't involve the list; typically, this will be done after a node is removed from the list.

4. Insert a node either into the front or back of the list.

5. Remove a node, either from the front or back of the list, and return that node to the caller.

6. Get the node from either the front or back of the list; this only observes the node data – it does not change the list in any way.

7. Determine whether the list is empty.

8. Determine the size of the list.

9. Print the list. This involves traversing the list and printing each node.

10. Print an individual node. This involves printing the ListData element of the node. The function to print ListData needs to be specific to the type of ListData. We will need a way to pass a print function as a parameter to this operation.

so we need these prototypes

```
LinkedList* CreateLinkedList();
bool      IsEmpty(    LinkedList* pList );
int       Size(       LinkedList* pList );
void      InsertNodeToFront(   LinkedList* pList , ListNode* pNode );
void      InsertNodeToBack(    LinkedList* pList , ListNode* pNode );
ListNode* RemoveNodeFromFront( LinkedList* pList );
ListNode* RemoveNodeFromBack(  LinkedList* pList );
ListNode* GetNode(             LinkedList* pList , int pos );
ListNode* CreateNode( ListData* pData );
void      DeleteNode( ListNode* pNode );
void      PrintList(  LinkedList* pList , void (*printData)(ListData* pData ) );
void      PrintNode(  ListNode* pNode ,void (*printData)(ListData* pData ) );
void      OutOfStorage( void );
```

## Pointers to Functions

When we have to declare a pointer to a function, we need more than just the pointer value!

We need to specify both the return type of the function and the parameter list of the funciton being pointed to...

• The return type of the function; in this case, void.

• The name of the pointer to the function; in this case, (*printData). This indicates that printData is the name pointer to a function; the function itself may have a completely different name. Given the first item, we know that the function returns void.

• The function we'll implement via this pointer to it has a parameter list, in this case, (ListData*pData).

Given these three parts, compare the function pointer declaration to the function's prototype, in this

```
case, PrintInt():
void (*printData)(ListData* pData);   // function pointer
void PrintInt(    ListData* pData);   // function prototype
void PrintInt(    ListData* pData)  { // function definition
  ...
}
```

## A Program to Test Our Linked List Structure

## Summary
"
• Doubly-linked list: A linked list that contains not only a single pointer to the next list node, but also another pointer that points to the preceding list node. The list may be traversed easily from front to back, as well as from back to front.

• Stack: A linked list where each list node is added only to the front of the list (pushed onto the stack). Subsequently, each list node is only removed from the front of the list (popped off the stack). This is also known as a Last In First Out (LIFO) list.

• Queue: A linked list where each list node is added only to the back of the list (enqueued). Subsequently, each list node is only removed from the front of the list (dequeued). This is also known as a First In First Out (FIFO) list.

• Deque: A generalized list that combines the properties of both a stack and a queue. Elements can be added or removed from anywhere in the list. Our implementation of a linked list is very close to that of a deque.

• Priority queue: A list where each list node also has a given priority. List nodes are added to the list in order of priority and removed from the list according to a priority scheduling scheme.

• Set: A collection of unique elements, in no particular order. Sometimes, they are implemented using other dynamic data structures, such as trees or hash tables.

• Map: A collection of key-value pairs, where the key is unique and is used to look up a value associated with that key. This can also be called an associative array, symbol table, or dictionary. 

• Tree: A tree simulates a hierarchical tree structure, with a single root node from which child nodes form branches. Like branches in a real tree, child nodes can only contain subchildren and cannot be linked to other branches.

• Graph: A collection of nodes connected via links. A graph is more of a general form of a tree in that it may have cycles (where a node from one branch may link to the root or a node in another branch). 
"