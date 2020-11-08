#include "Queue.h"

Queue::Queue()
	:pFront(NULL),size(0)
{
	
}

Queue::~Queue()
{
	if(pFront == NULL)
		return;

	delete pFront;
	pFront = NULL;
}

Status Queue::push(const int &data)
{
	return 0;
}

Status Queue::pop(int &_out)
{
	return 0;
}