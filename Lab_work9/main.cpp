#include <cstdio> //Ёта библиотека меньше и быстрее, чем iostream
#include <ctime>
#include <cstdlib>
using namespace std;

unsigned short size;

void subarr(short *A, short *B)//ќтнимание массивов из задани€ 3
{
	for(short i=0; i<size; i++)
	{
		for(short j=i; j<size; j++)
			if(A[i]==B[j])
			{ i++; break; }
		printf("%d ", A[i]);
	}
}
short *NewArray() //‘ункци€ создающа€ и инициализирующа€ случайными значени€ми массивы
{
	short *arr=new short[size];
	for(short i=0; i<size; i++, arr++)
		*arr=rand()%31;
	arr-=size;
	return arr;
}
void out(short *arr1, short *arr2=NULL) //‘ункци€ вывод€ща€ 1 или 2 массива
{
	if(arr2!=NULL) puts("A: ");
	for(short i=0; i<size; i++, arr1++)
		printf("%d ", *arr1);
	if(arr2!=NULL)
	{
	puts("\nB: ");
	for(short i=0; i<size; i++, arr2++)
		printf("%d ", *arr2);
	}
	putchar('\n');
}
void sort(short *arr, short asize=size)//—ортировка пузырьком
{
	short t;
	for(short i=0; i<asize; i++)
		for(short j=asize-1; j>i; j--)
			if(*(arr+j)<*(arr+j-1))
			{
				t=*(arr+j);
				*(arr+j)=*(arr+j-1);
				*(arr+j-1)=t;
			}
}

void tsk1()//Ёлементы четных и нечетных индексов мен€ютс€ местами
{
	short *arr=NewArray();
	out(arr);
	short t;
	for(short i=0; i<size-1; i+=2)
	{
		t=*(arr+i);
		*(arr+i)=*(arr+i+1);
		*(arr+i+1)=t;
	}
	out(arr);
}
void tsk2()
{
	short *A=NewArray(), *B=NewArray(), *C=new short[size*2];
	for(short i=0; i<size; i++, C++)
		*C=*(A+i);
	for(short i=0; i<size; i++, C++)
		*C=*(B+i);
	C-=size*2;
	sort(A);
	sort(B);
	sort(C, size*2);
	puts("Arrays:"); out(A,B);
	puts("C (A|B): ");
	short t=size; size*=2;
	out(C);
	size=t;
}
void tsk3()
{
	short *A=NewArray(), *B=NewArray();
	puts("Arrays:"); out(A,B);
	puts("A|B:");
	for(short i=0; i<size; i++)
		printf("%d ", *(A+i));
	for(short i=0; i<size; i++)
		printf("%d ", *(B+i));
	puts("\nA&B:");
	for(short i=0; i<size; i++)
		for(short j=i; j<size; j++)
			if(A[i]==B[j])
				printf("%d ", A[i]);
	puts("\nA-B:"); subarr(A,B);
	puts("\nB-A:"); subarr(B,A);
	puts("\n(A-B)|(B-A):");
	subarr(A,B); subarr(B,A);
	putchar('\n');
}

int main()
{
	srand(time(NULL));
	puts("*Please, don't enter char symbols*\n/Info: 0 to exit; -1 to change defaul size of arr/");
	printf("Enter default size of arrays: ");
	scanf("%hi", &size);
	for(short i; 1; i=0)
	{
		printf("Enter task number: ");
		scanf("%hi", &i);
		putchar('\n');
		switch(i)
		{
			case -1: printf("Enter new size of arrays: "); scanf("%d", &size); break;
			case 0: return 0;
			case 1: tsk1(); break;
			case 2: tsk2(); break;
			case 3: tsk3(); break;
			default: puts("404. Task not found.");
		}
	}
}
