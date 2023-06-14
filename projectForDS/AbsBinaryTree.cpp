#include"AbsBinaryTree.h"
template<class T>
inline AbsBinaryTree<T>::AbsBinaryTree()
{	
	this->head = new BinaryTreeNode<T>;
}

template<class T>
AbsBinaryTree<T>::~AbsBinaryTree()
{
	deleteTree(this->head);
}

template<class T>
void AbsBinaryTree<T>::deleteTree(BinaryTreeNode<T>* Nodehead)
{	
	queue<BinaryTreeNode<T>*> q;
	q.push(Nodehead);
	while (!q.empty()) {
		BinaryTreeNode<T>* temp = q.front();
		if (temp->left != nullptr) {
			q.push(temp->left);
		}
		if (temp->right != nullptr) {
			q.push(temp->right);
		}
		delete temp;
		q.pop();
	}
}
template<class T>
void AbsBinaryTree<T>::InitTree()
{
	queue<BinaryTreeNode<T>*> q;
	BinaryTreeNode<T>* head = this->head;
	if (!head->val) {
		cout << "head val" << endl;
		cin >> head->val;
	}
	q.push(head);
	while (!q.empty()) {
		InitTreeComponent(q);
		q.pop();
	}
	head->PreOrder(head);
	cout << "\n";
}

template<class T>
BinaryTreeNode<T>* AbsBinaryTree<T>::findParent(BinaryTreeNode<T>* node)
{
	
	return fp(this->head, node);

}

template<class T>
BinaryTreeNode<T>* AbsBinaryTree<T>::findBrother(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* pnode = findParent(node);
	if (pnode == nullptr) return nullptr;
	if (pnode->left == node) return pnode->right;
	else return pnode->left;
}

template<class T>
BinaryTreeNode<T>* AbsBinaryTree<T>::findLeftChildren(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* ans = fn(this->head, node);
	return ans->left;
}

template<class T>
BinaryTreeNode<T>* AbsBinaryTree<T>::findRightChildren(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* ans = fn(this->head, node);
	return ans->right;
}



template<class T>
void AbsBinaryTree<T>::InitTreeComponent(queue<BinaryTreeNode<T>*>& q)
{
	T element;
	BinaryTreeNode<T>* tempHead = q.front();
	cout << "left:";
	cin >> element;
	if (element != -1) {
		BinaryTreeNode<T>* temp = new BinaryTreeNode<T>(element);
		tempHead->left = temp;
		q.push(temp);
	}
	cout << "right:";
	cin >> element;
	if (element != -1) {
		BinaryTreeNode<T>* temp = new BinaryTreeNode<T>(element);
		tempHead->right = temp;
		q.push(temp);
	}
}

template<class T>
BinaryTreeNode<T>* AbsBinaryTree<T>::fp(BinaryTreeNode<T>* head, BinaryTreeNode<T>* node)
{
	if (head == nullptr) return nullptr;
	if (head->left!=nullptr&&head->left->val == node->val) return head;
	if (head->right != nullptr&&head->right->val == node->val) return head;
	auto lan = fp(head->left, node);
	if (lan != nullptr) return lan;
	auto ran = fp(head->right, node);
	if (ran != nullptr) return ran;
	return nullptr;
}

template<class T>
BinaryTreeNode<T>* AbsBinaryTree<T>::fn(BinaryTreeNode<T>* head, BinaryTreeNode<T>* node)
{
	if (head == nullptr) return nullptr;
	if (head->val == node->val) return head;
	auto lan = fn(head->left, node);
	if (lan != nullptr) return lan;
	auto ran = fn(head->right, node);
	if (ran != nullptr) return ran;
	return nullptr;
}
