#define _CRT_SECURE_NO_WARNINGS 1
#include "AVL.h"
void test1()
{
	//int a[] = { 1, 3, 5, 7,6 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> avl;
	for (auto e : a)
	{
		avl.Insert(make_pair(e,e));
	}
	avl.InOrder();
	cout  << avl.IsAVLTreeTrue() << endl;
}
int main()
{
	test1();
	return 0;
}