#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SListPrint(SLTNode *p)
{
	SLTNode *cur = p;
	while (cur != NULL)
	{
		printf("%d->", cur->datSLTNodea);
		cur = cur->next;
	}
	printf("NULL\n");
}
SListNode *BuySLTNode(SLTDataType x)
{
	SLTNode * node = (SLTNode *)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}
void SListPushBack(SLTNode **q, SLTDataType x)
{
	STLNode *newnode = BuySLTNode(x);
	if (**q = NULL)
		**q = newnode;
	else
	{
		SLTNode *tail = **q;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newnode;

	}
}
void SListPushFront(SLTNode **q,SLTDataType x)
{
	SLTNode *newnode = BuySLTNode(x);
	newnode->next = **q;
	**q = newnode;
}
void SListPopBack(SLTNode **q, SLTDataType x)
{
	if (*q = NULL)
		return;
	else if ((*q)->next == NULL)
	{
		free(*q);
		*q = NULL;
	}
	else
	{
		SLTNode *prev = NULL;
		SLTNode * tail = *q;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}