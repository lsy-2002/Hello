#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//����
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
//		char& operator[](size_t i)//��&�����޸ķ���ֵ
//		//ע�⣺���������г����������÷���
//		//ԭ�򣺳��˵�ǰ���������򣬷��ض����ڣ��Ϳ��������÷��أ�����ֻ���ô�ֵ����
//		//��ֵ���ػ�����һ��tmp���󿽱���
//		//1���������Ƚ�С��4/8byte����ôһ���ʹ�üĴ����洢����Ŀ���
//		//2����������Դ�һЩ�����������ͨ���������һ��������ջ֡
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
//	//Ĭ�����ɹ��캯���Ի������ͳ�Ա�����ǲ������
//	//(��Щ�Ƚ��µı�����Ҳ�п��ܻ��ʼ����0,���Ǵ�������������ᴦ��)
//	//int _a1;
//	//int _a2;
//	//C++11���������﷨������ȱʡֵ�����ֲ�ȱ��
//	int _a1 = 1;//���ﲻ�ǳ�ʼ�����Ǹ�ȱʡֵ
//	int _a2 = 2;
//	//Ĭ�����ɹ��캯�����Զ����͵ĳ�Ա��ȥ��������Ĭ�Ϲ��캯����ʼ��
//	//B _b = B(1);
//	B _b = 1;//��ʽ����ת��
//	C _c = C(1, 1);
//	//C _c = { 1, 1 };
//};
//class D
//{
//public:
//	//�������ʱ����Զ����ù��캯��
//	//���캯���ĳ�ʼ���б������Ϊ�ǳ�Ա���������ʼ���ĵط�
//	//��ʼ���б�����ʾ��д��д��������
//	D()
//	{}
//private:
//	int _d;//��Ա����
//	B _b;
//};
////�����ֳ�Ա���������ڳ�ʼ���б��ʼ��
////1��const  2������  3��û��Ĭ�Ϲ��캯���ĳ�Ա����
//int main()
//{
//	A aa;
//	D dd;//�������ʱ���ԱҲ��Ϊ�����һ���ֶ������
//	return 0;
//}
//����
//class Date
//{
//public:
//	~Date()
//	{
//		//û����Դ��Ҫ����
//		//���Բ�д���������Զ�����
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
//		string(const char* str = "")//���ܴ���ָ��
//		{					//�൱��"\0"
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
//	//Ĭ�����ɵ�������������ʲô������
//	//�������Ͳ������Զ������ͣ���ȥ����������������
//	int _a;
//	S::string s2;
//};
//int main()
//{
//	Date d;//��������������ɶ��������
//		  //��������Ǵ����ں���ջ֡����ģ�����������ջ֡���٣����������
//	S::string s1("hello world");
//	//���s1������ռ�Ҫ����
//	//1��s1����������������ջ֡���٣���������
//	//2��s1�����_strָ��Ķ��ϵĿռ䣬�����������������
//	F ff;
//	return 0;
//}
//��������
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
//	//������Ĭ�����ɿ������캯������Ի����������ֵ����(ǳ����)
//	//�Զ������͵ĳ�Ա��ȥ�������Ŀ�������
//	Date(int year = 1000, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)//��������
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
//	//ǳ����
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
//////// �������Ż�////////////////////////
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
//	//f(a1);//��ֵ������Ϊ
//	//f1(a1);
//	//A();//��������
//	//A().print();
//	//f(A());//���������Ż���Ϊ��һ����ͬһ�����ʽ��
//		   //����һ����ʱ����������ʱ����ȥ��������һ������
//	       //��ô���������ܻ��Ż�����������϶�Ϊһ��ֱ�ӹ����һ������
//	//A a2(1);
//	//A  a3 = 3;//��ʽ���͵�ת����A tmp(3),����tmp��������a3�����Ǳ������Ż��ˣ�ֱ�ӹ���
//	//f3();
//	//A a4 = f2();
//	//��һ�����ʽ�У�����������캯�����ܻᱻ�������Ż���һ��
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
	A ret = f(f(a));//����7�ο������캯��
	return 0;
}
//�ܽ᣺���������Ҫ�Ż���ֻ�п����Ϳ�������Żᱻ�Ż��ϲ���
//���ұ������ڱ��ʽ�����Ĳ����У������Ż����Ķ�����ʱ���󣬻�������������
//ͨ���Ǵ������ͷ���ֵ