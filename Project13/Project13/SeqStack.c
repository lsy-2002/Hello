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
}//��ʼ��
void StackDestory(Stack* s)
{
	assert(s);
	free(s->a);
	s->a = NULL;
	s->capacity = s->top = 0;
}//����
void StackPush(Stack* s, STDataType x)//���ʾ�����ջ����������
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
}//��ջ
STDataType StackPop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	return s->a[s->top - 1];

}//��ջ
STDataType StackTop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	return s->a[s->top - 1];
}//����ջ��Ԫ��
bool StackEmpty(Stack* s)
{
	//�շ���1���ǿշ���0
	assert(s);
	return s->top == 0;
}//�ж��Ƿ�Ϊ��
int StackSize(Stack* s)
{
	assert(s);
	return s->top;
}//ջ��Ԫ���ж���
