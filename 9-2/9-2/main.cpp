#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
using std::cout;
using std::endl;

//void test_stack()
//{
//	Stack::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
//void test_queue()
//{
//	Queue::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}
//void test_priority_queue()
//{
//	//底层是堆，默认是大堆，大的优先级高  less
//	//std::priority_queue<int> pq;
//	
//	//变成小堆，小的优先级高 greater
//	std::priority_queue<int, std::vector<int>,std::greater<int>> pq1;
//	pq1.push(3);
//	pq1.push(5);
//	pq1.push(7);
//	pq1.push(4);
//	pq1.push(1);
//	/*while (!pq.empty())
//	{
//		cout << pq.top() << endl;
//		pq.pop();
//	}*/
//	while (!pq1.empty())
//	{
//		cout << pq1.top() << endl;
//		pq1.pop();
//	}
//}
//void test_p_q()
//{
//	PQ::priority_queue<int> pq1;
//	pq1.push(3);
//	pq1.push(5);
//	pq1.push(7);
//	pq1.push(4);
//	pq1.push(1);
//	pq1.push(3);
//	pq1.push(5);
//	pq1.push(7);
//	pq1.push(4);
//	pq1.push(1);
//	while (!pq1.empty())
//	{
//		cout << pq1.top() << " ";
//		pq1.pop();
//	}
//
//}
////仿函数-》函数对象 这个类的对象可以像函数一样去使用
////为什么用仿函数? 函数指针不好用
//struct LessInt
//{
//	bool operator()(int i, int n)
//	{
//		return i < n;
//	}
//};
//
//int main()
//{
//	//test_stack();
//	//test_queue();
//	//test_priority_queue();
//	//test_p_q();
//	//LessInt li;
//	////cout<<li.operator()(3,4)<<endl;
//	//cout<<li(2, 4)<<endl;
//	
//	return 0;
//}
//#define N 1000
//模板参数
//类型模板参数
//非类型模板参数 --int常量
//template<class T,size_t N>
//class Array
//{
//public:
//	void f()
//	{
//		N = 100;
//	}
//private:
//	T _a[N];
//};
//int main()
//{
//	Array<int,100> aa1;//100
//	Array<int,1000> aa2;//1000
//	aa1.f();
//	return 0;
//}
template <class T>
bool IsEqual(const T& left, const T& right)
{
	return left == right;
}
//针对字符串类型要特殊化处理 -- 写一份特殊的函数模板出来
//函数模板的特化
template <>
bool IsEqual<const char*>(const char* const& left, const char* const& right)
//bool IsEqual(const char* left,const char* right)
{
	return strcmp(left, right) == 0;
}
//int main()
//{
//	cout << IsEqual(1, 2) << endl;
//	cout << IsEqual(1.1, 2.2) << endl;
//	char p1[] = "hello";
//	char p2[] = "hello";
//	cout << IsEqual(p1, p2) << endl;
//	char* p3 = "hello";
//	char* p4 = "hello";
//	cout << IsEqual(p3, p4) << endl;
//}
//	 char p5[] = "hello";
//	 char p6[] = "hello";
//	cout <<IsEqual(p5, p6) << endl;//相等
//	const char* p7 = "hello";
//	const char* p8 = "hello";
//	cout << IsEqual(p7, p8) << endl;//相等
//
//
//}

template <class T1,class T2>
class Date
{
public:
	Date()
	{
		cout << "Date <T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//假设针对T1 T2 是 int int 想做特殊化处理 -》类模板特化
template<>
class Date<int, int>
{
public:
	Date()
	{
		cout << "Date <int,int>" << endl;
	}

};
//将第二个参数特化为int --- 偏特化
template<class T>
class Date<T,int>
{
public:
	Date()
	{
		cout << "Date <T,int>"<< endl;
	}

};
template<class T1,class T2>
class Date<T1*,T2*>
{
public:
	Date()
	{
		cout << "Date<T1*,T2*>" << endl;
	}

};
template<class T1,class T2>
class Date<T1&,T2&>
{
public:
	Date()
	{
		cout << "Date<T1&,T2&"<< endl;
	}

};
int main()
{
	Date<int, int> d1;
	Date<int, double> d2;
	Date <char, int> d3;
	Date<int*,char*> d4;
	Date<int&, double&> d5;
	return 0;
}