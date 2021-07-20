#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s ;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,3);
	SeqListPushBack(&s,4);
	SeqListPushBack(&s,5);
	SeqListPopFront(&s,0);
	SeqListPopFront(&s,0); 
	SeqListPopFront(&s,0);
	SeqListPopFront(&s,0);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListDestory(&s);
}
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,3);
	SeqListPushBack(&s,4);
	SeqListPushBack(&s,5);
	SeqListPrint(&s);
	SeqListInsert(&s,2,30);
	SeqListPrint(&s);
	SeqListInsert(&s,0,30);
	SeqListPrint(&s);
	SeqListErase(&s,0);
	SeqListPrint(&s);
	SeqListModify(&s,10,8);
	SeqListDeatory(&s);

}
void menu()
{
	printf("************************************************\n");
	printf("1、尾插数据         2、头插数据\n");
	printf("3、尾删数据         4、头删数据\n");
	printf("5、查找数据         6、打印数据\n");
	printf("0、退出\n");
	printf("************************************************\n");
}
int removeDuplicates(int *num, int numsize)
{
	int *quick = num + 1;
	int *slow = num;
	int size = 0;
	while (1)
	{
		if (* slow >= num[numsize - 1])
		{
			size++;
			break;
		}
		if (*slow == *quick)
		{
			while (*slow == *quick)
				quick++;
			*(++slow) = *quick;
		}
		else
		{
			slow++;
			*slow = *quick;
		}
		size++;
	}
	return size;
}
int main()
{
	TestSeqList2();
	SeqList s;
	SeqListInit(&s);
	int option = 0;
	do
	{
		menu();
		scanf("%d", &option);
		int x;
		switch (option)
		{
		case 1:	printf("请输入数据，以-1结束\n");
				while (1)
				{
					scanf"%d",&x);
					if (x == -1)
						break;
				}break;
		case 2:	SeqListPushBack(&s); break;
		case 3:	SeqListPushFront(&s); break;
		case 4:	SeqListPopBack(&s); break;
		case 5:	SeqListPopFront(&s); break;
		case 6: SeqListPrint(&s); break;
		defaulf:printf("ERROR!\n"); break;
		}
		while (option != 0)
			SeqListDestory(&s);
	}
	
	return 0;
}