#pragma once

namespace PQ
{
	template<class T>
	struct less
	{
		bool operator()(const T& i, const T& n)
		{
			return i < n;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& i, const T& n)
		{
			return i > n;
		}
	};
	template<class T,class Container = std::vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		//typedef Container::value_type vt;// 报错 类模板没有实例化，编译器就不能去类中找
		//类模板，不会被留下，留下的具体实例化类模板中的T以后的类
		typedef typename Container::value_type vt;//typename/class 告诉编译器这后面是类型名称
		//等类模板实例化以后再去找它中的value_type
		void Adjustup(size_t child)
		{
			Compare com;
			size_t  parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] > _con[child])
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			Adjustup( _con.size() - 1);//向上调整
		}
		void Adjustdown(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] > _con[child + 1])
				if (child + 1 < _con.size() && (com(_con[child] , _con[child + 1])))
				{
					child++;
				}
				//if (_con[parent] > _con[child])
				if (com(_con[parent] , _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjustdown(0);//向下调整

		}
		T top()
		{
			return _con[0];
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
		Container  _con;
	
	};
}