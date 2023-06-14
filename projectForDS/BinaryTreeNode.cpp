#include"BinaryTreeNode.h"


template<class T>
inline void BinaryTreeNode<T>::PreOrder(BinaryTreeNode<T>* head)
{
	if (head == nullptr) return;

	cout << head->val << " ";
	PreOrder(head->left);
	PreOrder(head->right);

}

template<class T>
void BinaryTreeNode<T>::InOrder(BinaryTreeNode<T>* head)
{
	if (head == nullptr) return;

	InOrder(head->left);
	cout << head->val << " ";
	InOrder(head->right);

}

template<class T>
void BinaryTreeNode<T>::postOrder(BinaryTreeNode<T>* head)
{
	if (head == nullptr)  return;
	postOrder(head->left);
	postOrder(head->right);

	cout << head->val<<" ";

}




