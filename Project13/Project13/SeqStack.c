#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqStack.h"
void StackInit(Stack* s)
{
	/*assert(s);
	s->a = NULL;
	s->top = 0;
	s->capacity = 0;*/
	s->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	s->top = 0;
	s->capacity = 4;
}//初始化
void StackDestory(Stack* s)
{
	assert(s);
	free(s->a);
	s->a = NULL;
	s->capacity = s->top = 0;
}//销毁
void StackPush(Stack* s, STDataType x)//性质决定在栈顶出入数据
{
	assert(s);
	if (s->top == s->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(s->a, sizeof(STDataType)*s->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		s->a = tmp;
		s->capacity *= 2;
	}
	s->a[s->top] = x;
	s->top++;
}//入栈
STDataType StackPop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	return s->a[s->top - 1];

}//出栈
STDataType StackTop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	return s->a[s->top - 1];
}//返回栈顶元素
bool StackEmpty(Stack* s)
{
	//空返回1，非空返回0
	assert(s);
	return s->top == 0;
}//判断是否为空
int StackSize(Stack* s)
{
	assert(s);
	return s->top;
}//栈中元素有多少
