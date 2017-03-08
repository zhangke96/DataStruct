#include "BinaryTreeNode.h"
#include "BinaryTree.h"
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
	std::cout << std::endl;
	InOrder(&a);
	std::cout << std::endl;
	PostOrder(&a);
	std::cout << std::endl;
	LevelOrder(&a);
}

#endif  //BinaryTreeMain

#ifdef ABinaryTreeMain

int main()
{
	BinaryTree<char> null;
	BinaryTree<char> J('J');
	BinaryTree<char> G('G');
	BinaryTree<char> F('F', J, G);
	BinaryTree<char> H('H');
	BinaryTree<char> E('E', H, F);
	BinaryTree<char> D('D', E, null);
	BinaryTree<char> K('K');
	BinaryTree<char> C('C', K, null);
	BinaryTree<char> B('B', null, C);
	BinaryTree<char> A('A', D, B);
	A.PostOrder();
	

}

#endif  //ABinaryTreeMain