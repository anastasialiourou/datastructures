/* Ένα κατάστημα διατηρεί κάθε διαφορετικού τύπου προϊόν του μέσα σε κουτί όπου τα τοποθετεί οργανωμένα σε
μορφή στοίβας. Για το προϊόν «παιδικό φανελάκι» αποθηκεύει την τιμή και το μέγεθος. Να γίνει πρόγραμμα
όπου:
1. Θα δίνεται το πλήθος από τα παιδικά φανελάκια που θα καταχωρήσει στο κουτί.
2. Για κάθε φανελάκι θα δίνει την τιμή (ακέραια) και το μέγεθος (1 χαρακτήρας L/M/S) και θα εισάγει
(καταχωρεί) το φανελάκι στο κουτί (ως στοίβα). Δεν απαιτείται τα φανελάκια (στοιχεία) να είναι
ταξινομημένα ως προς το μέγεθος ή την τιμή για να εισαχθούν στη στοίβα-κουτί, απλά καταχωρούνται
στη στοίβα-κουτί (LIFO).Στοίβες - σελίδα 10 από 11
3. Όταν εισαχθούν όλα τα φανελάκια στη στοίβα-κουτί θα εμφανίζει το μήνυμα items in the box και στη
συνέχεια τα φανελάκια που καταχωρήθηκαν στη στοίβα-κουτί.
4. Θα αναζητά ένα φανελάκι με βάση το μέγεθος. Αν βρεθεί θα εμφανίζει μήνυμα Found the size
διαφορετικά Not Found the size. Θα σταματά την αναζήτηση μόλις βρει το πρώτο φανελάκι με το
συγκεκριμένο μέγεθος. Αν βρεθεί το φανελάκι θεωρούμε ότι αμέσως πωλείται.
5. Στη συνέχεια θα εμφανίζει το μήνυμα Items in the box και θα εμφανίζει αυτά που έμειναν στη στοίβακουτί. Στη συνέχεια θα εμφανίζει το μήνυμα Items out of the box και θα εμφανίζει αυτά που έχουν
βγει από τη στοίβα-κουτί.
6. Αν το φανελάκι δε βρεθεί τότε η στοίβα-κουτί με τα φανελάκια θα πρέπει να αποκατασταθεί και να
περιέχει όλα τα φανελάκια με την αρχική διάταξη. Αν το φανελάκι βρεθεί τότε η στοίβα-κουτί με τα
φανελάκια θα πρέπει να τα έχει διατεταγμένα με την αρχική διάταξη αλλά το φανελάκι που αναζητήθηκε
και βρέθηκε δε θα πρέπει να περιλαμβάνεται στη στοίβα-κουτί με τα φανελάκια, καθώς θεωρούμε ότι
μόλις βρεθεί πωλείται.
7. Στη συνέχεια θα εμφανίζει το μήνυμα Items in the box και θα εμφανίζει αυτά που βρίσκονται στη
στοίβα-κουτί και το μήνυμα Items out of the box και θα εμφανίζει αυτά που έχουν βγει από τη στοίβακουτί.*/

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


