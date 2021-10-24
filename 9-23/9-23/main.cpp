#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age" << _age << endl;
//	}
//protected:
//	string _name = "peter";
//private:
//	int _age = 18;
//};
//class Student :public Person
//{
//	//父类的私有成员继承不可见：
//	//内存上，子类对象有这个成员，但是语法规定不能访问
//protected:
//	int _stuid;
//};
//class Teacher :public Person
//{
//protected:
//	int _jobid;
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	return 0;
//}

////赋值兼容规则/切片
//class Person
//{
////protected:
//public:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Stu :public Person
//{
//public:
//	int _no;
//};
//int main()
//{
//	Person p;
//	Stu s;
//	//p = s;//子可给父 ->切割/切片
//	//s = p;//父不可给子
//	s._name = "张三";
//	s._sex = "男";
//	s._age = 18;
//	//p = s;//深拷贝
//	//以下都是切片
//	Person* ptr = &s;
//	Person& ref = s;
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "小李同学";
//	int _num = 111;
//};
//class Stu :public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名" << _name << endl;
//		cout << "身份证号" << Person::_num << endl;//111
//		cout << "学号" << _num << endl;//900
//	}
//protected:
//	int _num = 900;
//};
//int main()
//{
//	Stu s;
//	s.Print();
//	return 0;
//}
//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void func(int i)
//	{
//		A::func();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.func(10);//构成隐藏
//	//b.func();//错误
//	b.A::func();
//}
//int main()
//{
//	Test();
//	return 0;
//}
//class Person
//{
//public:
//	Person(const char* name = "Peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator = (const Person& p)
//	{
//		cout << "Person operator = (const Person& p)" << endl;
//		if (this !=  &p)
//		{
//			_name = p._name;
//			return *this;
//		}
//	}
//	~Person()//因为多态一些原因，任何类的析构函数都被统一处理成destructor()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//	
//
//};
//class Tea :public Person
//{
//public:
//	Tea(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{
//		//调用父类构造函数初始化继承父类的部分
//		//再初始化自己的成员
//		cout << "Tea()" << endl;
//	}
//	Tea(const Tea& t)
//		:Person(t)//将t传递给Person& t是一个切片行为
//		, _id(t._id)
//	{
//		//类似构造函数
//		cout << "Tea(const Tea& t)" << endl;
//	}
//	Tea& operator=(const Tea& t)
//	{
//		if (this != &t)
//		{
//			Person::operator = (t);
//			_id = t._id;
//
//		}
//		cout << "Tea& operator=(const Tea& t)" << endl;
//		return *this;
//	}
//	~Tea()
//	{
//		//Person::~Person();//编译器认为子类的析构函数和父类的构成隐藏
//		//调用需要指定父类
//		//清理自己的
//		cout << "~Tea()" << endl;
//		//为了保证析构时先子再父的后进先出的顺序析构
//		//子类析构函数完成后会自动调用父类的析构函数
//	}
//private:
//	//Person _p;
//	int _id;
//};
//int main()
//{
//	Tea t("张三", 100);
//	//Tea t1(t);
//	//Tea t1("李四",99);
//	
//	//t1 = t;
//	return 0;
//}

////设计出一个类，让这个类不能被继承
//class A
//{
//private:
//	void Print()
//	{}
//};
//class B :public A
//
//{
//
//};
//class Person
//{
//public:
//	string _name;
//};
//class Stu :virtual public Person
//{
//protected:
//	int _num;
//};
//class Tea :virtual public Person
//{
//protected:
//	int _id;
//};
//class A :public Stu, public Tea
//{
//protected:
//
//	string _mm;
//};
//int main()
//{
//	A a;
//	a._name = "peter";
//	return 0;
//}
//class Base1{ public:int _b1; };
//class Base2{ public:int _b2; };
//class Base3 :public Base1, public Base2 { public:int _d; };
//int main()
//{
//	Base3 d;
//	Base1 * p1 = &d;
//	Base2 * p2 = &d;
//	Base3 * p3 = &d;
//
//	return 0;
//}

class A
{
public:
	int _a;
};

class B :virtual public A
{
public:
	int _b;
};
class C:virtual public A
{
public:
	int _c;
};
class D : public B,public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}
