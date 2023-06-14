#pragma once
#include"BaseQueue.h"
template<class T>
class DNode
{
public:
	DNode() {
		next = nullptr;
		front = nullptr;
	};
	DNode(const T& element) {
		val = element;
		next = nullptr;
		front = nullptr;
	}
	~DNode() {

	};
	T val;
	DNode* next;
	DNode* front;
};
template<class T>
class DoubleQueue
{
public:
	DoubleQueue() {
		head = nullptr;
		End = nullptr;
		Front = nullptr;
		size = 0;
	};

	~DoubleQueue() {
		while (this->Front) {
			DNode<T>* temp = this->Front->next;
			delete this->Front;
			this->Front = temp;
		}
	};

	bool isEmpty() {
		return size == 0;
	}
	void PushHead(const T& element) {
		if (head == nullptr) {
			head = new DNode<T>(element);
			Front = head;
			End = head;
			size++;
			return;
		}
		DNode<T>* newNode = new DNode<T>(element);
		Front->front= newNode;
		newNode->next = Front;
		Front = Front->front;
		size++;
	}
	void PushEnd(const T& element) {
		if (head == nullptr) {
			head = new DNode<T>(element);
			Front = head;
			End = head;
			size++;
			return;
		}
		DNode<T>* newNode = new DNode<T>(element);
		End->next = newNode;
		newNode->front = End;
		End = End->next;
		size++;
	}
	T& PollHead() {
		if (isEmpty()) throw exception();
		DNode<T>* temp = Front;
		Front = Front->next;
		size--;
		return temp->val;
	};
	T& PollEnd() {
		if (isEmpty()) throw exception();
		DNode<T>* temp = End;
		End = End->front;
		size--;
		return temp->val;
	};

	T& GetHead() {
		if (isEmpty()) throw exception();
		return Front->val;
	};
	T& GetEnd() {
		if (isEmpty()) throw exception();
		return End->val;
	};
	int GetSize() {
		return size;
	}
private:
	DNode<T>* head;
	DNode<T>* Front;
	DNode<T>* End;
	int size;
};