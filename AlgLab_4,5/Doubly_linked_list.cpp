//Doubly_linked_list.cpp
#include <iostream>
#include "Doubly_linked_list.h"
using namespace std;

int ListSize=0;
struct DLL::Element
{
	int value;
	Element *next=NULL;
	Element *pre=NULL;
} *First=NULL, *End=First;

DLL::Element* DLL::access(int n) //Получение доступа к элементу
{
	if(n>=0 && n<=ListSize && First!=NULL)
	{
		Element *current;
		if(n<ListSize/2)
		{
			current=First;
			for(size_t count=0; count<n; count++)
				current=current->next;
		}
		else
		{
			current=End;
			for(size_t count=ListSize; count>n+1; count--)
				current=current->pre;
		}
		return current;
	}
	else
		return NULL;
}
void DLL::print(bool rev)
{
	if(!rev)
		puts("List:");
	else
		puts("Reverse list:");
	
	if(First==NULL)
	{ puts("/Empty list/"); return; }
	Element *current;
	if(!rev)
	{
		current=First;
		while(current->next!=NULL)
		{
			printf("%d ", current->value);
			current = current->next;
		}
	}
	else
	{
		current=End;
		while(current->pre!=NULL)
		{
			printf("%d ", current->value);
			current = current->pre;
		}
	}
	printf("%d ", current->value);
	putchar('\n');
}
void DLL::ReversePrint()
{
	this->print(1);
}
void DLL::add(int i, int n)
{
	if(n==-1)  //Связанно с особенностями C++
		n=ListSize;
	if(n>0 && n<ListSize) //Если всё хорошо
	{
		Element *NewEl=new Element, *current=access(n), *PreEl=current->pre;
		NewEl->value=i;
		NewEl->next=current;
		NewEl->pre=PreEl;
		current->pre=NewEl;
		PreEl->next=NewEl;
	}
	else if(n==0) //Если добавляем элемент в начало
	{
		if(First!=NULL) 
		{
			Element *NewFirst=new Element;
			NewFirst->value=i;
			NewFirst->next = First;
			First=NewFirst;
		}
		else //Если список пуст
		{
			First=new Element;
			First->value = i;
			End=First;
		}
	}
	else if(n==ListSize) //Если добавляем в конец
	{
		Element *NewEnd=new Element;
		NewEnd->value=i;
		End->next=NewEnd;
		NewEnd->pre=End;
		End=NewEnd;
	}
	else //Если всё не хорошо
	{ puts("Invalid index"); return; }
	ListSize++;
}
void DLL::remove(int n)
{
	if(n>0 && n<ListSize-1)
	{
		Element *rem=access(n), *bef_el=rem->pre, *next_el=rem->next;
		bef_el->next=next_el;
		next_el->pre=bef_el;
		delete rem;
	}
	else if(n==0)
	{
		if(First!=NULL) 
		{
			Element *temp=First;
			First=First->next;
			delete temp;
		}
		else
		{ puts("*List are empty. Nothing to remove*"); return; }
	}
	else if(n==ListSize-1)
	{
		Element *RemEnd=End, *NewEnd=End->pre;
		NewEnd->next=NULL;
		delete RemEnd;
		End=NewEnd;
	}
	else
	{ puts("Invalid index"); return; }
	ListSize--;
}
unsigned int DLL::size() 
{ return ListSize; }
void DLL::sort()
{
	if(First==NULL)
	{
		puts("*List are empty. Nothing to sort*");
		return;
	}
	if(ListSize==1)
		return;
	for(size_t i=1; i<ListSize; i++)
	{
		static Element *current=First, *temp;
		current=current->next;
		temp=current;
		for(size_t j=i; j>0 && (temp->value)<(temp->pre->value); j--)
		{
			swap(temp->value, temp->pre->value);
			temp=temp->pre;
		}
	}
}
void DLL::doc()
{
	puts("Doubly-Linked List documentation\nList each element of which is associated with neighboring elements\nFunctions:\n#print - show list\n#RevervePrint - show reverse list\n#add *int_value* *int_index* - put integer into list at this index. If index not defined integer will put at end of list\n#remove *int_index* - remove element from index\n#size - return size of list\n#sort - sorting the list\n#doc - show documentation\n");
}
