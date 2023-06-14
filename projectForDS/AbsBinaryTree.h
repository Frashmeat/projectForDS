#pragma once
//#include"BinaryTreeNode.h"
#include"BinaryTreeNode.cpp"
template<class T>
class AbsBinaryTree
{
public:
	AbsBinaryTree();
	~AbsBinaryTree();
	void InitTree();
	BinaryTreeNode<T>* findParent(BinaryTreeNode<T>* node);
	BinaryTreeNode<T>* findBrother(BinaryTreeNode<T>* node);
	BinaryTreeNode<T>* findLeftChildren(BinaryTreeNode<T>* node);
	BinaryTreeNode<T>* findRightChildren(BinaryTreeNode<T>* node);
	BinaryTreeNode<T>* getHead() {
		return this->head;
	};
private:
	void deleteTree(BinaryTreeNode<T>* head);
	void InitTreeComponent(queue<BinaryTreeNode<T>*>& q);
	BinaryTreeNode<T>* fp(BinaryTreeNode<T>* head, BinaryTreeNode<T>* node);
	BinaryTreeNode<T>* fn(BinaryTreeNode<T>* head, BinaryTreeNode<T>* node);
	//BinaryTreeNode<T>* frc(BinaryTreeNode<T>* head, BinaryTreeNode<T>* node);
	
	BinaryTreeNode<T>* head;
};
