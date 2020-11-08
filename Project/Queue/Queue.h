#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "../List/list.h"

class Queue
{
	public:
		Queue();
		~Queue();
		Status push(const int &data);
		Status pop(int &_out);
		bool IsEmpty() const {return size == 0;}
	private:
		List *pFront;
		uSize size;
};

#endif