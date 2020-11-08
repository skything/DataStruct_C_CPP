#ifndef _C_MEMORY_H
#define _C_MEMORY_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif
#if 0
    void* SafeMalloc(size_t size);
#else
	#define SafeMalloc(size) malloc((size_t)size)
#endif
    void  SafeFree(void** ptr);
	
	#define SaferMalloc(size) safeMalloc((size_t)size)
	#define SaferFree(ptr) SafeFree((void **)&ptr)
#ifdef __cplusplus
}
#endif

#endif