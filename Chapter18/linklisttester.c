#include <stdio.h>         // for printf() and fprintf()
#include <stdlib.h>        // for calloc() and free()
#include <stdbool.h>       // for bool, true, false

typedef enum  {// for testing
  eFront = 0 , // for testing
  eBack // for testing
} eWhere; // for testing
typedef enum  { // for testing
  eLook = 0 , // for testing
  eInsert , // for testing
  eDelete // for testing
} eAction; // for testing

typedef int  ListData;

typedef struct _Node ListNode;
typedef struct _Node {
  ListNode*  pNext;
  ListData*  pData;
} ListNode;

typedef struct {
  ListNode*  pFirstNode;
  int        nodeCount;
} LinkedList;


LinkedList* CreateLinkedList();
bool      IsEmpty(    LinkedList* pList );
int       Size(       LinkedList* pList );
void      InsertNodeToFront(   LinkedList* pList , ListNode* pNode );
void      InsertNodeToBack(    LinkedList* pList , ListNode* pNode );
ListNode* RemoveNodeFromFront( LinkedList* pList );
ListNode* RemoveNodeFromBack(  LinkedList* pList );
ListNode* GetNode(             LinkedList* pList , int pos );
ListNode* CreateNode( ListData* newPData );
void      DeleteNode( ListNode* pNode );
void      PrintList(  LinkedList* pList , void (*printData)(ListData* pData ) );
void      PrintNode(  ListNode* pNode ,void (*printData)(ListData* pData ) );
void      OutOfStorage( void );
void PrintInt( int* i );

ListData* CreateData( ListData d ); // for testing
void TestPrintOperation( LinkedList* pLL , eAction action , ListData data , eWhere  where ); // for testing
ListData TestExamineNode( LinkedList* pLL , eWhere where ); // for testing
ListData TestRemoveNodeAndFree( LinkedList* pLL , eWhere where); // for testing
void TestCreateNodeAndInsert( LinkedList* pLL , ListData data , eWhere where ); // for testing

int main( void )  {
    LinkedList* pLL = CreateLinkedList();
    printf( "Input or operation         "
            "Current state of linked list\n"
            "=========================  "
            "======================================");
    printf( "\nUsing input{ 1  2  3  4 } " );
    PrintList( pLL , PrintInt );
    int data1[] = { 1 , 2 , 3 , 4 };
    for( int i = 0 ; i < 4 ; i++)  {
        TestPrintOperation( pLL , eInsert , data1[i] , eFront );
    }

    TestPrintOperation( pLL , eLook   , 0   , eFront );
    TestPrintOperation( pLL , eDelete , 0   , eBack );
    printf( "\nUsing input{ 31 32 33 }   " );
    PrintList( pLL , PrintInt );
    int data2[] = { 31 , 32 , 33 };
    for( int i = 0 ; i < 3 ; i++)  {
        TestPrintOperation( pLL , eInsert , data2[i] , eBack );
    }

    TestPrintOperation( pLL , eLook   , 0   , eBack );

    int count = pLL->nodeCount;
    for( int i = 0 ; i < count ; i++)  {
        TestPrintOperation( pLL , eDelete, 0 , eFront );
    }
}

LinkedList* CreateLinkedList(){
    // Here we use the calloc function to allocate memory for the LinkedList header and initialize
    // all the values in the structure to 0.
    // A pointer to that memory is returned unless calloc fails!
    LinkedList* pLL = (LinkedList*) calloc (1, sizeof(LinkedList));

    if(pLL == NULL){
        OutOfStorage();
    }

    return pLL;
}

void OutOfStorage( void )  {
  fprintf(stderr,"### PRETTY BAD RUNTIME ERROR ### No Memory Available :(" );
  exit( EXIT_FAILURE );
}

bool  IsEmpty( LinkedList* pList )  {
  return( 0 == pList->nodeCount );
}

int  Size( LinkedList* pList )  {
  return pList->nodeCount;
}

void InsertNodeToFront(   LinkedList* pList , ListNode* pNode ){
    ListNode* pNextNode = pList->pFirstNode;
    pList->pFirstNode = pNode;
    pNode->pNext= pNextNode;
    pList->nodeCount++;
}

void InsertNodeToBack( LinkedList* pList , ListNode* pNode )  {
    if( IsEmpty( pList ) )  {
        pList->pFirstNode = pNode;
    }
    else {
        pNode->pNext = NULL;  // Ensure it's the last node in the list after we insert...
        ListNode* pDummyIterator = pList->pFirstNode ;
        while( NULL != pDummyIterator->pNext )  {
            pDummyIterator = pDummyIterator->pNext;
        } // This yeilds last node, lost node points to NULL
        pDummyIterator->pNext  = pNode;
    }

    pList->nodeCount++;
}

ListNode*  RemoveNodeFromFront( LinkedList* pList )  {
    if( IsEmpty( pList )){
        return NULL; // cannot remove anything...
    }
    ListNode* pCurr   = pList->pFirstNode; // grab pointer to first node
    pList->pFirstNode = pList->pFirstNode->pNext; // make that pointer to the first node point that nodes next!
    pList->nodeCount--;

    return pCurr;
}

