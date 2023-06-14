#pragma once
#include<iostream>
#include"BaseStack.h"
using namespace std;
template<class T>
class MyStack : public BaseStack<T>
{
public:
	MyStack(int Capacity = 5):BaseStack<T>(Capacity){
		
	}
	~MyStack() {
		delete[] this->arr;
	}
	void print() {
		for (int i = 0; i < this->size; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
	int getSize() {
		return this->size - this->base;
	}
	bool isEmpty() const {
		return this->size-this->base == 0;
	}
	void push(const T& element) {
		
		if (this->size >= this->capacity) {
			T* temp = new T[this->capacity*2];
			for (int i = this->base; i < this->size; i++) {
				temp[i] = this->arr[i];
			}
			this->arr = temp;
		}
		this->arr[this->size] = element;
		this->size++;
		
	}
	T GetTop() {
		if (isEmpty()) throw exception();
		return this->arr[this->size - 1];
	}
	T pop() {
		if (isEmpty()) throw exception();
		T temp= this->arr[this->size - 1];
		this->size--;
		return temp;
	}
	T popBase() {
		T* temp = new T[this->size];
		T popedData = this->arr[0];
		for (int i = 1; i < this->size; i++) {
			temp[i-1] = this->arr[i];
		}
		this->arr = temp;
		this->base++;
		return popedData;
	}
	void reCapacity(int newCap) {
		if (this->arr == nullptr) {
			this->arr = new T[newCap];
			this->capacity = newCap;
			this->base = 0;
			this->size = 0;
		}
		else {
			T* temp = new T[newCap];
			for (int i = this->base; i < this->size; i++) {
				temp[i] = this->arr[i];
			}
			this->capacity = newCap;
		}
	}
};

