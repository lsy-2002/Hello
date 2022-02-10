#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <initializer_list>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <assert.h>
#include <functional>
#include <thread>
using namespace std;
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	Point p = { 1, 2 };
//	Point p{ 1, 2 };//���Բ�ʹ�� '='
//	int x2{ 2 };
//	int* p = new int[4]{0};
//	int* p1 = new int[4]{1, 2, 3, 4};
//	return 0;
//}
//int main()
//{
//	auto li = { 10, 20, 30 };
//	initializer_list<int> li2 = { 1, 2, 3, 4 };
//	cout << typeid(li).name() << endl;
//
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> l{ 10, 20, 30 };
//	//vector<Date> vd = { { 2001, 1, 1 }, { 2002, 2, 2 } };
//	map<string, int> dict = { make_pair("sort", 1), { "insert", 2 } };
//	return 0;
//}
//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	decltype(pf) px;
//	cout << typeid(px).name() << endl;
//
//	return 0;
//}
//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	cout << &rr1 << endl;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//
//	// �������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//
//	return 0;
//}

// 1����ֵ����  -�� ��ֵ
// 2����ֵ����  -�� ��ֵ


// 3��const ��ֵ����  -����ֵ �� ��ֵ
// 4����ֵ����  -�� std::move(��ֵ) 


//int main()
//{
//	// ��ֵ����ֻ��������ֵ������������ֵ��
//	int a = 10;
//	int& ra1 = a;   // raΪa�ı���
//	// int& ra2 = 10;   // ����ʧ�ܣ���Ϊ10����ֵ
//
//	const int& ra2 = 10;
//	const int& ra3 = 10 + 20;
//
//	return 0;
//}

namespace test
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ����� ����һ����������ֵ���õİ汾
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			//ת����Դ
			cout << "string(string&& s) -- �ƶ�����" << endl;
			this->swap(s);
		}

		// �ƶ���ֵ 
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
			this->swap(s);

			return *this;
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};

	test::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		test::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);//β��
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;//��������strʶ���һ����ֵ
	}
}
////
//// ��ֵ���õ�ʹ�ó���
//// 1�������� -- ����
//// 2��������ֵ -- ��ȱ��
//void func1(test::string s)
//{}
//
//void func2(const test::string& s)
//{}
//
//int main()
//{
//	test::string s1("hello world");
//	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//	//func1(s1);
//	func2(s1);
//
//	// operator+=����ʹ�ô���ֵ���÷���
//	s1 += 'A';
//
//	// to_string ��������ֵ���÷��أ����������ֵ���ö̰�
//	// ����������ض�����˺���������Ͳ����ˣ��Ͳ���ʹ�������÷��أ��ͻ���ڿ���
//	test::string ret1 = test::to_string(1234);
//	test::to_string(1234);
//
//	return 0;
//}
//
//int main()
//{
//	test::string s1("hello world");
//	test::string s2 = s1;//��ֵ -- ���
//	test::string s3 = test::to_string(1234);//��ֵ -- �ƶ�����
//	test::string s4 = std::move(s1);//�ƶ�����
//	return 0;
//}
//int main()
//{
//	list<std::string> lt;
//
//	std::string s1("1111");
//	// ������õ��ǿ�������
//	lt.push_back(s1);
//
//	// ������ö����ƶ�����
//	lt.push_back("2222");
//	lt.push_back(std::string("2222"));
//	lt.push_back(std::move(s1));
//
//	return 0;
//}


void Fun(int &x){ cout << "��ֵ����" << endl; }
void Fun(const int &x){ cout << "const ��ֵ����" << endl; }

void Fun(int &&x){ cout << "��ֵ����" << endl; }
void Fun(const int &&x){ cout << "const ��ֵ����" << endl; }

// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����ת��
template<typename T>
void PerfectForward(T&& t)
{
	
	Fun(std::forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);		      // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	return 0;
//}

//template<class T>
//struct ListNode
//{
//	ListNode* _next = nullptr;
//	ListNode* _prev = nullptr;
//	T _data;
//};
//
//template<class T>
//class List
//{
//	typedef ListNode<T> Node;
//public:
//	List()
//	{
//		//_head = new Node;
//		_head = (Node*)malloc(sizeof(Node));
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	void PushBack(const T& x)
//	{
//		//Insert(_head, x);
//		Insert(_head, x);
//	}
//
//	void PushBack(T&& x)
//	{
//		//cout << &x << endl;
//		// ����x�����˻�Ϊ��ֵ������������������x��x��ʶ��Ϊ��ֵ
//
//		//Insert(_head, x);
//		// �����Ҫ������ת������x������ֵ��������
//		Insert(_head, std::forward<T>(x));
//	}
//
//	void PushFront(T&& x)
//	{
//		//Insert(_head->_next, x);
//		Insert(_head->_next, std::forward<T>(x));
//	}
//
//	void Insert(Node* pos, T&& x)
//	{
//		Node* prev = pos->_prev;
//		//Node* newnode = new Node;
//		//newnode->_data = std::forward<T>(x); // �ؼ�λ��
//		Node* newnode = (Node*)malloc(sizeof(Node));
//		new(&newnode->_data)T(std::forward<T>(x));
//
//		// prev newnode pos
//		prev->_next = newnode;
//		newnode->_prev = prev;
//		newnode->_next = pos;
//		pos->_prev = newnode;
//	}
//
//	void Insert(Node* pos, const T& x)
//	{
//		Node* prev = pos->_prev;
//		//Node* newnode = new Node;
//		//newnode->_data = x; // �ؼ�λ��
//		Node* newnode = (Node*)malloc(sizeof(Node));
//		new(&newnode->_data)T(x);
//
//		// prev newnode pos
//		prev->_next = newnode;
//		newnode->_prev = prev;
//		newnode->_next = pos;
//		pos->_prev = newnode;
//	}
//private:
//	Node* _head;
//};
//
//int main()
//{
//	List<test::string> lt;
//	test::string s1("1111");
//	lt.PushBack("1111");
//	lt.PushFront("2222");
//	//��ֵ���õĶ�������Ϊʵ�δ���ʱ�����Ի��˻�Ϊ��ֵ��ֻ��ƥ����ֵ����
//}

// //decltype��һЩʹ��ʹ�ó���
//template<class T1, class T2>
//auto F(T1 t1, T2 t2) -> decltype(t1 * t2)//��ͷָ�򷵻�ֵ����
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//	
//	return ret;
//}
//
//int main()
//{
//	F(1, 2.2);
//
//	return 0;
//}

////�ݹ���ֹ����
//void Sh()
//{
//	cout << endl;
//}
////չ������
//template<class T,class ... Args>
//void Sh(T value,Args ... args)
//{
//	//cout << sizeof ...(args) << endl;
//	//if(sizeof ...(args) == 0)
//	//{
//	//  return;
//    //}
//	cout << value << " ";
//	Sh(args...);
//}
//int main()
//{
//	Sh(1);
//	Sh(1, 'A');
//	Sh(1, 'B', std::string("insert"));
//	return 0;
//}
//template <class T>
//void PrintArgs(T t)
//{
//	cout << t << " ";
//}
////չ������
//template<class ... Args>
//void sh(Args ... args)
//{
//	//�б��ʼ��
//	//{ (PrintArgs(arg1),0)... },{ (PrintArgs(arg2),0)... },{ (PrintArgs(arg3),0)... }������
//	int arr[] = { (PrintArgs(args),0)... };
//	cout << endl;
//}
//
//int main()
//{
//	sh(1, 2, 3,4);//ֻ��������
//	return 0;
//}
// int main()
//{
//	// ����������һ�´��п���������ƶ������test::string��
//	// ���ǻᷢ����ʵ���Ҳ������emplace_back��ֱ�ӹ����ˣ�push_back
//	// ���ȹ��죬���ƶ����죬��ʵҲ���á�
//	std::list< std::pair<int, test::string> > mylist;
//	std::pair<int, test::string> kv(20, "sort");
//	mylist.emplace_back(kv);					// ��ֵ
//	mylist.emplace_back(std::pair<int, test::string>(20, "sort")); // ��ֵ
//	mylist.emplace_back(10, "sort");			// ������
//
//	//cout << endl;
//	//mylist.push_back(kv);					// ��ֵ
//	//mylist.push_back(std::pair<int, test::string>(20, "sort")); // ��ֵ
//
//
//	return 0;
//}
//
struct Goods
{
	string _name;
	double _price;
	int _num;

	// ...
};

struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

struct CompareNumLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num < gr._num;
	}
};

struct CompareNumGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num > gr._num;
	}
};

