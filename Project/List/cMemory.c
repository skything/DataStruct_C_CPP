#include "cMemory.h"

// TODO
#if 0
static uint32_t _UsedCount = 0;
void SafeMalloc(void **p,size_t size)
{
	p = NULL;
    p = malloc(size);	
    return p;
}
#endif

void  SafeFree(void** ptr)
{
    if (ptr == NULL || *ptr == NULL)
        return;

    free(*ptr);
    *ptr = NULL;
}