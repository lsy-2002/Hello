#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
class Date
{
public:
	//������������һ����������-��this
	//void Init(Date* this,int year, int month, int day)
	//�ĸ�����ȥ���ú�����Ա����Ա�����з��ʵľ����ĸ������еĳ�Ա������ͨ��thisָ�룩
	//1��thisָ���������ģ��Ǳ���������ʱ�ӵģ����ǲ����ڵ��úͺ��������м�
	//2�����ڳ�Ա������ʹ��thisָ��
	//3��thisָ��һ��洢��ջ�У���ͬ��������ͬ��vs��ʹ��ecx�洢�ڼĴ�����
	void Init(int year, int month, int day)
	{
		//year = year;//����ԭ�����ȷ����Լ� ����
		//Date::year = year //���� ����
		//��Ա�����У����������Զ�����this->,�Լ���Ҳ����
		this->_year = year;
		this->_month = month;
		this->_day = day;
		cout << "this:" << this << endl;
		
	}

private:
	//�����������������������������
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
	//��Ա�����н��ܵ���this�ǿ�ָ��
	void PrintA()
	{
		cout << _a << endl;//error,�����˽����ò���
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
	p->PrintA();//��ͨ�����������У���ָ��
	//
	p->Show();//��������
	//p->Show()�ȵ���Щ������û�ж�pָ����н�����
	//��ΪShow�ȳ�Ա�����ĵ�ַû�д浽��������
	return 0;
	//��Ա�����ĵ�ַ����ڹ��������
}

//����ʲô����д��ʱ�򣬱��������Զ�����6��Ĭ�Ϻ�������6�������ͽ�Ĭ�ϣ�ȱʡ����Ա����
//1�����캯��-����ʼ��
class Date
{
	//���ܻ����ǵ��ó�ʼ��
	//C++���-�����캯��
public:
	//����ʵ������ʱ���Զ�����
	//��֤����һ����ʼ��
	Date(int year, int month, int day)//Ĭ�ϳ�ʼ��
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()//��������
	{
		//����ֵ��ʼ��
		_year = 2000;
		_month = 1;
		_day = 1;
	}
	//һ������£������ʼ����Ϊ���֣�1��Ĭ�ϳ�ʼ��2������ֵ��ʼ��
	//�϶�Ϊһ  -��ȫȱʡ
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
		//cout << _aa.a << endl;//���ܷ����������治�ܷ���
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

//Ĭ�Ϲ��캯�������ò����Ϳ��Ե��õģ�
//1��������Ĭ�����ɵ�
//2���Լ�д���޲εĺ���
//3���Լ�д��ȱʡ����
class Date
{
public:
	~Date()//��������
	{
		//��Դ������
		//��Stack�������࣬�������������ش�����
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
	//˭��������
	//��Ϊ�����Ƕ����ں����У��������ûὨ��ջ֡
	//ջ֡�еĶ����������ҲҪ���Ϻ���ȳ�
	//d1�ȹ���
	//d2����
	//d2������
	//d1������
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
	//�������ʱ����������ʱ����һ������������������ڶ������Ҳ�����
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
	//�������ͣ����Բ���֧�������
	//�Զ������ͣ�Ĭ�ϲ�֧�֣�����C++����������������������֧����ĳ�������
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
	int _numsize;//���ݸ���
};
int main()
{
	Array arr;
	//arr.operate[](&arr,0)
	cout << arr[0] << endl;//0
	cout << arr[1] << endl;//10
	cout << arr[2] << endl;//20
	cout << arr[3] << endl;//30
	//���޸�
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
	//����������Ĭ�ϳ�Ա����
	//���ǲ�д���������Զ����ɿ�������
	//�������������������ͻ����ǳ����������ֵ����
	//���������ô��η������������ݹ����
	Date(const Date& d)//��ֹd�ı䣨Ȩ����С��
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
	Date d4(d1);//��������
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
	//�ô����� &��ֹthis����ʱ��������
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
	//Ҳ�ǿ�����Ϊ�����ǲ�һ�����ǣ����������Ǵ���һ������ʱ����ͬ������ʼ���Ŀ���
	//����ĸ��ƿ�������������Ѿ����ڣ��ѱ���ʼ����
	d1 = d2;
	d1 = d2 = d3;//������ֵ
	//d1 = (d2 = d3) //��Ҫ�з���ֵ
	//d1 = d2
	//��ֵ�����Ҳ��һ��Ĭ�ϳ�Ա��������д���������Զ�����
	//������Ĭ�����ɸ�ֵ����������������������һ�µ�
	//a������������ͣ������ǳ����
	//b������Զ������ͣ���������ĸ�ֵ�����������ɿ���
	Date d4(d1);//��������
	d1 = d2;//��ֵ���� �����Ѿ����ڵĶ��󿽱�
	Date d5 = d1;//�������� ��һ���Ѿ����ڵĶ���ȥ�����ʼ����һ��Ҫ�����Ķ���
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
	//ǰ��++�ͺ���++�������++����ͬ�ĵط����ڷ���ֵ��һ��
	//���������һ��������������һ���ģ�Ϊ�����֣���������
	//�Ժ���++�������⴦������һ���������γɺ�������
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