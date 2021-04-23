/* ��� ��������� �������� ���� ������������ ����� ������ ��� ���� �� ����� ���� �� ��������� ���������� ��
����� �������. ��� �� ������ �������� �������� ���������� ��� ���� ��� �� �������. �� ����� ���������
����:
1. �� ������� �� ������ ��� �� ������� ��������� ��� �� ����������� ��� �����.
2. ��� ���� �������� �� ����� ��� ���� (�������) ��� �� ������� (1 ���������� L/M/S) ��� �� �������
(���������) �� �������� ��� ����� (�� ������). ��� ���������� �� ��������� (��������) �� �����
������������ �� ���� �� ������� � ��� ���� ��� �� ��������� ��� ������-�����, ���� �������������
��� ������-����� (LIFO).������� - ������ 10 ��� 11
3. ���� ��������� ��� �� ��������� ��� ������-����� �� ��������� �� ������ �items in the box� ��� ���
�������� �� ��������� ��� ������������� ��� ������-�����.
4. �� ������� ��� �������� �� ���� �� �������. �� ������ �� ��������� ������ �Found the size�
����������� �Not Found the size�. �� ������� ��� ��������� ����� ���� �� ����� �������� �� ��
������������ �������. �� ������ �� �������� �������� ��� ������ ��������.
5. ��� �������� �� ��������� �� ������ �Items in the box� ��� �� ��������� ���� ��� ������� ��� �����������. ��� �������� �� ��������� �� ������ �Items out of the box� ��� �� ��������� ���� ��� �����
���� ��� �� ������-�����.
6. �� �� �������� �� ������ ���� � ������-����� �� �� ��������� �� ������ �� ������������� ��� ��
�������� ��� �� ��������� �� ��� ������ �������. �� �� �������� ������ ���� � ������-����� �� ��
��������� �� ������ �� �� ���� ������������ �� ��� ������ ������� ���� �� �������� ��� �����������
��� ������� �� �� ������ �� �������������� ��� ������-����� �� �� ���������, ����� �������� ���
����� ������ ��������.
7. ��� �������� �� ��������� �� ������ �Items in the box� ��� �� ��������� ���� ��� ���������� ���
������-����� ��� �� ������ �Items out of the box� ��� �� ��������� ���� ��� ����� ���� ��� �� �����������.*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define StackLimit 140

typedef struct{
int price;
char size;
}StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseStack(StackType Stack);
void menu(int *choice);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main(){
int n,i;
int found;
char size;
StackType stack,stack1;
CreateStack(&stack);
CreateStack(&stack1);

//a
printf("1|Give number of items ");
scanf("%d",&n);

printf("----------------------------\n");

printf("2|Give the items to store\n");

StackElementType item;

for(i=0; i<n; i++){
  printf("Give price ");
  scanf("%d",&item.price);
  printf("Give size ");
  scanf(" %c",&item.size);
   Push(&stack,item);
}
printf("----------------------------\n");

printf("3|Items in the box");
TraverseStack(stack);

printf("----------------------------\n");
printf("4|What size do you want? ");
scanf(" %c",&size);

found=0;
while(!EmptyStack(stack)) {
     Pop(&stack,&item);
    if(item.size==size){
    found=1;
    break;
    }
else{
        Push(&stack1,item);
}
i--;
}
if(found==0){
    printf("Not Found the size %c\n",size);
}
else if (found==1){
    printf("Found the size %c\n",size);
}
printf("\n");

printf("----------------------------\n");

printf("5|Items in the box");
TraverseStack(stack);

printf("\n");
printf("Items out of the box");
TraverseStack(stack1);

printf("----------------------------\n");
printf("6|\n");
while(!EmptyStack(stack1)){
    Pop(&stack1,&item);
    Push(&stack,item);
}
printf("----------------------------\n");

printf("7|Items in the box");
TraverseStack(stack);
printf("\n");
printf("Items out of the box");
TraverseStack(stack1);
return 0;
}



void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf(" %c, %d\n",Stack.Element[i].size,Stack.Element[i].price);
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

void Push(StackType *Stack, StackElementType Item){

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


