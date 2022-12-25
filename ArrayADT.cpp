#pragma once
#include<iostream>
using namespace std;
class ArrayADT
{
private:
	int *arr;
	int capacity;
	int currentSize;
protected:
	void deepCopy(int *&inCopy, int *tobeCopied,int capacity, int currentSize);
public:
	ArrayADT(int capacity = 1);
	ArrayADT(const ArrayADT&obj);
	void insertElementAtEnd(int value);
	void insertElementAtStart(int value);
	int removeElementFromEnd();
	bool search(int value)const;
	bool update(int num, int location);
	void display()const;
	~ArrayADT();
};
void ArrayADT::deepCopy(int *&inCopy, int *tobeCopied, int capacity, int currentSize)
{
	if (inCopy != nullptr)
	{
		delete[]inCopy;
		inCopy = nullptr;
	}
	inCopy = new int[capacity]();
	for (int i = 0; i < currentSize; i++)
		inCopy[i] = tobeCopied[i];
}
ArrayADT::ArrayADT(int capacity)
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
	this->arr = new int[capacity]();
	this->capacity = capacity;
	this->currentSize = 0;
}
ArrayADT::ArrayADT(const ArrayADT&obj)
{
	deepCopy(this->arr, obj.arr,obj.capacity,obj.currentSize);
	this->capacity = obj.capacity;
	this->currentSize = obj.currentSize;
}
void ArrayADT::insertElementAtEnd(int value)
{
	this->arr[currentSize] = value;
	this->currentSize++;
}
void ArrayADT::insertElementAtStart(int value)
{
	for (int i = 0; i < currentSize; i++)
		this->arr[i + 1] = this->arr[i];
	this->arr[0] = value;
	this->currentSize++;
}
int ArrayADT::removeElementFromEnd()
{
	if (this->currentSize != 0)
	{
		int temp = this->arr[this->currentSize-1];
		this->arr[this->currentSize] = 0;
		this->currentSize--;
		return temp;
	}
	else
		return -1;

}
bool ArrayADT::search(int value)const
{
	for (int i = 0; i < this->currentSize; i++)
	{
		if (this->arr[i] == value)
			return true;
	}
	return false;
}
bool ArrayADT::update(int num, int location)
{
	if (location>this->capacity && location > this->currentSize)
	{
		cout << " Sorry we are unable to update array : " << endl;
		return false;
	}
	else
	{
		this->arr[location] = num;
		return true;
	}
}
void ArrayADT::display()const
{
	if (this->currentSize > 0)
	{
		cout << " Data in array is : " << endl;
		for (int i = 0; i < this->currentSize; i++)
			cout << " " << arr[i];
		cout << endl;
	}
	else
		cout << " Array is already empty : " << endl;
}
ArrayADT::~ArrayADT()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
}