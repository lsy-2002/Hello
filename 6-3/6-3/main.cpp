#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
void Swapi(int& x1, int&x2)
{

}
void Swapd(double& x1, double& x2)
{

}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	Swapi(a, b);
	Swapd(c, d);
	return 0;
}

//���ͱ��-��ģ��

//����ģ��
template<class T>
void Swap(T& x1,T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	Swap(a, b);
	Swap(c, d);
	return 0;
}
//����ģ�����T������typename
template<typename T>
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	Swap(a, b);
	Swap(c, d);
	return 0;
}

template <class T>
T Add(const T& x1,const T& x2)
{
	return x1 + x2;
}
int main()
{
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	//������ͨ��ʵ�����βε�����T��Ϊint��double
	//��������ʽʵ����
	Add(a, b);
	Add(c, d);

	//���ñ������������ͣ���ʾָ������
	//��ʽʵ����
	cout << Add<int>(a, c) << endl;
	cout << Add<double>(b, d) << endl;
	return 0;
}

int Add(int x, int y)
{
	return x + y;
}
template <class T>
T Add(const T& x1, const T& x2)
{
	return x1 + x2;
}
void Test()
{
	Add(1, 2);//���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add<int>(1, 2.0);//���ñ������ػ���Add�汾
}

int Add(int x, int y)
{
	return x + y;
}
template <class T>
T Add(const T& x1, const T& x2)
{
	return x1 + x2;
}
void Test()
{
	Add(1, 2);//���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add(1, 2.0);//ģ�庯���������ɸ���ƥ��İ汾
}

//��ģ��
typedef int VDataTpye;
class vector
{
private:
	VDataTpye* _a;
	int _size;
	int _capacity;
};
int main()
{
	vector v1;//int
	vector v2//double
	return 0;
}

namespace hello
{
	template<class T>
	class vector
	{
	private:
		VDataTpye* _a;
		int _size;
		int _capacity;
	};
}

int main()
{
	hello::vector<int> v1;//int
	hello::vector<double> v2;//double
	return 0;
}

//ģ�岻֧�ַ������(������.h,������.cpp)
//���鶨����һ���ļ�
//Vector������Vector<int>��������
Vector<int>s1;
Vector, double > s2;
*/
//ע�⣺Vector���Ǿ�����࣬�Ǳ���������ģ�屻ʵ�������������ɾ������ģ��
template<class T>
class Vector
{
public:
	~Vector();
};
//ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template<class T>
vector<T>::~vector()
{}