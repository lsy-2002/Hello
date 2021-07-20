#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
ListNode* BuyListNode(LTDataType x)//�����½ڵ�
{
	ListNode* node = (struct ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void ListInit()//��ʼ��
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(ListNode* phead,LTDataType x)//β��
{
	/*assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	ListInsert(phead, x);
}
void ListPrint(ListNode* phead)//��ӡ
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushFront(ListNode* phead, LTDataType x)//ͷ��
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;	
}
void ListPushBack(ListNode* phead)//βɾ
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;
}
void ListPushFront(ListNode* phead)//ͷɾ
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}
ListNode ListFind(ListNode* phead, LTDataType x)//����ֵ��λ��
{
	assert(phead);
	ListNode*  cur = phead->next;
	while (cur !=phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos,LTDataType x)//����
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* pos)//ɾ��ĳλ�õĽڵ�
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;//��Ϊ1������Ϊ0
}
int ListSize(ListNode* phead)
{
	assert(phead);
	int size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	free(phead);

}