#include <iostream>
#include <string>
#define ERROR_PROC_ if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); return;}
#define ERROR_PROC_LOOP_ if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); continue;}
using namespace std;

void print_hex(const int num)
{
	cout<<"hex: "<<hex<<num<<'\n';
}
void print_oct(const int num)
{
	cout<<"oct: "<<oct<<num<<'\n';
}
void print_bin(int num)
{
	string bin;
	printf("bin: ");
	do
	{
		bin+=num%2+'0';
		num/=2;
	}while(num>0);
	for(auto it=bin.crbegin(); it!=bin.crend(); ++it)
		putchar(*it);
	putchar('\n');
}
void tsk1()
{
	void (*num_sys[3])(int)={print_hex, print_oct, print_bin}; //Для выполнения условия задания
	printf("Enter dec: ");
	int dec;
	cin>>dec;
	ERROR_PROC_
	for(auto &x: num_sys)
		x(dec);
}

void sort(string *arr, const int n, int(*compare)(string, string))
{
	for(size_t i=0; i<n; ++i)
		for(size_t j=n-1; j>i; --j)
			if(compare(arr[j], arr[j-1])==-1)
				swap(arr[j], arr[j-1]);
}
int compare(string s1, string s2)
{
		if(s1<s2)
			return -1;
		else if(s1>s2)
			return 1;
		else 
			return 0;	
}
void tsk2()
{
	int NoS;
	printf("Enter num of strings: ");
	cin>>NoS;
	ERROR_PROC_
	string *str_arr=new string[NoS];
	puts("Enter strings:");
	for(size_t i=0; i<NoS; ++i)
		cin>>str_arr[i];
	sort(str_arr, NoS, compare);
	for(size_t i=0; i<NoS; ++i)
		cout<<str_arr[i]<<' ';
}

int main()
{
	puts("/Info: 0 to exit/");
	while(1)
	{
		static short i;
		printf("Task: "); cin>>i;
		ERROR_PROC_LOOP_
		putchar('\n');
		switch(i)
		{
			case 0: return 0;
			case 1: tsk1(); break;
			case 2: tsk2(); break;
			default: puts("404. Task not found.");
		}
		putchar('\n');
	}
}
