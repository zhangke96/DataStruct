#include <iostream>
#include <vector>

template <typename T>
class BinaryTreeNode;
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
	friend void Visit<T>(BinaryTreeNode<T> *);
	friend void InOrder<T>(BinaryTreeNode<T> *);
	friend void PreOrder<T>(BinaryTreeNode<T> *);
	friend void PostOrder<T>(BinaryTreeNode<T> *);
	friend void LevelOrder<T>(BinaryTreeNode<T> *);
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
	std::vector<BinaryTreeNode<T> *> vec;
	vec.push_back(t);
	int cur = 0, last = 1;
	while (cur < vec.size())
	{
		last = vec.size();
		while (cur < last)
		{
			std::cout << vec[cur]->data << " ";
			if (vec[cur]->LeftChild)
				vec.push_back(vec[cur]->LeftChild);
			if (vec[cur]->RightChild)
				vec.push_back(vec[cur]->RightChild);
			++cur;
		}
		std::cout << std::endl;
	}
}