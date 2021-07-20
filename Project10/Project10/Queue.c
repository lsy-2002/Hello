#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void QueueInit(Queue* p)
{
	assert(p);
	p->head = p->tail = NULL;
}//初始化
void QueueDestroy(Queue* p)
{
	assert(p);
	QueueNode* cur = p->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	p->head = p->tail = NULL;
}//销毁
void QueuePush(Queue* p, QDataType x)
{
	assert(p);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode = NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	nownode->data = x;
	if (p->tail == NULL)
	{
		p->head = p->tail = newnode;
	}
	else
	{
		p->tail->next = newnode;
		p->tail = newnode;
	}
}//入队
void QueuePop(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	if (p->head->next == NULL)
	{
		free(p->head)
			p->head = p->tail = NULL;
	}
	else
	{
		QueueNode* next = p->head->next;
		free(p->head);
		p->head = next;
	}
	
}//出队
QDataType QueueFront(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->head->data;
}//返回对列的第一个元素值
QDataType QueueBack(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->tail->data;
}//返回队列的最后元素值
QDataType QueueEmpty(Queue* p);
{
	assert(p);
	//为空返回1，不为空返回0
	return p->head == NULL
}//判断是否为空
int QueueSize(Queue* p)
{
	int size = 0;
	QueueNode* cur = p->head;
	while (cur)
	{
		size++;
		cur = cur->next;
		return size;
	}
}//队列中元素有多少
int main()
{
	return 0;
}