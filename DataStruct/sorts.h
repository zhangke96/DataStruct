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
			//	assert(k < n);
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

template <typename T>              /* 利用辅助数组aux对T[lo] -- T[mid] 和 T[mid+1] -- T[hi]进行归并操作 */
void merge(T a[], T aux[], int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;       /* 分成两段的数组的下标 */

	for (int k = lo; k <= hi; ++k) /* 将数组先复制到辅助数组中 */
		aux[k] = a[k];

	for (int k = lo; k <= hi; ++k) /* 开始归并操作 */
	{
		if (i > mid)   /* 前面一段数组元素全部用完 */
			a[k] = aux[j++];
		else if (j > hi)  /* 后面一段数组元素全部用完 */
			a[k] = aux[i++];
		else if (aux[i] < aux[j])  /* 前面的比后面小，放前面的 */
			a[k] = aux[i++];
		else
			a[k] = aux[j++];
	}
}

template <typename T>
void MergeSort(T a[], T aux[], int lo, int hi)
{
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;    /* ==(hi + lo) / 2 预防溢出 */
	MergeSort(a, aux, lo, mid);
	MergeSort(a, aux, mid + 1, hi);
	merge(a, aux, lo, mid, hi);
}

template <typename T>
void MergeSort(T a[], int n)
{
	T *aux;
	aux = new T[n];
	MergeSort(a, aux, 0, n - 1);
	delete[] aux;
}

template <typename T>
/* 不使用递归，自底向上的归并排序 
*  将数组分为2个元素归并排序，4个元素归并排序，直至全部
*/
void AMergeSort(T a[], int n)
{
	T *aux;
	aux = new T[n];
	for (int sz = 1; sz < n; sz = 2 * sz)    /* 归并的两个数组的大小，从1开始增长直至2个归并的数组可以覆盖整个数组 */
	{
		for (int lo = 0; lo < n - sz; lo += 2 * sz)
		{
			int hi = (lo + 2 * sz - 1) < n - 1 ? lo + 2 * sz - 1 : n - 1;
			merge(a, aux, lo, lo + sz - 1, hi);
		}
	}
}