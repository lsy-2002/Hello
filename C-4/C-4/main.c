#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
//�����ṹ�壬�ص㣺ֻ����һ��
struct
{
	char c;
	int a;
	short s;
}S;
struct
{
	char c;
	int a;
	short s;
}*ps;
struct Node
{
	int data;
	struct Node * n;
};
struct S
{
	int a;
	int b;
	double d;
};
struct B
{
	char c;
	struct S s;
	short ss;
};
int main()
{
	struct B  b1= { 'a', { 100, 200, 3.14 }, 5 };
	printf("%lf\n", b1.s.d);
}

struct Book
{
	//��Ա����
	char name[20];
	char author[20];
	short price;
};
//typedef �൱�ڶ�����һ��С��
typedef struct nub
{
	//��Ա����
	char name[20];
	char author[20];
	short price;
}nub;
int main()
{
	struct Book b1 = { "C���Գ������", "̷��ǿ", 45 };
	nub n1 = { "hah", "llll", 90 };

	return 0;
}

//�ṹ���ڼ����Сʱ���ᷢ���ڴ����
//offsetof ������ǽṹ���Ա����ڽṹ����ʼλ�õ�ƫ����
#include <stddef.h>
struct S1
{
	char c1;
	int i;
	char c2;
};
int main()
{
	struct S1 s1;
	//printf("%d\n", sizeof(s1));//12
	printf("%d\n", offsetof(struct S1, c1));//1
	printf("%d\n", offsetof(struct S1, i));//4
	printf("%d\n", offsetof(struct S1, c2));//8
	return 0;
}

struct S1
{
	char c1;
	char c2;
	int i;
};
int main()
{
	struct S1 s1;
	printf("%d\n", sizeof(s1));//8
	return 0;
}

struct S3//16
{
	double d;//8
	char c;//1
	int i;//4
};
struct S4
{
	char c1;//1
	struct S3 s3;//16
	double d1;//8
};
int main()
{
	struct S4 s4;
	printf("%d\n", sizeof(s4));//32
	return 0;
}


#pragma pack(1)//����Ĭ�϶�����
struct S1
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//�ָ�Ĭ�϶�����
int main()
{
	printf("%d\n", sizeof(struct S1));//6
	return 0;
}

#pragma pack(4)
struct S3
{
	double d;
	char c;
	int i;
};
#pragma pack()
int main()
{
	printf("%d\n", sizeof(struct S3));
	return 0;
}

struct S
{
	int data[20];
	int num;
};
void Print(struct S s){}
void Print2(struct S* ps){}
int main()
{
	Print(s);//���ṹ��
	Print2(&s);//����ַ
	return 0;
}

//λ�� - ������λ
//λ������һ���̶��Ͻ�ʡ�ռ�
struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
int main()
{
	struct A a1;
	//һ�ο���һ������4���ֽ�
	//4  -��32bit
	//_a - 2
	//_b - 5
	//_c - 10
	//4  ->32bit
	//_d - 30
	printf("%d\n", sizeof(struct A));//4+4 = 8
	return 0;
}

struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}

enum Day
{
	//ö�����Ϳ���ȡֵ
	Mon = 3,
	Tues,
	Wed,
	Thus,
	Fri,
	Sat,
	Sun

};
enum RGB
{
	red,
	green,
	blue
};
int main()
{
	enum Day d = Wed;//4
	printf("%d\n", Tues);
	printf("%d\n", red);//0
	printf("%d\n", green);//1
	printf("%d\n", blue);//2
	return 0;
}

union Un//�������͵�����
{
	char c;
	int i;
};

union Un
{
	char c;
	int i;
};
int main()
{
	union Un u;//�������͵Ķ���
	printf("%d\n", sizeof(u));//4
	printf("%p\n", &u);
	//c��i�ṫ��һ��ռ�
	printf("%p\n", &u.c);
	printf("%p\n", &u.i);
	return 0;
}

union Un
{
	char c;
	int i;
};
int main()
{
	union Un u;//�������͵Ķ���
	u.i = 0x11223344;
	u.c = 0x55;
	printf("%x\n", u.i);//0x1122334455
	return 0;
}
int main()
{
	int a = 1;//0x 00 00 00 01
	//��            ��
	//01 00 00 00 С�˴洢
	//00 00 00 01 ��˴洢
	//�ó���һ���ֽڱȽ�
	if (1 == *(char*)&a)//int*->char*
	{
		printf("С��\n");
	}
	else
		printf("���\n");
	return 0;
}

int check_sys()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}

union U
{
	char arr[6];//6
	int i;//4
};
int main()
{
	union U u;
	printf("%d\n", sizeof(u));//8
	return 0;
}
*/
union U
{
	short arr[7];//14
	int i;//4
};
int main()
{
	union U u;
	printf("%d\n", sizeof(u));//16
	return 0;
}