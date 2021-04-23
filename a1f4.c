/*� ���������� � ��������� Search �� �� �������� ���������: boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,
ListPointer *PredPtr);
� ����� �� ������� ��� ����������� ����� (��) ����������� �� ������ (���������� FreePtr, List, Node) ��� ��� ��������
Item ��� �� ���������� boolean ���� � ����� ������� �� ������� � ��� �� ������������ �������� Item ��� �� ��� �� ����
(PredPtr) ��� ��������� ��� ����� ����������� ��� Item, ���� � �� ��� �� �������� ���� ��� �������� � �� ��������
��� ��������� Item �� ����� ������������ (����� ��� Search ���� ��� �������� � �� �������� ��������� ��� ��). �
�������� ��������� ���� �.�. ������� ������������ ��� ��������� ��� �� ������ �Continue Y/N:� (��� �����������
���������). ��� �� ������������� ��������. H ��������� Search �� ������ 2 ����� ��� ��� �������� ��� ������� ��� ��
��� ��� ��� �������� ��� ��� ������� ��� ��. �� �� �������� ������ �� ��������� �� ������ �The number is in the list and its
predecessor is in position� ��� ��� ���� ��� PredPtr, ����������� �� ��������� �� ������ �The number is not in the list�. ��
��������� �� ������ �� ������� ���� ����� ��� �������� ����������� ��� �� ������� ��� ����������� �� �������� ��� ��
main().
A. ������������ storage pool
B. ���������� ��� (������� ������� 10)
C. �������� ��� storage pool
D. �������� ��� ��������� ��� ��
E. �������� ��������� ���� ��. ���� ��� ���� �������� ��������� ��� �� ���� �� ������ �� ��������� ������������
�� ������� ������� (����� ��� Search ���� ��� �������� ��������� ��� ��)
F. �������� ��� storage pool
G. �������� ��� ��������� ��� ��
H. ������� ��� � �� ����� �����. �� � �� ����� ����� ��������� ������ �Empty List� ����������� �Not an Empty List�
I. ������� ��� � �� ����� ������. �� � �� ����� ������ ��������� ������ �Full List� ����������� �Not a Full List�
J. ��������� ���� ��������� ��� �� (��� �������� ��� ������� ��� �� ��� ��� �������� ��� ��� �������).*/
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




