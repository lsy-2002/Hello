#pragma once
#include <iostream>
using namespace std;


//red-black tree
enum Color
{
	RED,
	BLACK
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Color _col;
	
	RBTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};
template<class K,class V>
struct _TreeIterator
{
	typedef RBTreeNode<K, V> Node;
	Node* _node;
	_TreeIterator(Node* node)
		:_node(node)
	{}
	//operator*();
	//operator++();
	//operator--();
};
template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}
	void _Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}
	~RBTree()
	{
		_Destory(_root);
		_root = nullptr;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(_root, true);
		} 
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}
		Node* newnode = new Node(kv);
		newnode->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		//����Ľ���Ǻ�ɫ���Ǻ�ɫ��
		//�����ɫ��㣬�����ƻ�����3������Ӱ�첻��
		//�����ɫ��㣬һ���ƻ�����4�����һ�Ӱ������·����Ӱ����ܴ�
		cur = newnode;
		//������״��ڣ�����ɫΪ��ɫ����Ҫ����
		while (parent && parent->_col == RED)
		{
			//�ؼ�������
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//���1��uncle ������Ϊ��
					//��parent��uncle��ڣ�grandfather���
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;

				}
				else
				{
					//���2+3
					//uncle�����ڻ�uncle������Ϊ��
					if (cur == parent->_left)
					{
						//���2����Ҫ�ҵ���
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						//���3������˫��
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;

					}
					break;
				}
			}
			else//parent == grandfather->right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//���һ
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;

				}
				else
				{
					//���2+���3
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else // cur == parent->_left
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					//�������
					break;
				}
			}

		}
		_root->_col = BLACK;
		return make_pair(newnode, true);
		
	}
	void RotateR(Node* parent)
	{
		Node* subl = parent->_left;
		Node* sublr = subl->_right;
		parent->_left = sublr;
		if (sublr)
		{
			sublr->_parent = parent;
		}

		subl->_right = parent;
		Node* parentparent = parent->_parent;
		parent->_parent = subl;
		if (parent == _root)
		{
			//��һ����������
			_root = subl;
			_root->_parent = nullptr;
		}
		else
		{
			//ֻ������,parent����parent
			if (parentparent->_left == parent)
			{
				parentparent->_left = subl;
			}
			else
			{
				parentparent->_right = subl;
			}
			subl->_parent = parentparent;
		}
		
	}
	void RotateL(Node* parent)
	{
		Node* subr = parent->_right;
		Node* subrl = subr->_left;

		parent->_right = subrl;
		if (subrl)
		{
			subrl->_parent = parent;
		}
		Node* parentparent = parent->_parent;
		subr->_left = parent;
		parent->_parent = subr;

		if (parent == _root)
		{
			//�Ƕ�������
			_root = subr;
			_root->_parent = nullptr;
		}
		else
		{
			//������
			if (parentparent->_left == parent)
				parentparent->_left = subr;

			else
				parentparent->_right = subr;

			subr->_parent = parentparent;

		}
		
	}
	bool  _CheckBalance(Node* root, int blacknum, int count)
	{
		if (root == nullptr)
		{
			if (count != blacknum)
			{
				cout << "��ɫ�����Ŀ�����" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "����������ɫ" << endl;
			return false;
		}
		if (root->_col == BLACK)
		{
			count++;
		}
		return _CheckBalance(root->_left,blacknum,count)
			&& _CheckBalance(root->_right,blacknum,count);
	}
	bool CheckBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		if (_root->_col == RED)
		{
			cout << "root is red" << endl;
			return false;
		}
		//������·�����ο�ֵ
		int blacknum = 0;
		Node* left = _root;
		while (left)
		{
			if (left->_col == BLACK)
			{
				blacknum++;
			}
			left = left->_left;
		}
		int count = 0;
		return _CheckBalance(_root, blacknum, count);
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_kv.first <<"->"<<root->_kv.second<< endl ;
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
		
	}

private:
	Node* _root;
};