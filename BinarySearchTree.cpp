#pragma once
#include"Node.h"
class BinarySearchTree
{
private:
	Node *root;
	bool insertion(Node *root, int value);
	void DeleteTree(Node* root);
public:
	BinarySearchTree(Node *root = nullptr);
	BinarySearchTree(const BinarySearchTree &obj);
	void insertion(int value);
	void deleteTree();
	~BinarySearchTree();
};
bool BinarySearchTree::insertion(Node *root, int value)
{
	if (value < root->data)
	{
		if (root->left == nullptr)
		{
			Node *leaf = new Node(value);
			root->left = leaf;
		}
		else
		{
			bool temp = insertion(root->left, value);
			return temp;
		}
		return true;
	}
	else if (value>root->data)
	{
		if (root->right == nullptr)
		{
			Node *leaf = new Node(value);
			root->right = leaf;
		}
		else
		{
			bool temp = insertion(root->right, value);
			return temp;
		}
			
		return true;
	}
	else
	{
		cout << " Duplications are not allowed : " << endl;
		return false;
	}
}
BinarySearchTree::BinarySearchTree(Node *root)
{
	this->root = root;
}
BinarySearchTree::BinarySearchTree(const BinarySearchTree &obj)
{
	this->root = obj.root;
}
void BinarySearchTree::DeleteTree(Node* root)
{
	if (root != nullptr)
	{
		this->DeleteTree(root->left);
		this->DeleteTree(root->right);
		delete root;
	}
}
void BinarySearchTree::deleteTree()
{
	this->DeleteTree(this->root);
}
BinarySearchTree::~BinarySearchTree()
{
	this->deleteTree();
}
void BinarySearchTree::insertion(int value)
{
	if (this->root == nullptr)
	{
		Node *leaf = new Node(value);
		this->root = leaf;
	}
	else
	{
		bool temp = insertion(this->root, value);
		while (temp == false)
		{
			int data = 0;
			cout << " Enter another data you wants to insert in tree : ", cin >> data;
			temp = insertion(this->root, data);
		}
	}
}