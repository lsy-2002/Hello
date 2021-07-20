#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/*
int main()
{
	int a = 10;
	//&取地址操作符
	printf("%p\n", &a);//010FF80C
	printf("%d\n", a);//10
	//%p按地址的格式打印
	int*  pa = &a;//pa是专门用来存放地址的-把pa叫做指针变量
	//*说明pa是指针变量
	//int说明pa指向的是整型变量
	*pa = 20;//解引用操作
	printf("%d\n",a);//20
	return 0;
}
int main()
{
	printf("%d\n",sizeof(char*));//4
	printf("%d\n", sizeof(short*));//4
	printf("%d\n", sizeof(int*));//4
	printf("%d\n", sizeof(long*));//4
	printf("%d\n", sizeof(float*));//4
	printf("%d\n", sizeof(double*));//4
	return 0;
}
char *pc //指针存放char类型变量的地址
short* ps//指针存放short类型变量的地址
int* pi//指针存放int类型变量的地址
long* pl//指针存放long类型变量的地址
float* pf//指针存放float类型变量的地址
double* pd//指针存放double类型变量的地址

int main()
{
	int a = 10;
	int* p = &a;//指针变量
	p = 100;//p是指针变量所以此刻100是地址
	return 0;
}
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	*pa = 0;
	printf("%p\n", a);
	//0x00000000
	a = 0x11223344;
	char* pb = &a;
	*pb = 0;
	printf("%p\n", a);
	//0x11223300
	return 0;
	//指针类型的第一个作用：决定指针的访问权限，也就是能访问几个字节
	//int*  -- 4
	//char*  -- 1
	//short* --2
	//double* -- 8
}

int main()
{
	int arr[10] = { 0 };
	int* pa = arr;//数组名--首元素地址
	char* pc = arr;
	//printf("%p\n", arr);
	printf("%p\n", pa);
	printf("%p\n", pa+1);
	printf("---------------\n");
	printf("%p\n", pc);
	printf("%p\n", pc+1);
	//指针类型决定了指针+/-整数，走多大的距离
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	int* pr = &arr;
	for (int i = 0; i < 10; i++)
	{
		*(pr + i) = i;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", *(pr + i));
	}
	return 0;
}

//野指针
int* test()//返回空间释放
{
	int a = 10;
	return &a;
}
int main()
{
	int*p = test();
	//p得到地址之后，地址指向的空间已经释放了，所以这个时候p是野指针
	printf("%d\n", *p);
	//打印的是随机值
	return 0;
}
int main()
{
	int* p;
	//局部变量指针未初始化，默认为随机值
	*p = 20;
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	int* p = &arr;
	for (int i = 0; i < 11; i++)
	{
		*(p + i) = i;
		//当指针指向的范围超出数组的范围时，p就是野指针
	}
	return 0;
}
int main()
{
	int* p = NULL;//NULL指向的空指针是不能访问的
	*p = 20;
	return 0;
int main()
{
	int arr[5] = { 0 };
	int* p = &arr;
	for (int i = 0; i < 5; i++)
	{
		*(p + i) = i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d", *(p + i));
	}
	return 0;
}
}
int main()
{
	int arr[5] = { 0 };
	int* p = &arr;
	for (int i = 0; i < 5; i++)
	{
		*p++ = i;
	}
	p = arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d", *(p + i));
	}
	return 0;
}

//指针+-整数
#define numbers 5
float* vp;
for (vp = &values[0]; vp < &values[numbers];)
	*vp++ = 0;

int main()
{
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);//9
	//指针+-指针的绝对值 得到的是指针和指针之间的元素个数
	return 0;
}
//对比
for (vp = &values[numbers]; vp > &values[0];)//推荐使用
	*--vp= 0;
for (vp = &values[numbers-1]; vp > &values[0];vp--)
	*vp = 0;
//标准规定：
//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较
//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* p = &arr;
	for (int i = 0; i < 5; i++)
		printf("&arr[%d] = %p<==>%p\n", i, &arr[i], p + i);
	return 0;
}
int main()
{
	int arr[3][5];
	int*p = &arr;
	//二维数组的数组名是首元素的地址，也是数组首元素的地址（第一行的地址）
	return 0;
}

