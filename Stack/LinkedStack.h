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
	// ñúçäàâàíå íà ïðàçåí ñòåê
	LinkedStack();
	// êîíñòðóêòîð çà êîïèðàíå
	LinkedStack(LinkedStack const& ls);
	// îïåðàöèÿ çà ïðèñâîÿâàíå
	LinkedStack& operator=(LinkedStack const& ls);
	// ïðîâåðêà çà ïðàçíîòà íà ñòåê
	bool empty() const;
	// âêëþ÷âàíå íà åëåìåíò è âðúùà äàëè å áèëî óñïåøíî
	bool push(T const& x);
};
