/* a29f5.c
 Γράψτε πρόγραμμα που θα δέχεται για κάθε άτομο τον ΑΜΚΑ (ακέραιος), τον ΑΦΜ (ακέραιος), την ηλικία (ακέραιος). Θα
καταχωρεί τα στοιχεία του κάθε ατόμου σε 2 καταλόγους ανάλογα με την ηλικία του, αυτούς με ηλικία μικρότερη ή ίση
των 60 ετών και αυτούς με ηλικία μεγαλύτερη των 60.
Κάθε κατάλογος θα πρέπει να οργανωθεί ως ΔΔΑ με κλειδί τον ΑΜΚΑ. Το πρόγραμμα θα περιλαμβάνει τις εξής
λειτουργίες
- Εισαγωγή των στοιχείων του κάθε ατόμου στο αντίστοιχο ΔΔΑ ανάλογα με την ηλικία του (ΔΔΑ για άτομα με ηλικίες
<=60 και ΔΔΑ για άτομα με ηλικίες > 60). Και στα 2 ΔΔΑ το κλειδί θα είναι ο ΑΜΚΑ.
- Εμφάνιση των 2 καταλόγων
- Αναζήτηση ατόμου με βάση τον ΑΜΚΑ και την ηλικία.
Δίνεται ένα στιγμιότυπο εκτέλεσης όπου φαίνεται πως θα γίνεται το διάβασμα των δεδομένων και η εμφάνιση του
κάθε καταλόγου. Η αναζήτηση θα γίνει για 3 άτομα: α) ένα άτομο του οποίου τα στοιχεία έχουν καταχωρηθεί σε ένα εκ
των 2 καταλόγων (ΑΜΚΑ, ηλικία), β) ένα άτομο του οποίου το ΑΜΚΑ του έχει καταχωρηθεί στον αντίστοιχο κατάλογο
αλλά η ηλικία του δεν ταυτίζεται με τη δοθείσα και γ) ένα άτομο του οποίου το ΑΜΚΑ δεν έχει καταχωρηθεί σε κανένα
κατάλογο */

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
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
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
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
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
