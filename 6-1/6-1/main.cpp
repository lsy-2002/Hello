#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
void f2()
{
	int b = 0;
	cout<< "b:" << &b << endl;
}
void f1()
{
	int a = 0;
	cout << "a:"<< &a << endl;
	f2();
}
int main()
{
	f1();
	return 0;
}

int main()
{
	int* p1 = (int*)malloc(4);
	int* p2 = (int*)malloc(4);
	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;
	return 0;
}

int globalvar = 1;
static int staticgobalvar = 1;
void Test()
{
	static int staticvar = 1;
	int localvar = 1;
	int num[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pchar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);

}
//选项	A栈	  B堆	C数据段(静态区)		D代码段(常量区)

// globalvar:C		  staticgobalvar:C
//staticvar:C			localvar:A
//num:A
//char2:A			   *char2:A	       
//pchar3:A             *pchar:D
//ptr1:A               *ptr1:B         
//sizeof(num) =	40		strlen(char2) = 4
//sizeof(char2)=  5      strlen(pchar3)=4
//sizeof(pchar3)= 4      sizeof(ptr1) = 4
//

void Test()
{
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	int* p2 = (int*)calloc(4, sizeof(int));
	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
	//不需要free(p2)
	free(p3);
	//malloc堆上动态开空间
	//calloc堆上动态开空间+初始化成0 = malloc+memset
	//realloc针对已有空间扩容(原地扩容和异地扩容)
	//原地扩容-》后面有足够的空间
	//异地扩容-》 后面没有足够的空间
}

int main()
{
	//new/delete和malloc/free针对内置类型没有差别
	//new/delete和new[]/delete[]一定要匹配
	//申请一个10个int的数组
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = new int[10];
	free(p1);
	delete[]p2;
	//申请单个对象
	int* p3 = (int*)malloc(sizeof(int));
	int*p4 = new int;
	free(p3);
	delete p4;
	//动态申请一个int类型的空间并初始化为10
	int* p5 = new int(10);
	delete p5;
	return 0;
}

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _val;
	ListNode(int val = 0)
		:_next(nullptr)
		, _prev(nullptr)
		, _val(val){}
};
int main()
{
	// C malloc只是开空间 free释放空间
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(ListNode));
	free(p1);
	//C++ new 针对自定义类型：开空间+构造函数初始化
	//    delete针对自定义类型：析构函数清理+释放空间
	ListNode* p2 = new ListNode;
	delete p2;
	ListNode* p3 = new ListNode(5);//相当于创建新结点
	delete p3;
	ListNode* arr4 = new ListNode[4]{1, 2, 3, 4};
	delete[]arr4;
	//delete arr4 不匹配
	return 0;
}

//new -> 调用operator new + 构造函数-》调用malloc+失败抛异常机制
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _val;
	ListNode(int val = 0)
		:_next(nullptr)
		, _prev(nullptr)
		, _val(val){}
};
int main()
{
	//用法跟malloc/new一样，功能都是在堆上申请释放空间
	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
	free(p1);
	//失败的处理方式不一样，malloc失败返回NULL，operator new失败后抛出异常
	ListNode* p2 = (ListNode*)operator new(sizeof(ListNode));
	operator delete (p2);
	void* p3 = malloc(0x7fffffff);
	if (p3 == NULL)
		cout << "malloc fail" << endl;
	//捕获异常
	try
	{
		void* p4 = operator new(0x7fffffff);
	}
	catch (exception&e)
	{
		cout << e.what() << endl;
	}
	

	return 0;
}

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _val;
	//不调用全局-》类中重载专属operator new/delete
	//池化技术（提高效率）
	//内存池，进程池，线程池，连接池...
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		//allocate STL中空间配置器，一个简单的内存池
		cout << "memory pool allocate" << endl;
		return p;
	}
	void* operator delete (size_t n)
	{

		allocator<ListNode>().dallocate((ListNode*)p,1);
		cout << "memory pool dallocate" << endl;
	}
	ListNode(int val = 0)
		:_next(nullptr)
		, _prev(nullptr)
		, _val(val){}
};
int main()
{
	//调用的是全局的operator new和operator delete
	ListNode* p = new ListNode(1);
	delete p;
	return 0;
}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A():" << this<< endl;
	}
	~A()
	{
		cout << "~A():" <<this << endl;
	}
private:
	int _a;
};
int main()
{
	//A* p = (A*)malloc(sizeof(A));
	//等价于 A* p = new A
	A* P = (A*)operator new(sizeof(A));
	new(p)A;//new(p)A(3)
	//定位new,placement-new,显示调用构造函数初始化这块对象空间

	//等于 delete p
	P->~A();//析构函数可以调用
	operator delete (p);
	return 0;
}

//在堆上申请4G的内存
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}*/