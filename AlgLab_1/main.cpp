#include <cstdio> //ֱûסענוו ט לוםüרו קול iostream
#include <cstdlib>
#include <ctime>
using namespace std;

short BubbleSort(short *arr)
{
	short t;
	for(short i=0; i<20; i++)
		for(short j=19; j>i; j--)
			if(arr[j]<arr[j-1])
			{
				t=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=t;
			}
}
short InsertionSort(short *arr)
{
	short t;
	for(int i=1; i<20; i++)     
		for(int j=i; j>0 && arr[j-1]>arr[j]; j--)
			{
				t=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=t;
			}
}
short SelectionSort(short *arr)
{
	short t, min;
	for(short i=0; i<20; i++)
	{
		min=i;
		for(short j=i+1; j<20; j++)
			if(arr[j]<arr[min])
				min=j;
		if(min!=i)
		{
			t=arr[i];
			arr[i]=arr[min];
			arr[min]=t;
		}
	}
}

void tsk1(short *arr)
{
	short A[20];
	int Test1, Test2, B1, B2, I1, I2, S1, S2;
	Test1=clock();
	for(short i=0; i<10000; i++)
		for(short i=0; i<20; i++) A[i]=arr[i];
	Test2=clock();
	Test1=Test2-Test1;
	B1=clock();	
	for(short i=0; i<10000; i++)
	{
		for(short i=0; i<20; i++) A[i]=arr[i];
		BubbleSort(A);
	}
	B2=clock();
	I1=clock();
	for(short i=0; i<10000; i++)
	{
		for(short i=0; i<20; i++) A[i]=arr[i];
		InsertionSort(A);
	}
	I2=clock();
	S1=clock();
	for(short i=0; i<10000; i++)
	{
		for(short i=0; i<20; i++) A[i]=arr[i];
		SelectionSort(A);
	}
	S2=clock();
	printf("Bubble sort: %d pts\nInsertion sort: %d pts\nSelection sort: %d pts\n", B2-B1-Test1, I2-I1-Test1, S2-S1-Test1);
}
void tsk2(short *arr)
{
	short A[20], min=0, max=0, amin, amax;
	for(short i=0; i<20; i++)
	{
		A[i]=arr[i];
		if(A[i]<A[min])
			min=i;
		if(A[i]>A[max])
			max=i;
	}
	min<max? (amin=min, amax=max) : (amin=max, amax=min);
	printf("Min:%d: %d | Max:%d: %d\nAmin:%d | Amax:%d\nSorted array:\n",min,A[min],max,A[max],amin,amax);
	for(short i=0; i<20; i++)
	{
		if(i==amin)
		{
			for(short t; i<amax; i++)
				for(short j=amax-1; j>i; j--)
					if(A[j]<A[j-1])
					{
						t=A[j];
						A[j]=A[j-1];
						A[j-1]=t;
					}
			if(min<max)
				for(short j=amin; j<amax; j++)
					printf("%d ", A[j]);
			else
				for(short j=amax-1; j>amin-1; j--)
					printf("%d ", A[j]);
		}
		printf("%d ", A[i]);
	}
	putchar('\n');
}
void tsk3(short *arr)
{
	short A[20], t;
	for(short i=0; i<20; i++) A[i]=arr[i];
	for(short i=0; i<20; i++)
	{
		for(short j=9; j>i; j--)
			if(A[j]<A[j-1])
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			}
		for(short j=19; j>i+10; j--)
			if(A[j]<A[j-1])
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			}
	}
	for(short i=0; i<10; i++) printf("%d ", A[i]);
	for(short i=19; i>=10; i--) printf("%d ", A[i]);
	putchar('\n');
}

int main()
{
	srand(time(NULL));
	short arr[20];
	puts("Array: ");
	for(short i=0; i<20; i++)
		{ arr[i]=-20+rand()%61;  printf("%hi ", arr[i]); }
	puts("\n*Please, don't enter char symbols*\n/Info: 0 to exit/");
	for(short i; 1; i=0)
	{
		printf("Enter task number: ");
		scanf("%hi", &i);
		putchar('\n');
		switch(i)
		{
			case 0: return 0;
			case 1: tsk1(arr); break;
			case 2: tsk2(arr); break;
			case 3: tsk3(arr); break;
			default: puts("404. Task not found.");
		}
	}
}
