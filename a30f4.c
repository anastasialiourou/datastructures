/*Σε μια ΣΛ θέλουμε να καταχωρούμε τον Αριθμό Μητρώο (int) και τον βαθμό (float) ενός μαθητή. Τροποποιήστε τον
τύπο ListElementType ώστε να αποθηκεύει τον ΑΜ και το βαθμό του μαθητή. Κάντε τις κατάλληλες τροποποιήσεις όπου
είναι απαραίτητο, στις συναρτήσεις που θα αντιγράψετε από τα αρχεία L_ListADT.c & L_ListADT.h. Θέλουμε να εντοπίζουμε
και να εμφανίσουμε τα στοιχεία των μαθητών που έχουν τον ελάχιστο βαθμό. Να υλοποιήσετε τη συνάρτηση FindMins που
θα δέχεται 2 παραμέτρους: τη ΣΛ με τα στοιχεία των μαθητών και μια στοίβα όπου θα καταχωρεί τους ΑΜ όλων των
μαθητών με τον ίδιο ελάχιστο βαθμό, και θα επιστρέφει την τιμή του ελάχιστου βαθμού. To πρωτότυπο της συνάρτησης:
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
Αφού εντοπιστούν οι μαθητές με τους ελάχιστους βαθμούς, στη συνέχεια θα εμφανιστούν στην οθόνη.
Η εμφάνιση των AM των μαθητών με τον ίδιο ελάχιστο βαθμό θα γίνεται στη main() με χρήση των επιτρεπόμενων
λειτουργιών της στοίβας (άδειασμα στοίβας). Στη συνέχεια θα καλείται η βοηθητική συνάρτηση TraverseStack για την
επαλήθευση της ορθής υλοποίησης αυτού του ερωτήματος (η στοίβα θα πρέπει να είναι κενή μετά την «εμφάνιση»-
διαγραφή από τη στοίβα των ΑΜ). Το περιεχόμενο κάθε κόμβου της ΣΛ θα εμφανίζεται ως εξής: <ΑΜ, Βαθμός> πχ αν ο
κόμβος της ΣΛ είναι στη θέση 0 του πίνακα με ΑΜ 5 και βαθμό 10 και ο επόμενος κόμβος της ΣΛ είναι αποθηκευμένος στη
θέση 2 του πίνακα, τότε η εμφάνιση του κόμβου θα είναι: (0|<5,10.0> -> 2) που σημαίνει ότι ο κόμβος με περιεχόμενο 5, 10
είναι αποθηκευμένος στη θέση 0 του πίνακα και έχει επόμενο κόμβο αποθηκευμένο στη θέση 2 του πίνακα.
Το πρόγραμμα θα πρέπει να εκτελεί κατά σειρά τις παρακάτω λειτουργίες και οι κλήσεις των συναρτήσεων θα γίνονται από
τη main().
A. Αρχικοποίηση storage pool
B. Δημιουργία ΣΛ (μέγιστο μέγεθος 10)
C. Εμφάνιση της storage pool
D. Εμφάνιση των στοιχείων της ΣΛ
E. Εισαγωγή 5 στοιχείων στην ΣΛ. (Η εισαγωγή στοιχείου θα γίνεται πάντα στην αρχή της ΣΛ)
F. Εμφάνιση της storage pool
G. Εμφάνιση των στοιχείων της ΣΛΑπλή Συνδετική Λίστα, Στοίβα & Ουρά (υλοποίηση με δείκτες) - σελίδα 16 από 16
H. Έλεγχος εάν η ΣΛ είναι άδεια. Αν η ΣΛ είναι άδεια εμφανίζει μήνυμα «Empty List» διαφορετικά «Not an Empty List»
I. Έλεγχος εάν η ΣΛ είναι γεμάτη. Αν η ΣΛ είναι γεμάτη εμφανίζει μήνυμα «Full List» διαφορετικά «Not a Full List»
J. Εμφάνιση του ελάχιστου βαθμού και των ΑΜ των μαθητών με το ελάχιστο βαθμό
K. Κλήση της TraverseStack για την επαλήθευση της ορθής υλοποίησης του ερωτήματος J
L. Εμφάνιση της storage pool
M. Εμφάνιση των στοιχείων της ΣΛ*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define StackLimit 10
#define NumberOfNodes 10
#define NilValue -1


typedef struct{
    int am;
    float grade;
} ListElementType;

typedef int StackElementType;

typedef struct{
    int Top;
    StackElementType Element[StackLimit];
} StackType;

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
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);


int main(){

    float min;
    int i;
    NodeType node[NumberOfNodes];
    ListPointer list, freePtr, predPtr;
    ListElementType item;
    StackType s;
    StackElementType st;

    i=0;
    predPtr = NilValue;
//a
InitializeStoragePool(node, &freePtr);
//b
CreateList(&list);
//c
printf("---------------Question C--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(list, freePtr, node);
//d
printf("---------------Question D--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(list, node);

//e
printf("---------------Question E--------------------\n");
for(i=0;i<5;i++){
printf("DWSE AM GIA EISAGWGH STH LISTA: ");
scanf("%d", &item.am);
printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
scanf("%f", &item.grade);
Insert(&list, node, &freePtr, predPtr, item);
}

//f
printf("---------------Question F--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(list, freePtr, node);

//g
printf("---------------Question G--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(list, node);

//h
printf("---------------Question H--------------------\n");

if(EmptyList(list))
    printf("Empty List\n");
else
    printf("Not an Empty List\n");

//i
printf("---------------Question I--------------------\n");

if(FullList(freePtr))
    printf("Full List\n");
else
    printf("Not a Full List\n");

//j
printf("---------------Question J--------------------\n");
min = FindMins(list, node, &s);
printf("Min value=%.1f\n", min);
printf("AM with min grade are: ");
while(!EmptyStack(s)){
Pop(&s, &st);
printf("%d ", st);

}
//k
printf("\n---------------Question K--------------------\n");
TraverseStack(s);

//l
printf("---------------Question L--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(list, freePtr, node);

//m
printf("---------------Question M--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(list, node);

return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.grade=-1.0;
        }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[i].Data.grade=-1.0;
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
  Node[P].Data.am = -1;
  Node[P].Data.grade=-1.0;
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
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.am, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;

}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ", i, Node[i].Data.am, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}



boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)

{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){

    ListPointer CurrPtr;
    StackElementType am, item;
    float min;


    CreateStack(Stack);

if(!EmptyList(List)){
CurrPtr = List;
min = Node[CurrPtr].Data.grade;
while(CurrPtr != NilValue){
if(Node[CurrPtr].Data.grade <= min){
if(Node[CurrPtr].Data.grade < min){
while(!EmptyStack(*Stack)){
Pop(Stack, &item);
  }
 min = Node[CurrPtr].Data.grade;
 }
am= Node[CurrPtr].Data.am;
Push(Stack, am);
}
CurrPtr = Node[CurrPtr].Next;
}
}
else printf("Empty List..");

    return min;
}
