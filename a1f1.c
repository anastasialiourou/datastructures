/* Ένα σημαντικό πρόβλημα της θεωρίας αριθμών (του πεδίου των μαθηματικών που έχει ως αντικείμενο τη
μελέτη των ιδιοτήτων των μη αρνητικών ακεραίων) είναι το πρόβλημα του προσδιορισμού του κατά πόσο
ένας ακέραιος είναι πρώτος. Ένας θετικός ακέραιος n είναι πρώτος (prime) αν έχει ακριβώς δύο θετικούς
διαιρέτες, τον εαυτό του και το 1. Οι πρώτοι αριθμοί είναι ιδιαίτερα σημαντικοί σήμερα για την
κρυπτογραφία, αφού πολλές από τις καλύτερες τεχνικές κρυπτογράφησης βασίζονται στους πρώτους
αριθμούς. Να γραφεί πρόγραμμα που θα περιλαμβάνει τα παρακάτω υποπρογράμματα:
 συνάρτηση isPrime που θα δέχεται ένα θετικό ακέραιο n και θα επιστρέφει την τιμή TRUE ή FALSE
ανάλογα με το αν ο n είναι ή όχι αντίστοιχα πρώτος αριθμός
 διαδικασία createPrimeSet που θα δέχεται δύο θετικούς ακεραίους, έστω first και last, και θα
δημιουργεί και επιστρέφει το σύνολο των πρώτων αριθμών που ανήκουν στο διάστημα [first .. last]
 διαδικασία displaySet που δέχεται τον πρώτο αριθμό first ενός συνόλου θετικών ακεραίων S και
εμφανίζει τα στοιχεία του συνόλου στην ίδια γραμμή με ένα κενό χαρακτήρα μεταξύ τους.
Στη συνέχεια, γράψτε κυρίως πρόγραμμα όπου θα διαβάζονται δύο ακέραιοι αριθμοί, έστω first και last,
που θα πρέπει να ανήκουν στο διάστημα [2..200] και επιπλέον να ισχύει first < last. Στη συνέχεια, θα
καλούνται οι διαδικασίες createPrimeSet και displaySet για τη δημιουργία και εμφάνιση του συνόλου των
πρώτων αριθμών που ανήκουν στο διάστημα [first .. last].
Να χρησιμοποιηθεί ο ΑΤΔ σύνολο με πίνακα. Η διαδικασία displaySet θα δέχεται ένα σύνολο θετικών
ακεραίων S, τον πρώτο (first) και τον τελευταίο (last) αριθμό αυτού του συνόλου*/

#define megisto_plithos 201
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);


void menu(int *choice);
void displayset(int first, int last,typos_synolou set);

boolean isPrime (stoixeio_synolou n);

void createPrimeSet(stoixeio_synolou high, stoixeio_synolou low, typos_synolou synolo);

int main(){
int first, last,s1;
typos_synolou synolo;

do{
        printf("Dwse to first: ");
        scanf("%d", &first);
    }while(first < 2 || first > 200);

    do{
        printf("Dwse to last: ");
        scanf("%d", &last);
    }while(last < 2 || last > 200 || last <= first);

    createPrimeSet(first,last,synolo);

    displayset(first, last, synolo);

}

void menu(int *choice)
{
  printf("\nXRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit SetADT\n");
  printf("1 ---- DHMIOYRGIA SYNOLOU\n");
  printf("2 ---- KA8OLIKO\n");
  printf("3 ---- EISAGWGH\n");
  printf("4 ---  DIAGRAFH\n");
  printf("5 ---  MELOS\n");
  printf("6 ---- KENO SYNOLO\n");
  printf("7 ---- ISA SYNOLA\n");
  printf("8 ---- YPOSYNOLO\n");
  printf("9 ---- ENOSH 2 SYNOLWN\n");
  printf("10 ---- TOMH 2 SYNOLWN\n");
  printf("11 ---- DIAFORA SYNOLOU\n");
  printf("12 ---- EXIT\n");
  printf("\nChoice 1-12: ");
  do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>12);
}


void displayset(int first, int last, typos_synolou set)
{
	stoixeio_synolou i;

	for (i=first;i < last;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}

void Dimiourgia(typos_synolou synolo)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    return synolo[stoixeio];
}

boolean KenoSynolo(typos_synolou synolo)

{
    stoixeio_synolou i;
    boolean keno;

    keno=TRUE;
    i = 0;

    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = FALSE;
        else
            i++;
    }
    return keno;
}

boolean IsaSynola(typos_synolou s1, typos_synolou s2)

{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)

{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}
boolean isPrime(stoixeio_synolou n)
{

    if(n <= 1) return FALSE;
    if(n <= 3) return TRUE;

    if(n % 2 == 0 || n % 3 == 0) return FALSE;

    for(int i = 5; i * i <= n; i = i + 6)
        if(n % i == 0 || n % (i + 2) == 0) return FALSE;

    return TRUE;
}

void createPrimeSet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou synolo){
stoixeio_synolou i;
   Dimiourgia(synolo);
    for(i=first; i<=last; i++) {
        if(isPrime(i))
            Eisagogi(i, synolo);

   }

}



