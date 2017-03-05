#include "sorts.h"
#include <random>
#include <cassert>
#include <ctime>

#ifdef SelectSortMain



int main()
{
	int a[] = { 1, 4, 0, 43, -1 };
	SelectSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}
#endif // SelectSortMain

#ifdef InsertSortMain

int main()
{
	int a[] = { 1, -2, -4, 43, -1 };
	InsertSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}
#endif // InsertSortMain

#ifdef BubbleSortMain

int main()
{
	int a[] = { 1, -2, -4, 43, -1 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

#endif //BubbleSortMain 
#define SIZE 100000
#ifdef ShellSortMain

int main()
{
	std::default_random_engine randomengine;
	int b[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		b[i] = randomengine();
	}
	int c[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		c[i] = b[i];
	}
	/*
	int a[] = { 7, 4, 3, 1, 9, 2, 5, 0, 8, 6 };
	AShellSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	*/
	clock_t end;
	clock_t beg = clock();
	AShellSort(b, sizeof(b) / sizeof(int));
	end = clock();
	std::cout << end - beg << std::endl;
	assert(isSorted(b, sizeof(b) / sizeof(int)));
	beg = clock();
	ShellSort(c, sizeof(c) / sizeof(int));
	end = clock();
	std::cout << end - beg << std::endl;
	assert(isSorted(c, sizeof(c) / sizeof(int)));
	return 0;
}

#endif //ShellSortMain

#ifdef MergeSortMain

int main()
{
	std::default_random_engine randomengine;
	int b[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		b[i] = randomengine();
	}
	clock_t end;
	clock_t beg = clock();
	AMergeSort(b, (sizeof(b) / sizeof(int)));
	end = clock();
	assert(isSorted(b, sizeof(b) / sizeof(int)));
	std::cout << end - beg << std::endl;
	return 0;
}

#endif //MergeSortMain

#ifdef QuickSortMain

int main()
{
	std::default_random_engine randomengine;
	int a[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = randomengine();
	}
	clock_t end;
	clock_t beg = clock();
	AMergeSort(a, (sizeof(a) / sizeof(int)));
	end = clock();
	assert(isSorted(a, sizeof(a) / sizeof(int)));
	std::cout << end - beg << std::endl;
	return 0;
}
#endif // QuickSortMain
