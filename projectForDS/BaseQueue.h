#pragma once
#include<iostream>
using namespace std;
namespace baseQueue{
template<class T>
class Node
{
public:
	Node() {
		
	};
	~Node() {
	
	};
	Node* next;
	T val;
};


template<class T>
class BaseQueue
{
public:
	BaseQueue() {
		front = nullptr;
		end = nullptr;
		size = 0;
		cout << "do" << endl;
	};
	~BaseQueue() {
		while (this->front) {
			Node<T>* temp = this->front->next;
			delete this->front;
			this->front = temp;
		}
	};
	virtual bool isEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual T& GetFront() const = 0;
	virtual void push(const T& element) = 0;
	virtual T& poll() = 0;

	Node<T>* front;
	Node<T>* end;
	int size;
};
}
