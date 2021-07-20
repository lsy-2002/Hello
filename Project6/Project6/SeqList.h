#pragma once 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SeqDataType;
typedef struct SeqList
{
	SeqDataType *a;
	int size;//有效数据个数
	int capacity;//容量
}SeqList,SEQ;
//内存中管理数据的结构增删改查的接口

//
void SeqListInit(SeqList * pq);//初始化
void SeqListDestory(SeqList * pq);//删除顺序表
void SeqListPrint(SeqList *pq);//打印
void SeqListPushBack(SeqList * pq, SeqDataType x);//尾插
void SeqListPushFront(SeqList * pq, SeqDataType x);//头插
void SeqListPopBack(SeqList * pq);//头删
void SeqListPopFront(SeqList * pq);//尾删
int SeqListFind(SeqList*pq,SeqDataType x);//查找
void SeqListInsert(SeqList *pq,int pos, SeqDataType x);//插入
void SeqListErase(SeqList *pq, int pos);//删除
void SeqListModify(SeqList *pq,int pos, SeqDataType x);//修改