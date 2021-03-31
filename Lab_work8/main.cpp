#include "iostream"
using namespace std;

int tsk1(double a, short n)
{
	if(n<1)
		return 1;
	else
		return a*tsk1(a, n-1);
}
int tsk2(long nt)
{
	if(nt/10)
		return nt%10+tsk2(nt/10);
	else 
		return nt%10;
}
void tsk3(long n)
{
	if(!(n/10))
	{
		cout<<n%10;
		return;
	}
	cout<<n%10;
	tsk3(n/10);
}
int tsk4(int dec)
{
	if(dec<2)
		return dec;
	int b=2;
	short pow;
	for(pow=1; (dec-b*2)>=0; pow++)
		b*=2;
	return tsk1(10,pow)+tsk4(dec-b);
}
char hexsym(int dec) //It's so inefficiently. Alternative better (Look in main).
{
	switch(dec)
	{
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'A';
		case 11: return 'B';
		case 12: return 'C';
		case 13: return 'D';
		case 14: return 'E';
		case 15: return 'F';
	}
}
void tsk5(int dec, int rem=0)
{
	rem=dec%16;
	if(dec>=16)
		tsk5(dec/16,rem);
	cout<<hexsym(rem);
}

int main()
{
	cout<<"*Please, don't enter char symbols*\n/Enter 0 to exit/\n";
	for(short i; 1; i=0)
	{
		cout<<"Enter task number:";
		cin>>i;
		cout<<"\n";
		switch(i)
		{
			case 0: return 0;
			case 1:
				short a, n1;
				cout<<"a^n=b | Enter a and n:\n";
				cin>>a>>n1;
				cout<<tsk1((double)a,n1)<<'\n';
				break;
			case 2: 
				long nt;
				cout<<"Enter some natural number and get sum of digits: ";
				cin>>nt;
				cout<<tsk2(nt)<<'\n';
				break;
			case 3: 
				long n3;
				cout<<"Enter n, and get revers: ";
				cin>>n3;
				tsk3(n3);
				cout<<'\n';
				break;
			case 4:
				int dec4;
				cout<<"dec->bin\nEnter dec: ";
				cin>>dec4;
				cout<<"bin: "<<tsk4(dec4)<<'\n';
				break;
			case 5: 
				int dec5;
				cout<<"dec->hex\nEnter dec: ";
				cin>>dec5;
				cout<<"hex: ";
				tsk5(dec5);
				cout<<'\n';
				//[Alternative] cout<<hex<<dec5<<'\n';
				break;
			default: cout<<"404. Task not found.\n";
		}
	}
}
