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
//	//�����˽�г�Ա�̳в��ɼ���
//	//�ڴ��ϣ���������������Ա�������﷨�涨���ܷ���
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

////��ֵ���ݹ���/��Ƭ
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
//	//p = s;//�ӿɸ��� ->�и�/��Ƭ
//	//s = p;//�����ɸ���
//	s._name = "����";
//	s._sex = "��";
//	s._age = 18;
//	//p = s;//���
//	//���¶�����Ƭ
//	Person* ptr = &s;
//	Person& ref = s;
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "С��ͬѧ";
//	int _num = 111;
//};
//class Stu :public Person
//{
//public:
//	void Print()
//	{
//		cout << "����" << _name << endl;
//		cout << "���֤��" << Person::_num << endl;//111
//		cout << "ѧ��" << _num << endl;//900
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
//	b.func(10);//��������
//	//b.func();//����
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
//	~Person()//��Ϊ��̬һЩԭ���κ����������������ͳһ�����destructor()
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
//		//���ø��๹�캯����ʼ���̳и���Ĳ���
//		//�ٳ�ʼ���Լ��ĳ�Ա
//		cout << "Tea()" << endl;
//	}
//	Tea(const Tea& t)
//		:Person(t)//��t���ݸ�Person& t��һ����Ƭ��Ϊ
//		, _id(t._id)
//	{
//		//���ƹ��캯��
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
//		//Person::~Person();//��������Ϊ��������������͸���Ĺ�������
//		//������Ҫָ������
//		//�����Լ���
//		cout << "~Tea()" << endl;
//		//Ϊ�˱�֤����ʱ�����ٸ��ĺ���ȳ���˳������
//		//��������������ɺ���Զ����ø������������
//	}
//private:
//	//Person _p;
//	int _id;
//};
//int main()
//{
//	Tea t("����", 100);
//	//Tea t1(t);
//	//Tea t1("����",99);
//	
//	//t1 = t;
//	return 0;
//}

////��Ƴ�һ���࣬������಻�ܱ��̳�
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