int main()
{
	int a = 10;
	int* p = &a;//p是一级指针
	int** pp = &p;//pp是二级指针
	**pp = 20;
	printf("%d\n", a);//20
	//int*** ppp = &pp;//三级指针
	return 0;
}
//字符指针
int main()
{
	char ch = 'a';
	char* pc = &ch;
	char* p = "abcdef";
	//字符串中把首字符的地址存入p中
	printf("%c\n", *p);//a
	printf("%s\n", p);//abcdef
	return 0;
}
int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";
	char *str3 = "hello world";//常量字符串不能修改
	char *str4 = "hello world";
	//const char* p  = "hello world"//正确写法
	if (str1 == str2)
		printf("Same\n");
	else
		printf("Not Same\n");
	if (str3 == str4)
		printf("Same\n");
	else
		printf("Not Same\n");
	return 0;
}
int* arr[10]//整形指针的数组
char* arr[10]//一级字符指针的数组
char** arr[10]//二级字符指针的数组

int main()
{
	int arr[10] = { 0 };
	int (*pa)[10] = &arr;//数组的地址
	//(*pa)说明是指针，pa就是一个指向数组的指针
	//&arr数组名是整个数组，取出的是数组的地址
	int* pa[10];//指针数组，数组内的元素类型是int*
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	int* p1 = arr;//数组首元素地址
	int(*p2)[10] = &arr;//数组的地址
	printf("%p\n", p1);
	printf("%p\n", p1+1);
	printf("------------------\n");
	printf("%p\n", p2);
	printf("%p\n", p2+1);
	return 0;
	//&数组名
	//sizzeof(数组名)
	//除此之外，所有遇到的数组名都是首元素地址
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int(*p)[5] = &arr;
	//*p <==> arr
	for (int i = 0; i < 5; i++)
		printf("%d ", (*p)[i]);
	//等价于:printf("%d ",*((*p)+i));
	//等价于printf("%d ", *((*p+0) + i)
	//等价于printf("%d ",p[0][i])

	return 0;
}

void Print1(int(*p)[5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%d ", (*(p + i) + j));
		printf("%\n");
	}
	
}
void Print2(int* p, int c)
{}
int main()
{
	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, {3, 4, 5, 6, 7} };
	//二维数组传参，数组名是首元素的地址，二维数组的首元素是第一行
	//传过去就是第一行的地址
	Print1(arr, 3, 5);
	Print2(arr, 5);
	return 0;
}

int arr[5]//五个元素的整形数组
int* p[10]//整形指针数组，10个元素
int(*p1)[10]//数组指针，指向的数组有10个元素，元素类型是int
int(*p2[10])[5]
//p2是存放数组指针的数组

