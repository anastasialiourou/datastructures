/* Μια εναλλακτική υλοποίηση μιας ουράς που χρησιμοποιεί ένα
κυκλικό πίνακα και δεν απαιτεί να διατηρούμε μία κενή θέση μεταξύ
της εμπρός και της πίσω άκρη της για να ξεχωρίζει μια κενή ουρά από
μια γεμάτη χρειάζεται απλά την προσθήκη ενός ακέραιου πεδίου
Count στην εγγραφή τύπου QueueType, στο οποίο αποθηκεύεται ο
τρέχων αριθμός στοιχείων της ουράς. Να κάνετε τις απαραίτητες
αλλαγές στη δήλωση του τύπου της εγγραφής και στις βασικές
λειτουργίες του ΑΤΔ ουρά με πίνακες, έτσι ώστε να χρησιμοποιείται
αυτό το επιπλέον πεδίο και να μην διατηρείται κενή θέση στον πίνακα
όπου αποθηκεύονται τα στοιχεία της ουράς. Η TraverseQ που σας
δίνεται στο TestQueue θα πρέπει επίσης να τροποποιηθεί. Για να
ελέγξετε την ορθότητα του προγράμματος σας
(a) Δημιουργήστε μια ουρά (QueueLimit=10) που περιλαμβάνει
όλους τους ακέραιους αριθμούς στο διάστημα [0..9]. Εμφανίστε
την ουρά (με βοηθητική διαδικασία TraverseQ) την τιμή της
Front, Rear και του μετρητή των στοιχείων της ουράς.
(b) Στη συνέχεια επιχειρήστε να προσθέσετε ένα οποιοδήποτε
στοιχείο. Εμφανίστε την ουρά (με βοηθητική διαδικασία
TraverseQ)
(c) Αφαιρέστε τη κεφαλή της ουράς και εμφανίστε την ουρά (με
βοηθητική διαδικασία TraverseQ), το στοιχείο που αφαιρέσατε,
την τιμή της Front, Rear και του μετρητή των στοιχείων της ουράς
(d) Προσθέσετε ένα οποιοδήποτε στοιχείο και εμφανίστε την ουρά
(με βοηθητική διαδικασία TraverseQ), την τιμή της Front, Rear
και του μετρητή των στοιχείων της ουράς
(e) Στη συνέχεια επιχειρήστε να προσθέσετε ένα οποιοδήποτε
στοιχείο. Εμφανίστε την ουρά (με βοηθητική διαδικασία
TraverseQ), την τιμή της Front, Rear και του μετρητή των
στοιχείων της ουράς.
(f) Αδειάστε την ουρά. Μετά την αφαίρεση κάθε φορά της κεφαλής
της ουράς εμφανίστε την ουρά (με βοηθητική διαδικασία
TraverseQ), το στοιχείο που αφαιρέσατε, την τιμή της Front, Rear
και του μετρητή των στοιχείων της ουράς.
Η έξοδος του προγράμματος δίνεται στη διπλανή εικόνα.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 10

typedef int QueueElementType;

typedef struct  {
    int Front,Rear, Count;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

main()
{
   QueueType q;
   int i;
   QueueElementType item;
   int count=0;

   CreateQ(&q);
   for(i=0;i<QueueLimit;i++){
    AddQ(&q,i);
   }
   printf("---a---\n");
   printf("Queue: ");
   TraverseQ(q);
   printf("Front=%d Rear=%d Count=%d\n",q.Front, q.Rear, q.Count);


      printf("---b---\n");
      AddQ(&q,25);
      printf("\n");
      printf("Queue: ");
   TraverseQ(q);
   printf("Front=%d Rear=%d Count=%d\n",q.Front, q.Rear, q.Count);

   printf("---c---\n");
   RemoveQ(&q,&item);
      printf("Queue: ");
   TraverseQ(q);
   printf("Removed item=%d Front=%d Rear=%d Count=%d\n",item,q.Front, q.Rear, q.Count);




    printf("---d---\n");
    AddQ(&q,25);

      printf("Queue: ");
   TraverseQ(q);
   printf("Front=%d Rear=%d Count=%d\n",q.Front, q.Rear, q.Count);


    printf("---e---\n");
        AddQ(&q,30);
      printf("\n");
      printf("Queue: ");
   TraverseQ(q);
   printf("Front=%d Rear=%d Count=%d\n",q.Front, q.Rear, q.Count);


    printf("---f---\n");
    while(!EmptyQ(q)){
    RemoveQ(&q,&item);
      printf("Queue: ");
   TraverseQ(q);
    printf("Removed item=%d Front=%d Rear=%d Count=%d\n",item,q.Front, q.Rear, q.Count);}

	return 0;
}


void TraverseQ(QueueType Queue) {
	int current,i;
	current = 0;
	if(EmptyQ(Queue))
        printf("Empty queue");
    current=Queue.Front;
    for(i=0;i<Queue.Count;i++){
        printf("%d ",Queue.Element[current]);
        current=(current+1)%QueueLimit;    }

	printf("\n");
}
void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Count==0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		(Queue->Count)--;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit; ;
		(Queue ->Count)++;
	}
	else
		printf("Full Queue");
}


