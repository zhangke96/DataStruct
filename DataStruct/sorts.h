#include <iostream>

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