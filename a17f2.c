/*. �� ���������� � ��������� CopyStack � ����� �� ���������� ��� �� ���������� ��� ��������� ��� ��������
������� s1 ��������� ��� ������ ������ s1 ����������. �� ��������� ��� ���������� �����
StackType CopyStack(StackType *s1)������� - ������ 11 ��� 11
��� ������ ��������� ������������ �� ������ s1 ���������� � ���� 20 ��������. ��� ������ ���������
������ �� �������������� ���� ������ for, �� ���� ��������� ��� ������ �� �������� ��� ������ ��� ����� ���
���������� ������� ��� for. ��� �������� ��������� �� ����������� ��� ������� s1 (������� �� ���������
��������� TraverseStack, � �������� ��� ��������� ��� �� ���� 0 .. Stack.top). ������� ��� CopyStack ��� ���
�������� ��������� �� �������� ��� ������� s1 ��� �� �������� ��� ������� s2.*/

#include <stdio.h>
#include <stdlib.h>
#define StackLimit 20

typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
StackType CopyStack(StackType *s1);


void TraverseStack(StackType Stack);

void menu(int *choice);

int main()
{
    StackElementType i;
    StackType s1,s2;

    printf("Stack s1\n");
    CreateStack(&s1);
    for(i=0;i<StackLimit; i++){
        Push(&s1,i);
    }
    TraverseStack(s1);

    s2=CopyStack(&s1);

    printf("After copying s1 to s2\n");

    printf("Stack s1\n");
    TraverseStack(s1);

    printf("Stack s2\n");
    TraverseStack(s2);


    return 0;
}

StackType CopyStack(StackType *s1){
    StackElementType item;
    StackType s2,tempS;

CreateStack(&s2);
CreateStack(&tempS);

while(!EmptyStack(*s1)){
Pop(&(*s1), &item);
Push(&tempS,item);
    }

while(!EmptyStack(tempS)){
Pop(&tempS, &item);
Push(&(*s1),item);
Push(&s2,item);

}
 return s2;
}


 void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}



void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
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



