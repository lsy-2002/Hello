//用链表实现
#pragma once
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;
void QueueInit(Queue* p);//初始化
void QueueDestroy(Queue* p);//销毁
void QueuePush(Queue* p, QDataType x);//入队
void QueuePop(Queue* p);//出队
QDataType QueueFront(Queue* p);//返回对列的第一个元素值
QDataType QueueBack(Queue* p);//返回队列的最后元素值
QDataType QueueEmpty(Queue* p);
int QueueSize(Queue* p);//队列中元素有多少