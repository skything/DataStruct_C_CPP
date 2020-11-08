#ifndef _STACK_H
#define _STACK_H

#include "List.h"

class _Stack
{
public:
	_Stack() :pTop(nullptr), size(0) {}
	~_Stack();
	Status push(const int& val);
	Status pop(int& out);
	bool isEmpty() const { return size == 0; }
	int    GetTopVal() const;
	uSize  GetSize() const { return size; }
private:
	List* pTop;
	uSize size;
};


#endif