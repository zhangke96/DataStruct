#include <iostream>
#include "Chain.h"


#ifdef ChainMain
int main()
{
	Chain<int> a;
	std::cout << "�յĳ��ȣ� " << a.Length() << std::endl;
	a.Insert(0, 1);
	std::cout << "����һ��Ԫ�غ�ĳ��� " << a.Length() << std::endl;
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