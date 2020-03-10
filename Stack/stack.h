#pragma once
#include"AbstractStack.h"

const int MAX_STACK = 200;
const int EMPTY_STACK = -1;

class Stack :public AbstractStack<int>
{
private:
	int a[MAX_STACK];
	int top;
	
	bool full()const;
public:
	Stack();
	
	bool empty();

	bool push( int const& x);

	int pop();
	 
	int peek()const;
};
