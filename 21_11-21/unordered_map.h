#pragma once
#include "HashTable.h"
namespace hs
{
	template<class K,class V>
	class unordered_map
	{
		struct MapkeyofT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename OpenHash::HashTable<K, pair<K, V>, MapkeyofT>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator,bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		OpenHash::HashTable<K, pair<K, V>, MapkeyofT> _ht;
	};
}