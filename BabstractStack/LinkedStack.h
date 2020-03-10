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
	// ��������� �� ������ ����
	LinkedStack();
	// ����������� �� ��������
	LinkedStack(LinkedStack const& ls);
	// �������� �� �����������
	LinkedStack& operator=(LinkedStack const& ls);
	// �������� �� �������� �� ����
	bool empty() const;
	// ��������� �� ������� � ����� ���� � ���� �������
	bool push(T const& x);
};