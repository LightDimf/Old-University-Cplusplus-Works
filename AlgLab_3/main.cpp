#include <iostream>
#include <string>
using namespace std;

class SCL //"Symply-Connected List"
{
	unsigned int ListSize=0; //������ ������
	struct Item
	{
		int value;
		Item *next=NULL;
	}*list=NULL; //������ �������
	Item* access(int n) //��������� ������� � ��������
	{
		if(n>=0 && n<=ListSize && list!=NULL)
		{
			Item *current=list;
			for(short count=0; count<n; count++)
				current=current->next;
			return current;
		}
		else
			return NULL;
	}
	public:
		
		void print()
		{
			puts("List:");
			Item *current=list;
			if(list==NULL)
			{ puts("/Empty list/"); return; }
			while(current->next!=NULL)
			{
				printf("%d ", current->value);
				current = current->next;
			}
			printf("%d ", current->value);
			putchar('\n');
		}
		void add(int i, int n)
		{
			if(n>0 && n<ListSize) //���� �� ������
			{
				Item *NewEl=new Item, *current=access(n);
				NewEl->value=i;
				NewEl->next=current->next;
				current->next=NewEl;
			}
			else if(n==0) //���� ��������� ������� � ������
			{
				if(list!=NULL) 
				{
					Item *Pre=new Item;
					Pre->next = list;
					list=Pre;
					list->value=i;
				}
				else //���� ������ ����
				{
					list=new Item;
					list->value = i;
				}
			}
			else if(n==ListSize) //���� ��������� � �����
			{
				Item *NewEnd=new Item;
				NewEnd->value=i;
				access(ListSize-1)->next=NewEnd;
			}
			else //���� �� �� ������
			{ puts("Invalid index"); return; }
			ListSize++;
		}
		void remove(int n)
		{
			if(n>0 && n<ListSize-1)
			{
				Item *before=access(n-1), *removing=access(n);
				before->next=removing->next;
				delete removing;
			}
			else if(n==0)
			{
				if(list!=NULL) 
				{
					Item *temp=list;
					list=list->next;
					delete temp;
				}
				else
				{ puts("*List are empty. Nothing to remove*"); return; }
			}
			else if(n==ListSize-1)
			{
				Item *NewEnd=access(n-1), *RemovingEnd=access(n);
				NewEnd->next=NULL;
				delete RemovingEnd;
			}
			else
			{ puts("Invalid index"); return; }
			ListSize--;
		}
		int size() 
		{ return ListSize; }
		void sort()
		{
			if(list==NULL)
			{
				puts("*List are empty. Nothing to sort*");
				return;
			}
			for(short i=0; i<ListSize; i++) //Bubble Sort
				for(short j=ListSize-1; j>i; j--)
					if((access(j)->value) < (access(j-1)->value))
					{
						if(j>1 && j<=ListSize-1)
						{
							Item *before, *one, *two, *after; //1.����������� ����������
							before=access(j-2);//2.������������� ����������
							one=access(j-1);
							two=access(j);
							after=access(j+1);
							before->next=two;//3.���� ���������
							two->next=one;
							one->next=after;
						}
						else  //(j<=0)
						{
							Item *first, *two , *after;
							first=list;
							two=access(1);
							after=access(2);
							first->next=after;
							list=two;
							two->next=first;
						}
					}
		}
};

int main()
{
	SCL List;
	puts("Welcome. Symply-Connected List has created. Enter \"info\" to get full information");
	string input;
	while(1)
	{
		putchar('>');
		cin>>input;
		if(input=="print")
			List.print();
		else if(input=="add")
		{
			int v, p;
			cin>>v>>p;
			if(cin.good())
				List.add(v,p);
			else
				puts("Invalid input");
		}
		else if(input=="size")
			printf("Size: %d\n", List.size());
		else if(input=="remove")
		{
			int p;
			cin>>p;
			if(cin.good())
				List.remove(p);
			else
				puts("Invalid input");
		}
		else if(input=="sort")
			List.sort();
		else if(input=="exit")
			return 0;
		else if(input=="info")
			puts("INFO: (value - v; positin - p)\ninfo - you know\nprint - print list into cmd\nadd v p - add value in list\nremove p - remove element from list\nsize - view size of list\nsort - sort list\nexit - exit from programm");
		else
			puts("Invalid input");
		cin.clear();
		cin.ignore(10000, '\n');
	}
}
