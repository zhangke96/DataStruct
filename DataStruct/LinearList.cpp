#include "LinearList.h"
#include <iostream>
#ifdef LinearListMain
int main()
{
	LinearList<int> a;
	a.Insert(0, 1);
	a.Insert(1, 2);
	a.Insert(2, 3);
	a.Insert(3, 4);
	a.Insert(-1, 5);
	int b;
	a.output(std::cout);
	a.Delete(1, b);
	//std::cout << b << std::endl;
	a.output(std::cout);
	a.Delete(a.getLength(), b);
	a.output(std::cout);
	std::cout << a << std::endl;
}
#endif