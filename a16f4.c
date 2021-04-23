/*Σε μία ουρά κάθε στοιχείο εισέρχεται σε κάποια συγκεκριμένη θέση σύμφωνα με το βαθμό προτεραιότητας (σε
αύξουσα σειρά). Να γραφεί πρόγραμμα που θα περιλαμβάνει τα παρακάτω:
-Εισαγωγή του πλήθους των κόμβων της ουράς.
- Τη συνάρτηση void insert_prot(QueueType *Queue, QueueElementType Item) την εισαγωγή στοιχείων
στην ουρά, κάθε κόμβος της οποίας θα περιέχει έναν τριψήφιο κωδικό αριθμό και τον βαθμό προτεραιότητας (1-
20). Σε περίπτωση ίδιου βαθμού προτεραιότητας το στοιχείο εισέρχεται τελευταίο στην αντίστοιχη προτεραιότητα.
- Τη συνάρτηση void TraverseQ(QueueType Queue) που θα εμφανίζει τα περιεχόμενα της ουράς κατά αύξοντα
βαθμό προτεραιότητας. Τα στοιχεία κάθε κόμβου εμφανίζονται σε ξεχωριστή σειρά με ένα κενό μεταξύ τους και
πρώτο το βαθμό προτεραιότητας*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 50

typedef struct{
int code;
int prot;
} QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);


int main(){
    int i,x;
    QueueType q;
    QueueElementType item;
    CreateQ(&q);

   printf("DWSE TO PLITHOS: ");
   scanf("%d",&x);

for(i=0;i<x;i++){
    printf("DWSE TON KODIKO TOU %dou KOMVOU: ",i+1);
    scanf("%d",&item.code);
    printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU:",i+1);
    scanf("%d",&item.prot);
insert_prot(&q,item);
}




printf("----------Priority Queue-------------\n");
TraverseQ(q);

return 0;
}
void CreateQ(QueueType *Queue)

{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.prot, CurrPtr->Data.code);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
    QueuePointer TempPtr;
    QueuePointer CurrPtr;
    QueuePointer PredPtr;
    boolean flag;

    TempPtr=(QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data=Item;
    TempPtr->Next=NULL;

    if(EmptyQ(*Queue))
    {
        Queue->Front=TempPtr;
        Queue->Rear=TempPtr;
    }
    else
    {
        PredPtr=Queue->Front;
        CurrPtr=Queue->Front;
        flag=FALSE;

        if(CurrPtr->Data.prot>Item.prot)
        {
            Queue->Front=TempPtr;
            TempPtr->Next=CurrPtr;
        }
        else
        {
            while(CurrPtr!=NULL && flag==FALSE)
            {
                if(CurrPtr->Data.prot>Item.prot)
                {
                    PredPtr->Next=TempPtr;
                    TempPtr->Next=CurrPtr;
                    flag=TRUE;
                }
                PredPtr=CurrPtr;
                CurrPtr=CurrPtr->Next;
            }
            if(flag==FALSE)
            {
               PredPtr->Next=TempPtr;
               Queue->Rear=TempPtr;
            }
        }
    }
}



