#pragma once
#include"Node.h"
class DoublyLinkedList
{
private:
	Node *head;
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList &obj);
	int headValue();
	int tailValue();
	void insertAtHead(int val);
	void insertAtTail(int val);
	void insertatindex(int index, int val);
	void sortedInsert(int val);
	bool empty();
	int size();
	void display();
	void getLastNode(Node *&ptr);
	~DoublyLinkedList();
};
DoublyLinkedList::DoublyLinkedList()
{
	this->head = nullptr;
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &obj)
{
	this->head = obj.head;
}
int DoublyLinkedList::headValue()
{
	return this->head->data;
}
int DoublyLinkedList::tailValue()
{
	Node *temp = this->head;
	getLastNode(temp);
	return temp->data;
}
void DoublyLinkedList::insertAtHead(int val)
{
	Node *node = new Node(val);
	node->next = head;
	head = node;
}
void DoublyLinkedList::insertAtTail(int val)
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
void DoublyLinkedList::insertatindex(int index, int val)
{
	if (index > size() || index < 0)
		cout << " Index doesnt exist : " << endl;
	else
	{
		if (index == 0)
			this->insertAtHead(val);
		else if (index == size())
			this->insertAtTail(val);
		else
		{
			Node *node = new Node(val);
			Node *temp = this->head;
			for (int i = 0; i < index-1; i++)
			{
				temp = temp->next;
				if (temp->next == nullptr)
					break;
			}	
			node->next = temp->next;
			temp->next = node;
			node->next->previous = node;
			node->previous = temp;
		}
	}
}
void DoublyLinkedList::sortedInsert(int val)
{
	Node *node = new Node(val);
	if (empty())
		this->head  = node;
	else
	{
		Node *temp = this->head;
		Node *last = this->head;
		while (temp != nullptr)
		{
			if (temp->data > val)
				break;
			temp = temp->next;
		}
		if (this->head == temp)
		{
			node->next = this->head;
			this->head->previous = node;
			this->head = node;
		}
		else if (last == temp)
		{
			last->next = node;
			node->previous = last;
		}
		else
		{
			temp->previous->next = node;
			node->previous = temp->previous;
			temp->previous = node;
			node->next = temp;
			
		}
	}
}
bool DoublyLinkedList::empty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}
int DoublyLinkedList::size()
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
void DoublyLinkedList::getLastNode(Node *&ptr)
{
	while (ptr->next != nullptr)
		ptr = ptr->next;
}
void DoublyLinkedList::display()
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
DoublyLinkedList::~DoublyLinkedList()
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
