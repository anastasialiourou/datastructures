/* Αφαίρεση ελάχιστων. Υλοποιήστε την παρακάτω συνάρτηση: ListElementType RemoveMins(ListPointer *InList);
η οποία δέχεται ως είσοδο μια λίστα (InList) και θα:
• Βρίσκει τον ελάχιστο στοιχείο της λίστας και
• αφαιρεί από τη λίστα όλους τους αριθμούς ίσους με τον ελάχιστο αριθμό και τον επιστρέφει. Η εμφάνιση του
ελάχιστου θα γίνεται στη main()*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void list_insertion(ListPointer *List, int choice1);
ListElementType RemoveMins(ListPointer *InList);

int main()
{
   ListPointer AList, PredPtr;
   int i,x,m;
   ListElementType item,min;

   CreateList(&AList);

   printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
   scanf("%d",&x);
   for(i=0;i<x;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 1: ");
     scanf("%d",&item);
     LinkedInsert(&AList,item,NULL);
   }
   printf("Traversing list\n");
   LinkedTraverse(AList);

   printf("\nRemoving min from list\n");
   min=RemoveMins(&AList);
   printf("Min was %d",min);
   printf("\nTraversing list with min removed\n");
   LinkedTraverse(AList);

	return 0;
}


void list_insertion(ListPointer *List,int choice1)
{
 	ListElementType Item;
    char ch;
    ListPointer PredPtr;
    boolean Found;

	do
    {
   	    printf("Enter a number for insertion in the list: "); scanf("%d", &Item);
   	    if (choice1==1)
   	        OrderedLinearSearch(*List, Item, &PredPtr, &Found);
   	    else
            PredPtr= NULL;
        LinkedInsert(List, Item, PredPtr);
        printf("\nContinue Y/N: ");
        do
        {
      	     scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');
}


void CreateList(ListPointer *List)

{
	*List = NULL;
}

boolean EmptyList(ListPointer List)

{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)

{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));

   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)

{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)

{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)

{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)

{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

ListElementType RemoveMins(ListPointer *List){
ListPointer CurrPtr,PredPtr;
ListElementType min;
CurrPtr=*List;
min=CurrPtr->Data;
while(CurrPtr!=NULL){
  if(CurrPtr->Data<min){
       min=CurrPtr->Data;
  }
  CurrPtr=CurrPtr->Next;
}

CurrPtr=*List;
PredPtr=NULL;
while(CurrPtr!=NULL){
  if(CurrPtr->Data==min){
  CurrPtr=CurrPtr->Next;
  LinkedDelete(List,PredPtr);
  }

    else{
    PredPtr=CurrPtr;
    CurrPtr=CurrPtr->Next;
}
}
return min;

}

