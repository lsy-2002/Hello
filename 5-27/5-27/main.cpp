#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	
	//bool operator==(const Date&d)
	//const保护对象//bool operator==(Date* this,const Date&d)
	bool operator==(const Date&d)const//bool operator==(const Date*this,const Date&d)
	{
		//加const，修饰的是*this
		//好处是，函数中不小心改变了成员变量，编译时就会被检查出来
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	void Print()const//void Print(const Date* this)
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2021, 5, 27);
	Date d2(2021, 5, 27);
	cout << (d1 == d2) << endl;
	d1.Print()//可以，权限缩小
	return 0;
}
/	const Date* p1; 
	Date const *p2;
	Date* const p3;	
	const在*之前，修饰的是指针指向的对象，const在*之后修饰的是指针本身

class Date
{
public:
	//取地址运算符的重载
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const//有const的调用时使用
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};

class Date
{
	//友元函数的声明
	friend ostream& operator<<(ostream&out,const Date&d1);
	friend istream& operator>> (istream&in, Date&d);
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//d1 << cout
	//第一个是左操作数，第二个是右操作数
	//void operator<<(ostream&out)//void operator<<(Date* this,ostream& out)
	//{
		//out << _year << "-" << _month << "-" << _day << endl;
	//}
	//void operator>>(istream&in){}
private:
	int _year;
	int _month;
	int _day;
};
//cout<<d1
ostream& operator<<(ostream&out,const Date& d)//void operator<<(Date* this,ostream& out)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;

}
istream& operator>>(istream&in, Date& d)
{
	in >> d._year >>"-">> d._month>>"-" >> d._day;
}
int main()
{
	Date d1;
	//cin >> d1;
	//cout << d1;
	//cout 和cin能识别类型
	//内置类型的对象，直接就能用cin,cout输入输出
	//是因为它们之间构成函数重载
	return 0;
}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month) 
	{
		
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _n(10)
		, ret(year)
		, _a(1)
	{

		_day = day;
		//_n = 10 //不能在函数体内初始化，必须使用初始化列表初始化
		//ret = year
	}
private://不是定义，是声明，没开空间
	//不需要初始化
	int _year;
	int _month;
	int _day;

	//必须在初始化列表
	//一个对象的单个成员变量在初始化列表是它定义的阶段
	const int _n;
	int& ret;
	A _a;
};

class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};
int main()
{
	A aa(1);
	aa.Print();
	// 1  随机值
	//建议类中成员变量声明的顺序和初始化列表中出现的顺序保持一致
}

class A
{
public:
	explicit A(int a)
		:_a(a)
	{}
private:
	int _a;
};
int main()
{
	A aa1(1);
	A aa2 = 2;//单参数的构造函数，支持隐式类型转换
	//先构造一个临时对象 A tmp(2),再拷贝构造 A aa2(tmp)

	//int i = 0;
	//double d = i;//隐式类型转换
	return 0;
}
int main()
{
	A aa1(1);//标准构造函数调用，定义有名对象
	A aa2(2);//隐式类型转换，编译器优化后，也是直接调用构造

	A(3);//构造匿名对象，生命周期只在这一行
	//		A aa4()
	//      aa4.f();
	//匿名：A().f();写起来更简洁
	return 0;
}

//计算一个程序中A定义出多少个对象
class A
{
public:
	A()
	{
		++_n;
	}
	A(const A& a)//拷贝构造
	{
		++_n;
	}
	int GetP()
	{
		return _n;
	}//想获取私有值，定义共有函数
private:
	//不在构造函数中初始化
	static int _n;//n是存在静态区，属于整个类，也属于类的所有对象
};
//静态成员变量的初始化//
int A::_n = 0;
int main()
{
	A a;
	A a1;
	A a2;
	A();
	cout << sizeof(A) << endl;//1
	cout << sizeof(a) << endl;//1
	//cout << A::_n << endl;//共有时
	//cout << a1._n << endl;都可以
	//cout << a2._n << endl;
	//cout << A()._n << endl;
	cout << a1.GetP() << endl;
	cout << A().GetP() << endl;

	return 0;
}

//C++11
class B
{
public:
	B()
		:_x(0)
	{
		cout << "B()" << endl;
	}
	int _x;

};
class A
{
public:
	A(int a = 1; int*p = nullptr)
		:_a(a)
		, _p(p)
	{}
private:
	//声明-》缺省值
	int _a = 0;
	int* _p = nullptr;
	int* arr = (int*)malloc(sizeof(int)* 5);
	B _b = 6;//拷贝构造+构造	
};
int main()
{
	A aa;//默认构造函数
	return 0;
}

class A
{
public:
	//B叫做A的内部类
	class B//B是A的友元类，B可以访问A
	{
	public:
		B()
			:_x(0)
		{
			cout << "B()" << endl;
		}
		int _x;

	};
	A(int a = 1)
	{}
	
private:
	int _a = 0;
	B _b;	
};

//直接在类里面定义实现的成员函数，默认是内联函数
class A
{
public:
	void func()
	{
		cout << "A" << endl;
	}
private:
};
int main()
{
	A aa;
	aa.func();
	return 0;
}
*/