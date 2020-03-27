// SortAlgorithm.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#define DLL_IMPLEMENT
#include "SortAlgorithm.h"


void InsertionSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i, j;
	for (i = 1; i < n; ++i)
	{
		if (array[i - 1] > array[i])
		{
			int key = array[i];
			for (j = i - 1; j >= 0 && array[j] > key; --j)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = key;
		}
	}
}

void Swap(int *a, int *b)
{
	if (a == NULL || b == NULL)
	{
		return;
	}

	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void SwapInsertionSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i, j;
	for (i = 1; i < n; ++i)
	{
		for (j = i - 1; j >= 0 && array[j] > array[j + 1]; --j)
		{
			Swap(&array[j], &array[j + 1]);
		}
	}
}

int InsertPosition(int *array, int low, int high, int key)
{
	while (low <= high)
	{
		int mid = (high - low) / 2 + low;
		if (key < array[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return low;
}

void BinaryInsertionSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i, j;
	for (i = 1; i < n; ++i)
	{
		if (array[i - 1] > array[i])
		{
			int key = array[i];
			int position = InsertPosition(array, 0, i - 1, key);
			for (j = i - 1; j >= position; --j)
			{
				array[j + 1] = array[j];
			}
			array[position] = key;
		}
	}
}

void ShellSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i, j, gap;
	for (gap = n / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < n; ++i)
		{
			if (array[i - gap] > array[i])
			{
				int key = array[i];
				for (j = i - gap; j >= 0 && array[j] > key; j -= gap)
				{
					array[j + gap] = array[j];
				}
				array[j + gap] = key;
			}
		}
	}
}

void SelectSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		int index = i;
		for (j = i + 1; j < n; ++j)
		{
			if (array[j] < array[index])
			{
				index = j;
			}
		}
		
		if (index != i)
		{
			Swap(&array[i], &array[index]);
		}
	}
}

void BubbleSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < n - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void QuicklySortRecursively(int *array, int low, int high)
{
	if (low >= high)
	{
		return;
	}

	int r0 = array[low];

	int i = low;
	int j = high;
	while (i < j)
	{
		while (i < j && array[j] >= r0) --j;
		if (i != j) array[i] = array[j];
		while (i < j && array[i] <= r0) ++i;
		if (i != j) array[j] = array[i];
	}

	array[i] = r0;

	QuicklySortRecursively(array, low, i - 1);
	QuicklySortRecursively(array, i + 1, high);
}

void QuicklySort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	QuicklySortRecursively(array, 0, n - 1);
}


void HeapAdjust(int *array, int n, int s)
{
	int j;
	int key = array[s];

	for (j = 2 * s + 1; j < n; j = 2 * j + 1)
	{
		if (j < n - 1 && array[j] < array[j + 1])
			++j;

		if (key >= array[j])
			break;
		
		array[s] = array[j];
		s = j;
	}

	array[s] = key;
}

void HeapSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int i;
	for (i = n / 2 - 1; i >= 0; --i) //从最后一个非叶子结点开始调整堆
		HeapAdjust(array, n, i);

	for (i = n - 1; i > 0; --i)	//每次交换第一个元素和最后一个元素，再调整堆
	{
		Swap(&array[0], &array[i]);
		HeapAdjust(array, i, 0);
	}
}


void Merge(int *array, int low, int mid, int high, int *temp)
{
	int i = low;		int m = mid;
	int j = mid + 1;	int n = high;

	int k = 0;

	while (i <= m && j <= n)
	{
		if (array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}

	while (i <= m)
		temp[k++] = array[i++];

	while (j <= n)
		temp[k++] = array[j++];

	for (i = 0; i < k; ++i)
		array[low + i] = temp[i];
}

void MergeSortRecursively(int *array, int low, int high, int *temp)
{
	if (low >= high)
		return;

	int mid = (high - low) / 2 + low;
	MergeSortRecursively(array, low, mid, temp);
	MergeSortRecursively(array, mid + 1, high, temp);
	Merge(array, low, mid, high, temp);
}

void MergeSort(int *array, int n)
{
	if (array == NULL || n <= 0)
	{
		return;
	}

	int *temp = new int[n];

	MergeSortRecursively(array, 0, n - 1, temp);

	delete []temp;
}