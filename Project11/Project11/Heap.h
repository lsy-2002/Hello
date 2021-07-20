#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
typedef int HPDataType;
//´ó¶Ñ
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//HP* HeapInit(HPDataType* a, int n);
void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int parent);
void AdjustUp(int* a, int child);
void HeapInit(HP*php,HPDataType* a, int n);
void HeapDestory(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void HeapPrint(HP* php);