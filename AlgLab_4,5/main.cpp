//main.cpp
#include <iostream>
#include <string>
#include "queue.h"
#include "Doubly_linked_list.h"
#define ERROR_PROC_ cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); continue; //Обработка ошибок ввода
#define FUNC_ERROR_PROC_(a) if(cin.good()) {(a);} else {ERROR_PROC_} //обработка ошибок с функцией
using namespace std;

int main()
{
	DLL List;
	Queue Cherga;
	puts("Welcome to the ASD Lab #4\nEnter \"help\" to get information");
	while(1)
	{
		static string word_1, word_2;
		putchar('>');
		cin>>word_1;
		if(word_1=="help")
		{
			puts("/Doubly-Linked List and Queue/\nSyntax:\nName_of_structure name_of_function [parametrs]\n/Example: Queue print /or/ DLL add 3 1\nEnter \"*Name_of_structure* doc\" to see documentation");
		}
		else if(word_1=="DLL")
		{
			cin>>word_2;
			if(word_2=="print")
				List.print();
			else if(word_2=="ReversePrint")
				List.ReversePrint();
			else if(word_2=="add")
			{
				int v; cin>>v;
				if(cin.peek()=='\n')
				{
					FUNC_ERROR_PROC_(List.add(v))
				}
				else
				{
					int p; cin>>p;
					FUNC_ERROR_PROC_(List.add(v,p))
				}
			}
			else if(word_2=="remove")
			{
				int p; cin>>p;
				FUNC_ERROR_PROC_(List.remove(p))
			}
			else if(word_2=="size")
				printf("Size: %d\n", List.size());
			else if(word_2=="sort")
				List.sort();
			else if(word_2=="doc")
				List.doc();
			else
			{ERROR_PROC_}
		}
		else if(word_1=="Queue")
		{
			cin>>word_2;
			if(word_2=="pop")
				printf("First element with value %d have removed from queue\n", Cherga.pop());
			else if(word_2=="push")
			{
				int v; cin>>v;
				FUNC_ERROR_PROC_(Cherga.push(v))
			}
			else if(word_2=="show")
				Cherga.show();
			else if(word_2=="size")
				printf("Size: %d\n", Cherga.size());
			else if(word_2=="doc")
				Cherga.doc();
			else
			{ERROR_PROC_}
		}
		else if(word_1=="exit")
			return 0;
		else
		{ERROR_PROC_}
	}
}
