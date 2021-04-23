/* ������ ��� ��������� ��� �� ������� ��� �������������, ����������� �� ��������� ���� ��������� (����� �
������� �� ����� �� ��������� #) ��� �� ������� �� �� ������������� ��� ���� �����������, ���� �� �����
x C y
���� x ����� ��� ������������� ��� y ����� �� ���������� ��� x. ��� ����������, �� x = �������� ���� y =
�ABBABA�. � ������� �� ������� ���� �� �������� ��� ���� ���������. �� ��������� �� ��������� �� ��������
���������� ���� ���� ����� � ���������� �#�, ���� ����� ����������� ��� �� ������������� ��� ��������� ���
��������� �����. ���� ���������� �� ��������� �� ������ TRUE � FALSE ���������� �� �� ������������� ���� �
��� ���� �� �����.
��������: �� ���������� ��� �� ���������� ����� �� ����� � ���������� �C� ���������� �� ��� ������ ��� ����
���������� ��� ���������� ���� ��� �C� ����������� �� �� �������� ��� ��������� ���� ������ ��� �������. ��� ��
�������� ���� ��������� ��������������� : scanf("%c", &ch); getchar();*/

#include <stdio.h>
#include <stdlib.h>
#define StackLimit 50

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


void TraverseStack(StackType Stack);

void menu(int *choice);

int main()
{
    StackType s;
    boolean valid,flag;
    StackElementType ch,item;

    flag=FALSE;
    valid=TRUE;

    CreateStack(&s);

    printf("Enter string:\n");
    scanf("%c",&ch);
    getchar();

    if(ch=='#'){
        exit(1);
    }

while(ch!='#' && valid==TRUE){
if(flag==FALSE){
if(ch=='C'){
flag=TRUE;
scanf("%c",&ch);
getchar();
}

else{
Push(&s,ch);
scanf("%c",&ch);
getchar();
}
}

else{
if(!EmptyStack(s)){
Pop(&s,&item);
if(item!=ch){
valid=FALSE;
}
else{
scanf("%c",&ch);
getchar();
}
}
else{
valid=FALSE;
}
}
}

if(valid && EmptyStack(s)){
printf("TRUE");
}
else{
printf("FALSE");
}


return 0;
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


