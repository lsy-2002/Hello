#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
template<class K,class V>
class AVLTreeNode
{
public:
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K,V>* _right;
	AVLTreeNode<K,V>* _parent;

	int _bf;//ƽ������
	//������ - ������
	pair<K,V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};


template <class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
	~AVLTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}
	V& operator[](const K& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, v()));
		return ret.first->_kv.second;
	}
	pair<Node*,bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		//�ҵ����ݴ洢��λ�ã������ݲ���
		Node* parent = _root, *cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				//С��
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				//����
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//����
				return make_pair(cur,true);
			}
		}
		cur = new Node(kv);
		Node* newnode = cur;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//����ƽ��
		//1������ƽ������
		//2�������ƽ����Ҫ��ת
		while (parent != nullptr)//while(cur != _root)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//parent���ڵ������߶ȱ��ˣ���Ӱ��parant��parent���������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent���ڵ������Ѿ���ƽ�⣬��Ҫ��ת����
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//����ҵ�-���ҵ���
						RotateR(parent);
					}
					else// cur->_buf == 1
					{
						//����˫��
						RotateLR(parent);
					}
				}
				else//parent->_bf == 2
				{
					if (cur->_bf == 1)
					{
						//����
						RotateL(parent);

					}
					else//cur->_bf == -1
					{
						//����˫��
						RotateRL(parent);
					}
				}
			}
			else
			{
				//˵���ڲ�����֮ǰ�����Ѿ�ƽ������
				assert(false);
			}
			
		}
		return make_pair(newnode,true);
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
			subl->_parent = nullptr;
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
		subl->_bf = parent->_bf = 0;
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
			if (parentparent->_left = parent)
				parentparent->_left = subr;

			else
				parentparent->_right = subr;

			subr->_parent = parentparent;

		}
		parent->_bf = subr->_bf = 0;
	}
	void RotateRL(Node* parent)
	{
		Node* subr = parent->_right;
		Node* subrl = subr->_left;
		int bf = subrl->_bf;//��ǰ����ƽ������
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			//����c����
			subr->_bf = 0;
			parent->_bf = -1;
			subrl->_bf = 0;
		}
		else if (bf == -1)
		{
			//��b����
			parent->_bf = 0;
			subr->_bf = 1;
			subrl->_bf = 0;
		}
		else if (bf == 0)
		{
			//�������������
			parent->_bf = 0;
			subr->_bf = 0;
			subrl->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}
	void RotateLR(Node* parent)
	{
		Node* subl = parent->_left;
		Node* sublr = subl->_right;
		int bf = sublr->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == -1)
		{
			//��b�����½��
			subl->_bf = 0;
			parent->_bf = 1;
			sublr->_bf = 0;
		}
		else if (bf == 1)
		{
			//��c�����½��
			subl->_bf = -1;
			parent->_bf = 0;
			sublr->_bf = 0;
		}
		else if (bf == 0)
		{
			//�����������
			subl->_bf = 0;
			parent->_bf = 0;
			sublr->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{

	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);

	}
	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftheight = _Height(root->_left);
		int rightheight = _Height(root->_right);
		return rightheight > leftheight ? rightheight + 1 : leftheight + 1;
	}
	bool _Isbalance(Node* root)
	{
		//�ж����Ƿ�ƽ��
		if (root == nullptr)
		{
			return true;
		}
		int leftheight = _Height(root->_left);
		int rightheight = _Height(root->_right);
		//���ƽ�������Ƿ���ȷ
		if (rightheight - leftheight != root->_bf)
		{
			cout << "ƽ�������쳣" << root->_kv.first << endl;
			return false;
		}
		return abs(rightheight - leftheight) < 2
			&& _Isbalance(root->_left)
			&& _Isbalance(root->_right);
	}
	bool IsAVLTreeTrue()
	{
		return _Isbalance(_root);
	}
private:
	Node* _root;

};