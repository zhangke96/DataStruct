#include <iostream>
#include "BinaryTreeNode.h"

template <typename T>
class BinaryTree
{
public:
	BinaryTree() : root(NULL) {}
	BinaryTree(const T &element)
	{
		root = new BinaryTreeNode<T>(element);

	}
	BinaryTree(const T &element, BinaryTree<T> &left, BinaryTree<T> &right)
	{
		if (&left != &right)
		{
			root = new BinaryTreeNode<T>(element, left.root, right.root);
			left.root = right.root = NULL;
		}
	}
	bool isEmpty() const
	{
		return root == NULL;
	}
	bool Root(T &x) const  /* x值赋为root->data */
	{
		if (root)
		{
			x = root->data;
			return true;
		}
		return false;
	}
	void MakeTree(const T &element, BinaryTree<T> &left, BinaryTree<T> &right)
	{
		if (&left != &right && &left != this && &right != this)
		{
			root = new BinaryTreeNode<T>(element, left.root, right.root);
			left.root = right.root = NULL;
		}
	}
	void BreakTree(T &element, BinaryTree<T> &left, BinaryTree<T> &right)
	{
		if (!root)
			return;
		if (left.root || right.root) /* 拆开的两个子树不是空的 */
			return;
		element = root->data;
		left.root = root->LeftChild;
		right.root = root->RightChild;
		delete root;
		root = NULL;
	}
	void PreOrder() const
	{
		if (!root)
			return;
		PreOrderBT(root);
	}
	void InOrder() const
	{
		if (!root)
			return;
		InOrderBT(root);
	}
	void PostOrder() const
	{
		if (!root)
			return;
		PostOrderBT(root);
	}
private:
	BinaryTreeNode<T> *root;
	void PreOrderBT(const BinaryTreeNode<T> *t) const
	{
		if (!t)
			return;
		std::cout << t->getData() << " ";
		PreOrderBT(t->getLeftPoint());
		PreOrderBT(t->getRightPoint());
	}
	void InOrderBT(const BinaryTreeNode<T> *t) const
	{
		if (!t)
			return;
		InOrderBT(t->getLeftPoint());
		std::cout << t->getData() << " ";
		InOrderBT(t->getRightPoint());
	}
	void PostOrderBT(const BinaryTreeNode<T> *t) const
	{
		if (!t)
			return;
		PostOrderBT(t->getLeftPoint());
		PostOrderBT(t->getRightPoint());
		std::cout << t->getData() << " ";
	}
};
