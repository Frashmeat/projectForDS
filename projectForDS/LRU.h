#pragma once
#include<iostream>
#include"ChainList.h"
using namespace std;
using namespace chainList;
class LRU
{
public:
	LRU(int Capacity = 5) {
		this->Capacity = Capacity;
	};
	~LRU() {
		chainList::Node* temp = memory.head;
		while (temp) {
			chainList::Node* tempH = temp->next;
			delete temp;
			temp = tempH;
		}
	}
	void save(int val) {
		if (memory.getSize() >= Capacity) {
			memory.pop();
			chainList::Node* newNode = new chainList::Node(val);
			memory.insertFront(newNode);
			return;
		}
		chainList::Node* newNode = new chainList::Node(val);
		memory.insertFront(newNode);
	};
	void pop() {
		memory.pop();
	};
	chainList::Node* get(int val) {
		if (memory.getNode(val) != nullptr) {
			chainList::Node* res = memory.pop(val);
			memory.insertFront(res);
			return res;
		}
		return nullptr;
	};
	void print() {
		chainList::Node* temp = memory.head;
		while (temp) {
			cout << temp->val << ' ';
			temp = temp->next;
		}
		cout << '\n';
	}
private:
	ChainList memory;
	int Capacity;
};
