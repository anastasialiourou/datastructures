/* Γράψτε ένα πρόγραμμα που θα δέχεται ένα αλφαριθμητικό, διαβάζοντας το χαρακτήρα προς χαρακτήρα (μέχρι ο
χρήστης να δώσει ως χαρακτήρα #) και θα ελέγχει αν το αλφαριθμητικό που έχει σχηματιστεί, έχει τη μορφή
x C y
όπου x είναι ένα αλφαριθμητικό και y είναι το αντίστροφο του x. Για παράδειγμα, αν x = ‘ΑΒΑΒΒΑ’ τότε y =
‘ABBABA’. Ο έλεγχος θα γίνεται κατά το διάβασμα του κάθε χαρακτήρα. Το πρόγραμμα θα σταματάει να διαβάζει
χαρακτήρες είτε όταν δοθεί ο χαρακτήρας ‘#’, είτε μόλις διαπιστώσει ότι το αλφαριθμητικό δεν ακολουθεί την
επιθυμητή μορφή. Πριν τερματίσει θα εμφανίζει το μήνυμα TRUE ή FALSE αντίστοιχα αν το αλφαριθμητικό έχει ή
όχι αυτή τη μορφή.
Υπόδειξη: οι χαρακτήρες που θα διαβαστούν μέχρι να δοθεί ο χαρακτήρας ‘C’ εισάγονται σε μια στοίβα και κάθε
χαρακτήρας που διαβάζεται μετά τον ‘C’ συγκρίνεται με το στοιχείο που βρίσκεται στην κορυφή της στοίβας. Για το
διάβασμα κάθε χαρακτήρα χρησιμοποιείστε : scanf("%c", &ch); getchar();*/

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