void test(int arr[]){}//ok
void test(int arr[10]){}//ok
void test(int* arr){}//ok
int main()
{
	int arr[10] = { 0 };
	test(arr);
}
void test2(int* arr[20]){}//ok
void test2(int** arr){}//ok
int main()
{
	int* arr[20] = { 0 };
	test2(arr);
}
void test(int a[3][5]){}//ok
void test(int a[][]){}//NO!
void test(int a[][5]){}//ok
void test(int* a){}//No!
void test(int* a[5]){}//No!
void test(int (*a)[5]){}//ok
void test(int** a){}//No！
int main()
{
	int a[3][5] = { 0 };
	test3(a);
}
void test(int** pr)
{
	printf("%d\n", **pr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pr = &p;
	test(pr);
	test(&p);
	return 0;
}
void test(int** pr)
{
	printf("%d\n", **pr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pr = &p;
	int* arr[10];
	test(pr);
	test(&p);
	test(arr);
	return 0;
}

void test1(int *p){}
void test2(int(*p)[4]){}
int main()
{
	int arr[10];
	int* p = arr;
	int(*pa)[10] = &arr;//首元素地址
	int data[3][4];
	int(*pd)[4] = data;//首元素地址
	int(*p)[3][4] = &data;
	test2(data);
	return 0;
}

int Add(int x, int y)
{
	return x + y;
}
void test(char* str){}
int main()
{
	int(*p)(int,int) = &Add;//p是函数指针
	//（*p）指针，指向参数为（int,int）,返回类型是int的函数
	void(*pf)(char*) = &test;
	//(*pf)是指针，指向参数为（char*），返回类型是void的函数
	int ret = (*p)(2, 3);//int ret = Add(2,3)
	return 0;
}

( * ( void (*)() ) 0 )();
//void(*)()-》函数指针类型
//调用0地址处的函数，该函数无参数，返回类型是void

void(*signal(int, void(*)(int)))(int);
//这是一个函数声明
//声明的函数叫signal,signal有两个参数，
//第一个参数类型是int,
//第二个参数类型是函数指针，该函数指针指向的函数的参数是int,返回类型是void
//signal函数的返回类型是一个函数指针，该函数指针指向的函数参数是Int,返回值是void
//简化
typedef void(*pfun_t)(int);//第一步
pfun_t signal(int, pfun_t);//第二步

int Add(int x, int y){}
int Sub(int x, int y){};
int main()
{
	int (*pfArr[2])(int,int) = { Add, Sub };
	//函数指针数组
	return 0;
}

int main()
{
	int(*p)(int, int);//函数指针
	int(*pf[4])(int, int);//函数指针数组
	int(*(*ppf)[4])(int, int) = &pf;
	//指向函数指针数组的指针
	return 0; 
}
void test1()//回调函数-》通过函数指针调用的函数
{
	printf("haha\n");
}
void test2(void(*p)())
{
	p();
}
int main()
{
	test2(test1);
	return 0;
}

//一维数组
//1、数组名单独放在sizeof内部，数组名表示整个数组，计算的是整个数组的大小
//2、&数组名，数组名表述整个数组，取出的是整个数组的地址
//除上面两种情况外，所有数组名都是数组首元素的地址
int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16 - 数组名单独放在sizeof内部，计算的是数组总大小
	printf("%d\n", sizeof(a + 0));//4/8 - 首元素地址+0，还是首元素地址
	printf("%d\n", sizeof(*a));//4/8  *a - 数组a的首元素
	printf("%d\n", sizeof(a + 1));//4/8  -第二个元素的地址
	printf("%d\n", sizeof(a[1]));//4/8 - 数组的第二个元素
	printf("%d\n", sizeof(&a));//4/8 - 数组的地址，是地址就是4/8个字节
	printf("%d\n", sizeof(*&a));//16 &a->int(*p)[4] == sizeof(a)
	printf("%d\n", sizeof(&a + 1));//4/8 //&a+1是地址，指向数组之后的空间
	printf("%d\n", sizeof(&a[0]));//4/8 首元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4/8 数组第二个元素的地址
	return 0;
}

//字符数组
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));//6 整个数组的大小
	printf("%d\n", sizeof(arr + 0));//4/8 首元素的地址
	printf("%d\n", sizeof(*arr));//1 *arr->数组首元素
	printf("%d\n", sizeof(arr[1]));//1 arr[1]->数组第二个元素
	printf("%d\n", sizeof(&arr));//4/8 数组的地址
	printf("%d\n", sizeof(&arr + 1));//4/8 &arr+1跳过整个数组，还是地址
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0]+1是第二个元素的地址
	
	printf("%d\n", strlen(arr));//随机值 - 因为arr数组中没有\0，就会在数组后继续找\0
	printf("%d\n", strlen(arr + 0));//随机值
	//printf("%d\n", strlen(*arr));//error - *arr是'a',访问以a的ASCII值为地址的
	//printf("%d\n", strlen(arr[1]));//error ,同理
	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
	return 0;
}

int main()
{
	char arr[] = "abcdef";//abcdef\0 - 7
	printf("%d\n", sizeof(arr));//7 计算数组的总大小
	printf("%d\n", sizeof(arr + 0));//4/8 首元素地址
	printf("%d\n", sizeof(*arr));//1 首元素
	printf("%d\n", sizeof(arr[1]));//1 第二个元素
	printf("%d\n", sizeof(&arr));// 4/8 &arr数组的地址
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0]+1是第二个元素的地址

	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//error
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值
	printf("%d\n", strlen(&arr[0] + 1));//5
	return 0;
}

