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
	//const��������//bool operator==(Date* this,const Date&d)
	bool operator==(const Date&d)const//bool operator==(const Date*this,const Date&d)
	{
		//��const�����ε���*this
		//�ô��ǣ������в�С�ĸı��˳�Ա����������ʱ�ͻᱻ������
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	void Print()const//void Print(const Date* this)
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
	d1.Print()//���ԣ�Ȩ����С
	return 0;
}
/	const Date* p1; 
	Date const *p2;
	Date* const p3;	
	const��*֮ǰ�����ε���ָ��ָ��Ķ���const��*֮�����ε���ָ�뱾��

class Date
{
public:
	//ȡ��ַ�����������
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const//��const�ĵ���ʱʹ��
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
	//��Ԫ����������
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
	//��һ��������������ڶ������Ҳ�����
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
	//cout ��cin��ʶ������
	//�������͵Ķ���ֱ�Ӿ�����cin,cout�������
	//����Ϊ����֮�乹�ɺ�������
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
		//_n = 10 //�����ں������ڳ�ʼ��������ʹ�ó�ʼ���б��ʼ��
		//ret = year
	}
private://���Ƕ��壬��������û���ռ�
	//����Ҫ��ʼ��
	int _year;
	int _month;
	int _day;

	//�����ڳ�ʼ���б�
	//һ������ĵ�����Ա�����ڳ�ʼ���б���������Ľ׶�
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
	// 1  ���ֵ
	//�������г�Ա����������˳��ͳ�ʼ���б��г��ֵ�˳�򱣳�һ��
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
	A aa2 = 2;//�������Ĺ��캯����֧����ʽ����ת��
	//�ȹ���һ����ʱ���� A tmp(2),�ٿ������� A aa2(tmp)

	//int i = 0;
	//double d = i;//��ʽ����ת��
	return 0;
}
int main()
{
	A aa1(1);//��׼���캯�����ã�������������
	A aa2(2);//��ʽ����ת�����������Ż���Ҳ��ֱ�ӵ��ù���

	A(3);//��������������������ֻ����һ��
	//		A aa4()
	//      aa4.f();
	//������A().f();д���������
	return 0;
}

//����һ��������A��������ٸ�����
class A
{
public:
	A()
	{
		++_n;
	}
	A(const A& a)//��������
	{
		++_n;
	}
	int GetP()
	{
		return _n;
	}//���ȡ˽��ֵ�����干�к���
private:
	//���ڹ��캯���г�ʼ��
	static int _n;//n�Ǵ��ھ�̬�������������࣬Ҳ����������ж���
};
//��̬��Ա�����ĳ�ʼ��//
int A::_n = 0;
int main()
{
	A a;
	A a1;
	A a2;
	A();
	cout << sizeof(A) << endl;//1
	cout << sizeof(a) << endl;//1
	//cout << A::_n << endl;//����ʱ
	//cout << a1._n << endl;������
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
	//����-��ȱʡֵ
	int _a = 0;
	int* _p = nullptr;
	int* arr = (int*)malloc(sizeof(int)* 5);
	B _b = 6;//��������+����	
};
int main()
{
	A aa;//Ĭ�Ϲ��캯��
	return 0;
}

class A
{
public:
	//B����A���ڲ���
	class B//B��A����Ԫ�࣬B���Է���A
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

//ֱ���������涨��ʵ�ֵĳ�Ա������Ĭ������������
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