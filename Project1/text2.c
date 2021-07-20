#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("%d", a);
//	return 0;
//}
//#include<stdio.h>
//int a = 100;
//int main()
//{
//	int a = 10;
//	printf("%d", a);//局部变量优先
//	return 0;
//}
//全局变量作用域是整个工程
//extern是声明外部符号
//#include <stdio.h>
//extern int val;
//int main()
//{
//	printf("%d", val);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	//创建
//	{
//		int a = 10;
//		printf("%d", a);
//	}
//	//销毁
//	printf("%d", a);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	const int a = 10;
//	a = 20;
//	printf("%d",a);//error
//	return 0;
//}
//枚举 enum
//#include <stdio.h>
//enum sex
//{	//枚举常量
//	male = 5,
//	female,
//	secret
//};
//int main()
//{
//	printf("%d\n", male);
//	printf("%d\n", female);
//	printf("%d\n", secret);
//	return 0;
//}