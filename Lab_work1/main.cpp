#include <iostream>
using namespace std;

void tsk1()
{
	float f,s;
	cout<<"Enter 2 float numbers and get average\n";
	cin>>f>>s;
	cout<<"Average: "<<(f+s)/2<<'\n';
}
void tsk2()
{
	int f,s,t;
	cout<<"Enter 3 integer numbers and get sum and product:\n";
	cin>>f>>s>>t;
	cout<<"Sum: "<<f+s+t<<"\nProd: "<<f*s*t<<'\n';
}
void tsk3()
{
	cout<<"7 15 100\n";
}
void tsk4()
{
	char c;
	cout<<"a/b?\n>";
	cin>>c;
	if(c=='a')
	{
		int x;
		cout<<"y = 7x^2-3x+6\nEnter x:";
		cin>>x;
		cout<<"x = "<<7*(x*x)-3*x+6<<'\n';
	}
	else if(c=='b')
	{
		int a;
		cout<<"x = 12a^2+7a-16\nEnter a:";
		cin>>a;
		cout<<"x = "<<12*(a*a)+7*a-16<<'\n';
	}
	else
	cout<<"Error\n";
}
void tsk5()
{
	cout<<"234 days = "<<234/7<<" weeks\n";
}
void tsk6()
{
	short td;
	cout<<"Enter 2-didit number: ";
	cin>>td;
	if(td>9 && td<100)
		cout<<"a) The numbers of tens: "<<td/10<<"\nb) The numbers of ones: "<<td%10<<"\nc) Sum of digits: "<<td%10+td/10<<"\nd) Product of digits: "<<(td%10)*(td/10)<<'\n';
	else
		cout<<"Error\n";
}
void tsk7()
{
	short td;
	cout<<"Enter 2-digits number and get reversive: ";
	cin>>td;
	cout<<"Result: "<<td%10<<td/10<<'\n';
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
			case 1: tsk1(); break;
			case 2: tsk2(); break;
			case 3: tsk3(); break;
			case 4: tsk4(); break;
			case 5: tsk5(); break;
			case 6: tsk6(); break;
			case 7: tsk7(); break;
			default: cout<<"404. Task not found.\n";
		}
	}
}
