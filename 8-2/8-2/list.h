#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <algorithm>
#include <assert.h>
using namespace std;
namespace List
{
	template<class T>
	struct _list_node
	{
		 T _val;
		_list_node<T>* _next;
		_list_node<T>* _prev;
		_list_node(const T& val = T() )
			:_val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};
	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;
		node* _pnode;

		_list_iterator (node* pnode)
			:_pnode(pnode)
		{}
		//拷贝构造、opreator、析构用编辑器默认生成的

		//节点的指针原生行为不满足迭代器定义
		//这里迭代器通过类去封装节点的指针重载来控制
		Ref operator*()
		{
			return _pnode->_val;
		}
		Ptr operator ->()
		{
			return &_pnode->_val;
		}
		bool operator !=(const self& s)const
		{
			return _pnode != s._pnode;
		}
		bool operator ==(const self& s)const
		{
			return _pnode == s._pnode;
		}
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
			
		}
		self operator++(int)
		{
			self temp(*this);
			_pnode = _pnode->_next;
			return temp;
		}
		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator--(int)
		{
			self temp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;
		
	public:
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		list()
		{
			//_head = new node(T();
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto e : lt)
			{
				push_back(e);
			}
		}
		/*list<T>& operator=(const list<T>& lt) //传统
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
		list<T>& operator=( list<T> lt)
		{
			swap(_head, lt._head);
			return*this;
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
			/*node* newnode = new node(x);
			node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
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
			//prev newnode cur
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
			return begin() == end();
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

	};
	void PrintList(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator  it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			it++;
		}
	}
}
