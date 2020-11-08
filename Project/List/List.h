#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "cMemory.h"

typedef unsigned int uSize;
typedef signed int Status;

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct _Node Node;

    typedef struct _Node {
        Node* next;
        Node* prev;
        int data;
    }Node;

    Node* Node_New(const int dat);
    void Node_Delete(Node** pthis);
#ifdef __cplusplus
}
#endif

typedef _Node *Node_t;

class List
{
public:
    List() :pHead(NULL), pTail(NULL), Size(0) {}
    ~List();
	void   List_Test();
    Status List_Insert(const int &index,const int &data);
    Status List_Delete(const int& index, int& out);
    Status List_DeleteFromTail(int& out);
    Status List_DeleteFromHead(int& out);
    Status List_HeadInsert(const int& data);
    Status List_TailInsert(const int& data);
    Status List_ChangeValue(const int& index, const int& data);
    Status List_LookForValue(const int& data, int& _out) const;
    Status List_Travel(void);
    void   List_Show()const;
    bool   List_IsEmpty() const { return Size == 0; }
    // Static Function
    static int List_GetData(const Node_t& pNode) { return pNode->data; }
    // Operator Function
    Node_t operator[](const int index);
private:
    Status List_NormalInsert(const uSize &idx,const int& data);
    Status List_TravelInsert(const uSize &idx, const int& data);
private:
    Node_t pHead;// No data
    Node_t pTail;// No data
    uSize   Size;
};

#endif // LIST_H
