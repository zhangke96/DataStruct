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
		PreOrder(root);
	}
	void InOrder() const
	{
		if (!root)
			return;
		InOrder(root);
	}
	void PostOrder() const
	{
		if (!root)
			return;
		PostOrder(order);
	}
private:
	BinaryTreeNode<T> *root;
	void PreOrder(const BinaryTreeNode<T> *t) const
	{
		if (!t)
			return;
		std::cout << t->getData() << " ";
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	void InOrder(const BinaryTreeNode<T> *t) const
	{
		if (!t)
			return;
		InOrder(t->LeftChild);
		std::cout << t->getData() << " ";
		InOrder(t->RightChild);
	}
	void PostOrder(const BinaryTreeNode<T> *t) const
	{
		if (!t)
			return;
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		std::cout << t->getData() << " ";
	}
};
