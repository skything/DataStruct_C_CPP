#include "List.h"

Node* Node_New(const int dat)
{
    Node* p = (Node *)SafeMalloc(sizeof(Node));

    if (p == NULL)
        return NULL;

    p->data = dat;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void Node_Delete(Node** pthis)
{
    if (pthis == NULL || *pthis == NULL)
        return;

    (*pthis)->data = 0;
    SafeFree((void **)pthis);
}

void List::List_Test()
{
	pHead = Node_New(0);
	pTail = Node_New(0);
	
	Node_t K = Node_New(1);
	Node_t P = Node_New(2);
	Node_t L = Node_New(3);
	Node_t A = Node_New(4);
	Node_t B = Node_New(5);
	Node_t C = Node_New(6);
	
	pHead->next = K;
	K->prev = pHead;
	Size++;
	
	K->next = P;
	P->prev = K;
	Size++;

	
	P->next = L;
	L->prev = P;
	Size++;
	
	L->next = A;
	A->prev = L;
	Size++;
	
	A->next = B;
	B->prev = A;
	Size++;

	B->next = C;
	C->prev = B;
	Size++;
	
	C->next = pTail;
	pTail->prev = C;
	
	// Delete
	Node_t _pTmp = pHead->next->next;
    Node_t _pDel = pHead->next;
    uSize end = Size;
	for(uSize i = 0;i < end;i++){
		Node_Delete(&_pDel);
        _pDel = NULL;
        _pDel = _pTmp;
        _pTmp = _pTmp->next;
        Size--;
	}
	
	Node_Delete(&pTail);
	pTail = NULL;

	pHead->next = NULL;
	pHead->prev = NULL;
	Node_Delete(&pHead);
	pHead = NULL;
}

List::~List()
{
    Node_t _pTmp = pHead->next->next;
    Node_t _pDel = pHead->next;
    uSize end = Size;
	for(uSize i = 0;i < end;i++){
		Node_Delete(&_pDel);
        _pDel = NULL;
        _pDel = _pTmp;
        _pTmp = _pTmp->next;
        Size--;
	}

    Node_Delete(&pTail);
    pTail = NULL;

    pHead->next = NULL;
    pHead->prev = NULL;
    Node_Delete(&pHead);
    pHead = NULL;

    Size = 0U;
}

Status List::List_Insert(const int& index, const int& data)
{
    uSize idx = static_cast<uSize>(index);

    // Valid: 1 to Size + 1
    if (idx <= 0 || idx > Size + 1)
        return -2;

    if (idx <= 1)
        return List_HeadInsert(data);
    else if (idx >= Size + 1)
        return List_TailInsert(data);

    uSize mid = Size / 2;
    if (idx <= mid)
        return List_NormalInsert(idx, data);

    return List_TravelInsert(idx, data);
}

Status List::List_Delete(const int& index, int& out)
{
    if (index < 1 || (uSize)index > Size)
        return -1;

    if (index <= 1)
        return List_DeleteFromHead(out);
    else if ((uSize)index >= Size)
        return List_DeleteFromTail(out);
    
    Node_t _Ptl = pHead->next;
    for (int i = 2; i < index; i++)
        _Ptl = _Ptl->next;

    Node_t _pDelete = _Ptl->next;
    Node_t _pTN = _Ptl->next->next;

    _Ptl->next = _pTN;
    _pTN->prev = _Ptl;

    out = _pDelete->data;
    Node_Delete(&_pDelete);
    Size--;
    return 0;
}

Status List::List_DeleteFromTail(int& out)
{
    if (pTail->prev == NULL || pTail->prev->prev == NULL)
        return -1;

    Node_t _pOp = pTail->prev;
    Node_t _pPrv = pTail->prev->prev;

    out = _pOp->data;
    _pPrv->next = pTail;
    pTail->prev = _pPrv;

    Node_Delete(&_pOp);

    Size--;
    return 0;
}

Status List::List_DeleteFromHead(int& out)
{
    if (pHead->next == NULL || pHead->next->next == NULL)
        return -1;

    Node_t _pTp   = pHead->next;
    Node_t _pTNxt = pHead->next->next;

    out = _pTp->data;
    _pTNxt->prev = pHead;
    pHead->next = _pTNxt;

    Node_Delete(&_pTp);
    Size--;
    return 0;
}

Status List::List_HeadInsert(const int& data)
{
    Node_t pObh = Node_New(data);
    if (pObh == NULL)
        return -1;

    if (pHead == NULL) {
        pHead = Node_New(0);
        pTail = Node_New(0);

        pHead->next = pObh;
        pObh->next = pTail;
        pObh->prev = pHead;
        pTail->prev = pObh;

        Size++;
        return 0;
    }

    // old head
    // Head -> 1 -> 2 -> 3 ->Tail
    Node_t pTmp = pHead->next;

    pObh->next = pTmp;
    pHead->next = pObh;
    pObh->prev = pHead;
    pTmp->prev = pObh;

    Size++;
    return 0;
}

Status List::List_TailInsert(const int& data)
{
    Node_t pObt = Node_New(data);
    if (pObt == NULL)
        return -1;

    if (pHead == NULL) {
        pHead = Node_New(0);
        pTail = Node_New(0);

        pHead->next = pObt;
        pObt->next = pTail;
        pTail->prev = pObt;
        pObt->prev = pHead;

        Size++;
        return 0;
    }

    // Head -> 1  ->  2  -> 3 -> Tail
    Node_t pNode = pTail->prev;

    pObt->next = pTail;
    pNode->next = pObt;
    pObt->prev = pNode;
    pTail->prev = pObt;

    Size++;
    return 0;
}

Status List::List_ChangeValue(const int& index, const int& data)
{
    Node_t _pOOb = operator[](index);

    if (_pOOb == NULL)
        return -1;

    _pOOb->data = data;
    return 0;
}

Status List::List_LookForValue(const int& data, int& _out) const
{
    int pS = 0;
    for (Node_t pTmp = pHead->next; pS < (int)Size; pTmp = pTmp->next,pS++) {
        if (pTmp->data == data) {
            _out = pS;
            return 0;
        }
    }        

    return -1;
}

Status List::List_Travel(void)
{
    //Head And Tail Not Travel
    // Current
	// TODO
    Node_t prv = pHead;
    Node_t cur = NULL;
    Node_t nxt = NULL;

    // Head -> 1 -> 2 -> 3 -> 4 -> 5 -> Tail
    cur = pHead->next;//1
    nxt = pHead->next->next;//2
    prv->next = NULL;

    for (; cur != pTail;) {
        prv->prev = cur;//Head
        cur->next = prv;
        cur->prev = nxt;
        nxt->prev = nxt->next;//Get 3
        nxt->next = cur;

        prv = prv->prev;//1
        cur = cur->prev;//2
        nxt = nxt->prev;//3
        cur->prev = NULL;
    }

    // Swap the Head and Tail Pointer
    pTail->next = NULL;
    for (Node_t tmp = pHead; tmp->next != NULL; tmp = tmp->next)
        pTail = tmp->next;

    return 0;
}

Status List::List_NormalInsert(const uSize& idx, const int& data)
{
    Node_t pObj = Node_New(data);
    if (pObj == NULL)
        return -1;

    // Head -> 1  ->  2  -> 3 -> Tail
    Node_t pN = pHead->next;
    for (uSize i = 2; i < idx; i++)
        pN = pN->next;

    // pN:1  pNx:2
    Node_t pNx = pN->next;

    pObj->next = pNx;
    pN->next = pObj;
    pObj->prev = pN;
    pNx->prev = pObj;

    Size++;
    return 0;
}

Status List::List_TravelInsert(const uSize& idx, const int& data)
{
    Node_t pObk = Node_New(data);
    if (pObk == NULL)
        return -1;

    Node_t pP = pTail->prev;
    for (uSize k = Size; k > idx; k--)
        pP = pP->prev;

    Node_t pNW = pP->prev;
    pNW->next = pObk;
    pObk->next = pP;
    pP->prev = pObk;
    pObk->prev = pNW;

    Size++;
    return 0;
}

void List::List_Show() const
{
    Node_t p = pHead->next;

    for (; p != pTail; p = p->next) {
        std::printf("%d\n", p->data);
    }
}

Node_t List::operator[](const int index)
{
    Node_t _pNode = pHead->next;
    for (int i = 0; i < index; i++) {
        _pNode = _pNode->next;

        if (_pNode == NULL)
            return NULL;
    }

    return _pNode;
}

