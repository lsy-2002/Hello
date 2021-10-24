#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};
template <class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
private:
	Node* _FindR(Node* root,const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return root;
		}

	}
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else
		{
			return false;
		}
	}
	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else
		{
			//�ҵ���,root����Ҫɾ���Ľڵ�
			if (root->_left == nullptr)
			{
				Node* del = root;
				root = root->_right;
				delete del;
			}
			else if (root->_right == nullptr)
			{
				Node* del = root;
				root = root->_left;
				delete del;
			}
			else
			{
				////����������С�ڵ�
				//Node* minParent = root;
				//Node* minRight = root->_right;
				//while (minRight->_left)
				//{
				//	minParent = minRight;
				//	minRight = minRight->_left;
				//}
				////�����滻�ڵ��ֵ
				//root->key = minRight->_key;
				//if (minParent->_left == minRight)
				//{
				//	minParent->_left = minRight->_right;
				//}
				//else
				//{
				//	minParent->_right = minRight->_right;
				//}
				//delete minRight;
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight = minRight->_left;
					K min = minRight->_key;
				}
				_EraseR(root->_right, min);
				root->_key = min;
			}
			return ture;
		}
		
	}
	void _Destory(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}
	Node* _Copy(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(root->_key);
		copyNode->_left = _Copy(root->_left);
		copyNode->_right = _Copy(root->_right);
		return copyNode;
	}
public:
	BSTree()
		:_root(nullptr)
	{}
	BSTree(const BSTree<K>& t)
	{
		_root = _Copy(t._root);
	}
	~BSTree()
	{
		_Destory(_root);
		_root = nullptr;
	}
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}
	bool InsertR(const K& key)//�ݹ�汾
	{
		return _InsertR(_root, key);
	}

	Node* FindR(const K& key)//�ݹ�汾
	{
		return _FindR(_root, key);
	}
	bool EraseR(const K& key)//�ݹ�汾
	{
		return _EraseR(_root, key);
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return  NULL;
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_key << endl;
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//�ҵ���׼��ɾ��
				//��Ϊ�ջ���Ϊ�գ���ֱ��ɾ��������һ�����ӽ������׹���ɾ���Լ�
				if (cur->_left == nullptr)//��Ϊ��
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					
					delete cur;
				}
				else if (cur->_right == nullptr)//��Ϊ��
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					
				}
				else//���Ҷ���Ϊ�գ��滻��ɾ��
				{
					////�ҵ���������С�Ľڵ�ȥ�滻
					//Node* minparent = cur;
					//Node* minRight = cur->_right;
					//while (minRight->_left)
					//{
					//	minparent = minRight;
					//	minRight = minRight->_left;
					//}
					////�����滻�ڵ�
					//cur->_key = minRight->_key;
					////ɾ���滻�ڵ�
					//if (minparent->_left == minRight)
					//{
					//	minparent->_left = minRight->_right;
					//}
					//else
					//{
					//	minparent->_right = minRight->_right;
					//}
					//delete minRight;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K min = minRight->_key;
					//�ݹ�����Լ�ȥɾ���滻�ڵ�
					this->Erase(min);
					cur->_key = min;
				}
				return true;
			}
		}
		return false;
	}
private:
	Node* _root;
};
namespace KV
{
	template <class K,class V>
	struct BSTreeNode
	{
		BSTreeNode<K,V>* _left;
		BSTreeNode<K,V>* _right;
		K _key;
		V _value;
		BSTreeNode(const K& key,const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};
	template <class K,class V>
	class BSTree
	{
		typedef BSTreeNode<K,V> Node;
	private:
		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}

		}
		bool _InsertR(Node*& root, const K& key,const V& value)
		{
			if (root == nullptr)
			{
				root = new Node(key,value);
				return true;
			}
			if (root->_key < key)
			{
				return _InsertR(root->_right, key,value);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key,value);
			}
			else
			{
				return false;
			}
		}
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				//�ҵ���,root����Ҫɾ���Ľڵ�
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
						K kmin = minRight->_key;
						V vmin = minRight->_value;
					}
					_EraseR(root->_right, kmin);
					root->_key = kmin;
					root->_value = vmin;
				}
				return ture;
			}

		}
		void _Destory(Node* root)
		{
			if (root == NULL)
			{
				return;
			}
			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
		}
		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* copyNode = new Node(root->_key,root->_value);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);
			return copyNode;
		}
	public:
		BSTree()
			:_root(nullptr)
		{}
		BSTree(const BSTree<K,V>& t)
		{
			_root = _Copy(t._root);
		}
		~BSTree()
		{
			_Destory(_root);
			_root = nullptr;
		}
		BSTree<K,V>& operator=(BSTree<K,V> t)
		{
			swap(_root, t._root);
			return *this;
		}
		bool InsertR(const K& key,const V& value)//�ݹ�汾
		{
			return _InsertR(_root, key,value);
		}

		Node* FindR(const K& key)//�ݹ�汾
		{
			return _FindR(_root, key);
		}
		bool EraseR(const K& key)//�ݹ�汾
		{
			return _EraseR(_root, key);
		}
		
		void _Inorder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Inorder(root->_left);
			cout << root->_key<<":"<<root->_value << endl;
			_Inorder(root->_right);
		}
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		
	private:
		Node* _root;
	};
}
void test1()
{
	KV::BSTree<string, string>dict;
	dict.InsertR("string", "�ַ���");
	dict.InsertR("tree", "��");
	dict.InsertR("left", "��ߣ�ʣ��");
	dict.InsertR("right", "�ұ�");
	dict.InsertR("sort", "����");
	//����ʿ��е���
	string str;
	while(cin >> str)
	{
		KV::BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "����ƴд���󣬴ʿ���û���������" << str << endl;
		}
		else
		{
			cout << str << "->" << ret->_value << endl;
		}
	}
}
void test2()
{
	//ͳ��ˮ�����ֵĴ���
	string arr[] = { "ƻ��", "����", "�㽶", "����", "ƻ��", "����", "����" };
	KV::BSTree<string, int> countfriut;
	for (const auto e : arr)
	{
		//�Ȳ����ڲ�����������
		//1������-������<ˮ����1>
		//2����-��
		//KV::BSTreeNode<string, int>* ret = countfriut.FindR(e);
		auto ret = countfriut.FindR(e);
		if (ret == nullptr)
		{
			countfriut.InsertR(e,1);
		}
		else
		{
			ret->_value++;
		}
	}
	countfriut.Inorder();
}
int main()
{
	test2();
	return 0;
}