//// �ɵ��ö�������
//// �º���
//// ����ָ��
//// lamber
//
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3,  100}, { "����", 2.2 , 1000}, { "����", 1.5, 1} };
//	// Ҫ��ֱ����֡��۸��������������������
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareNumLess());
//	sort(v.begin(), v.end(), CompareNumGreater());
//
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
//	// Ҫ��ֱ����֡��۸��������������������
//
//	// ����º��������������淶����
//	
//	/*sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareNumLess());
//	sort(v.begin(), v.end(), CompareNumGreater());*/
//
//	/*auto f1 = [](const Goods& g1, const Goods& g2)
//	{
//	return g1._price > g2._price;
//	};
//	sort(v.begin(), v.end(), f1);
//	*/
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._num > g2._num; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._num < g2._num; });
//
//	return 0;
//}
//
//int main()
//{
//	[]{};
//
//	int a = 1, b = 2;
//	// ʵ��add��lambda
//	auto add1 = [](int x, int y)->int{return x + y; };
//	cout << add1(a, b) << endl;
//
//	// �ڲ�׽�б���׽a��b, û�в�������ʡ�Բ����б�����ֵ����ͨ�����ݣ�Ҳ����ʡ��
//	//auto add2 = [a, b]{}->int{return a + b + 10; };
//	auto add2 = [a, b]{return a + b + 10; };
//	cout << add2() << endl;
//
//	return 0;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	// д��1
//	auto swap1 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap1(a, b);
//	////д��2
//	//// �������ò�׽�б���׽��ǰ�ֲ���ı�����
//	//// �����Ͳ��ô��λ��߼��ٴ��Σ�ʡ�Բ����ͷ���ֵ
//	//// ���ﴫֵ��ʽ��׽���൱�ڿ��������a��b��lambda�����a��b
//	//// lambda�����a��b�ĸı䲻��Ӱ������
//	//auto swap2 = [a, b]()mutable
//	//{
//	//	int tmp = a;
//	//	a = b;
//	//	b = tmp;
//	//};
//	////��ֵ��׽�ı����ǲ��ܱ��޸ĵģ����Լ�mutable
//	//swap2();
//
//	//���õķ�ʽ��׽
//	auto swap3 = [&a, &b]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap3();
//
//	auto swap4 = [&]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap4();
//
//
//	return 0;
//}

//// ����ģ��ᱻʵ�������
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	cout << "-------------------" << endl;
//	return f(x);
//}
//
//double func(double i)
//{
//	return i / 2;
//}
//
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//
//int main()
//{
//	// ������
//	std::function<double(double)> f1 = func;
//	cout << useF(f1, 11.11) << endl;
//
//	// ��������
//	std::function<double(double)> f2 = Functor();
//	cout << useF(f2, 2) << endl;
//
//	// lamber���ʽ
//	std::function<double(double)> f3 = [](double d)->double{ return d / 3; };
//	cout << useF(f3, 11.11) << endl;
//	//useF������ʵ����3��
//	//ʹ�ð�װ�����Խ��
//	return 0;
//}

//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor1
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//int main()
//{
//	//��װ����ָ��
//	std::function<int(int, int)> ff = f;
//	cout << ff(1, 2) << endl;
//
//	//��װ�º���
//	std::function<int(int, int)> ff2 = Functor1();
//	cout << ff2(11, 22) << endl;
//
//	//��װ��Ա����
//	std::function<int(int, int)> ff3 = Plus::plusi;//��̬��Ա����
//	cout << ff3(111, 222) << endl;
//
//	std::function<double(Plus,double, double)> ff4 = &Plus::plusd;
//	cout << ff4(Plus(), 6.6, 7.7) << endl;
//
//	//��װlambda
//	auto f5 = [](int a, int b){return a + b; };
//	std::function<int(int, int)> ff5 = f5;
//	cout << ff5(2.2, 3.3) << endl;
//
//
//	return 0;
//}

//int Plus(int a, int b)
//{
//	return a + b;
//}
//
//class Sub
//{
//public:
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//};
//int main()
//{
//	bind(Plus, placeholders::_1, placeholders::_2);//placeholders:�����ռ�
//
//	std::function<int(int)> f2 = bind(Plus, 10, placeholders::_1);//+10
//	cout << f2(5) << endl;
//
//	//�󶨹̶��Ŀɵ��ö���
//	std::function<int(int, int)> f3 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
//	cout << f3(1, 2) << endl;
//	
//	//
//	std::function<int(int, int)> f4 = bind(&Sub::sub, Sub(), placeholders::_2, placeholders::_1);
//	cout << f4(1, 2) << endl;
//
//	
//
//	return 0;
//}

int main()
{
	//�����̣߳������ӡ��100
	thread t1([n]
		{
		for (size_t i = 0; i < n; i+= 2)
		{
			cout << i << endl;
		}
		}
	);
	thread t2([n]
	{
		for (size_t i = 0; i < n; i += 2)
		{
			cout << i << endl;
		}
	}
	);
	t1.join();
	t2.join();
	return 0;
}