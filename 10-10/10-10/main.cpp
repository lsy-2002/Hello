#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main()
//{
//	int i;
//	char c;
//	cin >> i;
//	cin >> c;
//	cout << i << endl;
//	cout << c << endl;
//	//看起来用的是一个函数，但实际不是，这就是多态实现的
//	return 0;
//}
//class Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "买票--全票" << endl;
//	}
//};
////virtuel void f() 
////只有类的非静态成员函数可以是虚函数
//class Old :public Person
//{
//public:
//	//子类的虚函数重写了父类的虚函数
//	virtual void Buyticket()
//	{
//		cout << "买票--免费" << endl;
//	}
//};
//class Stu:public Person
//{
//public:
//	//子类的虚函数重写了父类的虚函数
//	virtual void Buyticket()
//	{
//		cout << "买票--半票" << endl;
//	}
//};
//
//void f(Person& p)
//{
//	//传不同类型的对象，调用的是不同函数，实现了调用的多种形态
//	p.Buyticket();
//}
//void f(Person*  p)
//{
//	
//	p->Buyticket();
//}
//int main()
//{
//	Person p;
//	Stu s;
//	Old o;
//	f(p);
//	f(s);
//	f(o);
//	cout << endl;
//	f(&p);
//	f(&s);
//	f(&o);
//	return 0;
//}
//class A{};
//class B:public A{};
//class Person
//{
//public:
//	virtual A* f(){ 
//		cout << "A* Person::f()" << endl;
//		return new A;
//	};
//};
//
//class Stu:public Person
//{
//public:
//	virtual B* f(){
//		cout << "B* Stu::f()" << endl;
//		return new B;
//	};
//};
//int main()
//{
//	Person p;
//	Stu s;
//	Person* ptr;
//	ptr = &p;
//	ptr->f();
//	ptr = &s;
//	ptr->f();
//	return 0;
//}
//class Person
//{
//public:
//	//建议把父类析构函数定义为虚函数
//	//这样子类的虚函数方便重写父类的虚函数
//	 virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//
//	}
//	 //子函数没有重写父类
//};
//class Stu:public Person
//{
//public:
//	virtual ~Stu()
//	{
//		//Stu和Person析构函数的函数名看起来不相同，但是构成虚函数重写
//		cout << "~Stu()" << endl;
//
//	}
//
//};
//int main()
//{
//	//在普通场景下，父子类的析构函数是否构成重写，不重要，没影响
//	//Person p;
//	//Stu s;
//	Person* p1 = new Person;
//	Person* p2 = new Stu;
//	//多态行为
//	//这里p2指向子类对象，应该调用子类析构函数，但是没有调用
//	//那么肯内存泄漏(如果子类函数没做什么清理那就没什么事)
//	//如果子类函数有清理那就存在资源泄漏
//	delete p1;//p1->析构函数()+ operator delete(p1)
//	delete p2;//p2->析构函数()+ operator delete(p2)
//
//	return 0;
//}
//class Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "买票--全票" << endl;
//	}
//};
//class Stu: public Person 
//{
//public:
//	//子类虚函数，不写virtual也认为是虚函数，完成重写
//	 void Buyticket()
//	{
//		cout << "买票--半票" << endl;
//	}
//};
//void f(Person& p)
//{
//	p.Buyticket();
//}
//int main()
//{
//	Person p;
//	Stu s;
//	f(p);
//	f(s);
//
//	return 0;
//}
//class car
//{
//public:
//	virtual void Drive(){}
//};
//class Benz :public car
//{
//public:
//	virtual void Drive()override{ cout << "Benz-快" << endl; }
//};
//int main()
//{
//
//	return 0;
//}
//抽象类-》不能实例化出对象
//作用：可以更好的表示现实世界中，没有实例对象对应的抽象类型 eg:植物，人，动物...

