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
//	Point p{ 1, 2 };//可以不使用 '='
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
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	cout << &rr1 << endl;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//
//	return 0;
//}

// 1、左值引用  -》 左值
// 2、右值引用  -》 右值


// 3、const 左值引用  -》左值 或 右值
// 4、右值引用  -》 std::move(左值) 


//int main()
//{
//	// 左值引用只能引用左值，不能引用右值。
//	int a = 10;
//	int& ra1 = a;   // ra为a的别名
//	// int& ra2 = 10;   // 编译失败，因为10是右值
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

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// 移动构造 增加一个参数是右值引用的版本
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			//转移资源
			cout << "string(string&& s) -- 移动构造" << endl;
			this->swap(s);
		}

		// 移动赋值 
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			this->swap(s);

			return *this;
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
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

			str += ('0' + x);//尾插
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;//编译器把str识别成一个右值
	}
}
////
//// 左值引用的使用场景
//// 1、做参数 -- 可以
//// 2、做返回值 -- 有缺陷
//void func1(test::string s)
//{}
//
//void func2(const test::string& s)
//{}
//
//int main()
//{
//	test::string s1("hello world");
//	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//	//func1(s1);
//	func2(s1);
//
//	// operator+=可以使用传左值引用返回
//	s1 += 'A';
//
//	// to_string 不能用左值引用返回，这个就是左值引用短板
//	// 如果函数返回对象除了函数作用域就不在了，就不能使用做引用返回，就会存在拷贝
//	test::string ret1 = test::to_string(1234);
//	test::to_string(1234);
//
//	return 0;
//}
//
//int main()
//{
//	test::string s1("hello world");
//	test::string s2 = s1;//左值 -- 深拷贝
//	test::string s3 = test::to_string(1234);//右值 -- 移动拷贝
//	test::string s4 = std::move(s1);//移动构造
//	return 0;
//}
//int main()
//{
//	list<std::string> lt;
//
//	std::string s1("1111");
//	// 这里调用的是拷贝构造
//	lt.push_back(s1);
//
//	// 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(std::string("2222"));
//	lt.push_back(std::move(s1));
//
//	return 0;
//}


void Fun(int &x){ cout << "左值引用" << endl; }
void Fun(const int &x){ cout << "const 左值引用" << endl; }

void Fun(int &&x){ cout << "右值引用" << endl; }
void Fun(const int &&x){ cout << "const 右值引用" << endl; }

// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要完美转发
template<typename T>
void PerfectForward(T&& t)
{
	
	Fun(std::forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
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
//		// 这里x属性退化为左值，其他对象再来引用x，x会识别为左值
//
//		//Insert(_head, x);
//		// 这里就要用完美转发，让x保持右值引用属性
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
//		//newnode->_data = std::forward<T>(x); // 关键位置
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
//		//newnode->_data = x; // 关键位置
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
//	//右值引用的对象再作为实参传递时，属性会退化为左值，只能匹配左值引用
//}

// //decltype的一些使用使用场景
//template<class T1, class T2>
//auto F(T1 t1, T2 t2) -> decltype(t1 * t2)//箭头指向返回值类型
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

////递归终止函数
//void Sh()
//{
//	cout << endl;
//}
////展开函数
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
////展开函数
//template<class ... Args>
//void sh(Args ... args)
//{
//	//列表初始化
//	//{ (PrintArgs(arg1),0)... },{ (PrintArgs(arg2),0)... },{ (PrintArgs(arg3),0)... }。。。
//	int arr[] = { (PrintArgs(args),0)... };
//	cout << endl;
//}
//
//int main()
//{
//	sh(1, 2, 3,4);//只能是整数
//	return 0;
//}
// int main()
//{
//	// 下面我们试一下带有拷贝构造和移动构造的test::string，
//	// 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
//	// 是先构造，再移动构造，其实也还好。
//	std::list< std::pair<int, test::string> > mylist;
//	std::pair<int, test::string> kv(20, "sort");
//	mylist.emplace_back(kv);					// 左值
//	mylist.emplace_back(std::pair<int, test::string>(20, "sort")); // 右值
//	mylist.emplace_back(10, "sort");			// 参数包
//
//	//cout << endl;
//	//mylist.push_back(kv);					// 左值
//	//mylist.push_back(std::pair<int, test::string>(20, "sort")); // 右值
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

//// 可调用对象类型
//// 仿函数
//// 函数指针
//// lamber
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3,  100}, { "橙子", 2.2 , 1000}, { "菠萝", 1.5, 1} };
//	// 要求分别按名字、价格、数量进行排序，升序或降序
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
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	// 要求分别按名字、价格、数量进行排序，升序或降序
//
//	// 如果仿函数存在命名不规范问题
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
//	// 实现add的lambda
//	auto add1 = [](int x, int y)->int{return x + y; };
//	cout << add1(a, b) << endl;
//
//	// 在捕捉列表，捕捉a、b, 没有参数可以省略参数列表，返回值可以通过推演，也可以省略
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
//	// 写法1
//	auto swap1 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap1(a, b);
//	////写法2
//	//// 尝试利用捕捉列表，捕捉当前局部域的变量，
//	//// 这样就不用传参或者减少传参，省略参数和返回值
//	//// 这里传值方式捕捉，相当于拷贝外面的a和b给lambda里面的a、b
//	//// lambda里面的a、b的改变不会影响外面
//	//auto swap2 = [a, b]()mutable
//	//{
//	//	int tmp = a;
//	//	a = b;
//	//	b = tmp;
//	//};
//	////传值捕捉的变量是不能被修改的，所以加mutable
//	//swap2();
//
//	//引用的方式捕捉
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

//// 函数模板会被实例化多次
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
//	// 函数名
//	std::function<double(double)> f1 = func;
//	cout << useF(f1, 11.11) << endl;
//
//	// 函数对象
//	std::function<double(double)> f2 = Functor();
//	cout << useF(f2, 2) << endl;
//
//	// lamber表达式
//	std::function<double(double)> f3 = [](double d)->double{ return d / 3; };
//	cout << useF(f3, 11.11) << endl;
//	//useF函数被实例了3次
//	//使用包装器可以解决
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
//	//包装函数指针
//	std::function<int(int, int)> ff = f;
//	cout << ff(1, 2) << endl;
//
//	//包装仿函数
//	std::function<int(int, int)> ff2 = Functor1();
//	cout << ff2(11, 22) << endl;
//
//	//包装成员函数
//	std::function<int(int, int)> ff3 = Plus::plusi;//静态成员函数
//	cout << ff3(111, 222) << endl;
//
//	std::function<double(Plus,double, double)> ff4 = &Plus::plusd;
//	cout << ff4(Plus(), 6.6, 7.7) << endl;
//
//	//包装lambda
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
//	bind(Plus, placeholders::_1, placeholders::_2);//placeholders:命名空间
//
//	std::function<int(int)> f2 = bind(Plus, 10, placeholders::_1);//+10
//	cout << f2(5) << endl;
//
//	//绑定固定的可调用对象
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
	//两个线程，交替打印到100
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