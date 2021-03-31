//queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int QueueSize=0;
struct Queue::Element
{
	int value;
	Element *next=NULL;
} *Q_First=NULL, *Q_End=Q_First;

int Queue::pop()
{
	if(Q_First==NULL)
	{
		puts("Queue are empty");
		return 0;
	}
	int FirstValue=Q_First->value;
	Element *TempFirst=Q_First;
	Q_First=Q_First->next;
	delete TempFirst;
	QueueSize--;
	return FirstValue;
}
void Queue::push(int i)
{
	if(Q_First==NULL)
	{
		Q_First=new Element;
		Q_First->value=i;
		Q_End=Q_First;
		QueueSize++;
		return;
	}
	Element *NewEnd=new Element;
	Q_End->next=NewEnd;
	Q_End=NewEnd;
	Q_End->value=i;
	QueueSize++;
}
unsigned int Queue::size()
{ return QueueSize; }
void Queue::show()
{
	puts("Queue:");
	Element *current=Q_First;
	if(Q_First==NULL)
	{ puts("Queue are empty"); return; }
	while(current->next!=NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("%d ", current->value);
	putchar('\n');
}
void Queue::doc()
{
	puts("Queue documentation:\n\"First in, first out\"\n\nFunctions:\n#pop - return number from queue\n#push *int_value* - put integer in queue\n#size - return size of queue\n#show - print queue\n#doc - show documentation\n");
}
