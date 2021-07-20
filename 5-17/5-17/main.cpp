#define _CRT_SECURE_NO_WARNINGS 1
//C++ 兼容C的语法
/*
namespace N1//以N1为命名空间
{
	int a;//可以定义变量
	int add(int a, int b)//可以定义函数
	{
		return a + b;
	}
}
#include <stdio.h>
int main()
{
	//命名冲突
	//C语言的库里有scanf 函数
	//假设用scanf作为变量名
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
	//C语言不能解决的冲突问题
	//C++命名空间，名字隔离
	printf("%x\n", scanf);
}
#include <iostream>
//C++为了防止命名冲突，把自己库里面的东西都定义在std的空间命名中
1指定命名空间-》麻烦，每个地方都得写，最规范
int main()
{
	std::cout << "hello world" << std::endl;
	return 0;
}
#include <iostream>
//2、把std整个展开，相当于库里面的东西都到全局域了-》看起来方便，
//但是如果我们自己定义的东西与库冲突就没办法解决
using namespace std;
int main()
{
	cout << "hello world" << endl;
	return 0;
}
//3、对库里面常用的部分展开
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	cout << "hello world" << endl;
	return 0;
}
//在C里面的应用
#include <stdio.h>
int a = 0;
int main()
{
	int a = 1;
	printf("%d\n", a);
	printf("%d\n", ::a);// ：：指定访问左边的域-》左边为空白-》表示全局域
}
#include <iostream>
#include <stdio.h>
//ostream 类型全局变量 cout
//istream 类型全局变量 cin
int main()
{
	/*cout 输入
	cin 输出
	endl换行
	//对比C语言：可以自动识别类型
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
//注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，
//编译器无法确定到底该用哪个缺省值

int Add(int a, int b)
{}
double Add(double a, double b)
{}
double Add(int a, double b)
{}
int  Add(int a, double b)
{}
//错误：虽然返回值类型相同
//      但是形参相同
long Add(long a, long b)
{}

#include "f.h"//->声明：有声明，编译阶段让过
//                编译器会认为函数定义在其他地方
//				  链接时再去找定义
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
