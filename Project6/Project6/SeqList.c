#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList * pq)
{
	assert(pq);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}
void SeqListDestory(SeqList * pq)
{
	assert(pq);
	free (pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}
void SeqListPrint(SeqList *pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
		printf("%d", pq->a[i]);
	printf("\n");
}
//���ˣ���Ҫ����
void SeqCheckCapacity(SeqList *pq)
{
	if (pq->size == pq->capacity)
	{
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
		SeqDataType * newA = realloc(pq->a, sizeof(SeqDataType)* newcapacity);
		if (newA == NULL)
		{
			printf("relloc fail\n");
			exit(-1);
		}
		pq->a = newA;
		pq->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList * pq, SeqDataType x)
{
	assert(pq);
	SeqCheckCapacity(pq);
	pq->a[pq->size] = x;
	pq->size++;
}
void SeqListPushFront(SeqList * pq, SeqDataType x)
{
	/*assert(pq);
	SeqCheckCapacity(pq);
	int end = pq->size - 1;
	while (end >= 0);
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[0] = x;
	pq->size++;*/
	SeqListInsert(pq, 0, x);
}
void SeqListPopBack(SeqList *pq)
{
	/*assert(pq);
	assert(pq->size > 0);
	--pq->size;*/
	SeqListErase(pq,pq->size - 1);
}
void SeqListPopFront(SeqList *pq)
{
	/*assert(pq);
	int begin = 0;
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->[begin + 1];
		begin++;
	}
	pq->size--;*/
	SeqListErase(pq, 0);
}
int SeqListFind(SeqList *pq, SeqDataType x)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		if (pq->a[i] == x)
			return i;
	}
	return -1;
}
void SeqListInsert(SeqList *pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	SeqCheckCapacity(pq);
	int end = pq->size - 1;
	while (end >= pos)
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[pos] = x;
	pq->size++;
}
void SeqListErase(SeqList *pq, int pos)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	int begin = pos;
	while (begin <= pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		++begin;
	}
	pq->size--;
}
void SeqListModify(SeqList *pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	pq->a[pos] = x;
}