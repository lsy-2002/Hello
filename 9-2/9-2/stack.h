#pragma once
#include <vector>
#include <list>
namespace Stack
{
	//����ʵ�����ݽṹ�Ĳ���
	//template<class T>
	//class stack
	//{
	//public:
	//	//...
	//private:
	//	T* a;
	//	size_t _size;
	//	size_t _capacity;
	//};
	//����������
	//template<class T,class Container = std::list<T>>
	//template<class T,class Container = std::vector<T>>
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:

		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;

	};
}