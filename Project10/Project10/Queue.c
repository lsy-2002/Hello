#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void QueueInit(Queue* p)
{
	assert(p);
	p->head = p->tail = NULL;
}//��ʼ��
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
}//����
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
}//���
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
	
}//����
QDataType QueueFront(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->head->data;
}//���ض��еĵ�һ��Ԫ��ֵ
QDataType QueueBack(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->tail->data;
}//���ض��е����Ԫ��ֵ
QDataType QueueEmpty(Queue* p);
{
	assert(p);
	//Ϊ�շ���1����Ϊ�շ���0
	return p->head == NULL
}//�ж��Ƿ�Ϊ��
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
}//������Ԫ���ж���
int main()
{
	return 0;
}