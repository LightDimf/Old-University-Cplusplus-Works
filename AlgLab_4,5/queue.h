//queue.h
#pragma once

class Queue
{
	int QueueSize=0;
	struct Element;
	Element *Q_First=NULL, *Q_End=Q_First;
	public:
		int pop();
		void push(int i);
		unsigned int size();
		void show();
		static void doc();
};
