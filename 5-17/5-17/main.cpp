#define _CRT_SECURE_NO_WARNINGS 1
//C++ ����C���﷨
/*
namespace N1//��N1Ϊ�����ռ�
{
	int a;//���Զ������
	int add(int a, int b)//���Զ��庯��
	{
		return a + b;
	}
}
#include <stdio.h>
int main()
{
	//������ͻ
	//C���ԵĿ�����scanf ����
	//������scanf��Ϊ������
	int scanf = 10;
	scanf("%d", &scanf);
}
#include <stdio.h>
namespace std
{
	int scanf = 10;
}
int main()
{
	//C���Բ��ܽ���ĳ�ͻ����
	//C++�����ռ䣬���ָ���
	printf("%x\n", scanf);
}
#include <iostream>
//C++Ϊ�˷�ֹ������ͻ�����Լ�������Ķ�����������std�Ŀռ�������
1ָ�������ռ�-���鷳��ÿ���ط�����д����淶
int main()
{
	std::cout << "hello world" << std::endl;
	return 0;
}
#include <iostream>
//2����std����չ�����൱�ڿ�����Ķ�������ȫ������-�����������㣬
//������������Լ�����Ķ�������ͻ��û�취���
using namespace std;
int main()
{
	cout << "hello world" << endl;
	return 0;
}
//3���Կ����泣�õĲ���չ��
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	cout << "hello world" << endl;
	return 0;
}
//��C�����Ӧ��
#include <stdio.h>
int a = 0;
int main()
{
	int a = 1;
	printf("%d\n", a);
	printf("%d\n", ::a);// ����ָ��������ߵ���-�����Ϊ�հ�-����ʾȫ����
}
#include <iostream>
#include <stdio.h>
//ostream ����ȫ�ֱ��� cout
//istream ����ȫ�ֱ��� cin
int main()
{
	/*cout ����
	cin ���
	endl����
	//�Ա�C���ԣ������Զ�ʶ������
	int a = 10;
	int *p = &a;
	printf("%d,%p\n", a, p);
	std::cout << a << "," << p << std::endl;
	int b;
	std::cin >> b;
	std::cout << b << std::endl;

}
#include <iostream>
using  namespace std;
void TestFunc(int a = 10)
{
	cout << a << endl;
}
int main()
{
	TestFunc();
	TestFunc(3);
}
void TestFunc(int a = 10, int b = 20; int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
void TestFunc(int a , int b = 20; int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//a.h
void TestFunc(int a = 10)
{
	cout << a << endl;
}
//a.c
void TestFunc(int a = 20)
{
	cout << a << endl;
}
//ע�⣺��������붨��λ��ͬʱ���֣�ǡ������λ���ṩ��ֵ��ͬ��
//�������޷�ȷ�����׸����ĸ�ȱʡֵ

int Add(int a, int b)
{}
double Add(double a, double b)
{}
double Add(int a, double b)
{}
int  Add(int a, double b)
{}
//������Ȼ����ֵ������ͬ
//      �����β���ͬ
long Add(long a, long b)
{}

#include "f.h"//->������������������׶��ù�
//                ����������Ϊ���������������ط�
//				  ����ʱ��ȥ�Ҷ���
int main()
{
	add(1, 2);
	add(1.1, 2.2);
}
extern "C"int add(int a, int b);
int main()
{
	add(1, 2);
	return 0;
}*/
