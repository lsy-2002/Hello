#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*int main()
{
int a = 10;
int& b = a;
return 0;
}
int main()
{
	const int a = 10;//�����޸�
	//int& ra = a;//ra����a����Ȩ�޷Ŵ󣬲���
	//ra->�ɶ���д    a->�ɶ�
	const int& ra = a;
	int b = 20;
	int& rb = b;
	const int& rrb = b;//rrb����b����Ȩ����С������
					//rrb->�ɶ�   b->�ɶ���д
	int c = 10;
	double d = 1.11;
	d = c//��ʽ����ת����c��d֮�������ʱ����
	//double& rc = c;//����
	const double& rrc = c;//����
}
//������
void Swap(int& a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//������ֵ�����ⳡ���£�
int Add(int a, int b)//��ֵ����
{
	int c = a + b;
	return c;
}
int main()
{
	int ret = Add(1, 2);
	return 0;
}
int Add(int a, int b)//c����ʱ���������г��ԣ�����Ҫ��const
{
	int c = a + b;
	return c;
}
int main()
{
	const int& ret = Add(1, 2);
	return 0;
}
int& Add(int a, int b)//�����÷���
{
	int c = a + b;
	return c;
}
int main()
{
	int ret = Add(1, 2);
	Add(5, 6);
	cout << ret << endl;//3
	return 0;
}
//ʵ���ϣ�������˺��������򣬷��ر����Ͳ������ˣ��������÷���
int& Add(int a, int b)//�����÷���
{
	int c = a + b;
	return c;
}
int main()
{
	int &ret = Add(1, 2);
	Add(5, 6);
	cout << ret << endl;//11
	return 0;
}
int& Add(int a, int b)//c����ջ֡�ϣ��ھ�̬������̬�������٣�
{
	static int c = a + b;
	return c;
}
int main()
{
	int &ret = Add(1, 2);
	Add(5, 6);
	cout << ret << endl;//�����3
	return 0;
}
#include <time.h>
struct A
{
	int a[100000];
};
void TestFunc1(A a){}
void TestFunc2(A& a){}
void TestRefAndValue()
{
	A a;
	//��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i<10000; ++i)
		TestFunc1(a);
	size_t end1= clock();
//��������Ϊ��������

	size_t begin2 = clock();
	for (size_t i = 0; i<10000; ++i)
	TestFunc2(a);
	size_t end2 = clock();
	//�ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
//���ú�ָ�������
int main()
{
	int a = 10;
	//���﷨�ϣ���a�Ŀռ�ȡ��һ��������û���¿��ռ�
	int& ra = a;
	ra = 20;
	//���﷨�ϣ����ﶨ���paָ�����������4���ֽڣ�32λ�����洢a�ĵ�ַ
	int* pa = &a;
	*pa = 20;
	
	return 0;
}//ʵ�ʴӻ��ʵ�ֽǶȣ����õײ�Ҳ������ָ��洢��ַ�ķ�ʽ�����
void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
//C����Ϊ�˱���С��������ջ֡-���ṩ�꺯��֧��-����Ԥ����׶�չ��������Ҫ����ջ֡
//C++�ṩinline����-������꺯��ȱ��
//�꺯��ȱ�㣺1����֧�ֵ���2���꺯���﷨�������׳���3��û�����Ͱ�ȫ�ļ��
#define Add(x,y) ((x) + (y))//C���Ժ꺯��
int main()
{
	int x = 0;
	int y = 1;
	Swap(x,y);
	return 0;
}
//C++�Ƽ�Ƶ�����õ�С�����������inline ,���ڵ��õĵط�չ����û��ջ֡�Ŀ���
inline int add(int x, int y)
{
	return x + y;
}
int main()
{
	int c = add(1, 2);
	cout << c << endl;
	return 0;
}
#include <map>
#include <string.h>
int main()
{
	int a = 10;
	//int b = a;
	auto b = a;
	//����������auto�����Ը���a�������Զ��Ƶ�b������
	map<string, string>m;
	//map<string, string>::iterator it = m.begin()
	//������Ը���m.begin()�Զ��Ƶ�it��������map<string, string>::iterator 
	auto it = m.begin();
}
int main()
{
	int x = 10;
	auto a = &x;//int*
	auto* b = &x;//int*
	int& y = x;//y��������int 
	auto&c = y;//int 
	auto& d = x;//d��x������
	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	return 0;
}
int main()
{
	auto a = 1, b = 2;
	auto c = 3, d = 4.4;//����
	return 0;
}
void Testauto(auto a){}//������Ϊ�����Ĳ���
//�������޷���a��ʵ�����ͽ����Ƶ�
void Testauto()//����ֱ��������������
{
	int a[] = { 1, 2, 3 };
	auto b[] = { 6, 7, 8, 9 };
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		cout << array[i] << " ";
	cout << endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		 array[i] *= 2;
	// 2,4,6,8,10

	for (auto e : array)//ֻ�� ���������ı�ԭ����
		e *= 2;
	//2��4��6��8��10
	for (auto& e : array)//���ã��ı�
		e *= 2;
	//4��8��12��16��20
	for (auto e : array)//�Զ�����������ȡ��array�е�Ԫ�أ���ֵ��e��ֱ������
		cout << e << " ";
	cout << endl;
	return 0;
}
void Testfor(int array[])//����
{
	for (auto&e : array)
		cout << e << endl;
}*/
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	f(nullptr);
	return 0;
}