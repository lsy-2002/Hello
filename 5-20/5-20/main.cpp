#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
//c语言
typedef int DataType;
struct Stack
{
	DataType* a;
	int size;
	int capacity;
};
void StackPush(struct Stack* ps,DataType x);
//数据和方法是分离的，重点关注的是过程-》函数方法

//C++
//类-》定义出一个新的类型
//类由两部分构成：1、成员变量（属性）2、成员函数（行为）
//C++中struct兼容C的所有用法，同时C++中把struct升级成类
typedef int DataType;
struct Stack//class Stack
{
	void Init(int Initsize = 4)
	{
		a = (DataType*)malloc(sizeof(DataType));
		size = 0;
		capacity = Initsize;
	}
	void Push()
	{
		//...
	}
	//...
	DataType* a;//成员变量的声明
	int size;
	int capacity;
};
int main()
{
	//类
	Stack st;//定义
	st.Init();//定义
	//...
	Stack s1;//类的实例化
	Stack s2;//类的实例化
	return 0;

}

//f.h
typedef int DataType;
class Stack//声明和定义分离
{
public:
	void Init(int Initsize = 4);
	void Push();
	DataType* a;
	int size;
	int capacity;
};
int main()
{
	return 0;
}
class Person
{
public:
	void Print();
private:
	char name[20];
	int num[10];

};
//需要指定Print是属于Person这个类域
void Person::Print()
{}*/
class A1
{
public:
	void f1(){}
private:
	int _a;
};
class A2
{
public:
	void f2(){}
};
class A3
{};
int main()
{
	A1 a1;
	cout << sizeof(a1) << endl;//4
	A2 a2;
	//大小是1 是占位，表示对象存在过
	cout << sizeof(a2) << endl;//1
	A3 a3;
	cout << sizeof(a3) << endl;//1
}