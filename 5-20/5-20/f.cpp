#define _CRT_SECURE_NO_WARNINGS 1
#include "main.cpp"
//f.cpp
void Stack::Init(int Initsize)
{
	a = (DataType*)malloc(sizeof(DataType));
	size = 0;
	capacity = Initsize;
}
void  Stack::Push()
{
	//...
}
//...