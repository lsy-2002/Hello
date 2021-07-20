#pragma once 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SeqDataType;
typedef struct SeqList
{
	SeqDataType *a;
	int size;//��Ч���ݸ���
	int capacity;//����
}SeqList,SEQ;
//�ڴ��й������ݵĽṹ��ɾ�Ĳ�Ľӿ�

//
void SeqListInit(SeqList * pq);//��ʼ��
void SeqListDestory(SeqList * pq);//ɾ��˳���
void SeqListPrint(SeqList *pq);//��ӡ
void SeqListPushBack(SeqList * pq, SeqDataType x);//β��
void SeqListPushFront(SeqList * pq, SeqDataType x);//ͷ��
void SeqListPopBack(SeqList * pq);//ͷɾ
void SeqListPopFront(SeqList * pq);//βɾ
int SeqListFind(SeqList*pq,SeqDataType x);//����
void SeqListInsert(SeqList *pq,int pos, SeqDataType x);//����
void SeqListErase(SeqList *pq, int pos);//ɾ��
void SeqListModify(SeqList *pq,int pos, SeqDataType x);//�޸