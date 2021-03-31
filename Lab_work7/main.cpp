#include <iostream> 
using namespace std;

void primes(short pr)
{
	for(short sub=pr/2; sub!=1; sub--)
		if(pr%sub==0)
			return;
	cout<<pr<<' ';
}

int tsk2(int f, int t)
{
	short sum_f=0, sum_t=0;
	for(int tmp=f; tmp; tmp=tmp/10)
		sum_f+=tmp%10;
	for(int tmp=t; tmp; tmp=tmp/10)
		sum_t+=tmp%10;
	return sum_f>sum_t? f : t;
}
int tsk3(int i1, int i2)
	{return i1>i2? i1 : i2;}
void tsk4(short ave, int *mas)
{
	for(short i=0; i<10; i++)
	{
		if(*mas>ave)
			cout<<*mas<<' ';
		mas++;
	}
	cout<<'\n';
}
void tsk5()
{
	//too hard task; too few time
}
void tsk6(long n)
{
	short bigger=0;
	for(; n; n=n/10)
		if(n%10>bigger)
			bigger=n%10;
	cout<<"Bigger digit: "<<bigger<<'\n';
}
int tsk7(int f, int t)
	{return f<t? f : t;}

void tsk8(double n, short d)
{
	for(short tmp=n; d>1; d--)
		n*=tmp;
	cout<<"Result: "<<n<<'\n';
}
double tsk9(double n)
{
	for(short tmp=n-1; tmp>1; tmp--)
		n*=tmp;
	return n;
}
void tsk10(int *p)
{
	long sum=0;
	for(short i=0; i<10; i++)
		sum+=*(p+i);
	cout<<"Sum: "<<sum<<'\n';
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
			case 1: 
				for(short pr=100; pr<=999; pr++)
					primes(pr);
				cout<<'\n';
				break;
			case 2: 
				int f,t;
				cout<<"Enter 2 numbers (returns numbers which sum of digits is bigger):\n";
				cin>>f>>t;
				cout<<tsk2(f,t)<<'\n'; 
				break;
			case 3:
			   {cout<<"Enter 6 numbers, and get bigger:\n";
				int nums[6], bigger=0, tmp;
				for(short i=0; i<6; i++)
					cin>>nums[i];
				for(short i=0; i<5; i++)
					{
						tmp=tsk3(nums[i], nums[i+1]);
						if(tmp>bigger)
							bigger=tmp;
					}
				cout<<"Bigger number is: "<<bigger<<'\n';
				break;}
			case 4: 
			   {cout<<"Enter 10 numbers, and get amount of numbers which bigger then average value of them:\n";
				int mas[10];
				short ave=0;
				for(short i=0; i<10; i++)
					cin>>mas[i];
				for(short i=0; i<10; i++)
					ave+=mas[i];
				ave/=10;
				tsk4(ave, &mas[0]);  
				break;}
			case 5: tsk5();  break;
			case 6: 
				long n;
				cout<<"Enter number and get bigger digit: ";
				cin>>n;
				tsk6(n);
				break;
			case 7:
				int f7, t7;
				cout<<"Enter 2 numbers and get smaller: \n";
				cin>>f7>>t7;
				cout<<"Smaller: "<<tsk7(f7, t7)<<'\n';
				break;
			case 8: 
				short n8, deg;
				cout<<"Enter number and it's degree and get result:\n";
				cin>>n8>>deg;
				tsk8((double)n8, deg);
				break;
			case 9: 
				short n9;
				cout<<"Enter n, and get n!: "; //max 170
				cin>>n9;
				cout<<n9<<"!="<<tsk9((double)n9)<<'\n';
				break;
			case 10:
			   {cout<<"Enter 10 numbers and get sum:\n";
			    int mas10[10];
				for(short i=0; i<10; i++)
					cin>>mas10[i];
				tsk10(&mas10[0]); 
				break;}
			default: cout<<"404. Task not found.\n";
		}
	}
}
