#pragma once
#include<iostream>
namespace chainList {
	class Node
	{
	public:
		Node() {
			next = nullptr;
			front = nullptr;
			val = 0;
		};
		Node(int val) {
			next = nullptr;
			front = nullptr;
			this->val = val;
		}
		~Node() {

		};
		bool operator==(const Node& other) {
			return other.val == this->val;
		}

		Node* next;
		Node* front;
		int val;
	};


	class ChainList
	{
	public:
		ChainList() {

		}
		void insertBack(Node* newNode) {
			if (head == nullptr) {
				head = newNode;
				newNode->front = head;
				size++;
			}
			else {
				Node* temp = head;
				while (temp->next != nullptr) {
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->front = temp;
				newNode->next = nullptr;
				size++;
			}
		};
		void insertFront(Node* newNode) {
			if (head == nullptr) {
				head = newNode;
				size++;
			}
			else {
				newNode->next = head;
				newNode->front = nullptr;
				head->front = newNode;
				head = newNode;
				size++;
			}
		}
		void pop() {
			if (head == nullptr) return;
			else {
				Node* temp = head;
				while (temp->next->next != nullptr) {
					temp = temp->next;
				}
				temp->next = nullptr;
				size--;
			}
		};
		Node* pop(int val) {
			if (head == nullptr) return nullptr;
			else {
				Node* temp = head;
				while (temp->next != nullptr) {
					if (temp->next->val == val) {
						Node* poped = temp->next;
						temp->next = temp->next->next;
						size--;
						return poped;
					}
					temp = temp->next;
				}
			}
		}
		Node* getNode(const Node* node) {
			Node* temp = head;
			while (temp) {
				if (*temp == *node) {
					return temp;
				}
				temp = temp->next;
			}
			return nullptr;
		};
		Node* getNode(int val) {
			Node* temp = head;
			while (temp) {
				if (val == temp->val) {
					return temp;
				}
				temp = temp->next;
			}
			return nullptr;
		};
		int getSize() {
			return size;
		}

		void print() {
			Node* temp = head;
			while (temp) {
				std::cout << temp->val << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
		Node* head;
	private:
		int size = 0;
	};
}


