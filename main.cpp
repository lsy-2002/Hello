#define _CRT_SECURE_NO_WARNINGS 1

#include "RBT2.h"
#include "Map.h"
#include "Set.h"
#include "Iterator.h"
#include"List.h"
//void test1()
//{
//	RBTree<int, int> t;
//	
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	t.Inorder();
//	cout << t.CheckBalance() << endl;
//}
//void test2()
//{
//	rbt::Map<int, int> m;
//	m.insert(make_pair(1, 1));
//	rbt::Set<int> s;
//	s.insert(1);
//}
int main()
{
	rbt::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(9, 9));

	rbt::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	rbt::Set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(0);
	s.insert(15);
	s.insert(18);

	rbt::Set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	rbt::Set<int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;

	rbt::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	rbt::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	rbt::map<string, string> dict;
	dict["sort"];
	dict["left"] = "";
	dict["left"] = "?";

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	dict["sort"] = "";

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}

	return 0;
}