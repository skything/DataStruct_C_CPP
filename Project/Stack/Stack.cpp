#include "Stack.h"

_Stack::~_Stack()
{
    if (pTop == nullptr)
        return;

    delete pTop;
    pTop = nullptr;
}

Status _Stack::push(const int& val)
{
    static uSize index = 1;

    if (pTop == NULL) {
        pTop = new List;
        if (pTop->List_Insert(index, val) == 0) {
            index++;
            size++;
            return 0;
        }
        return -1;
    }

    if (pTop->List_Insert(index, val) == 0) {
        index++;
        size++;
        return 0;
    }
    return -2;
}

Status _Stack::pop(int& out)
{
    return pTop->List_DeleteFromTail(out);
}

int _Stack::GetTopVal() const
{
    return 0;
}
