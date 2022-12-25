#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int num = 0);
	Node(const Node&obj);
	~Node();
};
Node::Node(int num)
{
	this->data = num;
	this->next = nullptr;
}

Node::Node(const Node&obj)
{
	this->data = obj.data;
	this->next = obj.next;
}
Node::~Node()
{
	cout << " Destructor of node is called : " << endl;
}
