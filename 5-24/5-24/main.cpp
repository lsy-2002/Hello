#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
class Date
{
public:
	//编译器会增加一个隐含参数-》this
	//void Init(Date* this,int year, int month, int day)
	//哪个对象去调用函数成员，成员函数中访问的就是哪个对象中的成员变量（通过this指针）
	//1、this指针是隐含的，是编译器编译时加的，我们不能在调用和函数定义中加
	//2可以在成员变量中使用this指针
	//3、this指针一般存储在栈中，不同编译器不同，vs是使用ecx存储在寄存器中
	void Init(int year, int month, int day)
	{
		//year = year;//优先原则优先访问自己 可以
		//Date::year = year //类域 可以
		//成员函数中，编译器会自动加上this->,自己加也可以
		this->_year = year;
		this->_month = month;
		this->_day = day;
		cout << "this:" << this << endl;
		
	}

private:
	//凡是命名变量，建议命名风格区分
	 int _year; // int year;
	 int _month;//int month;
	  int _day;// int day;
};
int main()
{
	Date d1;
	cout << "d1:" << &d1 << endl;
	d1.Init(2021, 5, 24);
	//d1.Init(&d1,2021,5,24);
	Date d2;
	cout << "d2:" << &d2 << endl;
	d2.Init(2021, 5, 25);
	//d2.Init(&d2,2021,5,25);
	return 0;
}

class A
{
public:
	//成员函数中接受到的this是空指针
	void PrintA()
	{
		cout << _a << endl;//error,进行了解引用操作
		//this->_a
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->PrintA();//能通过，不能运行，空指针
	//
	p->Show();//正常运行
	//p->Show()等等这些函数，没有对p指针进行解引用
	//因为Show等成员函数的地址没有存到对象里面
	return 0;
	//成员函数的地址存放在公共代码段
}

//我们什么都不写的时候，编译器会自动生成6个默认函数，这6个函数就叫默认（缺省）成员函数
//1、构造函数-》初始化
class Date
{
	//可能会忘记调用初始化
	//C++解决-》构造函数
public:
	//对象实例化的时候自动调用
	//保证对想一定初始化
	Date(int year, int month, int day)//默认初始化
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()//函数重载
	{
		//给定值初始化
		_year = 2000;
		_month = 1;
		_day = 1;
	}
	//一般情况下，对象初始化分为两种：1、默认初始化2、给定值初始化
	//合二为一  -》全缺省
	Date(int year = 2000, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2021, 5, 24);
	return 0;
}

class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Print();
	return 0;
}
class A
{
public:
	A(int a = 0)
	{
		_a = a;
	}
	void Print()
	{
		cout << _a << endl;
	}
private:
	int _a;
};
class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//cout << _aa.a << endl;//不能访问在类外面不能访问
		_aa.Print();
	}
private:
	int _year;
	int _month;
	int _day;
	A _aa;
};
int main()
{
	Date d1;
	d1.Print();
	return 0;
}

