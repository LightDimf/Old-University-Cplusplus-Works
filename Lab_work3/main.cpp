#include "iostream"
using namespace std;

void first()
{
	int i;
	cout<<"55...87:\n";
	for(i=55;i<=87;i++)
		cout<<i<<" ";
	cout<<"\n";
}
void second()
{
	int i;
	cout<<"0...101:\n";
	for(i=0;i<=101;i++)
		cout<<i<<" ";
	cout<<"\n";
}
void third()
{
	int i;
	cout<<"200...50:\n";
	for(i=200;i>=50;i--)
		cout<<i<<" ";
	cout<<"\n";
}
void fourth()
{
	cout<<"7 9 11...<100:\n";
	for(int i=7;i<100;i+=2)
		cout<<i<<" ";
	cout<<"\n";
}
void fifth()
{
	int sum=0;
	cout<<"/sum of (1+...+100)/\n";
	for(int i=1;i<=100;i++)
		sum+=i;
	cout<<"sum="<<sum<<"\n";
}
void sixth()
{
	long int num, num2;
	int pow, pow2;
	cout<<"/number^power/\nEnter num:";
	cin>>num;
	num2=num;
	cout<<"Enter pow:";
	cin>>pow;
	for(pow2=pow;pow>1;pow--)
		num2=num2*num;
	if(pow2==0)
		num2=1;
	cout<<num<<"^"<<pow2<<"="<<num2<<endl;
}
void seventh()
{
	for(int mul_er=1; mul_er<10; mul_er++)
		cout<<"7*"<<mul_er<<"="<<mul_er*7<<endl;
}
void eighth()
{
	double mul=1;
	cout<<"/Multiplication of (1*...*50) (Factorial)/\n";
	for(int i=1;i<=50;i++)
		mul*=i;
	cout<<"50!="<<mul<<"\n";
}
void ninth()
{
	int sh=300;
	for(int i=1;i<=20;i++)
		cout<<"Price of sharovaia x"<<i<<" : "<<sh*i<<" griven\n";
}
void tenth()
{
	int k,d;
	char c;
	cout<<"\"What day?\"a/b?";
	cin>>c;
	if(c=='a')
		d=0;
	else if(c=='b')
	{
		cout<<"Enter d(1-7):";
		cin>>d;
		if(d<1 || d>7)
		{
			cout<<"Error\n";
			tenth();
		}
		d--;
	}
	else
	{
		cout<<"Error\n";
		tenth();
	}
	cout<<"Enter k:";
	cin>>k;
	if(k>=1 && k<=365)
	{
		while(k>0)
		{
			d++;
			k--;
			if(d>7)
				d=1;
		}
		switch(d)
		{
			case 1: cout<<"It's Monday\n"; break;
			case 2: cout<<"It's Tuesday\n"; break;
			case 3: cout<<"It's Wednesday\n"; break;
			case 4: cout<<"It's Thursday\n"; break;
			case 5: cout<<"It's Friday\n"; break;
			case 6: cout<<"It's Saturday\n"; break;
			case 7: cout<<"It's Sunday\n"; break;
			default: cout<<"Some error...\n";
		}
	}
	else
		cout<<"Error\n";
}
void eleventh()
{
	register short n,k,r=0;
	cout<<"\"From kopecks to rubles\"\nEnter n(kopecks):";
	cin>>n;
	if(n>=1 && n<=9999)
	{
		for(k=0;n>0;n--)
		{
			k++;
			if(k==60)
			{
				r++;
				k=0;
			}
		}
		cout<<"It's "<<r<<" rubles ";
		if(k!=0)
		{
			cout<<k<<" kopeks\n";
		}
		else
			cout<<"\n";
		//Without cycles it would be more effective:
		//cout<<"It's "<<n/60<<" rubles "<<n%60<<" kopecks\n";
	}
	else
		cout<<"Error\n";
}
int main()
{
	int i;
	cout<<"*Please, don't enter char symbols*\n/Enter 0 to exit/\n";
	while(1)
	{
		i=0;
		cout<<"Enter task number:";
		cin>>i;
		cout<<"\n";
		switch(i)
		{
			case 0: return 0;
			case 1: first(); break;
			case 2: second(); break;
			case 3: third(); break;
			case 4: fourth(); break;
			case 5: fifth(); break;
			case 6: sixth(); break;
			case 7: seventh(); break;
			case 8: eighth(); break;
			case 9: ninth(); break;
			case 10: tenth(); break;
			case 11: eleventh(); break;
			default: cout<<"404. Task not found.\n";
		}
	}
}
