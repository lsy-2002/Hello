#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
#include <string.h>
/*
/���ļ�
FILE * fopen(const char *filename, const char *mode);
//�ر��ļ�
int fclose(FILE *stream);
int main()
{
	//..��ʾ��һ��Ŀ¼
	//.��ʾ��ǰĿ¼
	FILE *pf = fopen("data.txt", "w");
	if (pf == NULL)
	{
		printf("���ļ���ʧ��\n");
		printf("%s\n", strerror(errno));
		return 1;//ʧ�ܷ���
	}
	//���ļ��ɹ�
	printf("���ļ��ɹ�\n");
	//��д�ļ�
	//������
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
//C���Եĳ������е�ʱ��Ĭ�ϻ��3����
//stdin - ��׼�����������̣�
//stdout - ��׼���������Ļ��
//stderr - ��׼����������Ļ��

int main()
{
	
	FILE *pf = fopen("data.txt", "r");
	if (pf == NULL)
	{
		printf("���ļ���ʧ��\n");
		printf("%s\n", strerror(errno));
		return 1;//ʧ�ܷ���
	}
	//���ļ��ɹ�
	
	printf("���ļ��ɹ�\n");
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
		printf("���ļ���ʧ��\n");
		printf("%s\n", strerror(errno));
		return 1;
	}
	fputs("hello world\n", pf);
	fputs("llllll\n", pf);

	
}