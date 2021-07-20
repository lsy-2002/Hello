#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void TestList1()
{
	SLTNode *P = NULL;
	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPrint(p);
	SListPushFront(&p, 0);
	SListPrint(p);
	SListPopBack(&p);
	SListPopBack(&p);
	SListPopBack(&p);
	SListPopBack(&p);
	SListPopBack(&p);
	SListPopBack(&p);
	SListPrint(&p);
}
int main()
{
	TestList1();
	return 0;
}