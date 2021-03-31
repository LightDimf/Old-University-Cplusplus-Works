#include "iostream"
using namespace std;

short gmas[16], gmas_2[12], size;

void first()
{
	short fib[12]={1,1};
	cout<<"/First 12 Fibonacci numbers/\n>"<<fib[0]<<","<<fib[1];
	for(short i=2;i<12;i++)
		cout<<","<<(fib[i]=fib[i-1]+fib[i-2]);
	cout<<"\n";
}

void second()
{
	int n;
	short mas[16], i;
	size=0;
	cout<<"/Reverse number n/\n[1111<n<99999999]\nEnter n:";
	cin>>n;
	if(n>1111&&n<99999999)
	{
		for(i=0;i<16;i++)
		{
			mas[i]=n%10;
			n/=10;
			if(n==0)
				size++;
		}
		for(i=0;(17-size)>i;i++)
		{
			cout<<mas[i];
			gmas[i]=mas[i];
		}
		cout<<"\n";
	}
	else
		cout<<"Error.\n";
}

void third()//add 10 to even and divides into 3 odd numbers from before function
{
	for(short i=0;(17-size)>i;i++)
	{
		if(gmas[i]%2==0)
			gmas[i]+=10;
		else
			gmas[i]/=3;
		cout<<gmas[i];
	}
	cout<<"\n";
}

void fourth()//First 12 natural numbers multiples of 13 or 17
{
	short i=0;
	for(short c=300; i<12; c++)
		if(c%13==0 || c%17==0)
		{
			gmas_2[i]=c;
			cout<<gmas_2[i]<<"\n";
			i++;
		}
}

void fifth()
{
	short i;
	cout<<"/Enter -1 to end/\n(Enter index of massive from before task)\n";
	while(1)
	{
		cout<<"Ent i:";
		cin>>i;
		if(i>=0 && i<12)
			cout<<gmas_2[i]<<"\n";
		else if(i==-1)
			break;
		else
			cout<<"Error";
	}
}

int main()
{
	cout<<"*Please, don't enter char symbols*\n/Enter 0 to exit/\n";
	for(short i;1;i=0)
	{
		cout<<"Enter task number:";
		cin>>i;
		cout<<"\n";
		switch(i)
		{
			case 0: return 0;
			case 1: first();  break;
			case 2: second(); break;
			case 3: third();  break;
			case 4: fourth(); break;
			case 5: fifth();  break;
			default: cout<<"404. Task not found.\n";
		}
	}
}
