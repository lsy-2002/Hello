#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/*
int main()
{
	int a = 10;
	//&ȡ��ַ������
	printf("%p\n", &a);//010FF80C
	printf("%d\n", a);//10
	//%p����ַ�ĸ�ʽ��ӡ
	int*  pa = &a;//pa��ר��������ŵ�ַ��-��pa����ָ�����
	//*˵��pa��ָ�����
	//int˵��paָ��������ͱ���
	*pa = 20;//�����ò���
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
char *pc //ָ����char���ͱ����ĵ�ַ
short* ps//ָ����short���ͱ����ĵ�ַ
int* pi//ָ����int���ͱ����ĵ�ַ
long* pl//ָ����long���ͱ����ĵ�ַ
float* pf//ָ����float���ͱ����ĵ�ַ
double* pd//ָ����double���ͱ����ĵ�ַ

int main()
{
	int a = 10;
	int* p = &a;//ָ�����
	p = 100;//p��ָ��������Դ˿�100�ǵ�ַ
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
	//ָ�����͵ĵ�һ�����ã�����ָ��ķ���Ȩ�ޣ�Ҳ�����ܷ��ʼ����ֽ�
	//int*  -- 4
	//char*  -- 1
	//short* --2
	//double* -- 8
}

int main()
{
	int arr[10] = { 0 };
	int* pa = arr;//������--��Ԫ�ص�ַ
	char* pc = arr;
	//printf("%p\n", arr);
	printf("%p\n", pa);
	printf("%p\n", pa+1);
	printf("---------------\n");
	printf("%p\n", pc);
	printf("%p\n", pc+1);
	//ָ�����;�����ָ��+/-�������߶��ľ���
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

//Ұָ��
int* test()//���ؿռ��ͷ�
{
	int a = 10;
	return &a;
}
int main()
{
	int*p = test();
	//p�õ���ַ֮�󣬵�ַָ��Ŀռ��Ѿ��ͷ��ˣ��������ʱ��p��Ұָ��
	printf("%d\n", *p);
	//��ӡ�������ֵ
	return 0;
}
int main()
{
	int* p;
	//�ֲ�����ָ��δ��ʼ����Ĭ��Ϊ���ֵ
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
		//��ָ��ָ��ķ�Χ��������ķ�Χʱ��p����Ұָ��
	}
	return 0;
}
int main()
{
	int* p = NULL;//NULLָ��Ŀ�ָ���ǲ��ܷ��ʵ�
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

//ָ��+-����
#define numbers 5
float* vp;
for (vp = &values[0]; vp < &values[numbers];)
	*vp++ = 0;

int main()
{
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);//9
	//ָ��+-ָ��ľ���ֵ �õ�����ָ���ָ��֮���Ԫ�ظ���
	return 0;
}
//�Ա�
for (vp = &values[numbers]; vp > &values[0];)//�Ƽ�ʹ��
	*--vp= 0;
for (vp = &values[numbers-1]; vp > &values[0];vp--)
	*vp = 0;
//��׼�涨��
//����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚ�
//���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�

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
	//��ά���������������Ԫ�صĵ�ַ��Ҳ��������Ԫ�صĵ�ַ����һ�еĵ�ַ��
	return 0;
}

int main()
{
	int a = 10;
	int* p = &a;//p��һ��ָ��
	int** pp = &p;//pp�Ƕ���ָ��
	**pp = 20;
	printf("%d\n", a);//20
	//int*** ppp = &pp;//����ָ��
	return 0;
}
//�ַ�ָ��
int main()
{
	char ch = 'a';
	char* pc = &ch;
	char* p = "abcdef";
	//�ַ����а����ַ��ĵ�ַ����p��
	printf("%c\n", *p);//a
	printf("%s\n", p);//abcdef
	return 0;
}
int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";
	char *str3 = "hello world";//�����ַ��������޸�
	char *str4 = "hello world";
	//const char* p  = "hello world"//��ȷд��
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
int* arr[10]//����ָ�������
char* arr[10]//һ���ַ�ָ�������
char** arr[10]//�����ַ�ָ�������

