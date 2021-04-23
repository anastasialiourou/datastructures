/* �� ��� ������� ���� ������� ���������� � ����� ��� �������� ������� ������ ���� ��� ��� A ��� ���������
������ ������� �������� ���� �, ����������� �� ������������� ��� ������� ��� (�������, ��������, ������
���). ��������� ��� ������� ���� ���� ������, ��� ������� ������� �������� ��� ��� ���� ��������� �
������������, � ����������� ��� ������� ������ ����� ��������� � ������������. ������ ��������� ��
����� ������������ �� ������� ������������ ��� ��������, ��������������� ��� ��� ����. ���� ������� ���
���������� ���� ������� ������� �� ��� ���� ��������. ��� ���� ������ ��� ���������� �� ���������� ��
����� ������, �� �������� ���������, ��� ��� �������, ��� ��� ����� ��� ������������. � �������� �������
������� ��� ������������� ���� ���� �������� ����� 3. �� ��������� �� �������� ��� ���� ������ ��� ���
������ ��� ��� ����� ��������� �� �� ����� ��������, ���������������. � ��� ������ ��� � ������
��������� ������� �� ����� ����������� ������ �������.
���������� 3 �����������:
1. ��������� ��� �� �������� ��� ��� ������ ��� ��� ����� ��������� ��� ���� ������ �� �� �����
��������, ��������������� ��� �� ������� ��� ������ ���� ���� ��������. ��� ��� ��� ������� ���
��� ����� �� ������������ � ��������޻ ���� -1 (� �������� ��� ������� ���� ���� �������� �������� ����� - ������ 7 ��� 7
��� ��������� �� ������� ������ ��� ���������� ���� �������). � ��������� �� ����� void �� ���������
��� ���� ��������.
2. ��������� � ����� ������������ ��� ����������� ��� �������. ������ ����-���� ��� ������ ��� ���
���� �������� ��� ��� ���� ������ ��� ������������� �� ���������� ��� ��� ������� ��� ����� ���
������������ ��� �� ��������� ��� ������ ���� ���� ��������������� (��� ����). � ��� ������� ���
������������ ��� ������� ����� � ������ ������ ��� ������ ������ (��� ��� ����������� ���������). �
��������� ���� ��� ��������� ��� ���� �������� ��� ���������� ��� ���� ��� ���������������. ��
��������� ��� ���������� �����
QueueType TimesInQueue(QueueType *Queue)
3. ��������� �� 2 �����������: ��� �������� ��� �����, ��� ��� ����. �� � ���� ��� ����� ����� ��
��������� ��� ���� ������ ��� ������������� �����������, ��� �� ����� ����� �� ��������� �������
������ (��� ��� ����������� ���������).*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 4

typedef struct{
    int arrival,stay;
	int start,end;
} QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void menu(int *choice);
void TraverseQ(char qname[50],QueueType Queue);
void ReadCustomer(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);

int main(){
QueueType WaitingQueue,ServiceQueue;

CreateQ(&WaitingQueue);
CreateQ(&ServiceQueue);

for(int i=0;i<3;i++){
    printf("Give: arrival time,stay time for client %d: ",i+1);
    ReadCustomer(&WaitingQueue);
}
TraverseQ("Waiting Queue",WaitingQueue);
ServiceQueue=TimesInQueue(&WaitingQueue);
TraverseQ("Waiting Queue",WaitingQueue);
TraverseQ("Service Queue",ServiceQueue);
return 0;
}
void TraverseQ(char qname[],QueueType Queue) {
	int current;
	int i=1;
	if(!EmptyQ(Queue)){
        printf("\n%s\n",qname);
	current = Queue.Front;
	printf("Client \t\t\tStart\tEnd\tArrival\tStay\n");
	while (current != Queue.Rear) {
        printf("Client %d \t\t%d\t%d\t%d\t%d\n",i, Queue.Element[current].start,Queue.Element[current].end,Queue.Element[current].arrival,Queue.Element[current].stay);
		current = (current + 1) % QueueLimit;
		i++;
	} }
	else{
	printf("\n%s is empty\n",qname);
}

}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}

void ReadCustomer(QueueType *Queue){
QueueElementType tmpCustomer;
scanf("%d,%d",&tmpCustomer.arrival,&tmpCustomer.stay);
tmpCustomer.start=-1;
tmpCustomer.end=-1;
AddQ(&(*Queue),tmpCustomer);
}




QueueType TimesInQueue(QueueType *Queue){
int earliestStart =0;
int currentStart=0;
int currentEnd=0;

QueueType QueueServiced;
QueueElementType CurrentCust;
CreateQ(&QueueServiced);

while(!(EmptyQ(*Queue))){
RemoveQ(&(*Queue),&CurrentCust);

if(CurrentCust.arrival>earliestStart){

currentStart=CurrentCust.arrival;
}
else{

currentStart=earliestStart;
}
currentEnd=currentStart +CurrentCust.stay;

earliestStart=currentEnd;

CurrentCust.start=currentStart;
CurrentCust.end=currentEnd;

AddQ(&QueueServiced,CurrentCust);
}

return QueueServiced;
}



