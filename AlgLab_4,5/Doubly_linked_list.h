//Doubly_linked_list.h
#pragma once

class DLL
{
	int ListSize=0;
	struct Element;
	Element *First=NULL, *End=First;
	Element* access(int n);
	public:
		void print(bool rev=false);
		void ReversePrint();
		void add(int i, int n=-1);
		void remove(int n);
		unsigned int size();
		void sort();
		static void doc();
};
