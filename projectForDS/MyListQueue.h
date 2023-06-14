#pragma once
#include"BaseQueue.h"
using namespace baseQueue;
template<class T>
class MyListQueue : public BaseQueue<T>
{
public:
	MyListQueue() {
	};
	~MyListQueue() {
	};
	bool isEmpty() const {
		return this->size == 0;
	}
	int GetSize() const {
		return this->size;
	}
	T& GetFront() const {
		if (isEmpty()) throw exception();
		return this->front->val;
	}
	void push(const T& element) {
		if (!this->front) {
			this->front = new baseQueue::Node<T>();
			this->front->val = element;
			this->end = this->front;
			this->size++;
		}
		else {
			baseQueue::Node<T>* newNode = new  baseQueue::Node<T>();
			newNode->val = element;
			this->end->next = newNode;
			this->end = this->end->next;
			this->size++;
		}
		
	}
	T& poll() {
		if (isEmpty()) throw exception();
		baseQueue::Node<T>* temp = this->front;
		this->front = this->front->next;
		this->size--;
		return temp->val;
	}
	void print() {
		baseQueue::Node<T>* t = this->front;
		while (t) {
			cout << t->val << " ";
			t = t->next;
		}
		cout << endl;
	}
};
