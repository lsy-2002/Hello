#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
//void PrintVecort(const vector<int>& v)
//{
//	vector<int>::const_iterator it1 = v.begin();
//	while (it1 != v.end())
//	{
//		
//		cout << *it1 << " ";
//		it1++;
//	}
//}
template<class T>
void PrintVecort(const vector<T>& v)
{
	vector<T>::const_iterator it1 = v.begin();
	while (it1 != v.end())
	{

		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
}
void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1[0] = 10;
	//����1
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	//����2
	vector<int>::iterator it1 = v1.begin();
	//�������ıȽ϶�ʹ�� == �� != ��Ϊ���list,map����ʽ�ṹ�Ͳ�����
	while (it1 != v1.end())
	{
		*it1 += 1;
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	//����3 �Զ��жϽ������Զ�����++ -��ʵ�����滻���˵�����
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	PrintVecort(v1);
}
void test_vector2()
{
	//vector�����Ĺ��췽ʽ
	vector<int> v1;
	vector<int> v2(10, 0);//��10��0��ʼ��
	vector<int> v3(v2.begin(), v2.end());//�õ��������ʼ��
	string s("hello world");
	vector<char> v4(s.begin(),s.end());
	vector<string> v5;
	string s1("sort");
	v5.push_back(s1);
	v5.push_back(string("hello"));//��������
	//�Ƽ�
	v5.push_back("world");//��ʽ����ת��

	PrintVecort(v1);
	PrintVecort(v2);
	PrintVecort(v4);
	PrintVecort(v5);
	vector<string> copy(v5);
	PrintVecort(copy);

	//vector<string>::reverse_iterator rit = copy.rbegin();
	auto rit = copy.rbegin();
	while (rit != copy.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}
void test_vector3()
{
	//��֤vector�����ݷ�ʽ VS:1.5��ȡ������ Linux:2������
	size_t sz;
	vector<int> f;
	sz = f.capacity();
	cout << "grow\n";
	//f.reserve(20);��ǰ���ռ�Ͳ���������
	for (int i = 0; i < 10; i++)
	{
		f.push_back(i);
		if (sz != f.capacity())
		{
			sz = f.capacity();
			cout << "capacity change:" << sz << endl;
		}
	}
}
void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.insert(v.begin(), 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		v.insert(pos, 30);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//ɾ��3
	//v.erase(pos); //������ʧЧ
	//������ʧЧ�����1��pos������ı� 2�����ܻ��������Ұָ��

	v.erase(pos);
	pos = find(v.begin(), v.end(), 3);
		for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	//Ҫ��ɾ��vector������ż��
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0) 
		{//erase(it)�Ժ�itʧЧ������++
			it = v.erase(it);//erase����ɾ��λ��it����һ��λ��
		}
		else
			it++;
	}
}
void test_vector6()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	swap(v1, v2);//3�����
	v1.swap(v2);//�Ƽ�
}
int main()
{
	L::test_vector4();
	return 0;
}