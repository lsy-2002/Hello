//������ķ�ʽʵ��ջ
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;
typedef struct Stack
{

	STDataType* a;
	int top;//ջ��
	int capacity;//��������������
}Stack;




void StackInit(Stack* s);//��ʼ��
void StackDestory(Stack* s);//����
void StackPush(Stack* s,STDataType x);//��ջ
STDataType StackPop(Stack* s);//��ջ
STDataType StackTop(Stack* s);//����ջ��Ԫ��
bool StackEmpty(Stack* s);//�ж��Ƿ�Ϊ��
int StackSize(Stack* s);//ջ��Ԫ���ж���


	