int main()
{
	int arr[10] = { 0 };
	int (*pa)[10] = &arr;//����ĵ�ַ
	//(*pa)˵����ָ�룬pa����һ��ָ�������ָ��
	//&arr���������������飬ȡ����������ĵ�ַ
	int* pa[10];//ָ�����飬�����ڵ�Ԫ��������int*
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	int* p1 = arr;//������Ԫ�ص�ַ
	int(*p2)[10] = &arr;//����ĵ�ַ
	printf("%p\n", p1);
	printf("%p\n", p1+1);
	printf("------------------\n");
	printf("%p\n", p2);
	printf("%p\n", p2+1);
	return 0;
	//&������
	//sizzeof(������)
	//����֮�⣬����������������������Ԫ�ص�ַ
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int(*p)[5] = &arr;
	//*p <==> arr
	for (int i = 0; i < 5; i++)
		printf("%d ", (*p)[i]);
	//�ȼ���:printf("%d ",*((*p)+i));
	//�ȼ���printf("%d ", *((*p+0) + i)
	//�ȼ���printf("%d ",p[0][i])

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
	//��ά���鴫�Σ�����������Ԫ�صĵ�ַ����ά�������Ԫ���ǵ�һ��
	//����ȥ���ǵ�һ�еĵ�ַ
	Print1(arr, 3, 5);
	Print2(arr, 5);
	return 0;
}

int arr[5]//���Ԫ�ص���������
int* p[10]//����ָ�����飬10��Ԫ��
int(*p1)[10]//����ָ�룬ָ���������10��Ԫ�أ�Ԫ��������int
int(*p2[10])[5]
//p2�Ǵ������ָ�������

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
void test(int** a){}//No��
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
	int(*pa)[10] = &arr;//��Ԫ�ص�ַ
	int data[3][4];
	int(*pd)[4] = data;//��Ԫ�ص�ַ
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
	int(*p)(int,int) = &Add;//p�Ǻ���ָ��
	//��*p��ָ�룬ָ�����Ϊ��int,int��,����������int�ĺ���
	void(*pf)(char*) = &test;
	//(*pf)��ָ�룬ָ�����Ϊ��char*��������������void�ĺ���
	int ret = (*p)(2, 3);//int ret = Add(2,3)
	return 0;
}

( * ( void (*)() ) 0 )();
//void(*)()-������ָ������
//����0��ַ���ĺ������ú����޲���������������void

void(*signal(int, void(*)(int)))(int);
//����һ����������
//�����ĺ�����signal,signal������������
//��һ������������int,
//�ڶ������������Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int,����������void
//signal�����ķ���������һ������ָ�룬�ú���ָ��ָ��ĺ���������Int,����ֵ��void
//��
typedef void(*pfun_t)(int);//��һ��
pfun_t signal(int, pfun_t);//�ڶ���

int Add(int x, int y){}
int Sub(int x, int y){};
int main()
{
	int (*pfArr[2])(int,int) = { Add, Sub };
	//����ָ������
	return 0;
}

int main()
{
	int(*p)(int, int);//����ָ��
	int(*pf[4])(int, int);//����ָ������
	int(*(*ppf)[4])(int, int) = &pf;
	//ָ����ָ�������ָ��
	return 0; 
}
void test1()//�ص�����-��ͨ������ָ����õĺ���
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

//һά����
//1����������������sizeof�ڲ�����������ʾ�������飬���������������Ĵ�С
//2��&�������������������������飬ȡ��������������ĵ�ַ
//��������������⣬��������������������Ԫ�صĵ�ַ
int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16 - ��������������sizeof�ڲ���������������ܴ�С
	printf("%d\n", sizeof(a + 0));//4/8 - ��Ԫ�ص�ַ+0��������Ԫ�ص�ַ
	printf("%d\n", sizeof(*a));//4/8  *a - ����a����Ԫ��
	printf("%d\n", sizeof(a + 1));//4/8  -�ڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(a[1]));//4/8 - ����ĵڶ���Ԫ��
	printf("%d\n", sizeof(&a));//4/8 - ����ĵ�ַ���ǵ�ַ����4/8���ֽ�
	printf("%d\n", sizeof(*&a));//16 &a->int(*p)[4] == sizeof(a)
	printf("%d\n", sizeof(&a + 1));//4/8 //&a+1�ǵ�ַ��ָ������֮��Ŀռ�
	printf("%d\n", sizeof(&a[0]));//4/8 ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));//4/8 ����ڶ���Ԫ�صĵ�ַ
	return 0;
}

