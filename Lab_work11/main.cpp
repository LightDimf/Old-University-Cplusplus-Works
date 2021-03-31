#include <iostream>
#include <string>
#define STR_INIT_ string str=input(); //Создание и инициализация строки
#define INTERVAL_ int m, n; interval(&m, &n); ERROR_PROC_ //Задание интервала с обработкой ошибок
#define ERROR_PROC_ if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); return;} //обработка ошибок ввода
#define ERROR_PROC_LOOP_ if(cin.fail()){cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); continue;} //Обработка ошибок ввода внутри цикла
using namespace std;

bool IsConsonat(const char ch) //Согласное ли
{
    static const string consonats="bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for(short i = 0; i<consonats.size(); i++)
        if(ch == consonats[i])
            return true;
    return false;
}
string input() 
{
	string str;
	printf("Input: ");
	cin.get(); getline(cin, str);
	return str;
}
void interval(int *m, int *n)
{
	printf("Enter interval: ");
	cin>>*m>>*n;
}

void tsk1()
{
	puts("/SubString/");
	STR_INIT_
	INTERVAL_
	string newstr(str.substr(m, n-m+1));
	cout<<"\nSubString: "<<newstr<<'\n';
}
void tsk2()
{
	puts("/Remove interval/");
	STR_INIT_
	INTERVAL_
	str=str.erase(m, n-m+1);
	cout<<"\nString without interval: "<<str<<'\n';
}
void tsk3()
{
	puts("/All matches/");
	STR_INIT_
	printf("Set searching character: ");
	char chr=getchar();
	cin.ignore(1000, '\n');
	printf("Character indexes: ");
	for(short i=0; i!=str.length(); i++)
		if(str[i]==chr)
			printf("%hi ", i);
	putchar('\n');
}
void tsk4()
{
	puts("Enter way to the treasure(And get it's coordinates)\nFormat: *Syde of the world* *Steps* (Example: West 5)\nEnter \"End 0\" to end");
	string str;
	short steps, OX=0, OY=0;
	while(1)
	{
		printf("> ");
		cin>>str>>steps;
		if(str=="End"&&steps==0)
			break;
		ERROR_PROC_LOOP_ 
		if(str!="North" && str!="South" && str!="East" && str!="West") 
		{
			puts("Error input");
			continue;
		}
		if(str=="North") OY+=steps;
		if(str=="South") OY-=steps;
		if(str=="East")  OX+=steps;
		if(str=="West")  OX-=steps;
	}
	printf("Coordinates: (%hi; %hi)", OX, OY);
}
void tsk5()
{
	puts("/Is it polyndrome string?/");
	STR_INIT_
	for(short i=0, size=str.size(); i<=size/2; i++)
		if(str[i]!=str[size-i-1])
		{
			puts("It's not a polyndrome"); return;
		}
	puts("It's a polyndrome");
}
void tsk6()
{
	puts("/Is it unvowel polyndrome?/\n*Enter 1 word**Only English*");
	string word;
	cin>>word;
	cin.ignore(1000, '\n');
	short consonat_amount=0;
	for(short i=0; i<word.size(); i++)
		if(IsConsonat(word[i]))
			consonat_amount++;
	for(short i=0, size=word.length(); consonat_amount/2; consonat_amount-=2)
	{
		for(;!IsConsonat(word[i]); i++);
		for(;!IsConsonat(word[size]); size--);
		if(word[i++]!=word[size--])
		{
			puts("It's not a unvowel polyndrome"); return;
		}
	}
	puts("It's a unvowel polyndrome");
}

int main()
{
	puts("/Info: 0 to exit; several nums through spaces to do several tasks at once/");
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
			case 5: tsk5(); break;
			case 6: tsk6(); break;
			default: puts("404. Task not found.");
		}
		putchar('\n');
	}
}
