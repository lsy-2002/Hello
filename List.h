#pragma once
#include <assert.h>
#include "Iterator.h"

namespace rbt
{
	template<class T>
	struct _list_node
	{
		T _val;
		_list_node<T>* _next;
		_list_node<T>* _prev;

		_list_node(const T& val = T())
			:_val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	// typedef _list_iterartor<T, T&, T*> iterator;
	// typedef _list_iterartor<T, const T&, const T*> const_iterator;
	template<class T, class Ref, class Ptr>
	struct _list_iterartor
	{
		typedef Ref reference;
		typedef Ptr pointer;

		typedef _list_node<T> node;
		typedef _list_iterartor<T, Ref, Ptr> self;

		node* _pnode;

		_list_iterartor(node* pnode)
			:_pnode(pnode)
		{}

		// 拷贝构造、operator=、析构我们不写，编译器默认生成就可以用

		// T& operator*()		 iterator 可读可写
		// const T& operator*()  const_iterator 可读可写
		Ref operator*()
		{
			return _pnode->_val;
		}

		Ptr operator->()
		{
			return &_pnode->_val;
		}

		bool operator!=(const self& s) const
		{
			return _pnode != s._pnode;
		}

		bool operator==(const self& s) const
		{
			return _pnode == s._pnode;
		}

		// ++it -> it.operator++(&it)
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}

		// it++ -> it.operator++(&it, 0)
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}

		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	};


	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterartor<T, T&, T*> iterator;
		typedef _list_iterartor<T, const T&, const T*> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(iterator(_head->_prev));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(iterator(_head));
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			//_head = new node(T());
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		// copy(lt)
		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		//copy = lt1;
		/*	list<T>& operator=(const list<T>& lt)
		{
		if (this != &lt)
		{
		clear();
		for (const auto& e : lt)
		{
		push_back(e);
		}
		}

		return *this;
		}*/

		// copy = lt1;
		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);

			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//it = erase(it);
				erase(it++);
			}
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos._pnode);

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos._pnode);
			assert(pos != end());

			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;

			delete pos._pnode;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

		bool empty()
		{
			return begin() == end()；
		}

		size_t size()
		{
			size_t sz = 0;
			iterator it = begin();
			while (it != end())
			{
				++sz;
				++it;
			}

			return sz;
		}
	private:
		node* _head;
		//size_t _size;
	};

	void PrintList(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			// *it += 1; // ?
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	class Date
	{
	public:
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

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
			*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		PrintList(lt);
	}

	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._year << " " << (*it)._month <<" " <<(*it)._day<<endl;
			cout << it->_year << " " << it->_month << " " << it->_day << endl;

			++it;
		}
		cout << endl;

		Date d;
		Date* p = &d;

		(*p)._year = 100;
		p->_year = 100;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		PrintList(lt);

		list<int> copy(lt);
		PrintList(copy);

		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		copy = lt1;
		PrintList(copy);
		PrintList(lt1);



		lt.clear();
		PrintList(lt);
	}
}