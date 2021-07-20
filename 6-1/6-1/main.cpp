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
//ѡ��	Aջ	  B��	C���ݶ�(��̬��)		D�����(������)

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
	//����Ҫfree(p2)
	free(p3);
	//malloc���϶�̬���ռ�
	//calloc���϶�̬���ռ�+��ʼ����0 = malloc+memset
	//realloc������пռ�����(ԭ�����ݺ��������)
	//ԭ������-���������㹻�Ŀռ�
	//�������-�� ����û���㹻�Ŀռ�
}

int main()
{
	//new/delete��malloc/free�����������û�в��
	//new/delete��new[]/delete[]һ��Ҫƥ��
	//����һ��10��int������
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = new int[10];
	free(p1);
	delete[]p2;
	//���뵥������
	int* p3 = (int*)malloc(sizeof(int));
	int*p4 = new int;
	free(p3);
	delete p4;
	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
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
	// C mallocֻ�ǿ��ռ� free�ͷſռ�
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(ListNode));
	free(p1);
	//C++ new ����Զ������ͣ����ռ�+���캯����ʼ��
	//    delete����Զ������ͣ�������������+�ͷſռ�
	ListNode* p2 = new ListNode;
	delete p2;
	ListNode* p3 = new ListNode(5);//�൱�ڴ����½��
	delete p3;
	ListNode* arr4 = new ListNode[4]{1, 2, 3, 4};
	delete[]arr4;
	//delete arr4 ��ƥ��
	return 0;
}

//new -> ����operator new + ���캯��-������malloc+ʧ�����쳣����
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
	//�÷���malloc/newһ�������ܶ����ڶ��������ͷſռ�
	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
	free(p1);
	//ʧ�ܵĴ���ʽ��һ����mallocʧ�ܷ���NULL��operator newʧ�ܺ��׳��쳣
	ListNode* p2 = (ListNode*)operator new(sizeof(ListNode));
	operator delete (p2);
	void* p3 = malloc(0x7fffffff);
	if (p3 == NULL)
		cout << "malloc fail" << endl;
	//�����쳣
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
	//������ȫ��-����������ר��operator new/delete
	//�ػ����������Ч�ʣ�
	//�ڴ�أ����̳أ��̳߳أ����ӳ�...
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		//allocate STL�пռ���������һ���򵥵��ڴ��
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
	//���õ���ȫ�ֵ�operator new��operator delete
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
	//�ȼ��� A* p = new A
	A* P = (A*)operator new(sizeof(A));
	new(p)A;//new(p)A(3)
	//��λnew,placement-new,��ʾ���ù��캯����ʼ��������ռ�

	//���� delete p
	P->~A();//�����������Ե���
	operator delete (p);
	return 0;
}

//�ڶ�������4G���ڴ�
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}*/