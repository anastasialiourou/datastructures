/* Χρησιμοποιήστε τις λειτουργίες που έχουν οριστεί στον ΑΤΔ στοίβα υλοποίηση με πίνακα και γράψτε στο κυρίως
πρόγραμμα κώδικα για κάθε μία από τις παρακάτω λειτουργίες:
(a) Θέστε στη μεταβλητή x την τιμή του δεύτερου στοιχείου από την κορυφή της στοίβας, αφήνοντας τη
στοίβα χωρίς τα δύο πρώτα στοιχεία της κορυφής.
(b) Θέστε στη μεταβλητή x την τιμή του δεύτερου στοιχείου από την κορυφή της στοίβας, αφήνοντας τη
στοίβα αμετάβλητη (δεν θα διαγραφεί κανένα στοιχείο).
(c) Θέστε στη μεταβλητή x την τιμή του n-οστού στοιχείου από την κορυφή της στοίβας, αφήνοντας τη στοίβα
χωρίς τα n πρώτα στοιχεία της κορυφής.
(d) Θέστε στη μεταβλητή x την τιμή του n-οστού στοιχείου από την κορυφή της στοίβας, αφήνοντας τη στοίβα
αμετάβλητη. (Υπόδειξη: Χρησιμοποιείστε μία άλλη, βοηθητική στοίβα.)
(e) Θέστε στη μεταβλητή x την τιμή του τελευταίου στοιχείου της στοίβας, αφήνοντας τη στοίβα αμετάβλητη.
(f) Θέστε στη μεταβλητή x την τιμή του τρίτου στοιχείου από τη βάση της στοίβας, αφήνοντας τη στοίβα
αμετάβλητη.
(g) Θέστε στη μεταβλητή x την τιμή του τελευταίου στοιχείου της στοίβας, αφήνοντας τη στοίβα κενή.
Στο κυρίως πρόγραμμα θα δημιουργείται πρώτα η στοίβα και θα εισάγονται σ’ αυτή 15 αριθμοί. Για λόγους
απλότητας μπορεί να χρησιμοποιηθεί ένας βρόχος for, σε κάθε επανάληψη του οποίου θα εισάγεται στη στοίβα το
δεκαπλάσιο της τιμής της μεταβλητής ελέγχου της for. Στη συνέχεια εμφανίστε το περιεχόμενο της στοίβας
(καλέστε τη βοηθητική συνάρτηση TraverseStack, η εμφάνιση των στοιχείων από τη θέση 0 .. Stack.top).
Πριν την εκτέλεση των παραπάνω λειτουργιών θα διαβάζεται ο ακέραιος αριθμός n (n≤ (Stack.Top-1)/2) που
χρειάζεται στις λειτουργίες (c) και (d). Δε χρειάζεται να γίνεται έλεγχος ορθής καταχώρησης της τιμής του n εντός
του παραπάνω ορίου θεωρούμε ότι θα δοθεί ορθά.
Μετά από την εκτέλεση κάθε λειτουργίας (a) έως (g) θα εμφανίζεται η τιμή της μεταβλητής x στη συνέχεια το
πλήθος των στοιχείων της στοίβας και το περιεχόμενο της στοίβας. Η είσοδος και η έξοδος του προγράμματος
φαίνεται στο παρακάτω ενδεικτικό στιγμιότυπο.*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define StackLimit 150

typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
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
StackElementType x,i,n,temp;
StackType Stack;
StackType Stack1;
CreateStack(&Stack);

for(i=0;i<StackLimit;i+=10){
    Push(&Stack,i);
}
TraverseStack(Stack);
printf("Give nth element (n<=6) ");
scanf("%d",&n);

Pop(&Stack,&x);
Pop(&Stack,&x);
printf("\nQuestion a: x=%d ",x);
printf("\n");
TraverseStack(Stack);


//a
Pop(&Stack,&temp);
Pop(&Stack,&x);
Push(&Stack,x);
Push(&Stack,temp);
printf("\nQuestion b: x=%d ",x);
printf("\n");
TraverseStack(Stack);

//b
for(i=0;i<n;i++){
Pop(&Stack,&x);
}
printf("\nQuestion c: x=%d ",x);
printf("\n");
TraverseStack(Stack);

//c
CreateStack(&Stack1);
for(i=0;i<n;i++){
    Pop(&Stack,&x);
    Push(&Stack1,x);
}

//d
printf("\nQuestion d: x=%d ",x);
while((!EmptyStack(Stack1))){
    Pop(&Stack1,&temp);
    Push(&Stack,temp);
}
printf("\n");
TraverseStack(Stack);

while(!EmptyStack(Stack)){
    Pop(&Stack,&x);
    Push(&Stack1,x);
}

//e
printf("\nQuestion e: x=%d ",x);
while(!EmptyStack(Stack1)){
    Pop(&Stack1,&x);
    Push(&Stack,x);
}
printf("\n");
TraverseStack(Stack);

while(x > Stack.Element[2]){
    Pop(&Stack,&x);
    Push(&Stack1,x);
}
//f
printf("\nQuestion f: x=%d ",x);
while(!EmptyStack(Stack1)){
    Pop(&Stack1,&x);
    Push(&Stack,x);
 }
 printf("\n");
TraverseStack(Stack);

while(!EmptyStack(Stack)){
    Pop(&Stack,&x);
}
//g
printf("\nQuestion g: x=%d ",x);
printf("\n");
TraverseStack(Stack);
return 0;

}



// ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
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
