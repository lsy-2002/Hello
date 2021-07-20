#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
//匿名结构体，特点：只能用一次
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
	//成员变量
	char name[20];
	char author[20];
	short price;
};
//typedef 相当于定义了一个小名
typedef struct nub
{
	//成员变量
	char name[20];
	char author[20];
	short price;
}nub;
int main()
{
	struct Book b1 = { "C语言程序设计", "谭浩强", 45 };
	nub n1 = { "hah", "llll", 90 };

	return 0;
}

//结构体在计算大小时，会发生内存对齐
//offsetof 计算的是结构体成员相对于结构体起始位置的偏移量
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


#pragma pack(1)//设置默认对齐数
struct S1
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//恢复默认对齐数
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
	Print(s);//传结构体
	Print2(&s);//传地址
	return 0;
}

//位段 - 二进制位
//位段是在一定程度上节省空间
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
	//一次开辟一个整形4个字节
	//4  -》32bit
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
	//枚举类型可能取值
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

union Un//联合类型的声明
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
	union Un u;//联合类型的定义
	printf("%d\n", sizeof(u));//4
	printf("%p\n", &u);
	//c和i会公用一块空间
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
	union Un u;//联合类型的定义
	u.i = 0x11223344;
	u.c = 0x55;
	printf("%x\n", u.i);//0x1122334455
	return 0;
}
int main()
{
	int a = 1;//0x 00 00 00 01
	//低            高
	//01 00 00 00 小端存储
	//00 00 00 01 大端存储
	//拿出第一个字节比较
	if (1 == *(char*)&a)//int*->char*
	{
		printf("小端\n");
	}
	else
		printf("大端\n");
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
		printf("小端\n");
	else
		printf("大端\n");
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