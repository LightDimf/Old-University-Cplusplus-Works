#include "iostream"
#include "cmath"
using namespace std;

void first()
{
	register unsigned int a,b,i;
	short c;
	cout<<"/Finding all prime numbers from a to b/\nEnter a:";
	cin>>a;
	cout<<"Enter b:";
	cin>>b;
	if(a==1)
		a++;
	if(a<b)
		for(cout<<"Primal numbers: ";a<=b;a++)
		{
			c=0;
			for(i=2;i<a;i++)
				if(a%i==0)
				{
					c++;
					break;
				}
			if(c==0)
				cout<<a<<"  ";
		}
	else
		cout<<"Error. a can't be bigger then b or less then zero\n";
	cout<<"\n";
}

void second()
{
	unsigned long long int nn, d, tmp;
	short i, md=0, c=0;
	cout<<"/Finding all maximal digits in natural number/\nEnter natural number:";
	cin>>nn;
	for(i=0; i<=1; i++)
		for(tmp=nn; tmp; tmp/=10)
		{
			d=tmp%10;
			if(i==0)
 				if(md<d)
 		    		md=d;
		    else
		    	if(md==d)
 		    		c++;
		}
	cout<<"Max digit:"<<md<<"\nNum of max digits:"<<++c<<"\n";	
}

int third()
{
	long long int fc, n;
	int mul=1;
	cout<<"/Finding reverse factorial(only for natural numbers)/\nEnter factorial:";
	cin>>fc;
	if(fc<1)
	{cout<<"Too small...\n"; return 0;}
	for(n=1;n<fc+1;n*=mul)
	{
		if(n==fc)
		{cout<<fc<<"="<<mul<<"!\n"; return 0;}
		mul++;
	}
	cout<<"Sorry. Natural n (n!="<<fc<<") not exist...\n";
	return 0;
}

void fourth()
{
	int n,i,p;
	cout<<"/Graphical representation of the divisibly of numbers fron 1 to n/\nEnter n:";
	cin>>n;
	if(n>1)
	{
		for(i=1;n>=i;i++)
		{
			cout<<i;
			for(p=1;p<=i;p++)
				if(i%p==0)
					cout<<"+";
			cout<<"\n";
		}
	}
	else
	{cout<<"n must be bigger then 1\n"; fourth();}
}

void fifth()
{
	register int i,n,r;
	cout<<"/This function search all perfect numbers from 1 to 100000/\nP.N.:\n";
	for(n=2;n<=100000;n++)
	{
		r=0;
		for(i=1;n>i;i++)
			if(n%i==0)
				r+=i;
		if(r==n)
			cout<<n<<"\n";
	}
}

void sixth()//didn't happened with nested loop.
{
	int i;
	double res=0;
	cout<<"sqrt(1+sqrt(2+...+sqrt(50))...) = ";
	for(i=50;i!=0;res=sqrt(res+i--)){}
	cout<<res<<endl;
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
			case 1: first(); break;
			case 2: second(); break;
			case 3: third(); break;
			case 4: fourth(); break;
			case 5: fifth(); break;
			case 6: sixth(); break;
			default: cout<<"404. Task not found.\n";
		}
	}
}
