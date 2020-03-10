#pragma once
#include <iostream>

using namespace std;

template<typename T>
class AbstractStack
{
public:
	virtual bool empty()const = 0;

	virtual bool push(T const& x) = 0;

	virtual T pop() = 0;

	virtual T peek() = 0;
};