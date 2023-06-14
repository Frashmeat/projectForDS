#pragma once
#include<iostream>
#include<Queue>

using namespace std;

template<class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode();
	BinaryTreeNode(T element);
	void PreOrder(BinaryTreeNode<T>* head);
	void InOrder(BinaryTreeNode<T>* head);
	void postOrder(BinaryTreeNode<T>* head);

	BinaryTreeNode* left;
	BinaryTreeNode* right;
	T val;
private:
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode():left(nullptr),right(nullptr),val(0)
{

}

template<class T>
inline BinaryTreeNode<T>::BinaryTreeNode(T element) : left(nullptr), right(nullptr), val(element)
{

}


