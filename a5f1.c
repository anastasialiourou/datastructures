/* ��� ����������, � ��������� Fibonacci �������� �� �� ������ ��� ������� ��� ���������� ��� ��
�������� ��� ��� ������������ ������� ��� �������. �� �������, �� 2 ������ ������� ��� ������� �����
�� 0,1. �� ������ ��������� �� ����� �� �������� ��� �������� �����������:
a. ��������� isFibonacci, � ����� ������� ���� ������ ������� n ��� ��� ��������� Fibonacci
(typos_synolou) ��� ���������� ��� ���� TRUE � FALSE ������� ��� � ������� ������ � ���
���������� ���� ��������� Fibonacci
b. ���������� createFibonacciSet � ����� �� ������� ���� ������ ������� threshold ��� �� ����������
��� ���������� �� ������ Fibonacci, ����� ��� ��� ������ ��� ����� ���������� � ���� ��� ���
������� �������.
��� ��������, ������ ������ ��������� �� ����� �� ������ ��� ��� ������ ���� ������� ������ max, �
������ ������ ��� �������� [2�1000] ��� �� ���������� ��� �� ��������� ��� ��������� Fibonacci, ����
�� ���������� �������� ��� �� ����� ��������� � ��� ��� max. ��������������� ��� ��������� ���
������ �� ������ ��� �� ���������� displaySet ��� �� TestSetADT.c ��� ��� �������� ��� �������.
�����, ���� ��� �������� ��� �������, � ������� �� ������ �� ������� �������� ������������, ����
������� �� ��������� �� ������� ��� �� ��� ������� ���� �������� ��������� Fibonacci ��� �� ��������������� - ������ 3 ��� 4
���������� ������*/

#define megisto_plithos 1001
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

boolean isFibonacci(int n, typos_synolou synolo);
void createFibonacciSet(int threshold, typos_synolou synolo);


void menu(int *choice);
void displayset(typos_synolou set);

int main()
{
    typos_synolou synolo;
    int num,max,tmp;


      do{
    printf("Dwse to megisto arithmo: ");
    scanf("%d", &max);
}while(max<2||max>1000);
createFibonacciSet(max,synolo);
displayset(synolo);
printf("\n");


    while (tmp>0){
        printf("Enter a number to check: ");
        scanf("%d", &tmp);
        if(tmp<0){ break;}
        if (tmp>=0||tmp<=1000){


   if(isFibonacci(tmp,synolo)){
        printf("Fibonacci!\n");
    }
    else {
        printf("Not Fibonacci...\n");
    }  }
    }





        return 0;

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


void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
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


boolean isFibonacci(stoixeio_synolou n,typos_synolou synolo) {
 if(Melos(n,synolo)){
    return TRUE; }
else {
    return FALSE;
}
}

void createFibonacciSet(int threshold, typos_synolou synolo){
int t1 = 0, t2 = 1, nextTerm = 0,i ;
Dimiourgia(synolo);
Eisagogi(t1,synolo);
for(i=2; i<=threshold; i++){
        Eisagogi(t2,synolo);
    nextTerm=t1+t2;
    if(nextTerm>threshold){break;}
    t1=t2;
    t2=nextTerm;

}

    }



