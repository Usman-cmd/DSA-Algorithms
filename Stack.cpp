#pragma once
#include<iostream>
using namespace std;
class Stack
{
private:
	int *arr;
	int maxSize;
	int currentSize;
protected:
	void deepCopy(int *tobecopied, int*&incopy);
public:
	Stack(int maxSize = 10);
	Stack(const Stack &obj);
	~Stack();
	bool empty();
	bool full();
	int size();
	int top();
	void push(int val);
	int pop();
	void showStack();
};
void Stack::deepCopy(int *tobecopied, int*&incopy)
{
	if (incopy != nullptr)
	{
		delete[] incopy;
		incopy = nullptr;
	}
	incopy = new int[maxSize]();
	for (int i = 0; i < maxSize; i++)
		tobecopied[i] = incopy[i];
}
Stack::Stack(int maxSize)
{
	this->maxSize = maxSize;
	this->currentSize = -1;
	if (this->arr != nullptr)
	{
		delete[]this->arr;
		this->arr = nullptr;
	}
	this->arr = new int[this->maxSize]();
}
Stack::Stack(const Stack &obj)
{
	this->maxSize = obj.maxSize;
	this->currentSize = obj.currentSize;
	deepCopy(obj.arr, this->arr);
}
bool Stack::empty()
{
	if (this->currentSize == -1)
		return true;
	else
		return false;
}
bool Stack::full()
{
	if (this->currentSize == this->maxSize - 1)
		return true;
	else
		return false;
}
int Stack::size()
{
	return this->maxSize;
}
int Stack::top()
{
	if (empty())
	{
		cout << " Stack is empty you are not able to receive data from it : " << endl;
		return -100;
	}
	else
		return this->arr[this->currentSize];
}
void Stack::push(int val)
{
	if (full())
	{
		cout << " Array is full : " << endl;
		cout << " You are not able to upload data in array : " << endl;
	}
	else
	{
		this->currentSize++;
		this->arr[this->currentSize] = val;
	}
}
int Stack::pop()
{
	if (empty())
	{
		cout << " Array is already empty : " << endl;
		return -100;
	}
	else
	{
		int temp = this->arr[this->currentSize];
		this->arr[this->currentSize] = -1;
		this->currentSize--;
		return temp;
	}
}
void Stack::showStack()
{
	if (empty())
		cout << " Stack is already empty : " << endl;
	else
	{
		cout << " data in Stack is : " << endl;
		for (int i = 0; i <= this->currentSize; i++)
			cout << " " << this->arr[i];
		cout << endl;
	}
}
Stack::~Stack()
{
	if (this->arr != nullptr)
	{
		this->arr = nullptr;
		delete[] this->arr;
	}
}
