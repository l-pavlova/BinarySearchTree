#include "stack.h"



bool Stack::full() const
{
	return top==MAX_STACK-1;
}

Stack::Stack()
{
	top = EMPTY_STACK;
}

bool Stack::empty()
{
	return top==EMPTY_STACK;
}

bool Stack::push(int const& x)
{
	if (full())
	{
		cerr << "Opit za vkarvane v pulen stek"<<endl;
		return false;
	}
	a[++top] = x;
	return true;
	
}

int Stack::pop()
{
	if (empty())
	{
		cerr << "Opit za izvajdane ot prazen stek" << endl;
		return 0;
	}

	return a[top--];
}

int Stack::peek() const
{
	return a[top];
}
