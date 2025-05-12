#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf( "List has %2d entries: [" , Size( pList ) );
    
    ListNode* pCurr = pList->pFirstNode;

    while( NULL != pCurr )  {
        PrintNode( pCurr , printData );
        pCurr = pCurr->pNext;
    }
    printf( "]\n" );
}