#include "BinaryTreeNode.h"
#ifdef BinaryTreeMain


int main()
{
	//BinaryTreeNode<int> a(1);
	BinaryTreeNode<int> b(2);
	BinaryTreeNode<int> c(3);
	int A = 1;
	BinaryTreeNode<int> a(A, &b, &c);
	//Visit(&a);
	PreOrder(&a);
}

#endif  //BinaryTreeMain