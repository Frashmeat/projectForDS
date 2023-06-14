#pragma once
#include<iostream>
using namespace std;
template<class T>
class BaseStack
{
public:
	BaseStack() {
		capacity = 0;
		base = 0;
		size = 0;
	}
	BaseStack(int Capacity) {
		this->arr = new T[Capacity];
		this->capacity = Capacity;
		base = 0;
		size = 0;
		//cout << "do" << endl;
	}
	virtual bool isEmpty() const = 0;
	virtual void push(const T& element) = 0;
	virtual T GetTop() = 0;
	virtual T pop() = 0;
	T* arr;
protected:
	
	int base;
	int size;
	int capacity;
};