#include <stdio.h>
#include<time.h>
#include<stdlib.h>


void PrintArray(int* a, int n);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// 
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);

void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);