//�ַ�����
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));//6 ��������Ĵ�С
	printf("%d\n", sizeof(arr + 0));//4/8 ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));//1 *arr->������Ԫ��
	printf("%d\n", sizeof(arr[1]));//1 arr[1]->����ڶ���Ԫ��
	printf("%d\n", sizeof(&arr));//4/8 ����ĵ�ַ
	printf("%d\n", sizeof(&arr + 1));//4/8 &arr+1�����������飬���ǵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0]+1�ǵڶ���Ԫ�صĵ�ַ
	
	printf("%d\n", strlen(arr));//���ֵ - ��Ϊarr������û��\0���ͻ�������������\0
	printf("%d\n", strlen(arr + 0));//���ֵ
	//printf("%d\n", strlen(*arr));//error - *arr��'a',������a��ASCIIֵΪ��ַ��
	//printf("%d\n", strlen(arr[1]));//error ,ͬ��
	printf("%d\n", strlen(&arr));//���ֵ
	printf("%d\n", strlen(&arr + 1));//���ֵ-6
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1
	return 0;
}

int main()
{
	char arr[] = "abcdef";//abcdef\0 - 7
	printf("%d\n", sizeof(arr));//7 ����������ܴ�С
	printf("%d\n", sizeof(arr + 0));//4/8 ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*arr));//1 ��Ԫ��
	printf("%d\n", sizeof(arr[1]));//1 �ڶ���Ԫ��
	printf("%d\n", sizeof(&arr));// 4/8 &arr����ĵ�ַ
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0]+1�ǵڶ���Ԫ�صĵ�ַ

	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//error
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//5
	return 0;
}

int main()
{
	char *p = "abcdef";
	printf("%d\n", sizeof(p));//4/8 p��ָ�����
	printf("%d\n", sizeof(p + 1));//4/8 p+1���ַ�b�ĵ�ַ
	printf("%d\n", sizeof(*p));//1 p���ַ�ָ�룬*p����1���ֽ�
	printf("%d\n", sizeof(p[0]));//1 p[0]==*(p+0)==*p
	printf("%d\n", sizeof(&p));//4/8 &p��p�ĵ�ַ
	printf("%d\n", sizeof(&p + 1));//4/8 &p+1ָ��p��ߵĿռ�
	printf("%d\n", sizeof(&p[0] + 1));//4/8 &p[0]+1���ǵ�ַ

	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//���ֵ
	printf("%d\n", strlen(&p + 1));//���ֵ
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}

//��ά����
int main()
{
	int a[3][4] = { 0 };
	//���ڶ�ά����
	printf("%d\n", sizeof(a));//48 ��������������sizeof�ڲ������������������Ĵ�С
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16 a[0]�ǵ�һ�е���������
	//��һ������������sizeof�ڲ���������ǵ�һ��������ܴ�С
	printf("%d\n", sizeof(a[0] + 1));//4/8 arr[0]��Ϊ��һ�е���������û�з���sizeof�ڲ�
	//�����������൱����Ԫ�صĵ�ַ�����ǵ�һ�е�һ��Ԫ�صĵ�ַ
	//a[0]+1 ->��һ�еڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*(a[0] + 1)));//4 ������-����һ�еڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(a + 1));//4/8 a��Ϊ��ά�������������û��&��Ҳû�з���sizeof�ڲ�
	//��ô������a������Ԫ�أ���һ�У��ĵ�ַ
	//a+1->�ڶ��е�ַ
	printf("%d\n", sizeof(*(a+1)));//16 �ڶ��еĴ�С *(a+1)==a[1]
	printf("%d\n", sizeof(&a[0] + 1));//4/8 &arr[0]�ǵ�һ�еĵ�ַ��&a[0]+1�ǵڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));//16 ������ǵڶ��еĴ�С
	printf("%d\n", sizeof(*a));//16 *a==*(a+0)==a[0]
	//a����ά�������������û��&��Ҳû�е�������sizeof�ڲ�
	//����a�Ƕ�ά������Ԫ�صĵ�ַ��Ҳ���ǵ�һ�еĵ�ַ
	//*a���ǵ�һ��
	printf("%d\n", sizeof(a[3]));//16 a[3]Խ�磬������ȷ���;Ϳ��Լ����С

	return 0;
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	//&a -��int(*)[5] ����ָ��
	//&a + 1 -��������������
	printf("%d,%d\n", *(a + 1), *(ptr - 1));//2   5
	return 0;
}

struct Test//����ṹ��Ĵ�С��20�ֽ�
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
	printf("%p\n", p + 0x1);//p�ǽṹ��ָ�룬0x100000+20=0x100014
	printf("%p\n",(unsigned long) p + 0x1);//(unsigned+1)ת�������� 0x100000+1=0x100001
	printf("%p\n",(unsigned int*) p + 0x1);//ת����ָ�� 0x100000+4=0x100004
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
	printf("%d\n", p[0]);//*��p+0��
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