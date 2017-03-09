#include <iostream>
#include "MaxPQ.h"
#include <random>

#ifdef MaxPQMain



int main()
{
	MaxPQ<int> a(100);
	std::default_random_engine re;
	for (int i = 0; i < 8; ++i)
		a.insert(re());
//	for (int i = 0; i < 4; ++i)
//		std::cout << *(a.getPoin() + i + 1) << " ";
//	std::cout << std::endl;
//	int z = 3;
	while (!a.isEmpty())
	{
//		std::cout << a.delMax() << " ";
//		std::cout << std::endl << "É¾³ýÖ®ºó: ";
//		for (int i = 0; i < z; ++i)
//			std::cout << *(a.getPoin() + i + 1) << " ";
		std::cout << a.delMax() << " ";
		std::cout << std::endl;
		//--z;
	}
	std::cout << std::endl;
}

#endif // MaxPQMain