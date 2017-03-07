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
void PreOrder(BinaryTreeNode<T> *t)    /* ǰ����� ���������� */
{
	if (t)
	{
		Visit(t);
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}
template <typename T>
void InOrder(BinaryTreeNode<T> *t)    /* ��������� �󡢸����� */
{
	if (t)
	{
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}
template <typename T>
void PostOrder(BinaryTreeNode<T> *t)   /* ������������ҡ��� */
{
	if (t)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}
template <typename T>
void LevelOrder(BinaryTreeNode<T> *t)  /* ��α��� */
{

}