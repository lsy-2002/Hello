#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d", a[i]);
	printf("\n");
}
void InsertSort(int* a, int n)
{
	//��������
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		//��tmp���뵽�����[0,end]����������
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
			a[end + 1] = tmp;
		}
	}
}
void ShellSort(int* a, int n)
{
	//gap > 1 ʱ��Ԥ����
	//gap = 1 ʱ��ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3 + 1);
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[gap + end];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}

	}
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int min = left, max = right;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		Swap(&a[left], &a[right]);
		if (left == max)
			max = min;
		Swap(&a[right], &a[max]);
		++left;
		--right;
	}
}
//������
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] + 1 > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	//���򽨴��
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
//ð��
void BubbleSort(int* a, int n)
{
	/*for (int j = 0; j < n; j++)
	{
	for (int i; i < n - j; i++)
	{
	if (a[i - 1] > a[i])
	Swap(&a[i - 1], &a[i]);
	}
	}*/
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		for (int i = 0; i < end - 1; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
			if (exchange == 0)
				break;
		}
	}
}
//hoare--����ָ�뷨
int   PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		//��С
		while (left < right && a[right] >= a[key])
			right--;
		//�Ҵ�
		while (left < right && a[left] <= a[key])
			left++;
		Swap(&a[left], &a[right]);
	}
	int meet = left;
	Swap(&a[key], &a[left]);
	return left;
}
int GetMid(int* a, int left, int right)//��key���м�ֵ
{
	int mid = (left + right) >> 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;

	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}
//�ڿӷ�
int  PartSort2(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	while (left < right)
	{

		//��С
		while (left < right && a[right] >= key)
			right--;
		//�ŵ���ߵĿӣ��ұ��γ��µĿ�
		a[left] = a[right];
		//�Ҵ�
		while (left < right && a[left] <= key)
			left++;
		//�ŵ��ұߵĿ�λ������γ��µĿ�
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

//ǰ��ָ�뷨
void PartSort3(int* a, int left, int right)
{
	int key = left;
	int prev = key, cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		cur++;

	}
	Swap(&a[cur], &a[prev]);
}
//����
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	/*int left = begin, right = end;
	int key = left;
	while (left < right)
	{
	//��С
	while (left < right && a[right] >= a[key])
	right--;
	//�Ҵ�
	while (left < right && a[left] <= a[key])
	left++;
	Swap(&a[left], &a[right]);
	}
	int meet = left;
	Swap(&a[key], &a[meet]);*/
	if (end - begin > 10)//С�����Ż�
	{
		//������������ݽ϶࣬����ѡkey���ָ���������εݹ�
		//������������ݽ�С����ȥ���β�����
		int key = GetMid(a, begin, end);
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
	else
		InsertSort(a + begin, end - begin + 1);

}
#include "SeqStack.h"
void QuickSortNonR(int*a, int begin, int end)
{
Stack st;
StackInit(&st);
StackPush(&st, begin);
StackPush(&st, end);
while (!StackEmpty(&st))
{
int left, right;
right = StackTop(&st);
StackPop(&st);
left = StackTop(&st);
StackPop(&st);
int key = PartSort1(a, left, right);
if (left < key - 1)
{
StackPush(&st, left);
StackPush(&st, key - 1);
}
if (key + 1 < right)
{
StackPush(&st, key + 1);
StackPush(&st, right);
}
}
StackDestory(&st);
}

//�鲢

void _Merge(int*a ,int* tmp, int begin1, int end1, int begin2, int end2)//�ǵݹ����
{
	int j = begin1;
	int i = begin2;
	while (begin1 < end1 && begin2 < end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1];
		else
			tmp[i++] = a[begin2];
	}
	while (begin1 < end1)
		tmp[i++] = a[begin1++];
	while (begin2 < end2)
		tmp[i++] = a[begin2++];
	//�鲢��ɺ󣬿�����ԭ����
	for (; j <= end2; ++j)
		a[j] = tmp[j];
}
void _MergeSort(int* a, int left, int right,int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 2;
	//[left][mid]  [mid+1][right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//�鲢
	//��������������鲢tmp����������ȥ
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	_Merge(a, tmp, left, mid, mid + 1, right);

	/*int i = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1];
		else
			tmp[i++] = a[begin2];
	}
	while (begin1 < end1)
		tmp[i++] = a[begin1++];
	while (begin2 < end2)
		tmp[i++] = a[begin2++];
	for (int j = left; j <= right; j++)
		a[j] = tmp[j];
	//�鲢��ɺ󣬿�����ԭ����*/

}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1] [i+gap,i+2*gap+1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//����ڶ���С���䲻���ھͲ���Ҫ�鲢�ˣ���������ѭ��
			if (begin2 >= n)
				break;
			//����ڶ���������ڣ����ǵڶ���С���䲻��gap��������λ��Խ���ˣ���Ҫ����
			if (end2 >= n)
				end2 = n - 1;
			_Merge(a, tmp, begin1,end1,begin2,end2);

		}
		gap *= 2;
	}
	free(tmp);
}
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* count = malloc(sizeof(int)* range);
	memset(count, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count);
}