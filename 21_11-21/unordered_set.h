#include "HashTable.h"
namespace hs
{
	template<class K>
	class unordered_set
	{
		struct SetKeyofT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		
		typedef typename OpenHash::HashTable<K, K,SetKeyofT>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		
		pair<iterator,bool> insert(const K& k)
		{
			_ht.Insert(k);
			return true;
		}
	private:
		OpenHash::HashTable<K, K,SetKeyofT> _ht;
	};
	/*void test1()
	{
		unordered_set<int> us;
		us.insert(2);
		us.insert(1);
		us.insert(2);
		us.insert(3);
		us.insert(5);
		us.insert(6);
		us.insert(2);
		us.insert(6);
		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}*/
}