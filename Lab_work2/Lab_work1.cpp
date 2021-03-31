#include "iostream"
#include "cmath"
#define PI 3.14159265
using namespace std;

int first()
{
	int x;
	long double y;
	cout<<"y = {sin^2x, x>0;\n    {1-2sin^2, x<=0.\nEnter x:";
	cin>>x;
	cout<<endl;
	if(x>0)
		y=pow(sin(x*PI/180),2);
	else
		y=1-2*sin(pow(x,2)*PI/180);
	cout<<"y="<<y<<endl;
	return 0;
}

int second()
{
	int x,p;
	cout<<"\"Is x a polindrome?\"\nEnter x(Only 3 digits):";
	cin>>x;
	if((x/100)!=0 && (x/100)<10)
	{
		p=(x%10)*100+((x%100)/10)*10+x/100;
		if(p==x)
			cout<<"x is polindrome."<<endl;
		else
			cout<<"x isn't polindrome"<<endl;
	}
	else
		cout<<"Error. Number must have ONLY 3 DIGITS!"<<endl;
	return 0;
}

int third()
{
	int x,y;
	cout<<"Enter x:";
	cin>>x;
	cout<<"Enter y:";
	cin>>y;
	cout<<"|x-y|="<<abs(x-y)<<endl;
	if((x-y)>0)
		cout<<"sqrt(x-y)="<<sqrt(x-y)<<endl;
	else
		cout<<"sqrt(x-y)=*complex number*"<<endl;
	return 0;
}

int fourth()
{
	double a;
	cout<<"*\"a\" is a purchase amount*\nEnter a:";
	cin>>a;
	if(a>1000)
		cout<<"You have a 15% discount! Now your purchase amount:"<<a-(a/100)*15<<endl;
	else
		cout<<"You have not discount. Your purchase amount:"<<a<<endl;
	return 0;
}

int fifth()
{
	int a,b,c,D;
	cout<<"ax^2+bx+c=0\tx=?\t*a!=0*\nEnter a:";
	cin>>a;
	cout<<"Enter b:";
	cin>>b;
	cout<<"Enter c:";
	cin>>c;
	if(a!=0)
	{
		D=b*b-4*a*c;
		if(D>0)
			cout<<"x1="<<(-b+sqrt(D))/(2*a)<<"\nx2="<<(-b-sqrt(D))/(2*a)<<endl;
		else if(D=0)
			cout<<"x="<<-b/(2*a)<<endl;
		else
			cout<<"Function hasn't roots."<<endl;
	}
	else
		cout<<"a can't be 0"<<endl;
}

int sixth()
{
	int x1,y1,x2,y2,a1,b1,a2,b2,r1=0;
	cout<<"/You should enter coordinates left-down corners of rectangles and the length of their sides/"<<endl;
	cout<<"/a-horisontal side; b-vertical side/\n/R-rectangle/"<<endl;
	cout<<"Enter x1:";
	cin>>x1;
	cout<<"Enter y1:";
	cin>>y1;
	cout<<"Enter a1:";
	cin>>a1;
	cout<<"Enter b1:";
	cin>>b1;
	cout<<"Enter x2:";
	cin>>x2;
	cout<<"Enter y2:";
	cin>>y2;
	cout<<"Enter a2:";
	cin>>a2;
	cout<<"Enter b2:";
	cin>>b2;
	if((x1>=x2 && y1>=y2)&&(((a2-a1)-abs(x2-x1))>=0)&&(((b2-b1)-abs(y2-y1))>=0))
	{
		cout<<"a) All points of R1 belong to R2."<<endl;
		r1++;
	}
	else
		cout<<"a) R1 don't belong to R2."<<endl;
	if((r1==1)||((x2>=x1 && y2>=y1)&&(((a1-a2)-abs(x1-x2))>=0)&&(((b1-b2)-abs(y1-y2))>=0)))
		cout<<"b) R1 belong to R2, or R2 belong to R1."<<endl;
	else
		cout<<"b) R1 don't belong to R2 and R2 don't belong to R1."<<endl;
	if(((((x1+a1)<x2)&&((y1+b1)<y2))||(((x1+a1)<x2)&&((y2+b2)<y1)))||((((x2+a2)<x1)&&((y2+b2)<y1))||((x2+a2)<x1)&&((y1+b1)<y2)))
		cout<<"c) R1 doesn't intersect R2."<<endl;
	else
		cout<<"c) R1 intersect R2."<<endl;
	return 0;
}

int seventh()
{
	int a,b,c,d,along,across;
	cout<<"/a must > b, and c must > d/\nEnter a:";
	cin>>a;
	cout<<"Enter b:";
	cin>>b;
	cout<<"Enter c:";
	cin>>c;
	cout<<"Enter d:";
	cin>>d;
	if(a<b||c<d)
		{
			cout<<"Error"<<endl;
			seventh();
		}
	along=(a/c)*(b/d);
	across=(a/d)*(b/c);
	cout<<"\nAlong:"<<along<<"\nAcross:"<<across<<endl;
	if(along>across)
		cout<<"Along can fit more then across"<<endl;
	else
		cout<<"Across can fit more then along"<<endl;
	return 0;
}
int main()
{
	int i;
	cout<<"*Please, don't enter char symbols*\n/Enter 0 to exit/"<<endl;
	while(1)
	{
		i=0;
		cout<<"Enter task number:";
		cin>>i;
		cout<<endl;
		switch(i)
		{
			case 0:
				return 0;
			case 1:
				first();
				break;
			case 2:
				second();
				break;
			case 3:
				third();
				break;
			case 4:
				fourth();
				break;
			case 5:
				fifth();
				break;
			case 6:
				sixth();
				break;
			case 7:
				seventh();
				break;
			default:
				cout<<"Error. Task not found."<<endl;
		}
	}
}
