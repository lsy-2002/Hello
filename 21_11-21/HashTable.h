#pragma once
#include <iostream>
#include <vector>
using namespace std;
//一个类型去做map/set的Key有什么要求？ -- 能支持比较大小
//一个类型去做unordered_set/unordered_map的Key有什么要求？ -- 能支持转换成整型+相等比较
namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXITS,
		DELETE
	};
	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;//状态标识
	};
	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	//特化
	template<>
	struct Hash<string>
	{
		struct StringKHash//仿函数的目的：字符串转成对应的整型值，因为整形才能取模算映射位置
		{
			//期望：字符串不同，转出的整型值尽量不同
			size_t operator()(const string& s)
			{
				//BKDR Hash
				size_t value = 0;
				for (auto h : s)
				{
					value += h;
					value *= 131;
				}
				return value;
			}
		};
	};
	struct KHash
	{

	};
	template<class K,class V,class KHash = Hash<K>>//KHash仿函数
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			HashData<K,V>* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}
			//计算负载因子
			if (_table.size() == 0)
			{
				_table.resize(10);
			}
			else if ((double)_n / (double)_table.size() > 0.7)
			{
				//增容,重新计算每个数据在新空间中的位置
				HashTable<K, V,KHash> newHT;
				newHT._table.resize(_table.size() * 2);
				for (auto& e : _table)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}
				_table.swap(newHT._table);

			}
			KHash kh;
			size_t start = kh(kv.first) % _table.size();
			size_t index = start;
			//探测后面的位置 ：线性探测/二次探测
			size_t i = 1;
			while (_table[index]._state == EXITS)
			{
				index = start + i*i;
				index %= _table.size();
				i++;
			}
			_table[index]._kv = kv;
			_table[index]._state = EXITS;
			_n++;
			return true;
		}
		HashData<K,V>* Find(const K& key)
		{
			if(_table.size() == 0)
			{
				return nullptr;
			}
			KHash kh;
			size_t start = kh(key) % _table.size();
			size_t index = start;
			size_t i = 1;
			while (_table[index]._state == EXITS && _table[index]._state != EMPTY)
			{
				if (_table[index]._kv.first == key)
				{
					return &_table[index];
				}
				index = start + i*i;
				index %= _table.size();
				i++;

			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			{
				if (ret == nullptr)
				{
					return false;
				}
				else
				{
					ret->_state = DELETE;
					return false;
				}
			}
		}
	private:
		/*HashData* _table;
		size_t _size;
		size_t _capacity;*/
		vector<HashData<K,V>>  _table;
		size_t _n = 0;//存储的有效数据
	};
	struct IntKHash
	{
		int operator()(int i)
		{
			return i;
		}
	};
	struct StringKHash//仿函数的目的：字符串转成对应的整型值，因为整形才能取模算映射位置
	{
		//期望：字符串不同，转出的整型值尽量不同
		size_t operator()(const string& s)
		{
			//BKDR Hash
			size_t value = 0;
			for (auto h : s)
			{
				value += h;
				value *= 131;
			}
			return value;
		}
	};
	void test1()
	{
		int a[] = { 1, 5, 10, 1000, 100, 18, 15 ,7,40};
		HashTable<int, int,IntKHash> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		auto ret = ht.Find(100);
		if (ret)
		{
			cout << "找到" << endl;
		}
		else
		{
			cout << "没找到" << endl;
		}
		ht.Erase(100);
		auto rret = ht.Find(100);
		if (rret)
		{
			cout << "找到" << endl;
		}
		else
		{
			cout << "没找到" << endl;
		}
	}
	void Test2()
	{
		StringKHash hf;
		cout << hf("insert") << endl;
		cout << hf("int") << endl;

		cout << hf("abcd") << endl;
		cout << hf("bacd") << endl;

		cout << hf("abbb") << endl;
		cout << hf("acdc") << endl;

	}
}
//namespace OpenHash
//{
//	template<class K, class V>
//	struct HashNode
//	{
//		HashNode<K, V>* _next;
//		pair<K, V> _kv;
//		HashNode(const pair<K, V>& kv)
//			:_next(nullptr)
//			, _kv(kv)
//		{}
//	};
//	template<class K>
//	struct Hash
//	{
//		size_t operator()(const K& key)
//		{
//			return key;
//		}
//	};
//	template<>
//	struct Hash<string>
//	{
//		size_t operator()(const string& s)
//		{
//			size_t value = 0;
//			for (auto e : s)
//			{
//				value += e;
//				value *= 131;
//			}
//			return value;
//		}
//	};
//	template<class K,class V,class KHash>
//	class HashTable
//	{
//		typedef HashNode<K, V> Node;
//	public:
//		bool Insert(const pair<K, V>& kv)
//		{
//			if (Find(kv.first))
//			{
//				return false;
//			}
//			KHash hf;
//			//负载因子到1时，进行增容
//			if (_n == _table.size())
//			{
//				vector<Node*>  newtable;
//				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
//				newtable.resize(newsize,nullptr);
//				
//			
//				//遍历旧表，把位置映射到新表
//				for (size_t i = 0; i < _table.size(); i++)
//				{
//					if (_table[i])
//					{
//						Node* cur = _table[i];
//						while (cur)
//						{
//							Node* next = cur->_next;
//							size_t index = hf(cur->_kv.first) % newtable.size();
//							//头插
//							cur->_next = _table[index];
//							_table[index] = cur;
//							cur = next;
//
//						}
//						_table[i] = nullptr;
//					}
//				}
//				_table.swap(newtable);
//			}
//
//			size_t index = hf( kv.first) % _table.size();
//			Node* newnode = new Node(kv);
//			//头插
//			newnode->_next = _table[index];
//			_table[index] = newnode;
//			_n++;
//		}
//		Node* Find(const K& key)
//		{
//			if (_table.size() == 0)
//			{
//				return false;
//			}
//			KHash hf
//			size_t index = hf(key.first) % _table.size();
//			Node* cur = _table[index];
//			while (cur)
//			{
//				if (cur->_kv.first == key)
//				{
//					return cur;
//				}
//				else
//				{
//					cur = cur->_next;
//				}
//			}
//			return nullptr;
//		}
//		bool Erase(const K& key)
//		{
//			KHash hf;
//			size_t index = hf(key) % _table.size();
//			Node* prev = nullptr;
//			Node* cur = _table[index];
//			while (cur)
//			{
//				if (cur->_kv.first == key)
//				{
//					if (_table[index] == cur)
//					{
//						//删除的是第一个
//						_table[index] = cur->_next;
//					}
//					else
//					{
//						prev->_next = cur->_next;
//					}
//					delete cur;
//					_n--;
//					return true;
//				}
//				else
//				{
//					prev = cur;
//					cur = cur->_next;
//				}
//			}
//			return false;
//		}
//	private:
//		vector<Node*> _table;
//		size_t _n;//有效数据的个数
//
//
//
//	};
//
//}
namespace OpenHash
{
	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& s)
		{
			size_t value = 0;
			for (auto e : s)
			{
				value += e;
				value *= 131;
			}
			return value;
		}
	};
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;
		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
	};
	//前置声明
	template<class K, class T, class KeyofT, class KHash>
	class HashTable;


	
	//迭代器
	template<class K, class T, class KeyofT, class KHash = Hash<K>>
	struct  _HTIterator
	{
	
		typedef HashNode<T> Node;
		typedef _HTIterator<K, T, KeyofT, KHash>  Self;
		typedef HashTable<K, T, KeyofT, KHash> HT;
		Node* _node;
		HT* _pht;
		
		_HTIterator(Node* node, HT* pht)
			:_node(node)
			, _pht(pht)
		{}

		Self& operator++()
		{
			//当前桶中还有数据，就在当前桶往后走
			//当前桶走完了，需要往下一个桶去走
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyofT kot;
				KHash hf;
				size_t index = hf(kot()(_node->_data)) % _pht->_table.size();
				index++;
				while (index < _pht->_table.size())
				{
					if (_pht->_table[index])
					{
						_node = _pht->_table[index];
						return *this;
					}
					else
					{
						++index;
					}
					
				}
				_node = nullptr;
				

			}
			return *this;
		}
		
		T& operator*()
		{
			return _node->_data;
		}
		T* operator->()
		{
			return _node->_data;
		}
		bool operator != (const Self& s) const
		{
			return _node == s._node;
		}
		bool operator == (const Self& s) const
		{
			return _node == s._node;
		}
	};
	template<class K, class T, class KeyofT,class KHash = Hash<K>>
	class HashTable
	{
		typedef HashNode<T> Node;
		template<class K, class T, class KeyofT, class KHash = Hash<K>>
		friend struct _HTIterator;
	public:
		typedef _HTIterator<K, T, KeyofT, KHash> iterator;
		HashTable() = default;//显示指定生成默认构造函数
		HashTable(const HashTable& ht)
		{
			_n = ht._n;
			_table.resize(ht._table.size());
			for (size_t i; i < ht._table.size(); i++)
			{
				Node* cur = ht._table[i];
				while (cur)
				{
					Node* copy = new Node(cur->_data);
					//头插到新表
					copy->_next = _table[i];
					_table[i] = copy;
					cur = cur->_next;
				}
			}
		}
		HashTable& operator=(HashTable ht)
		{
			_table.swap(ht._table);
			swap(_n, ht._n);
			return *this;
		}
		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}
		iterator begin()
		{
			size_t i = 0;
			while (i < _table.size())
			{
				if (_table[i])
				{
					return iterator(_table[i],this);//找到第一个桶
				}
				i++;
			}
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator,bool> Insert(const T& data)
		{
			KeyofT kot;
			auto ret = Find(kot(data));
			if (ret != end())
			{
				return make_pair(ret, false);
			}
			KHash hf;
			//负载因子到1时，进行增容
			if (_n == _table.size())
			{
				vector<Node*>  newtable;
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				newtable.resize(newsize, nullptr);


				//遍历旧表，把位置映射到新表
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = hf(kot(cur->_data)) % newtable.size();
							//头插
							cur->_next = newtable[index];
							newtable[index] = cur;
							cur = next;

						}
						_table[i] = nullptr;
					}
				}
				_table.swap(newtable);
			}

			size_t index = hf(kot(_data)) % _table.size();
			Node* newnode = new Node(data);
			//头插
			newnode->_next = _table[index];
			_table[index] = newnode;
			_n++;
			return make_pair(iterator(newnode, this), true);
		}
		iterator* Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return end();
			}
			KeyofT kot;
			KHash hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur,this);
				}
				else
				{
					cur = cur->_next;
				}
			}
			return end;
		}
		bool Erase(const K& key)
		{
			KHash hf;
			size_t index = hf(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (_table[index] == cur)
					{
						//删除的是第一个
						_table[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					
					_n--;
					delete cur;
					return true;
				}
				
					prev = cur;
					cur = cur->_next;
				
			}
			return false;
		}
	private:
		vector<Node*> _table;
		size_t _n;//有效数据的个数



	};

}
