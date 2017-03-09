#ifndef BINARYTREE

#define BINARYTREE


#include <iostream>
#include <stack>
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
	bool Root(T &x) const  /* xֵ��Ϊroot->data */
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
		if (left.root || right.root) /* �𿪵������������ǿյ� */
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
	/* ����stack�Զ���������ǰ�����
	*  �����ڵ���ջ��ÿ�δ�ջ������һ����㣬���ʸýڵ�
	*  �ѵ�ǰ�����Һ�����ջ
	*  �ѵ�ǰ����������ջ
	*  ��ջ˳��Ϊ�ȸ��ڵ㣬�������������������
	*/
	void StackPreOrder() const      
	{
		std::stack<const BinaryTreeNode<T> *> stk;
		if (root)
			stk.push(root);
		else
			return;
		const BinaryTreeNode<T> * BTNPoint = NULL;
		while (!stk.empty())
		{
			BTNPoint = stk.top();
			stk.pop();
			std::cout << BTNPoint->getData() << " ";
			if (BTNPoint->getRightPoint())
				stk.push(BTNPoint->getRightPoint());
			if (BTNPoint->getLeftPoint())
				stk.push(BTNPoint->getLeftPoint());
		}
	}
	/* ����stack�Զ����������������
	*
	*/
	void StackInOrder() const
	{
		std::stack<const BinaryTreeNode<T> *> stk;
		if (!root)
			return;
		const BinaryTreeNode<T> * BTNPoint = root;
		while (BTNPoint || !stk.empty())
		{
			if (BTNPoint)
			{
				stk.push(BTNPoint);
				BTNPoint = BTNPoint->getLeftPoint();
			}
			else
			{
				BTNPoint = stk.top();
				stk.pop();
				std::cout << BTNPoint->getData() << " ";
				BTNPoint = BTNPoint->getRightPoint();
			}
		}
	}
	/*
	*  ��������ջ������������� 
	*/
	void StackPostOrder() const
	{
		if (!root)
			return;
		std::stack<const BinaryTreeNode<T> *> stk1, stk2;
		stk1.push(root);
		const BinaryTreeNode<T> *BTNPoint = NULL;
		while (!stk1.empty())
		{
			BTNPoint = stk1.top();
			stk1.pop();
			stk2.push(BTNPoint);
			if (BTNPoint->getLeftPoint() != NULL)
				stk1.push(BTNPoint->getLeftPoint());
			if (BTNPoint->getRightPoint() != NULL)
				stk1.push(BTNPoint->getRightPoint());
		}
		while (!stk2.empty())
		{
			std::cout << (stk2.top())->getData() << " ";
			stk2.pop();
		}
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

#endif // !BINARYTREE