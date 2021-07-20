#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
void Swapi(int& x1, int&x2)
{

}
void Swapd(double& x1, double& x2)
{

}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	Swapi(a, b);
	Swapd(c, d);
	return 0;
}

//泛型编程-》模板

//函数模板
template<class T>
void Swap(T& x1,T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	Swap(a, b);
	Swap(c, d);
	return 0;
}
//定义模板参数T可以用typename
template<typename T>
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	Swap(a, b);
	Swap(c, d);
	return 0;
}

template <class T>
T Add(const T& x1,const T& x2)
{
	return x1 + x2;
}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	//编译器通过实参推形参的类型T分为int和double
	//这种是隐式实例化
	Add(a, b);
	Add(c, d);

	//不让编译器推演类型，显示指定类型
	//显式实例化
	cout << Add<int>(a, c) << endl;
	cout << Add<double>(b, d) << endl;
	return 0;
}

int Add(int x, int y)
{
	return x + y;
}
template <class T>
T Add(const T& x1, const T& x2)
{
	return x1 + x2;
}
void Test()
{
	Add(1, 2);//与非模板函数匹配，编译器不需要特化
	Add<int>(1, 2.0);//调用编译器特化的Add版本
}

int Add(int x, int y)
{
	return x + y;
}
template <class T>
T Add(const T& x1, const T& x2)
{
	return x1 + x2;
}
void Test()
{
	Add(1, 2);//与非模板函数匹配，编译器不需要特化
	Add(1, 2.0);//模板函数可以生成更加匹配的版本
}

//类模板
typedef int VDataTpye;
class vector
{
private:
	VDataTpye* _a;
	int _size;
	int _capacity;
};
int main()
{
	vector v1;//int
	vector v2//double
	return 0;
}

namespace hello
{
	template<class T>
	class vector
	{
	private:
		VDataTpye* _a;
		int _size;
		int _capacity;
	};
}

int main()
{
	hello::vector<int> v1;//int
	hello::vector<double> v2;//double
	return 0;
}

//模板不支持分离编译(声明在.h,定义在.cpp)
//建议定义在一个文件
//Vector类名，Vector<int>才是类型
Vector<int>s1;
Vector, double > s2;
*/
//注意：Vector不是具体的类，是编译器根据模板被实例化的类型生成具体类的模具
template<class T>
class Vector
{
public:
	~Vector();
};
//注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template<class T>
vector<T>::~vector()
{}