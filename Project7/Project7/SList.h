#include <stdio.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTData Type data;
	struct SListNode * next;
}SLTNode;
void SListPrint(SLTNode *p);
void SListPushBack(SLTNode **q,SLTDataType x);
void SListPushFront(SLTNode **q, SLTDataType x);
void SListPopBack(SLTNode **q);
void SListPopFront(SLTNode **q);