/* a29f5.c
 ������ ��������� ��� �� ������� ��� ���� ����� ��� ���� (��������), ��� ��� (��������), ��� ������ (��������). ��
��������� �� �������� ��� ���� ������ �� 2 ���������� ������� �� ��� ������ ���, ������ �� ������ ��������� � ���
��� 60 ���� ��� ������ �� ������ ���������� ��� 60.
���� ��������� �� ������ �� ��������� �� ��� �� ������ ��� ����. �� ��������� �� ������������ ��� ����
�����������
- �������� ��� ��������� ��� ���� ������ ��� ���������� ��� ������� �� ��� ������ ��� (��� ��� ����� �� �������
<=60 ��� ��� ��� ����� �� ������� > 60). ��� ��� 2 ��� �� ������ �� ����� � ����.
- �������� ��� 2 ���������
- ��������� ������ �� ���� ��� ���� ��� ��� ������.
������� ��� ����������� ��������� ���� �������� ��� �� ������� �� �������� ��� ��������� ��� � �������� ���
���� ���������. � ��������� �� ����� ��� 3 �����: �) ��� ����� ��� ������ �� �������� ����� ����������� �� ��� ��
��� 2 ��������� (����, ������), �) ��� ����� ��� ������ �� ���� ��� ���� ����������� ���� ���������� ��������
���� � ������ ��� ��� ���������� �� �� ������� ��� �) ��� ����� ��� ������ �� ���� ��� ���� ����������� �� ������
�������� */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int AMKA;
    int AFM;
    int AGE;
} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

int main()
{
    BinTreePointer ARoot, BRoot, LocPtr;
    BinTreeElementType person;
    boolean answer, found;
    int i;

    CreateBST(&ARoot);
    CreateBST(&BRoot);

    do {
        printf("Give AMKA? ");
        scanf("%d", &person.AMKA);
        printf("Give AFM? ");
        scanf("%d", &person.AFM);
        printf("Give age? ");
        scanf("%d", &person.AGE);
        if (person.AGE <= 60)
            BSTInsert(&ARoot, person);
        else
            BSTInsert(&BRoot, person);
        printf("\nContinue Y/N: ");
        do
        {
            scanf("%c", &answer);
        } while (toupper(answer)!= 'N' && toupper(answer)!= 'Y');
    } while (toupper(answer)!= 'N');

    printf("\n\nPeople with age less-equal 60\n");
    InorderTraversal(ARoot);
    printf("\n\nPeople with age greater than 60\n");
    InorderTraversal(BRoot);
    printf("\n");

    for (i=0;i<3;i++)
    {
        printf("Give AMKA: ");
        scanf("%d", &person.AMKA);
        printf("Give age: ");
        scanf("%d", &person.AGE);
        if (person.AGE <= 60)
            BSTSearch(ARoot, person, &found, &LocPtr);
        else
            BSTSearch(BRoot, person, &found, &LocPtr);
        if (found)
        {
            if (LocPtr->Data.AGE == person.AGE)
                printf("The person with AMKA %d, AFM %d and age %d is the catalogue\n", LocPtr->Data.AMKA, LocPtr->Data.AFM, LocPtr->Data.AGE);
            else
                printf("The person with AMKA %d has age %d different from the person you are looking for\n", LocPtr->Data.AMKA, LocPtr->Data.AGE);
        }
        else
        {
            printf("The person with AMKA %d and age %d is Unknown\n", person.AMKA, person.AGE);
        }
    }

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.AMKA < LocPtr->Data.AMKA)
            LocPtr = LocPtr ->LChild;
        else if (Item.AMKA > LocPtr ->Data.AMKA)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data.AMKA = Item.AMKA;
        LocPtr ->Data.AFM = Item.AFM;
        LocPtr ->Data.AGE = Item.AGE;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.AMKA < Parent ->Data.AMKA)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.AMKA < (*LocPtr)->Data.AMKA)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.AMKA > (*LocPtr)->Data.AMKA)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���
                ��� ��� ������ ��� ������ �����.
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������
                ����� ��� ������, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue.AMKA < (*LocPtr)->Data.AMKA) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.AMKA > (*LocPtr)->Data.AMKA) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ���
                ������ ��� n ���� �� ������� ���� ������� */
                n->Data = nNext->Data;
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d, %d) ",Root->Data.AMKA, Root->Data.AFM, Root->Data.AGE);
        InorderTraversal(Root->RChild);
    }
}