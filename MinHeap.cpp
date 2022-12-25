#pragma once
#include<iostream>
using namespace std;
class MinHeap
{
private:
	int size;
	int *arr;
	int count;
	void HeapUp(int child);
	void HeapDown(int parent);
protected:
	void deepCopy(int *tobecopy, int *&incopy, int size);
public:
	MinHeap(int size = 1);
	MinHeap(const MinHeap &obj);
	void display()const;
	void addData(int &data);
	int removeData();
	~MinHeap();
};

void MinHeap::HeapUp(int child)
{
	if (child > 0)
	{
		int parent = (child - 1) / 2;
		if (arr[parent] > arr[child])
		{
			int temp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = temp;
			HeapUp(parent);
		}
	}
}

void MinHeap::HeapDown(int parent)
{
	int last = this->count - 1;
	int leftchild = (parent * 2) + 1;
	int rightChild = (parent * 2) + 2;
	int bigBrother;
	if (leftchild == last)
		bigBrother = leftchild;
	else if (rightChild == last)
		bigBrother = rightChild;
	else
	{
		if (arr[leftchild] > arr[rightChild])
			bigBrother = leftchild;
		else
			bigBrother = rightChild;
	}
	if (arr[bigBrother] > arr[parent])
	{
		int temp = arr[bigBrother];
		arr[bigBrother] = arr[parent];
		arr[parent] = temp;
		HeapDown(bigBrother);
	}
}

void MinHeap::addData(int &data)
{
	if (this->count == this->size)
		cout << " Heap is already Full : " << endl;
	else
	{
		arr[count] = data;
		HeapUp(count);
		count++;
	}
}

int MinHeap::removeData()
{
	if (count == 0)
	{
		cout << " Heap is already empty : " << endl;
		return NULL;
	}
	else
	{
		int temp = arr[0];
		arr[0] = arr[count - 1];
		count--;
		HeapDown(0);
		return temp;
	}
}

void MinHeap::display()const
{
	if (count == 0)
		cout << " Heap is empty : " << endl;
	else
	{
		cout << " Required data is : " << endl;
		for (int i = 0; i < count; i++)
			cout << " " << arr[i];
		cout << endl;
	}
}

void MinHeap::deepCopy(int *tobecopy, int *&incopy, int size)
{
	if (incopy != nullptr)
	{
		delete incopy;
		incopy = new int[size]();
	}
	for (int i = 0; i < size; i++)
		incopy[i] = tobecopy[i];
}

MinHeap::MinHeap(int size)
{
	this->count = 0;
	this->size = size;
	this->arr = new int[size]();
}

MinHeap::MinHeap(const MinHeap &obj)
{
	this->count = obj.count;
	this->size = obj.size;
	deepCopy(obj.arr, this->arr, obj.size);
}

MinHeap::~MinHeap()
{
	delete[] this->arr;
}
