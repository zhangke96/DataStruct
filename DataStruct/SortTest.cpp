#include "sorts.h"

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
