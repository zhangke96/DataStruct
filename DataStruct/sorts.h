#include <iostream>
#include <cassert>
template <typename T>
void SelectSort(T a[], int n)   /* 对T a[n]进行选择排序 */
{
	T min;
	int locate;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		min = a[i];
		locate = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < min)
			{
				locate = j;
				min = a[locate];
			}

		}
		temp = a[i];
		a[i] = a[locate];
		a[locate] = temp;
	}
}

template <typename T>
void InsertSort(T a[], int n)   /* 对T a[n]进行插入排序 */
{
	for (int i = 1; i < n; ++i)
	{
		int j = i;
		int temp = a[j];
		while (j > 0 && temp < a[j - 1])
		{
			a[j] = a[j - 1];
			--j;
		}
		a[j] = temp;
	}
}

template <typename T>
void BubbleSort(T a[], int n)   /* 对T a[n]进行冒泡排序 */
{
	int i = n - 1;
	int last;
	int temp;
	while (i > 0)
	{
		last = 0;
		for (int j = 0; j < i; ++j)
		{
			if (a[j + 1] < a[j])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				last = j;
			}
		}
		i = last;
	}
}

template <typename T>
void ShellSort(T a[], int n)   /* 对T a[n]进行希尔排序 */
{
	int h = 1;
	while (h < n / 3)          /* 确定最大的间隔 */
		h = 3 * h + 1;  
	while (h >= 1)
	{
		for (int i = 0; i < h; ++i)
		{
			for (int j = i + h; j < n; j += h)
			{
			//	assert(j < n);
				int k = j;
				int temp = a[k];
				while (k >= h && temp < a[k - h])
				{
					a[k] = a[k - h];
					k -= h;
				}
				assert(k < n);
				a[k] = temp;
			}
		}
		h = h / 3;
	}
}

template <typename T>
void AShellSort(T a[], int n)
{
	int h = 1;
	int temp;
	while (h < n / 3)
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (int i = h; i < n; ++i)
		{
			for (int j = i; j >= h && (a[j] < a[j - h]); j -= h)
			{
				temp = a[j];
				a[j] = a[j - h];
				a[j - h] = temp;
			}
		}
		h = h / 3;
	}
}

template <typename T>
bool isSorted(T a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}