#include <cstdio>
#include <cstdlib>
#include <ctime>
#define _SET_ARR  short size; printf("Array size: "); scanf("%hi", &size); short *arr=new short[size]; puts("Array:");
using namespace std;

short IsPrime(short num)
{
	if(num<2)
		return 0;
	for(short i=2; i<num/2; i++)
		if(num%i==0)
			return 0;
	return 1;
}

void tsk1()
{
	short count=0;
	_SET_ARR
	for(short i=0; i<size; i++)
	{
		arr[i]=rand()%101;
		printf("%hi ", arr[i]);
		count+=IsPrime(arr[i]);
	}
	short *PrimeArray=new short[count]; count=0;
	puts("\nPrime array:");
	for(short i=0; i<size; i++)
		if(IsPrime(arr[i]))
		{
			PrimeArray[count]=arr[i];
			printf("%hi ", PrimeArray[count++]);
		}
	putchar('\n');
}
void tsk2()
{
	short count_even=0, count_odd=0;
	_SET_ARR
	for(short i=0; i<size; i++)
	{
		arr[i]=rand()%51;
		printf("%hi ", arr[i]);
		arr[i]%2==0? count_even++ : count_odd++;
	}
	short *even=new short[count_even], *odd=new short[count_odd];
	count_even=0; count_odd=0;
	for(short i=0; i<size; i++)
		arr[i]%2==0 ? even[count_even++]=arr[i] : odd[count_odd++]=arr[i];
	puts("\nEvens:");
	for(short i=0; i<count_even; i++)
		printf("%hi ", even[i]);
	puts("\nOdds:");
	for(short i=0; i<count_odd; i++)
		printf("%hi ", odd[i]);
	putchar('\n');
}
void tsk3()
{
	_SET_ARR 
	short *min=arr, *max=arr;
	for(short i=0; i<size; i++)
	{
		arr[i]=rand()%51;
		printf("%hi ", arr[i]);
		if(arr[i]<*min) min=&arr[i];
		if(arr[i]>*max) max=&arr[i];
	}
	printf("\n&min: 0x%x\n&max: 0x%x\n", min, max);
	max>min? printf("&max-&min= 0x%x\n", max-min) : printf("&max-&min= -0x%x\n", min-max);
}
void tsk4()
{
	_SET_ARR
	for(short i=0; i<size; i++)
	{
		arr[i]=rand()%51;
		printf("%hi ", arr[i]);
	}
	short *p1=arr, *p2=arr;
	printf("\np1: %hi\np2: %hi\n", *(p1+2), *(p2+4)); //выводит третий и пятый элементы массива
}

int main()
{
	srand(time(NULL));
	puts("*Please, don't enter char symbols*\n/Info: 0 to exit/");
	for(short i;;)
	{
		printf("Enter task number: "); scanf("%hi", &i);
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
	}
}
