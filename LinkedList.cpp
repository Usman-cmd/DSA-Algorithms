#pragma once
#include"Node.h"
class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	LinkedList(const LinkedList &obj);
	int headValue();
	int tailValue();
	void insertAtHead(int val);
	void insertAtTail(int val);
	void removeFromHead();
	void removeFromTail();
	bool empty();
	int size();
	void getLastNode(Node *&ptr);
	void display();
	~LinkedList();
};
LinkedList::LinkedList()
{
	this->head = nullptr;
}
LinkedList::LinkedList(const LinkedList &obj)
{
	this->head = obj.head;
}
int LinkedList::headValue()
{
	return this->head->data;
}
int LinkedList::tailValue()
{
	Node *temp = this->head;
	getLastNode(temp);
	return temp->data;
}
void LinkedList::insertAtHead(int val)
{
	Node *node = new Node(val);
	node->next = head;
	head = node;
}
void LinkedList::insertAtTail(int val)
{
	Node *node = new Node(val);
	if (head == nullptr)
		head = node;
	else
	{
		Node *temp = head;
		getLastNode(temp);
		temp->next = node;
	}
}
void LinkedList::removeFromHead()
{
	if (empty())
	{
		cout << " Linked List is already empty : " << endl;
		return;
	}
	else
	{
		if (head->next == nullptr)
			head = nullptr;
		else
		{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}
}
void LinkedList::removeFromTail()
{
	if (empty())
	{
		cout << " Linked List is already empty : " << endl;
		return;
	}
	else
	{
		if (head->next == nullptr)
			head = nullptr;
		else
		{
			Node *temp = head;
			while (temp->next->next != nullptr)
				temp = temp->next;
			delete temp->next;
			temp->next = nullptr;
		}
	}
}
bool LinkedList::empty()
{
	if (head == nullptr)
		return true;
	else 
		return false;
}
int LinkedList::size()
{
	int len = 0;
	if (head != nullptr)
	{
		Node *temp = head;
		len = 1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			len++;
		}
	}
	return len;
}
void LinkedList::getLastNode(Node *&ptr)
{
	while (ptr->next != nullptr)
		ptr = ptr->next;
}
void LinkedList::display()
{
	if (empty())
	{
		cout << " Linked List is already empty : " << endl;
		return;
	}
	else
	{
		cout << " Required data is : " << endl;
		Node *temp = head;
		while (temp != nullptr)
		{
			cout << " " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
}
LinkedList::~LinkedList()
{
	Node *temp = head;
	Node *previous = nullptr;
	while (temp != nullptr)
	{
		previous = temp;
		temp = temp->next;
		delete previous;
	}
}
