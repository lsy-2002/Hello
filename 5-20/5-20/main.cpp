#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
//c����
typedef int DataType;
struct Stack
{
	DataType* a;
	int size;
	int capacity;
};
void StackPush(struct Stack* ps,DataType x);
//���ݺͷ����Ƿ���ģ��ص��ע���ǹ���-����������

//C++
//��-�������һ���µ�����
//���������ֹ��ɣ�1����Ա���������ԣ�2����Ա��������Ϊ��
//C++��struct����C�������÷���ͬʱC++�а�struct��������
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
	DataType* a;//��Ա����������
	int size;
	int capacity;
};
int main()
{
	//��
	Stack st;//����
	st.Init();//����
	//...
	Stack s1;//���ʵ����
	Stack s2;//���ʵ����
	return 0;

}

//f.h
typedef int DataType;
class Stack//�����Ͷ������
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
//��Ҫָ��Print������Person�������
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
	//��С��1 ��ռλ����ʾ������ڹ�
	cout << sizeof(a2) << endl;//1
	A3 a3;
	cout << sizeof(a3) << endl;//1
}