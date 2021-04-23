/* Γράψτε ένα πρόγραμμα που θα πραγματοποιεί ορθογραφικό έλεγχο ενός κειμένου. Οι λέξεις που απαρτίζουν το λεξικό
είναι αποθηκευμένες στο αρχείο κειμένου ‘I112f5.TXT’ (σε κάθε γραμμή του υπάρχει μία λέξη). Διαβάζονται και
αποθηκεύονται μία-μία σε ένα ΔΔΑ με τη συνάρτηση CreateDictionary και έτσι δημιουργείται το λεξικό-ΔΔΑ. Μετά τη
δημιουργία του λεξικού-ΔΔΑ θα εμφανίζετε τις λέξεις του λεξικού. Στη συνέχεια το πρόγραμμα μέσω της συνάρτησης
SpellingCheck θα διαβάζει ένα κείμενο που είναι αποθηκευμένο στο αρχείο κειμένου ‘I111F5.TXT’, σε κάθε γραμμή του
οποίου υπάρχει μία λέξη και θα διενεργεί ορθογραφικό έλεγχο, δηλαδή θα αναζητά τη λέξη του αρχείου ‘I111F5.TXT’ στο
λεξικό-ΔΔΑ. Κατά τον ορθογραφικό έλεγχο θα πρέπει να εκτυπώνετε τις λέξεις που δεν βρέθηκαν στο λεξικό και να
υπολογίζετε το πλήθος τους. Το πλήθος των λέξεων που δεν βρέθηκαν στο λεξικό θα εμφανίζεται στη main.
Δίνονται τα πρωτότυπα των συναρτήσεων*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char BinTreeElementType[20];

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

void InorderTraversal(BinTreePointer Root);

void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);

int main ()
{
    BinTreePointer ARoot;

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("i112f5.txt","r");
    fp2 = fopen("i111f5.txt","r");

    CreateBST(&ARoot);
    CreateDictionary(&ARoot,fp1);

    printf("**********Dictionary**********\n");
    InorderTraversal(ARoot);
    printf("\n");


    printf("**********Not in Dictionary**********\n");
    printf("Number of words not in Dictionary: %d\n",SpellingCheck(ARoot, fp2));

    fclose(fp1);
    fclose(fp2);

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
        if (strcmp(Item, LocPtr->Data) < 0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item, LocPtr->Data) > 0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        //LocPtr ->Data = Item;//kati edo
        strcpy(LocPtr ->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent ->Data) < 0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue,(*LocPtr)->Data) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue,(*LocPtr)->Data) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void InorderTraversal(BinTreePointer Root)

{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}

void CreateDictionary(BinTreePointer *Root, FILE *fp)
{
    BinTreeElementType Item;

    while(!feof(fp)){

        fscanf(fp,"%s", Item);
        BSTInsert(Root, Item);
    }
}

int SpellingCheck(BinTreePointer Root, FILE *fp)
{
    boolean Found;
    BinTreePointer LocPtr;
    BinTreeElementType Item;
    int count;
    count=0;

    while(!feof(fp)){

        fscanf(fp,"%s", Item);
        BSTSearch(Root, Item, &Found, &LocPtr);

        if(!Found){
            printf("%s \n",Item);
            count++;
        }
    }

    return count;
}
