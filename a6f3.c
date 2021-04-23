/* ��� ����������� ��������� ���� ����� ��� ������������ ���
������� ������ ��� ��� ������� �� ���������� ��� ���� ���� ������
��� ������ ��� ��� ���� ���� ��� ��� �� ��������� ��� ���� ���� ���
��� ������ ���������� ���� ��� �������� ���� �������� ������
Count ���� ������� ����� QueueType, ��� ����� ������������ �
������ ������� ��������� ��� �����. �� ������ ��� �����������
������� ��� ������ ��� ����� ��� �������� ��� ���� �������
����������� ��� ��� ���� �� �������, ���� ���� �� ���������������
���� �� �������� ����� ��� �� ��� ����������� ���� ���� ���� ������
���� ������������� �� �������� ��� �����. � TraverseQ ��� ���
������� ��� TestQueue �� ������ ������ �� ������������. ��� ��
�������� ��� �������� ��� ������������ ���
(a) ������������ ��� ���� (QueueLimit=10) ��� ������������
����� ���� ��������� �������� ��� �������� [0..9]. ���������
��� ���� (�� ��������� ���������� TraverseQ) ��� ���� ���
Front, Rear ��� ��� ������� ��� ��������� ��� �����.
(b) ��� �������� ����������� �� ���������� ��� �����������
��������. ��������� ��� ���� (�� ��������� ����������
TraverseQ)
(c) ��������� �� ������ ��� ����� ��� ��������� ��� ���� (��
��������� ���������� TraverseQ), �� �������� ��� ����������,
��� ���� ��� Front, Rear ��� ��� ������� ��� ��������� ��� �����
(d) ���������� ��� ����������� �������� ��� ��������� ��� ����
(�� ��������� ���������� TraverseQ), ��� ���� ��� Front, Rear
��� ��� ������� ��� ��������� ��� �����
(e) ��� �������� ����������� �� ���������� ��� �����������
��������. ��������� ��� ���� (�� ��������� ����������
TraverseQ), ��� ���� ��� Front, Rear ��� ��� ������� ���
��������� ��� �����.
(f) �������� ��� ����. ���� ��� �������� ���� ���� ��� �������
��� ����� ��������� ��� ���� (�� ��������� ����������
TraverseQ), �� �������� ��� ����������, ��� ���� ��� Front, Rear
��� ��� ������� ��� ��������� ��� �����.
� ������ ��� ������������ ������� ��� ������� ������.*/

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
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Count==0);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
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
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
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


