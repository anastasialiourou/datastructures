/*Συνένωση 2 Α.Σ.Λ. σε μία (πχ 1η ΑΣΛ: 4, 3, 2, 1 και 2η ΑΣΛ: 8, 7, 6, τελική ΑΣΛ: 6, 7, 8, 1, 2, 3, 4).*/
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
void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);


void menu(int *choice);
void list_insertion(ListPointer *List, int choice1);

int main()
{
   ListPointer AList,BList,FinalList,PredPtr;

   CreateList(&AList);
   CreateList(&BList);
   CreateList(&FinalList);
   ListElementType item;
   int i,x,y;

   printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
   scanf("%d",&x);
   for(i=0;i<x;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
     scanf("%d",&item);
     LinkedInsert(&AList,item,NULL);
   }
   printf("LISTA 1:\n");
   LinkedTraverse(AList);
   printf("\n");

    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
   scanf("%d",&y);
   for(i=0;i<y;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
     scanf("%d",&item);
     LinkedInsert(&BList,item,NULL);
   }
     printf("LISTA 2:\n");
   LinkedTraverse(BList);
    printf("\n");

printf("SYNENWMENH LISTA:\n");
concat_list(AList,BList,&FinalList);
LinkedTraverse(FinalList);

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


void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList){
ListPointer CurrPtr;

CurrPtr=AList;

while(CurrPtr!=NULL){
LinkedInsert(FinalList,CurrPtr->Data,NULL);
CurrPtr=(*CurrPtr).Next;;
}

CurrPtr=BList;

while(CurrPtr!=NULL){
LinkedInsert(FinalList,CurrPtr->Data,NULL);
CurrPtr=(*CurrPtr).Next;
}

}
