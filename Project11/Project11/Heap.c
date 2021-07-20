#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void Swap(HPDataType* p1, HPDataType* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(HPDataType* a, int n, HPDataType parent)
{
	int child = parent * 2 + 1;
	while (child < n){

		if (child + 1 < n && a[child + 1] > a[child]){
			++child;
		}

		if (a[child] > a[parent]){
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(HP*php, HPDataType* a, int n)
{
	assert(php);
	php->a =(HPDataType*) malloc(sizeof(HPDataType)* n);
	if (php->a = NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType)*n);
	php->size = n;
	php->capacity = n;
	//建堆
	for (int i = (php->size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, php->size, i);
	}
}
void HeapDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->size = php->capacity = 0;
}
void HeapPush(HP* php, HPDataType x)
{
	//满了，需要增容
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size - 1] = x;
	AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a);
	}
	printf("\n");
	int num = 0;
	int levelSize = 1;
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		num++;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n");
}