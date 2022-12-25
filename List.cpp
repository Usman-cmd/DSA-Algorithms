#pragma once
#include<iostream>
using namespace std;
class List
{
private:
	int *arr;
	int maxSize;
	int currentSize;
protected:
	void deepCopy(int *tobecopied, int*&incopy);
public:
	List(int maxSize = 10);
	List(const List &obj);
	void addElement(int val);
	int removeElement();
	void print()const;
	~List();
};
void List::deepCopy(int *tobecopied, int*&incopy)
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
List::List(int maxSize)
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
List::List(const List &obj)
{
	this->maxSize = obj.maxSize;
	this->currentSize = obj.currentSize;
	deepCopy(obj.arr, this->arr);
}
void List::addElement(int val)
{
	if (this->currentSize == this->maxSize - 1)
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
int List::removeElement()
{
	if (this->currentSize == -1)
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
void List::print()const
{
	if (this->currentSize == -1)
		cout << " Array is already empty : " << endl;
	else
	{
		cout << " data in array is : " << endl;
		for (int i = 0; i <= this->currentSize; i++)
			cout << " " << this->arr[i];
		cout << endl;
	}
	
}
List::~List()
{
	if (this->arr != nullptr)
	{
		this->arr = nullptr;
		delete[] this->arr;
	}
}

