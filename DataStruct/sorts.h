#include <iostream>
#include <cassert>
template <typename T>
void SelectSort(T a[], int n)   /* ��T a[n]����ѡ������ */
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
void InsertSort(T a[], int n)   /* ��T a[n]���в������� */
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
void BubbleSort(T a[], int n)   /* ��T a[n]����ð������ */
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
void ShellSort(T a[], int n)   /* ��T a[n]����ϣ������ */
{
	int h = 1;
	while (h < n / 3)          /* ȷ�����ļ�� */
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

template <typename T>              /* ���ø�������aux��T[lo] -- T[mid] �� T[mid+1] -- T[hi]���й鲢���� */
void merge(T a[], T aux[], int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;       /* �ֳ����ε�������±� */

	for (int k = lo; k <= hi; ++k) /* �������ȸ��Ƶ����������� */
		aux[k] = a[k];

	for (int k = lo; k <= hi; ++k) /* ��ʼ�鲢���� */
	{
		if (i > mid)   /* ǰ��һ������Ԫ��ȫ������ */
			a[k] = aux[j++];
		else if (j > hi)  /* ����һ������Ԫ��ȫ������ */
			a[k] = aux[i++];
		else if (aux[i] < aux[j])  /* ǰ��ıȺ���С����ǰ��� */
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
	int mid = lo + (hi - lo) / 2;    /* ==(hi + lo) / 2 Ԥ����� */
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
/* ��ʹ�õݹ飬�Ե����ϵĹ鲢���� 
*  �������Ϊ2��Ԫ�ع鲢����4��Ԫ�ع鲢����ֱ��ȫ��
*/
void AMergeSort(T a[], int n)
{
	T *aux;
	aux = new T[n];
	for (int sz = 1; sz < n; sz = 2 * sz)    /* �鲢���������ƽ���ֳ�����������������������Ĵ�С��������Ĵ�СӦ��<= 2*sz����1��ʼ����ֱ��2���鲢��������Ը����������� */
	{
		for (int lo = 0; lo < n - sz; lo += 2 * sz) /* ȷ���鲢���������ʼ�±꣬sz��С����ĳ��ȣ�lo����ʼ�±꣩ÿ��λ��2*sz��lo���n-sz-1����Ϊ���ʱ�������һ�ηֻ������ܱ�֤���һ��ǰ����ȣ����������Ƿֳ��������������еĺ���һ��ֻ��һ��Ԫ��*/
		{
			int hi = (lo + 2 * sz - 1) < n - 1 ? lo + 2 * sz - 1 : n - 1;   /* ���������������һ��Ԫ�ص��±꣬ע��Ҫ��������������һ���±�Ƚϣ���Ϊ���һ�β��ܱ�֤���þ��� */
			merge(a, aux, lo, lo + sz - 1, hi);        /* midֱ��ͨ��������ǰ����±�ͳ������-1��ã�mid�ǵ�һ��С��������һ��Ԫ���±� */
		}
	}
}

template <typename T>
int partition(T a[], int lo, int hi)  /* ���������е��зֺ�������a[lo] -- a[hi]��loΪ��׼�����з֣��з�Ϊ���������飬ǰһ��������ֵ��С�ڵ���a[lo]���������a[lo]�����±� */
{
	int i = lo;
	int j = hi + 1;
	T standard = a[lo];    /* �����з������һ��Ԫ����Ϊ��׼ */
	T temp;
	while (true)
	{
		while (a[++i] < standard)  /* ��i�±��ֵ�Ȼ�׼С��һֱ��� */
			if (i == hi)
				break;
		while (a[--j] > standard)  /* ��j�±��ֵ�Ȼ�׼��һֱ��ǰ */
			if (j == lo)
				break;
		if (i >= j)             /* �������±꽻���ˣ��˳� */
			break;
		temp = a[i];              /* ���������±��ֵ */
		a[i] = a[j];
		a[j] = temp;
	}
	/* ������׼��j�±��ֵ */
	temp = a[lo];
	a[lo] = a[j];
	a[j] = a[lo];
	reutrn j;               /* ���ڽ��������һ���ֳַ���a[lo] -- a[j-1] <= a[j] <= a[j+1] -- a[hi]*/
}

template <typename T>
void QuickSort(T a[], int lo, int hi)    /* ��a[lo] -- a[hi] �������� */
{
	if (lo >= hi)
		return;
	int j = partition(a, lo, hi);
	QuickSort(a, lo, j - 1);
	QuickSort(a, j + 1, hi);
}
template <typename T>
void QuickSort(T a[], int n)  /* ��T a[n] ���п������� */
{
	QuickSort(a, 0, n - 1);    /* n-1 ����Ϊ�±���Ҫ���Է��ʵ���� */
}