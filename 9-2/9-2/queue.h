#pragma once
#include <vector>
#include <list>

namespace Queue
{
	template <class T,class Container = std::deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		T front()
		{
			return _con.front();
		}
		T back()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}