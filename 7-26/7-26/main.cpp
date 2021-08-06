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
	//遍历1
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	//遍历2
	vector<int>::iterator it1 = v1.begin();
	//迭代器的比较都使用 == 或 != 因为面对list,map等链式结构就不行了
	while (it1 != v1.end())
	{
		*it1 += 1;
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	//遍历3 自动判断结束，自动迭代++ -》实际上替换成了迭代器
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	PrintVecort(v1);
}
void test_vector2()
{
	//vector常见的构造方式
	vector<int> v1;
	vector<int> v2(10, 0);//给10个0初始化
	vector<int> v3(v2.begin(), v2.end());//用迭代区间初始化
	string s("hello world");
	vector<char> v4(s.begin(),s.end());
	vector<string> v5;
	string s1("sort");
	v5.push_back(s1);
	v5.push_back(string("hello"));//匿名对象
	//推荐
	v5.push_back("world");//隐式类型转换

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
	//验证vector的增容方式 VS:1.5倍取整增容 Linux:2倍增容
	size_t sz;
	vector<int> f;
	sz = f.capacity();
	cout << "grow\n";
	//f.reserve(20);提前开空间就不会有增容
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
	//删掉3
	//v.erase(pos); //迭代器失效
	//迭代器失效情况：1、pos的意义改变 2、可能会崩溃出现野指针

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
	//要求删除vector中所有偶数
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0) 
		{//erase(it)以后it失效，不能++
			it = v.erase(it);//erase返回删除位置it的下一个位置
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
	swap(v1, v2);//3次深拷贝
	v1.swap(v2);//推荐
}
int main()
{
	L::test_vector4();
	return 0;
}