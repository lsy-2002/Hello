#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//构造
//namespace S
//{
//
//	class string
//	{
//	public:
//		string(const char* str)
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		char& operator[](size_t i)//加&可以修改返回值
//		//注意：并不是所有场景都能引用返回
//		//原则：出了当前函数作用域，返回对象还在，就可以用引用返回，否则只能用传值返回
//		//传值返回会生成一个tmp对象拷贝。
//		//1、如果对象比较小（4/8byte）那么一般会使用寄存器存储对象的拷贝
//		//2、如果对象稍大一些，这个拷贝他通常会存在上一个函数的栈帧
//		{
//			return _str[i];
//		}
//	private:
//		char* _str;
//	};
//}
//int main()
//{
//	S::string s("hello world");
//	cout << s[2] << endl;
//	cout << s.operator[](2) << endl;
//	s[2] += 1;
//	cout << s[2] << endl;
//	return 0;
//}
//class B
//{
//public:
//	/*B()
//		:_b(0)
//	{}*/
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//class C
//{
//public:
//	C(int c1 = 0, int c2 = 0)
//		:_c1(c1)
//		, _c2(c2)
//	{}
//private:
//	int _c1;
//	int _c2;
//};
//class A
//{
//private:
//	//默认生成构造函数对基本类型成员变量是不处理的
//	//(有些比较新的编译器也有可能会初始化成0,但是大多数编译器不会处理)
//	//int _a1;
//	//int _a2;
//	//C++11给出补充语法：声明缺省值，来弥补缺陷
//	int _a1 = 1;//这里不是初始化，是给缺省值
//	int _a2 = 2;
//	//默认生成构造函数对自动类型的成员会去调用它的默认构造函数初始化
//	//B _b = B(1);
//	B _b = 1;//隐式类型转换
//	C _c = C(1, 1);
//	//C _c = { 1, 1 };
//};
//class D
//{
//public:
//	//对象定义的时候会自动调用构造函数
//	//构造函数的初始化列表可以认为是成员变量定义初始化的地方
//	//初始化列表，你显示的写或不写，都在走
//	D()
//	{}
//private:
//	int _d;//成员声明
//	B _b;
//};
////有三种成员变量必须在初始化列表初始化
////1、const  2、引用  3、没有默认构造函数的成员对象
//int main()
//{
//	A aa;
//	D dd;//对象定义的时候成员也作为对象的一部分定义出来
//	return 0;
//}
//析构
//class Date
//{
//public:
//	~Date()
//	{
//		//没有资源需要清理
//		//可以不写，编译器自动生成
//	}
//private:
//	int _year = 100;
//	int _month = 1;
//	int _day = 1;
//};
//namespace S
//{
//
//	class string
//	{
//	public:
//		string(const char* str = "")//不能传空指针
//		{					//相当于"\0"
//			
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//		~string()
//		{
//			cout << "~string" << endl;
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//	};
//}
//class F
//{
//private:
//	//默认生成的析构函数不是什么都不做
//	//基本类型不处理，自定义类型，会去调用它的析构函数
//	int _a;
//	S::string s2;
//};
//int main()
//{
//	Date d;//析构函数不是完成对象的销毁
//		  //这个对象是存在在函数栈帧里面的，函数结束，栈帧销毁，对象就销毁
//	S::string s1("hello world");
//	//针对s1有两块空间要销毁
//	//1、s1对象本身，函数结束，栈帧销毁，它就销毁
//	//2、s1里面的_str指向的堆上的空间，它是析构函数清理的
//	F ff;
//	return 0;
//}
//拷贝构造
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	B(const B&bb)
//		:_b(bb._b)
//	{
//		cout << "const B&bb" << endl;
//	}
//private:
//	int _b;
//};
//class Date
//{
//public:
//	//编译器默认生成拷贝构造函数，会对基本类型完成值拷贝(浅拷贝)
//	//自定义类型的成员会去调用它的拷贝构造
//	Date(int year = 1000, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)//拷贝构造
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	B _b = 10;
//};
//int main()
//{
//	//浅拷贝
//	Date d1;
//	Date d2(d1);
//	Date d3 = d1;
//	return 0;
//}
//namespace S
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		//s2(s1)
//		string(const string&s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//		~string()
//		{
//			cout << "~string" << endl;
//			delete[] _str;
//			_str = nullptr;
//		}
//     string& operator=(const string& ss)
//		{
//			if (this != &ss)
//			{
//           delete[] _str;
//           _str = new char[strlen(ss._str)+1];
//           strcpy(_str,ss._str);
//			_str= ss._str;
//   		}
//	     }
//	private:
//		char* _str;
//	};
//}
//int main()
//{
//	S::string s1("hello world");
//	S::string s2(s1);
//
////}
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	B(const B&bb)
//		:_b(bb._b)
//	{
//		cout << "const B&bb" << endl;
//	}
//	B& operator=(const B& bb)
//	{
//		if (this != &bb)
//		{
//			_b = bb._b;
//		}
//	}
//private:
//	int _b;
//};
////////////////////////////////////////////
//////// 编译器优化////////////////////////
class A
{
public:
	A(int a = 0)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A&a)" << endl;
	}
	A operator = (const A&a)
	{
		cout << "A operator = (const A&a)" << endl;
		return *this;
	}
	void print()
	{
		cout << "print A" << endl;
	}
};
//void f(A aa)
//{}
//void f1(const A& aa)
//{}
//A f2()
//{
//	static A aa;
//	return aa;
//}
//A& f3()
//{
//	static A aa;
//	return aa;
//}
////A aa;
//int main()
//{
//	//A a1;
//	//f(a1);//传值拷贝行为
//	//f1(a1);
//	//A();//匿名对象
//	//A().print();
//	//f(A());//编译器的优化行为，一般在同一个表达式中
//		   //产生一个临时对象，再用临时对象去拷贝构造一个对象，
//	       //那么编译器可能会优化，两个对象合二为一，直接构造出一个对象
//	//A a2(1);
//	//A  a3 = 3;//隐式类型的转换，A tmp(3),再用tmp拷贝构造a3，但是编译器优化了，直接构造
//	//f3();
//	//A a4 = f2();
//	//在一个表达式中，连续多个构造函数可能会被编译器优化成一次
//	A a4;
//	a4 = f2();
//	return 0;
//}

A f(A aa)
{
	A copy1(aa);
	A copy2 = copy1;
	return copy2;
}
int main()
{
	A a;
	A ret = f(f(a));//调用7次拷贝构造函数
	return 0;
}
//总结：如果编译器要优化，只有拷贝和拷贝构造才会被优化合并，
//并且必须是在表达式连续的步骤中，并且优化掉的都是临时对象，或者是匿名对象
//通常是传参数和返回值