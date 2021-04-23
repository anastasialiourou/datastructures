/*α υλοποιηθεί η συνάρτηση Search με το παρακάτω πρωτότυπο: boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,
ListPointer *PredPtr);
η οποία θα δέχεται μια Συνδεδεμένη Λίστα (ΣΛ) υλοποιημένη με πίνακα (παράμετροι FreePtr, List, Node) και ένα στοιχείο
Item και θα επιστρέφει boolean τιμή η οποία δείχνει αν βρέθηκε ή όχι το αναζητούμενο στοιχείο Item στη ΣΛ και τη θέση
(PredPtr) του στοιχείου που είναι προηγούμενο του Item, ώστε η ΣΛ που θα προκύψει μετά την εισαγωγή ή τη διαγραφή
του στοιχείου Item να είναι ταξινομημένη (χρήση της Search πριν την εισαγωγή ή τη διαγραφή στοιχείου στη ΣΛ). Η
εισαγωγή στοιχείων στην Σ.Λ. γίνεται επαναληπτικά και ελέγχεται από το μήνυμα ‘Continue Y/N:’ (δες στιγμιότυπο
εκτέλεσης). Στη ΣΛ καταχωρούνται ακέραιοι. H συνάρτηση Search θα κληθεί 2 φορές μια για στοιχείο που υπάρχει στη ΣΛ
και μια για στοιχείο που δεν υπάρχει στη ΣΛ. Αν το στοιχείο βρεθεί θα εμφανίζει το μήνυμα «The number is in the list and its
predecessor is in position» και την τιμή της PredPtr, διαφορετικά θα εμφανίζει το μήνυμα «The number is not in the list». Το
πρόγραμμα θα πρέπει να εκτελεί κατά σειρά τις παρακάτω λειτουργίες και οι κλήσεις των συναρτήσεων θα γίνονται από τη
main().
A. Αρχικοποίηση storage pool
B. Δημιουργία ΑΣΛ (μέγιστο μέγεθος 10)
C. Εμφάνιση της storage pool
D. Εμφάνιση των στοιχείων της ΣΛ
E. Εισαγωγή στοιχείων στην ΣΛ. Μετά από κάθε εισαγωγή στοιχείου στη ΣΛ αυτή θα πρέπει να παραμένει ταξινομημένη
σε αύξουσα διάταξη (χρήση της Search πριν την εισαγωγή στοιχείου στη ΣΛ)
F. Εμφάνιση της storage pool
G. Εμφάνιση των στοιχείων της ΣΛ
H. Έλεγχος εάν η ΣΛ είναι άδεια. Αν η ΣΛ είναι άδεια εμφανίζει μήνυμα «Empty List» διαφορετικά «Not an Empty List»
I. Έλεγχος εάν η ΣΛ είναι γεμάτη. Αν η ΣΛ είναι γεμάτη εμφανίζει μήνυμα «Full List» διαφορετικά «Not a Full List»
J. Αναζήτηση ενός στοιχείου στη ΣΛ (για στοιχείο που υπάρχει στη ΣΛ και για στοιχείο που δεν υπάρχει).*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,ListPointer *PredPtr);

int main()
{
    boolean found;
    int Apos;
    ListElementType AnItem;
    NodeType Node[NumberOfNodes];
    ListPointer list,FreePtr,PredPtr;
    char ch;
    int i;

//a
InitializeStoragePool(Node, &FreePtr);

//b
CreateList(&list);

//c
printf("---------------Question C--------------------\n");
printf("--------------Storage pool-------------------\n");

printAll(list,FreePtr,Node);

//d
printf("---------------Question D--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(list,Node);

//E
printf("---------------Question E--------------------\n");
do{
printf("Give a number: ");
scanf("%d",&AnItem);

found=Search(FreePtr,list,Node,AnItem,&PredPtr);
Insert(&list, Node,&FreePtr,PredPtr,AnItem);

printf("Continue Y/N:");

do{
  scanf("%c",&ch);
}while(toupper(ch)!='N' && toupper(ch)!='Y');


}while(toupper(ch)!='N');


//f
printf("---------------Question F--------------------\n");
printAll(list,FreePtr,Node);

//g
printf("---------------Question G--------------------\n");
TraverseLinked(list,Node);

//h
printf("---------------Question H--------------------\n");
if(EmptyList(list)){
        printf("Empty List");
}
else printf("Not an Empty List");

//i
printf("\n---------------Question I--------------------\n");
if(FullList(list)){
        printf("Full List");
}
else printf("Not an Full List");
//j
printf("\n---------------Question J--------------------\n");
printf("-----------------Search for a number-----------------\n");
for(i=0;i<2;i++){
printf("Give a number ");
scanf("%d",&AnItem);
found=Search(FreePtr,list,Node,AnItem,&PredPtr);

if(found==TRUE){
    printf("The number is in the list and its predecessor is in position %d\n",PredPtr);
}
else printf("The number is not in the list\n");
}





	return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)

{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)

{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)

{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)

{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])

{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)

{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)

{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)

{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])

{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr)
{
ListPointer CurrPtr;
boolean found=FALSE;
boolean stop=FALSE;
*PredPtr=NilValue;

if (!EmptyList(List)){
CurrPtr =List;
while ((CurrPtr != NilValue)&&(!stop))
{
if (Node[CurrPtr].Data>=Item)
{
 stop=TRUE;
found=(Node[CurrPtr].Data == Item);
 }
  else
{
*PredPtr=CurrPtr;
 CurrPtr=Node[CurrPtr].Next;
 }
}
}
else
found=FALSE;
  return found;
}




