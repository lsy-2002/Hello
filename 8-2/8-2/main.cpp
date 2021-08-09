#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
using namespace std;

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " "; 
		it++;
	}
	cout << endl;
	//g++ test_list1.cpp -std=C++11 Linux �±���
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	int a[] = { 16, 2, 77, 29 };
	list<int> lt1(a, a + 4);//list(InputIterator first,InputIterator last)
	//ԭ��ָ����Ե�����Ȼ�ĵ�����ʹ��  vector/string�ĵ�����Ҳ��ԭ��ָ��
	
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int> v(a, a + 4);
	// < ���� Ĭ��
	// > ����
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	sort(a, a + 4); 
	//sort�ײ�ʹ�ÿ������򣬿���Ҫ����������������������������


}
template<class Con>
void PrintList(const Con& c)
{
	Con::const_iterator it = c.begin();
	while (it != c.begin())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void test_list2()
{

	list<int> lt;
	lt.push_back(10);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	PrintList(lt);
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	lt.insert(pos, 20);//��������ʧЧ
	lt.erase(pos);//��������ʧЧ
}
void test_list3()
{

	list<int> lt;
	lt.push_back(10);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
}
int main()
{
	test_list1();
	return 0;
}