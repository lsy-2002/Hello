#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

void test_unordered_set()
{
	unordered_set <int> us;
	us.insert(2);
	us.insert(1);
	us.insert(3);
	us.insert(5);
	us.insert(6);
	us.insert(2);
	us.insert(6);
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//auto pos = us.find(2);//unordered_set专用，使用哈希特性查找:O(1)
	auto pos = find(us.begin(), us.end(),2)//通用，所有容器都可以用，缺点：暴力查找O(N)

}
int main()
{
	test_unordered_set();
	return  0;
}