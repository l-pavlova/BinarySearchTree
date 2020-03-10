#include "IntStack.h"

bool IntStack::full()
{
	return top>=capacity-1;
}
void swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
void IntStack::resize()
{
	
		int new_capacity = capacity * 2;
		int *new_arr = new int[new_capacity];
		for(int i=0;i<capacity;i++)
		{
			new_arr[i] = a[i];
		}
		delete[]a;
		a = new_arr;
		capacity = new_capacity;
	
}

IntStack::IntStack()
{
	capacity = STACK_CAPACITY;
	top = EMPTY_STACK;
	a = new int[capacity];
}

IntStack::~IntStack()
{
}

void IntStack::push(int element)
{
	if(full())
	{
		resize();
	}
	top++;
	a[top] = element;
}

int IntStack::pop()
{
	if(empty())
	{
		cerr << "empty stack sry";
		return 0;
	}
	return a[top--];
	
}

int IntStack::peek() const
{

	return a[top];
}

bool IntStack::empty()
{
	return top == EMPTY_STACK;
}

void IntStack::print() const
{
	for(int i=top;i>=0;i--)
	{
		cout << a[i] << endl;
	}
	cout << "____________________" << endl;
}

void IntStack::sortStack()
{
	for(int i=0;i<=top;i++)
	{
		for(int j=0;j<=top;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
