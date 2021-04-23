/*�� ����� ��������� ��� �� ������������ ��� ���� �� �� ������� ��� �������, ������ �� ����������� ��� ����� ��
��������������� �� ��� ����������� ��� �������. ���� �� ��������������� ��� ���� ����� �� ��������������� 2 �������.
���� ������ �������� ���� ������� ������ ��� � �������� ��������� �� ������� �� ����: ������ ���������, ��������. ��
��������� �� ��������� �� ����������� ��� ��� 2 �������. � 2� ������ ���� ������������ �� �������� ���� �� ���� ��
������ �������������� ��� ����.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);



int main()
{
   StackPointer s1,s2;
   int i,x;
   StackElementType item;
   CreateStack(&s1);
   CreateStack(&s2);

   printf("PLH8OS STOIXEIWN: ");
   scanf("%d",&x);
   for(i=0;i<x;i++){
    printf("DWSE TO %do STOIXEIO: ",i+1);
     scanf("%d",&item);
     Push(&s1,item);
   }
   printf("*********1i stoiva***********\n");
   TraverseStack(s1);

  while(!EmptyStack(s1)){
    Pop(&s1,&item);
    Push(&s2,item);
  }

   printf("*********2i stoiva***********\n");
   TraverseStack(s2);
	return 0;
}


void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
void CreateStack(StackPointer *Stack)

{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)

{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)

{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)

{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