int main()
{
	char *p = "abcdef";
	printf("%d\n", sizeof(p));//4/8 p是指针变量
	printf("%d\n", sizeof(p + 1));//4/8 p+1是字符b的地址
	printf("%d\n", sizeof(*p));//1 p是字符指针，*p访问1个字节
	printf("%d\n", sizeof(p[0]));//1 p[0]==*(p+0)==*p
	printf("%d\n", sizeof(&p));//4/8 &p是p的地址
	printf("%d\n", sizeof(&p + 1));//4/8 &p+1指向p后边的空间
	printf("%d\n", sizeof(&p[0] + 1));//4/8 &p[0]+1就是地址

	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//随机值
	printf("%d\n", strlen(&p + 1));//随机值
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}

//二维数组
int main()
{
	int a[3][4] = { 0 };
	//对于二维数组
	printf("%d\n", sizeof(a));//48 数组名单独放在sizeof内部，计算的是整个数组的大小
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16 a[0]是第一行的数组名，
	//第一行数组名放在sizeof内部，计算的是第一行数组的总大小
	printf("%d\n", sizeof(a[0] + 1));//4/8 arr[0]作为第一行的数组名，没有放在sizeof内部
	//所以数组名相当于首元素的地址，就是第一行第一个元素的地址
	//a[0]+1 ->第一行第二个元素的地址
	printf("%d\n", sizeof(*(a[0] + 1)));//4 解引用-》第一行第二个元素的大小
	printf("%d\n", sizeof(a + 1));//4/8 a作为二维数组的数组名，没有&，也没有放在sizeof内部
	//那么数组名a就是首元素（第一行）的地址
	//a+1->第二行地址
	printf("%d\n", sizeof(*(a+1)));//16 第二行的大小 *(a+1)==a[1]
	printf("%d\n", sizeof(&a[0] + 1));//4/8 &arr[0]是第一行的地址，&a[0]+1是第二行的地址
	printf("%d\n", sizeof(*(&a[0] + 1)));//16 计算的是第二行的大小
	printf("%d\n", sizeof(*a));//16 *a==*(a+0)==a[0]
	//a数二维数组的数组名，没有&，也没有单独放在sizeof内部
	//所以a是二维数组首元素的地址，也就是第一行的地址
	//*a就是第一行
	printf("%d\n", sizeof(a[3]));//16 a[3]越界，但是明确类型就可以计算大小

	return 0;
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	//&a -》int(*)[5] 数组指针
	//&a + 1 -》跳过整个数组
	printf("%d,%d\n", *(a + 1), *(ptr - 1));//2   5
	return 0;
}

struct Test//这里结构体的大小是20字节
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);//p是结构体指针，0x100000+20=0x100014
	printf("%p\n",(unsigned long) p + 0x1);//(unsigned+1)转化成整形 0x100000+1=0x100001
	printf("%p\n",(unsigned int*) p + 0x1);//转化成指针 0x100000+4=0x100004
	return 0;
}

int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x\n", ptr1[-1], *ptr2);
	return 0;
}

int main()
{
	int a[2][3] = { (0, 1), (2, 3), (4, 5) };
	//{1,3,5}
	//1 3
	//5 0
	//0 0
	int* p;
	p = a[0];
	printf("%d\n", p[0]);//*（p+0）
	return 0;
}

int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}

int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}

int main()
{
	char *a[] = { "work", "at", "alibaba" };
	char **pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}
*/
int main()
{
	char *c[] = { "ENTTER", "NEW", "POINT", "FIRST" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***ccp = cp;
	printf("%s\n", **++ccp);//POINT
	printf("%s\n", *--*++ccp + 3);//ER
	printf("%s\n", *ccp[-2] + 3);//ST
	printf("%s\n", ccp[-1][-1] - 1);//EW
	return 0;
}