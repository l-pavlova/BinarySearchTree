#pragma once
#include "AbstractStack.h"

template<typename T>
struct StackElement
{
	T data;
	StackElement* next;
};

template <typename T>
class LinkedStack:public AbstractStack<T>
{
	StackElement<T>* top;
	void copy(LinkedStack const& ls);
	void erase();

public:
	// създаване на празен стек
	LinkedStack();
	// конструктор за копиране
	LinkedStack(LinkedStack const& ls);
	// операция за присвояване
	LinkedStack& operator=(LinkedStack const& ls);
	// проверка за празнота на стек
	bool empty() const;
	// включване на елемент и връща дали е било успешно
	bool push(T const& x);
};