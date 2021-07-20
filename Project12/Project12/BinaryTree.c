#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.H>
#include "Queue.h"
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;
typedef char BTDataType;


void PrevOrder(BTNode* root)//ǰ��
{
	if (root == NULL)
	{
		printf("NULL");
		return ;
	}
	printf("%c", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	InOrder(root->left);
	printf("%c", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c", root->data);
}
BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;

}
/*int TreeSize(BTNode* root,int* psize)//˼·һ�����������ķ�ʽ
{
	if (root == NULL)
	{
		return 0;
	}
	(*psize)++;
	TreeSize(root->left);
	TreeSize(root->right);
}*/
int TreeSize(BTNode* root)//�����ĸ���
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode* root)//Ҷ�ӽ��ĸ���
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&& root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int TreeKLevelSize(BTNode* root, int k)//��K��Ҷ�ӽ�����
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1) + 
		   TreeKLevelSize(root->right, k - 1);

}
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//���Լ�����
	if (root->data == x)
		return root;
	//�ֱ���������Ѱ��
	BTNode* lret = TreeFind(root->left,x);
	if (lret)
		return lret;
	 BTNode* rret = TreeFind(root->right,x);
	if (rret)
		return rret;
	//���Ҷ�û�ҵ�
	return NULL;
}
void BinaryTreeDestoty(BTNode** proot)//��������
{
	//
	if (*proot == NULL)
		return;
	BinaryTreeDestoty(&(*proot)->left);
	BinaryTreeDestoty(&(*proot)->right);
	free(*proot);
	*proot = NULL;

}
/*void BinaryTreeDestoty(BTNode*& root)//��������  *&->��С����c++��
{
	//
	if (root == NULL)
		return;
	BinaryTreeDestoty(root->left);
	BinaryTreeDestoty(root->right);
	free(root);
	root = NULL;

}*/
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
	{
		QueuePush(&q, root->data);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c", front->data);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);
}
bool BinaryTreeCompelet(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root->data);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
			return false;
	}
	QueueDestroy(&q);
	return true;
}
int main()
{
	
	
	return 0;
}
