//用数组的方式实现栈
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;
typedef struct Stack
{

	STDataType* a;
	int top;//栈顶
	int capacity;//容量，方便增容
}Stack;




void StackInit(Stack* s);//初始化
void StackDestory(Stack* s);//销毁
void StackPush(Stack* s,STDataType x);//入栈
STDataType StackPop(Stack* s);//出栈
STDataType StackTop(Stack* s);//返回栈顶元素
bool StackEmpty(Stack* s);//判断是否为空
int StackSize(Stack* s);//栈中元素有多少


	

