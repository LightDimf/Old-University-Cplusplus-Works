#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct STUDENT
{
	string NAME;
	string GROUP;
	short SES[5];
};

struct sdate
{
	short Mounth;
	short Day;
	short Year;
	void set()
	{
		printf("Enter DATE (MOUNTH/DAY/YEAR): ");
		scanf("%hi/%hi/%hi", &Mounth, &Day, &Year);
		if(Mounth>12 || Day>31)
		{
			puts("Input fail.");
			Mounth=0; Day=0;
			set();
		}
	}
	void get()
	{
		printf("%hi/", Mounth); printf("%hi/", Day); printf("%hi\n", Year);
	}
};
struct stime
{
	short Hour;
	short Minute;
	void set()
	{
		printf("Enter TIME (HOUR:MINUTE): ");
		scanf("%hi:%hi", &Hour, &Minute);
		if(Hour>59 || Minute>59)
		{
			puts("Input fail.");
			Hour=0; Minute=0;
			set();
		}
	}
	void get()
	{
		if(Hour<10)
			printf("0%hi:", Hour);
		else
			printf("%hi:", Hour);
		if(Minute<10)
			printf("0%hi\n", Minute);
		else
			printf("%hi\n", Minute);
	}
};
struct TRAIN
{
	string NAZV;
	short NUMR;
	sdate DATE;
	stime TIME;
};

int comp (const short *first, const short *second)//for qsort();
	{ return *first - *second; }
void tsk1()
{
	short arr[20];
	puts("Array: ");
	for(short i=0; i<20; i++) //инициализация массива
	{ arr[i]=rand()%20+1;  printf("%hi ", arr[i]); }
	qsort(arr, 10, sizeof(short), (int(*)(const void *, const void *)) comp);//Функция быстрой сортировки из стандартной библиотеки
	qsort(arr+10, 10, sizeof(short), (int(*)(const void *, const void *)) comp);//Отдельно сортируем вторую половину
	for(short i=0, t; i<5; i++) //реверс второй половины массива
	{
		t=arr[i+10];
		arr[i+10]=arr[19-i];
		arr[19-i]=t;
	}
	putchar('\n');
	for(short i=0; i<20; i++) printf("%hi ", arr[i]);
	puts("\n/Enter number, and get its index in array; 0 to exit/");
	short num, middle, left, right, index;
	while(1)
	{
		index=-1;
		printf("Num: ");
		scanf("%hi", &num);
		if(num==0) break;
		printf("Index: ");
		left=0; right=9;
		while(1)//ищем число в первой половине
		{
			middle=(left+right)/2;
			if(num<arr[middle]) right=middle-1;
			else if(num>arr[middle]) left=middle+1;
			else {index=middle; break;}
			if(left>right) break;
		}
		if(index==-1)
		{
			left=10; right=19;
			while(1)//ищем во второй половине
			{
				middle=(left+right)/2;
				if(num>arr[middle]) right=middle-1;
				else if(num<arr[middle]) left=middle+1;
				else {index=middle; break;}
				if(left>right) break;
			}
		}
		if(index==-1) puts("Not found\n");
		else printf("%hi\n\n", index);
	}
}
void tsk2()
{
	STUDENT blank;
	printf("Enter name: ");  cin>>blank.NAME;
	printf("Enter group: "); cin>>blank.GROUP;
	printf("Enter 5 SES/Through the space/: ");
	for(short i=0; i<5; i++)
		cin>>blank.SES[i];
	puts("Enter field name that you would to see [For example: \">NAME\" or \">SES3\"; 0 to exit]:");
	string inp;
	while(1)
	{
		putchar('>');
		cin>>inp;
		if(inp=="NAME")
			cout<<blank.NAME<<'\n';
		else if(inp=="GROUP")
			cout<<blank.GROUP<<'\n';
		else if(inp=="SES1"||inp=="SES2"||inp=="SES3"||inp=="SES4"||inp=="SES5")//Это проще регулярных выражений
		{
			short n=inp[3]-'0';
			printf("%hi\n", blank.SES[n-1]);
		}
		else if(inp=="0") break;
		else 
			puts("Error input");
	}
}
void tsk3()
{
	TRAIN poyezd;
	printf("Enter NAZV: "); cin>>poyezd.NAZV;
	printf("Enter NUMR: "); cin>>poyezd.NUMR;
	poyezd.DATE.set();
	poyezd.TIME.set();
	puts("Enter field name that you would to see [For example: \">NAZV\" or \">DATE\"; 0 to exit]:");
	string inp;
	while(1)
	{
		putchar('>');
		cin>>inp;
		if(inp=="NAZV")
			cout<<poyezd.NAZV<<'\n';
		else if(inp=="NUMR")
			cout<<poyezd.NUMR<<'\n';
		else if(inp=="DATE")
			poyezd.DATE.get();
		else if(inp=="TIME")
			poyezd.TIME.get();
		else if(inp=="0") break;
		else 
			puts("Error input");
	}
}

int main()
{
	srand(time(NULL));
	puts("/Please, don't enter char symbols/\n/Info: 0 to exit/");
	for(short i; 1; i=0)
	{
		printf("Enter task number: "); scanf("%hi", &i);
		putchar('\n');
		switch(i)
		{
			case 0: return 0;
			case 1: tsk1(); break;
			case 2: tsk2(); break;
			case 3: tsk3(); break;
			default: puts("404. Task not found.");
		}
	}
}
