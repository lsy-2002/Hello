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
//	//�������õ���һ����������ʵ�ʲ��ǣ�����Ƕ�̬ʵ�ֵ�
//	return 0;
//}
//class Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "��Ʊ--ȫƱ" << endl;
//	}
//};
////virtuel void f() 
////ֻ����ķǾ�̬��Ա�����������麯��
//class Old :public Person
//{
//public:
//	//������麯����д�˸�����麯��
//	virtual void Buyticket()
//	{
//		cout << "��Ʊ--���" << endl;
//	}
//};
//class Stu:public Person
//{
//public:
//	//������麯����д�˸�����麯��
//	virtual void Buyticket()
//	{
//		cout << "��Ʊ--��Ʊ" << endl;
//	}
//};
//
//void f(Person& p)
//{
//	//����ͬ���͵Ķ��󣬵��õ��ǲ�ͬ������ʵ���˵��õĶ�����̬
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
//	//����Ѹ���������������Ϊ�麯��
//	//����������麯��������д������麯��
//	 virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//
//	}
//	 //�Ӻ���û����д����
//};
//class Stu:public Person
//{
//public:
//	virtual ~Stu()
//	{
//		//Stu��Person���������ĺ���������������ͬ�����ǹ����麯����д
//		cout << "~Stu()" << endl;
//
//	}
//
//};
//int main()
//{
//	//����ͨ�����£�����������������Ƿ񹹳���д������Ҫ��ûӰ��
//	//Person p;
//	//Stu s;
//	Person* p1 = new Person;
//	Person* p2 = new Stu;
//	//��̬��Ϊ
//	//����p2ָ���������Ӧ�õ���������������������û�е���
//	//��ô���ڴ�й©(������ຯ��û��ʲô�����Ǿ�ûʲô��)
//	//������ຯ���������Ǿʹ�����Դй©
//	delete p1;//p1->��������()+ operator delete(p1)
//	delete p2;//p2->��������()+ operator delete(p2)
//
//	return 0;
//}
//class Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "��Ʊ--ȫƱ" << endl;
//	}
//};
//class Stu: public Person 
//{
//public:
//	//�����麯������дvirtualҲ��Ϊ���麯���������д
//	 void Buyticket()
//	{
//		cout << "��Ʊ--��Ʊ" << endl;
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
//	virtual void Drive()override{ cout << "Benz-��" << endl; }
//};
//int main()
//{
//
//	return 0;
//}
//������-������ʵ����������
//���ã����Ը��õı�ʾ��ʵ�����У�û��ʵ�������Ӧ�ĳ������� eg:ֲ��ˣ�����...

//class car
//{
//public:
//	//���麯��
//	virtual void Drive() = 0;
//};
//class Benz :public car
//{
//public:
//	//����ʵ���������󣬵���д
//	virtual void Drive()
//	{ 
//		cout << "Benz-��" << endl; 
//	}
//};
//class BMW :public car
//{
//public:
//	//����ʵ���������󣬵���д
//	virtual void Drive()
//	{
//		cout << "BWM--����" << endl;
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
//		cout << "��Ʊ--ȫƱ" << endl;
//	}
//
//};
//class Stu :public Person
//{
//public:
//	virtual void Buyticket()
//	{
//		cout << "��Ʊ--��Ʊ" << endl;
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
//	printf("ջ�ϵ�ַ:%p\n", &i);
//	printf("���ݶε�ַ:%p\n", &j);
//	int* k =new int ;
//	printf("�ѵ�ַ:%p\n", k);
//	char* cp = "hello world";
//	printf("����ε�ַ:%p\n", cp);
//	return 0;
//}
//���̳�
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
////дһ�������ӡһ�����ȷ������е��õĺ���
//typedef void(*VF)();
////void PrintVF(VF ptr[])
//void PrintVF(VF* ptr)
//{
//	printf("����ַ:%p\n" ,ptr);
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
////��̳�
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
//	printf("����ַ:%p\n" ,ptr);
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
