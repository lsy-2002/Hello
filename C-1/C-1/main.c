#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
//移位操作符
// << 左移操作符
// << 右移操作符
int main()
{
	//整数的二进制位怎么描述？
	//整数的二进制位有三种表示形式：原码、反码、补码
	//正数的原、反、补是相同的
	//复数的原码、反码、补码是要计算的
	int a = 5;//整形是4个字节（32bit位）
	int b = a << 1;
	//5
	//00000000000000000000000000000101 - 原码
	//内存中存储的是补码
	printf("%d\n", b);
	printf("%d\n", a);
	return 0;
}

int main()
{
	
	//-1
	//10000000000000000000000000000001 - 原码
	//原码的符号位不变，其他位按位取反，得到反码
	//11111111111111111111111111111110 - 反码
	//反码+1，得到补码
	int a = -1;
	//11111111111111111111111111111111 - 补码
	int b = a << 1;
	//11111111111111111111111111111110 - 补码
	//11111111111111111111111111111101 - 反码
	//10000000000000000000000000000010 - 原码
	//-2
	printf("%d\n", b);//打印的是原码
	return 0;
}
int main()
{
	int a = 5;
	int b = a >> 1;
	printf("%d\n", b);//2
	//右移操作符
	//1、算数右移
	//右边丢弃，左边补原来的符号位
	//2、逻辑右移
	//右边丢弃，左边补0
	//

	return 0;
}
int main()
{
	int a = -1;
	int b = a >> 1;
	printf("%d\n", b);//-1
	//10000000000000000000000000000001 - 原码
	//11111111111111111111111111111110 - 反码
	//11111111111111111111111111111111 - 补码

	return 0;
}
int num = 10;
num >> -1 //error

& //按位与
| //按位或
^ //按位异或
int main()
{
	int a = 3;
	int b = 5;
	int c = a & b;//&按（二进制）与
		//00000000000000000000000000000011  3
		//00000000000000000000000000000101  5
		//00000000000000000000000000000001  1
	printf("%d\n", c);// 1
	return 0;
}

int main()
{
	int a = 3;
	int b = 5;
	int c = a | b;// |按（二进制）或
	//00000000000000000000000000000011  3
	//00000000000000000000000000000101  5
	//00000000000000000000000000000111  7
	printf("%d\n", c);// 7
	return 0;
}
int main()
{
	int a = 3;
	int b = 5;
	int c = a ^ b;//^按（二进制）异或
	//00000000000000000000000000000011  3
	//00000000000000000000000000000101  5
	//00000000000000000000000000000110  6 
	printf("%d\n", c);// 6
	return 0;
}
int main()
{
	int a = 3;
	int b = 5;
	int tmp;//创建一个临时变量
	tmp = a;
	a = b;
	b = tmp;
	printf("a = %d,b = %d\n", a, b);
	return 0;
}
//要求：不创建临时变量
int main()
{
	int a = 3;
	int b = 5;
	a = a + b;
	b = a - b;//b = 3
	a = a - b;//a = 5
	printf("a = %d,b = %d\n", a, b);
	return 0;
	//可能会出现整形溢出
}
int main()
{
	int a = 3;
	int b = 5;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d,b = %d\n", a, b);
	return 0;
}
int main()
{
	//char -> signed char (有符号位)
	char a = 3;//char 类型只能存8个bit位（1个字节） 
	//00000000 00000000 00000000 00000011	//截断
	//00000011 - a
	char b = 127;
	//00000000 00000000 00000000 01111111	//截断
	//01111111 - b
	char c = a + b;
	//a和b的大小不够一个整形大小，所以要发生整形提升
	//整形提升是按照变量原符号位来提升的
	//00000000 00000000 00000000 00000011
	//00000000 00000000 00000000 01111111
	//00000000 00000000 00000000 10000010	//截断
	//10000010 - c  //整型提升-》按符号位提升
	//11111111 11111111 11111111 10000010 - 补码
	//11111111 11111111 11111111 10000001 - 反码
	//10000000 00000000 00000000 01111110 - 原码
	printf("%d\n", c);//-126
	//%d - 按有符号整形打印
	return 0;
	//char a, b, c;
	//c = b + a;
	//a和b的值被提升为普通整形，然后再执行加法运算
	//加法运算完成之后，结果将被截断，然后再存储在c中
	//负数的整型提升
	char d = -1;
	//11111111 - d
	//整型提升，高位补充符号位，即为1
	//11111111 11111111 11111111 11111111
	//正数的整型提升
	char e = 1;
	//00000001 - e
	//整型提升，高位补充符号位，即为0
	//00000000 00000000 00000000 00000001
	//无符号整型提升，高位补充0
}

//实例1
int main()
{
	char a = 0xb6;
	//1011 0110 ->整形提升，高位补充符号位为1
	short b = 0xb600;
	//1011 0110 00->整形提升，高位补充符号位为1
	int c = 0xb6000000;
	if (a == 0xb6)
		printf("a\n");
	if (b == 0xb600)
		printf("b\n");
	if (c == 0xb6000000)
		printf("c\n");//打印
	return 0;
}
//实例2
int main()
{
	char c = 1;
	printf("%u\n", sizeof(c));//1
	printf("%u\n", sizeof(+c));//4  带符号表示参与运算-》提升成整形
	printf("%u\n", sizeof(-c));//4  带符号表示参与运算-》提升成整形
	return 0;
}
long double
double
float
unsigned long int 
long int 
unsigned int 
int 
//统计二进制中1的个数
int count_one(size_t num)//size_t 无符号（方便接受负值）
{
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)
			count++;
		num /= 2;
	}
	return count;
}
int count_one(int n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 1)
			count++;
	}
	return count;
}

//n = 15
//n = n &(n-1)
//1111 - n
//1110 - n-1
// 1110
int count_one(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
int main()
{
	int num;
	scanf("%d", &num);
	int ret = count_one(num);
	printf("%d\n", ret);
	return 0;
}
//求两个数二进制中不同的位数
int count_dif(int m, int n)
{
	int i;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n>>i)&1))
			count++;
	}
	return count;
}
int count_dif(int m, int n)
{
	int count = 0;
	int tmp = m^n;
	while (tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	return count;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int ret = count_dif(m, n);
	printf("%d\n", ret);
	return 0;
	}
//判断 n是否为2^m次方
//8
//100
//10
//1100
int main()
{
	int n;
	scanf("%d", &n);
	if (n&(n - 1) == 0)
		printf("YES\n");
	else
		printf("No\n");
	return 0;
}*/
//打印整数二进制的奇数位和偶数位
void Print(int m)
{
	//打印奇数位
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", ((m >> i) & 1));
	}
	printf("\n");
	//打印偶数位
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d", ((m >> i) & 1));
	}

}
int main()
{
	int m = 0;
	scanf("%d", &m);
	Print(m);
	return 0;
}