//������ʵ��
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
void QueueInit(Queue* p);//��ʼ��
void QueueDestroy(Queue* p);//����
void QueuePush(Queue* p, QDataType x);//���
void QueuePop(Queue* p);//����
QDataType QueueFront(Queue* p);//���ض��еĵ�һ��Ԫ��ֵ
QDataType QueueBack(Queue* p);//���ض��е����Ԫ��ֵ
QDataType QueueEmpty(Queue* p);
int QueueSize(Queue* p);//������Ԫ���ж���