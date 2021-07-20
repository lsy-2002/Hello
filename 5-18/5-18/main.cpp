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
	const int a = 10;//不可修改
	//int& ra = a;//ra引用a属于权限放大，不行
	//ra->可读可写    a->可读
	const int& ra = a;
	int b = 20;
	int& rb = b;
	const int& rrb = b;//rrb引用b属于权限缩小，可以
					//rrb->可读   b->可读可写
	int c = 10;
	double d = 1.11;
	d = c//隐式类型转换，c和d之间产生临时变量
	//double& rc = c;//不行
	const double& rrc = c;//可以
}
//做参数
void Swap(int& a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//做返回值（特殊场景下）
int Add(int a, int b)//传值返回
{
	int c = a + b;
	return c;
}
int main()
{
	int ret = Add(1, 2);
	return 0;
}
int Add(int a, int b)//c是临时变量，具有常性，所以要加const
{
	int c = a + b;
	return c;
}
int main()
{
	const int& ret = Add(1, 2);
	return 0;
}
int& Add(int a, int b)//传引用返回
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
//实际上，如果出了函数作用域，返回变量就不存在了，不能引用返回
int& Add(int a, int b)//传引用返回
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
int& Add(int a, int b)//c不在栈帧上，在静态区（静态区不销毁）
{
	static int c = a + b;
	return c;
}
int main()
{
	int &ret = Add(1, 2);
	Add(5, 6);
	cout << ret << endl;//结果是3
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
	//以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i<10000; ++i)
		TestFunc1(a);
	size_t end1= clock();
//以引用作为函数参数

	size_t begin2 = clock();
	for (size_t i = 0; i<10000; ++i)
	TestFunc2(a);
	size_t end2 = clock();
	//分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
//引用和指针的区别
int main()
{
	int a = 10;
	//在语法上，给a的空间取了一个别名，没有新开空间
	int& ra = a;
	ra = 20;
	//在语法上，这里定义个pa指针变量，开了4个字节（32位），存储a的地址
	int* pa = &a;
	*pa = 20;
	
	return 0;
}//实际从汇编实现角度，引用底层也是类似指针存储地址的方式处理的
void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
//C语言为了避免小函数建立栈帧-》提供宏函数支持-》在预处理阶段展开，不需要建立栈帧
//C++提供inline函数-》解决宏函数缺点
//宏函数缺点：1、不支持调试2、宏函数语法复杂容易出错3、没有类型安全的检查
#define Add(x,y) ((x) + (y))//C语言宏函数
int main()
{
	int x = 0;
	int y = 1;
	Swap(x,y);
	return 0;
}
//C++推荐频繁调用的小函数，定义成inline ,会在调用的地方展开，没有栈帧的开销
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
	//类型声明成auto，可以根据a的类型自动推导b的类型
	map<string, string>m;
	//map<string, string>::iterator it = m.begin()
	//这里可以根据m.begin()自动推导it的类型是map<string, string>::iterator 
	auto it = m.begin();
}
int main()
{
	int x = 10;
	auto a = &x;//int*
	auto* b = &x;//int*
	int& y = x;//y的类型是int 
	auto&c = y;//int 
	auto& d = x;//d是x的引用
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
	auto c = 3, d = 4.4;//错误！
	return 0;
}
void Testauto(auto a){}//不能作为函数的参数
//编译器无法对a的实际类型进行推导
void Testauto()//不能直接用来声明函数
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

	for (auto e : array)//只读 拷贝，不改变原数组
		e *= 2;
	//2，4，6，8，10
	for (auto& e : array)//引用，改变
		e *= 2;
	//4，8，12，16，20
	for (auto e : array)//自动遍历，依次取出array中的元素，赋值给e，直到结束
		cout << e << " ";
	cout << endl;
	return 0;
}
void Testfor(int array[])//错误！
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