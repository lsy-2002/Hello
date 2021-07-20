#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
#include <string.h>
/*
/打开文件
FILE * fopen(const char *filename, const char *mode);
//关闭文件
int fclose(FILE *stream);
int main()
{
	//..表示上一级目录
	//.表示当前目录
	FILE *pf = fopen("data.txt", "w");
	if (pf == NULL)
	{
		printf("打开文件夹失败\n");
		printf("%s\n", strerror(errno));
		return 1;//失败返回
	}
	//打开文件成功
	printf("打开文件成功\n");
	//读写文件
	//。。。
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
//C语言的程序，运行的时候，默认会打开3个流
//stdin - 标准输入流（键盘）
//stdout - 标准输出流（屏幕）
//stderr - 标准错误流（屏幕）

int main()
{
	
	FILE *pf = fopen("data.txt", "r");
	if (pf == NULL)
	{
		printf("打开文件夹失败\n");
		printf("%s\n", strerror(errno));
		return 1;//失败返回
	}
	//打开文件成功
	
	printf("打开文件成功\n");
	int ch = fgetc(pf);
	printf("%c\n", ch);
	ch = fgetc(pf);
	printf("%c\n", ch);
	ch = fgetc(pf);
	printf("%c\n", ch);
	ch = fgetc(pf);
	printf("%c\n", ch);

	fclose(pf);
	pf = NULL;
	return 0;
}
*/
int main()
{
	FILE* pf = fopen("data.txt", "w");
	if (pf == NULL)
	{
		printf("打开文件夹失败\n");
		printf("%s\n", strerror(errno));
		return 1;
	}
	fputs("hello world\n", pf);
	fputs("llllll\n", pf);

	
}