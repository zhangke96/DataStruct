#include <iostream>
template <typename T>
class BinaryTreeNode<T>;
template <typename T>
void Visit(BinaryTreeNode<T> *);
template <typename T>
void InOrder(BinaryTreeNode<T> *);
template <typename T>
void PreOrder(BinaryTreeNode<T> *);
template <typename T>
void PostOrder(BinaryTreeNode<T> *);
template <typename T>
void LevelOrder(BinaryTreeNode<T> *);
template <typename T>
class BinaryTreeNode
{
	friend void Visit(BinaryTreeNode<T> *);
	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<T> *);
public:
	BinaryTreeNode() : LeftChild(NULL), RightChild(NULL) {}
	BinaryTreeNode(const T &e) : data(e), LeftChild(NULL), RightChild(NULL) {}
	BinaryTreeNode(const T &e, BinaryTreeNode *lh, BinaryTreeNode *rh) : data(e), LeftChild(lh), RightChild(rh) {}
private:
	T data;
	BinaryTreeNode<T> *LeftChild, *RightChild;
};

template <typename T>
void Visit(BinaryTreeNode<T> *t)
{
	std::cout << t->data << " ";
}
template <typename T>
void PreOrder(BinaryTreeNode<T> *t)    /* 前序遍历 ，根、左、右 */
{
	if (t)
	{
		Visit(t);
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}
template <typename T>
void InOrder(BinaryTreeNode<T> *t)    /* 中序遍历， 左、根、右 */
{
	if (t)
	{
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}
template <typename T>
void PostOrder(BinaryTreeNode<T> *t)   /* 后序遍历，左、右、根 */
{
	if (t)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}
template <typename T>
void LevelOrder(BinaryTreeNode<T> *t)  /* 层次遍历 */
{

}