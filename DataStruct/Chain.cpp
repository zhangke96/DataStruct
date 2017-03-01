#include <iostream>
#include "Chain.h"


#ifdef ChainMain
int main()
{
	Chain<int> a;
	std::cout << "空的长度： " << a.Length() << std::endl;
	a.Insert(0, 1);
	std::cout << "插入一个元素后的长度 " << a.Length() << std::endl;
	std::cout << a << std::endl;
	a.Insert(1, 2);
	int b;
	a.Find(2, b);
	std::cout << "find: " << b << std::endl;
	std::cout << "search" << a.Search(2) << std::endl;
	a.Delete(1, b);
	std::cout << a << std::endl;
	a.Delete(1, b);
	std::cout << "b: " << b << std::endl;
	std::cout << a << std::endl;
	return 0;

}
#endif