#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace L
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(size_t n, const T val)
		//vector(int n, const T& value = T())
		: _start(nullptr)
			,_finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			/*this->reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}*/
			_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());//深层次深浅拷贝
		/*	总结：T是内置类型，它们增容或者拷贝中，用memcpy没问题
			但是T是深拷贝的自定义类型(string)，它们增容或拷贝就有问题
			vs下，string结构跟g++不同,vs在string本身对象中加了一个buf
			字节少存在buf里，字节多用ptr指针指向*/
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];//调用的operator= 复制
			}
			_endofstorage = _start = v.capacity();
			_finish = _start + v.size();
		}
		//传统写法
		/*vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				delete[] = _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T)*v.size());
				_endofstorage = _start = v.capacity();
				_finish = _start + v.size();
			}
			return *this;
		}*/
		void swap(vector<T>&v)
		{

			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::(_endofstorage, v._endofstorage);
		}
		//现代写法
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}
			_start = _finish = _endofstorage = nullptr;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		void resize(size_t n, T val = T())
		{
			if (n <size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				
					
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sz*sizeof(T));
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void push_back(const T&x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(!empty);
			--_finish;
		}
		void insert(iterator& pos, const T&x)
		{
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//更新pos解决增容后失效问题
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish ++;
			pos += 1;//解决迭代器失效
		}
		iterator erase(iterator pos)
		{
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			_finish--;
			return pos;
		}
	
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	template <class T>
	void PrintVector(const vector<T>& v)
	{
		vector<int> ::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		vector<int> ::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout <<endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		PrintVector(v);
		v.resize(3);
		PrintVector(v);
		v.resize(6, 1);
		PrintVector(v);
		v.resize(10, 2);
		PrintVector(v);
	}
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		PrintVector(v);
		vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		v.insert(pos, 30);
		//迭代器失效

		//删除所有偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}
			else
			{
				it++;
			}
			
		}
		PrintVector(v);
	}
	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		vector<int>v2(v);
		PrintVector(v);
		PrintVector(v2);
		
		
	}

}