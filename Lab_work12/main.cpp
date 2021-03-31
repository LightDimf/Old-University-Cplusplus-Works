#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define ERROR_PROC_ if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); return;}
#define ERROR_PROC_DEL_(x, y) if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); delet_2D(x,y); return;}
#define ERROR_PROC_LOOP_ if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); continue;}
using namespace std;

template <class T>
void delet_2D(T **arr, short size)//удаление двумерного массива
{
	for(size_t i=0; i<size; ++i)
		delete []arr[i];
	delete []arr;
}

void tsk1()
{
	short **triangle=new short*[10];
	for(size_t i=0; i<10; ++i)
	{
		triangle[i]=new short[i+1];
		for(size_t j=0; j<=i; ++j)
			printf("%hi ", triangle[i][j]=(i+1)*10+j);
		putchar('\n');
	}
	delet_2D(triangle, 10);
}
void tsk2()
{
	short **arr=new short*[5];
	for(size_t i=0; i<5; ++i)//инициализация и вывод
	{
		arr[i]=new short[5];
		for(size_t j=0; j<5; j++)
			printf("%hi ", arr[i][j]=rand()%20);
		putchar('\n');
	}
	for(short i=0; i<5; ++i)//сортировка
		for(short j=4; j>i; --j)
			if(arr[0][j]<arr[0][j-1])
				for(size_t k=0; k<5; ++k)
					swap(arr[k][j], arr[k][j-1]);
	putchar('\n');
	for(size_t i=0; i<5; ++i)//вывод
	{
		for(size_t j=0; j<5; ++j)
			printf("%hi ", arr[i][j]);
		putchar('\n');
	}
	delet_2D(arr, 5);
}
void tsk3()
{
	long double real[5];
	short results[5][3];
	printf("Enter 5 real numbers: ");
	cin>>real[0]>>real[1]>>real[2]>>real[3]>>real[4];
	ERROR_PROC_
	puts("Integer:  fract:  negative?:\n");
	for(size_t i=0; i<5; ++i)
	{
		static long double tmp;
		results[i][1]=(short)(modf(real[i], &tmp)*100000);
		printf("%hi   %hi   %hi\n", results[i][0]=tmp, results[i][1], results[i][2]=real[i]<0?1:0);
	}
}
void tsk4()
{
	short n, m, k;
	printf("Enter number of rows and number of sits: ");
	cin>>n>>m;
	ERROR_PROC_
	if(n==0 || m==0)
	{
		puts("Error input");
		return;
	}
	bool **cinema=new bool*[n];
	puts("Fill each sit (1-engaged, 0-free):");
	for(size_t i=0; i<n; ++i)
	{
		cinema[i]=new bool[m];
		for(size_t j=0; j<m; j++)
		{
			cin>>cinema[i][j];
			ERROR_PROC_DEL_(cinema, n)
		}
	}
	printf("Enter k: "); cin>>k;
	ERROR_PROC_DEL_(cinema, n)
	if(k==0)
	{
		puts("Error input");
		return;
	}
	if(k>m)
		putchar('0');
	for(size_t i=0; i<n; ++i)
	{
		static short count;
		count=0;
		for(size_t j=0; j<m; j++)
		{
			if(cinema[i][j]==0)
			{
				count++;
				if(count==k)
				{
					printf("%d\n", i+1);
					delet_2D(cinema, n);
					return;
				}
			}
			else
				count=0;	
		}
	}
	putchar('0');
	delet_2D(cinema, n);
}

int main()
{
	srand(time(NULL));
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
			case 3: tsk3(); break;
			case 4: tsk4(); break;
			default: puts("404. Task not found.");
		}
		putchar('\n');
	}
}