ListNode* RemoveNodeFromBack( LinkedList* pList)  {
    if( IsEmpty( pList ) )  {
        return NULL;
    }
    else {
        ListNode* pCurrent = pList->pFirstNode;
        ListNode* pCurrentsPrevious = NULL;

        while( NULL != pCurrent->pNext )  {
            pCurrentsPrevious = pCurrent;
            pCurrent = pCurrent->pNext;
        } // This yeilds last node, lost node points to NULL
        pCurrentsPrevious->pNext = NULL;
        pList->nodeCount--;
        return pCurrent;
    }
}

ListNode* GetNode( LinkedList* pList , int pos )  {
    ListNode* pCurr = pList->pFirstNode;
    if( NULL == pCurr )  {
        //return pList->pFirstNode; // or pCurr, why do that author?
        return pCurr;
    }
    else if ( pos == 0 )  { // I DO NOT BELIEVE WE NEED THIS ELSE IF
        //return pList->pFirstNode;
        return pCurr;
    } // I DO NOT BELIEVE WE NEED THIS ELSE IF
    else {
        int i = 0;
        while( NULL != pCurr->pNext )  {
            if( i == pos ){
                return pCurr;
            }
            i++;
            pCurr = pCurr->pNext;
        }
        return pCurr; // last one? What if node position is not in list...
    }
}

ListNode*  CreateNode( ListData* newPData )  {
    ListNode* pNewNode = (ListNode*) calloc( 1 , sizeof( ListNode) );
    if( NULL == pNewNode ){
        OutOfStorage();
    }
    pNewNode->pData = newPData;  
    return pNewNode;
}

void  DeleteNode( ListNode* pNode )  {
    free( pNode->pData );
    free( pNode );
}

void  PrintList( LinkedList* pList , void (*printData)(ListData* pData ) )  {
    // "printData is a pointer to a function that takes a ListData* and returns void."
    // So inside PrintList, you can call printData(pData) on any node's data — and that
    // function will do whatever printing logic you defined elsewhere.
    // this is the function pointer: void (*printData)(ListData* pData);
    // In other words: printData is not a variable storing data — it’s 
    // a variable storing code (a reference to a function).
    printf( "List has %2d entries: [" , Size( pList ) );
    
    ListNode* pCurr = pList->pFirstNode;

    while( NULL != pCurr )  {
        PrintNode( pCurr , printData );
        pCurr = pCurr->pNext;
    }
    printf( "]\n" );

    // void PrintList(LinkedList* pList, void (*printData)(ListData* pData));
    // This declares that PrintList takes a function pointer printData, which points to a function that accepts ListData* (a pointer to the data type inside your nodes) and returns void.

    // Calling PrintList:
    // When you call PrintList(myList, PrintInt);, you're passing PrintInt as the second argument.

    // What happens here?
    // PrintInt is the name of a function, but in C, the name of a function is a pointer to that function.

    // So, PrintInt is actually a pointer to the function PrintInt, which matches the type expected by printData.
}

void PrintNode( ListNode* pNode , void(*printData)( ListData* pData ) )  {
  printData( pNode->pData );
}

void PrintInt( int* i )  {
  printf( "%2d ", *i );
}

ListData* CreateData( ListData d )  {
    ListData* pD = (ListData*)calloc( 1 , sizeof( ListData ) );
    if( pD == NULL ){
        OutOfStorage();
    }
    *pD = d;
    return pD;
}

void TestPrintOperation( LinkedList* pLL , eAction action , ListData data , eWhere  where )  {
switch( action )  {
    case eLook:
      data = TestExamineNode( pLL , where );
      printf( "Get %s node, see [%2d]. " ,
               where==eFront ? "front" : " back" , data );
      break;
    case eInsert:
      printf( "Insert [%2d] to %s.     " , data ,
               where==eFront ? "front" : " back" );
      TestCreateNodeAndInsert( pLL , data , where );
      break;
    case eDelete:
      data = TestRemoveNodeAndFree( pLL , where );
      printf( "Remove [%2d] from %s.   " , data ,
               where==eFront ? "front" : " back" );
      break;
    default:
      printf( "::ERROR:: unknown action\n" );
      break;
  }
  PrintList( pLL , PrintInt );
}

ListData TestExamineNode( LinkedList* pLL , eWhere where )  {
    ListNode * pNode;
    switch( where ) {
        case eFront: 
            pNode = GetNode( pLL , 0 );
            break;
        case eBack: 
            pNode = GetNode( pLL , pLL->nodeCount );
            break;
    }
    ListData data = *(pNode->pData);
    return data;
}

ListData TestRemoveNodeAndFree( LinkedList* pLL , eWhere where)  {
  ListNode * pNode;
  switch( where ) {
    case eFront:
        pNode = RemoveNodeFromFront( pLL );
        break;
    case eBack: 
        pNode = RemoveNodeFromBack(  pLL );
        break;
  }
  ListData data = *(pNode->pData);
  DeleteNode( pNode );
  return data;
}

void TestCreateNodeAndInsert( LinkedList* pLL , ListData data , eWhere where )  {
    ListData* pData = CreateData( data );
    ListNode* pNode = CreateNode( pData );
    switch( where ) {
    case eFront:
        InsertNodeToFront( pLL , pNode );
        break;
    case eBack:
        InsertNodeToBack(  pLL , pNode );
        break;
    }
}