//默认构造函数（不用参数就可以调用的）
//1、编译器默认生成的
//2、自己写的无参的函数
//3、自己写的缺省函数
class Date
{
public:
	~Date()//不能重载
	{
		//资源的清理
		//像Stack这样的类，析构函数具有重大意义
		cout << "~Date" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2;
	//谁先析构？
	//因为对象是定义在函数中，函数调用会建立栈帧
	//栈帧中的对象构造和析构也要符合后进先出
	//d1先构造
	//d2后构造
	//d2先析构
	//d1后析构
	return 0;
}

class Date
{
public:
	/*
	//d1->this  d2->Date d
	bool Equel(Date d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	*/
/*
	bool operator == (Date d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
	//当运算符时两个操作数时，第一个参数是左操作数，第二个是右操作数
	//d1 < d2
	bool operator <(Date x)
	{
		if (_year < x._year)
			return true;
		else if (_year == x._year)
		{
			if (_month < x._month)
				return true;
			else if (_month == x._month)
			{
				if (_day == x._day)
					return true;
			}
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
/*bool operator == (Date d1, Date d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}
int main()
{
	Date d1;
	Date d2;
	//d1.Equel(d2);
	//内置类型，语言层面支持运算符
	//自定义类型，默认不支持，但是C++可以用运算符重载让类对象支持用某个运算符
	//opreator == (d1, d2);//d1 == d2
	d1.operator == (d2);
	d1.operator<(d2);
	cout << (d1 == d2) << endl;
	return 0;
}

class Array
{
public:
	Array()
	{
		for (int i = 0; i < 10; i++)

		{
			_a[i] = i * 10;
		}
	}
	int& operator[](size_t pos)
	{
		return _a[pos];
	}
private:
	int _a[10];
	int _numsize;//数据个数
};
int main()
{
	Array arr;
	//arr.operate[](&arr,0)
	cout << arr[0] << endl;//0
	cout << arr[1] << endl;//10
	cout << arr[2] << endl;//20
	cout << arr[3] << endl;//30
	//可修改
	arr[0] = 100;
	arr[1] = 200;
	arr[2] = 300;
	arr[3] = 400;
	cout << arr[0] << endl;//100
	cout << arr[1] << endl;//200
	cout << arr[2] << endl;//300
	cout << arr[3] << endl;//400

	return 0;
}

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造是默认成员函数
	//我们不写编译器会自动生成拷贝构造
	//这个拷贝构造对内置类型会完成浅拷贝，或者值拷贝
	//必须是引用传参否则会引起无穷递归调用
	Date(const Date& d)//防止d改变（权限缩小）
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d4(d1);//拷贝构造
	return 0;
}

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//用传引用 &防止this传递时拷贝构造
	Date& operator = (const Date&d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2021,5,28);
	Date d2;
	Date d3;
	//也是拷贝行为，但是不一样的是，拷贝构造是创建一个对象时，拿同类对象初始化的拷贝
	//这里的复制拷贝是这个对象已经存在，已被初始化，
	d1 = d2;
	d1 = d2 = d3;//连续赋值
	//d1 = (d2 = d3) //需要有返回值
	//d1 = d2
	//赋值运算符也是一个默认成员函数，不写编译器会自动生成
	//编译器默认生成赋值运算符跟拷贝构造的特性是一致的
	//a、针对内置类型，会完成浅拷贝
	//b、针对自定义类型，会调用它的赋值运算符重载完成拷贝
	Date d4(d1);//拷贝构造
	d1 = d2;//赋值重载 两个已经存在的对象拷贝
	Date d5 = d1;//拷贝构造 拿一个已经存在的对象去构造初始化另一个要创建的对象
	return 0;
}
*/
#include "Date.h"
void Test2()
{
	Date d1(2021,5,25);
	d1.Print();
	d1 += 3;
	d1.Print();
	Date d2 = d1 + 100;
	d2.Print();
}
void Test3()
{
	Date d1(2021, 5, 27);
	d1 -= 120;
	d1.Print();
	Date d2(2021, 5, 27);
	d2 -= -100;
	d2.Print();
}
void Test4()
{
	Date d1(2021, 5, 27);
	//前置++和后置++都完成了++，不同的地方在于返回值不一样
	//它们运算符一样，函数名就是一样的，为了区分，函数重载
	//对后置++做了特殊处理，加了一个参数，形成函数重载
	Date ret1 = d1++;//d1.operator++(&d1,int)
	ret1.Print();
	d1.Print();
	Date ret2 = ++d1;//d1,operator++(&d1)
	ret2.Print();
	d1.Print();
}
void Test5()
{
	Date d1(2021, 5, 27);
	Date d2(2021, 12, 31);
	cout << (d2 - d1) << endl;
	cout << (d1 - d2 )<< endl;
}

int main()
{
	Test5();
	
	return 0;
}