//class car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//class Benz :public car
//{
//public:
//	//不能实例化出对象，得重写
//	virtual void Drive()
//	{ 
//		cout << "Benz-快" << endl; 
//	}
//};
//class BMW :public car
//{
//public:
//	//不能实例化出对象，得重写
//	virtual void Drive()
//	{
//		cout << "BWM--舒适" << endl;
//	}
//};
//int main()
//{
//	car* pBen = new Benz;
//	pBen->Drive();
//	car* pBMW = new BMW;
//	pBMW->Drive();
//
//	return 0;
//}
//class Base
//{
//public:
//	virtual void f1()
//	{
//		cout << "f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "f2()" << endl;
//	}
//	void f3()
//	{
//		cout << "f3()" << endl;
//	}
//private:
//	int _i = 1;
//	char _ch = '\0';
//
//};
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base bs;
//	return 0;
//}
//class Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "买票--全票" << endl;
//	}
//
//};
//class Stu :public Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "买票--半票" << endl;
//	}
//};
//void f(Person& p)
//{
//	p.Buyticket();
//}
//int main()
//{
//	Person L;
//	f(L);
//	Stu s;
//	f(s);
//	return 0;
//}
//class Base
//{
//public:
//
//	Base()
//	{
//		cout << "Base()" << endl;
//	}
//	virtual void f1()
//	{
//		cout << "Base::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "Base::f2()" << endl;
//	}
//	void f3()
//	{
//		cout << "Base::f3()" << endl;
//	}
//private:
//	int _b = 1;
//	
//	
//};
//class Dr :public Base
//{
//public:
//	virtual void f1()
//	{
//		cout << "Dr::f1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int j = 0;
//int main()
//{
//	Base b;
//	Base* p = &b;
//	printf("_vfptr:%p\n",(*(int*)p));
//	int i;
//	printf("栈上地址:%p\n", &i);
//	printf("数据段地址:%p\n", &j);
//	int* k =new int ;
//	printf("堆地址:%p\n", k);
//	char* cp = "hello world";
//	printf("代码段地址:%p\n", cp);
//	return 0;
//}
//单继承
//class Base
//{
//public:
//	virtual void f1()
//	{
//		cout << "Base::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "Base::f2()" << endl;
//	}
//private:
//	int _b;
//};
//class Dr :public Base
//{
//public:
//	virtual void f1()
//	{
//		cout << "Dr::f1()" << endl;
//	}
//	virtual void f3()
//	{
//		cout << "Dr::f3()" << endl;
//	}
//	virtual void f4()
//	{
//		cout << "Dr::f4()" << endl;
//	}
//private:
//	int _d;
//};
////写一个程序打印一个虚表，确认虚表中调用的函数
//typedef void(*VF)();
////void PrintVF(VF ptr[])
//void PrintVF(VF* ptr)
//{
//	printf("虚表地址:%p\n" ,ptr);
//	for (int i = 0; ptr[i] != nullptr; i++)
//	{
//		printf("VF[%d]:%p->\n", i,ptr[i]);
//		ptr[i]();
//	}
//	printf("\n");
//}
//int main()
//{
//	Base ba;
//	PrintVF((VF*)(*(int*)&ba));
//	Dr dr;
//	PrintVF((VF*)(*(int*)&dr));
//	return 0;
//}
////多继承
//
//class Base1
//{
//public:
//	virtual void f1()
//	{
//		cout << "Base1::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "Base1::f2()" << endl;
//	}
//private:
//	int _b1;
//};
//class Base2
//{
//public:
//	virtual void f1()
//	{
//		cout << "Base2::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "Base2::f2()" << endl;
//	}
//private:
//	int _b2;
//};
//class Dr :public Base1,public Base2
//{
//public:
//	virtual void f1()
//	{
//		cout << "Dr::f1()" << endl;
//	}
//	virtual void f3()
//	{
//		cout << "Dr::f3()" << endl;
//	}
//
//private:
//	int _d;
//};
//typedef void(*VF)();
//void PrintVF(VF* ptr)
//{
//	printf("虚表地址:%p\n" ,ptr);
//	for (int i = 0; ptr[i] != nullptr; i++)
//	{
//		printf("VF[%d]:%p->\n", i,ptr[i]);
//		ptr[i]();
//	}
//	printf("\n");
//}
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Dr dr;
//	//PrintVF((VF*)(*(int*)&b1));
//	//PrintVF((VF*)(*(int*)&b2));
//	PrintVF((VF*)(*(int*)&dr));
//	PrintVF((VF*)(*(int*)((char*)&dr + sizeof(Base1))));
//	return 0;
//}
class A
{
public:
		virtual void f1()
		{
			cout << "A::f1()" << endl;
		}
	int _a;
};

class B :virtual public A
{
public:
	virtual void f1()
	{
		cout << "B::f1()" << endl;
	}
	int _b;
};
class C :virtual public A
{
public:
	virtual void f1()
	{
		cout << "C::f1()" << endl;
	}
	int _c;
};
class D : public B, public C
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}
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
