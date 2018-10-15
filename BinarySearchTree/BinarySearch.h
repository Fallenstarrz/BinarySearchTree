#pragma once
#include <memory>

// Class for nodes
template <typename genericType>
class Node
{
private:
	// Attributes
	genericType data;
	Node* left = NULL;
	Node* right = NULL;
public:
	// Methods
	// Constructors
	Node()
	{

	}
	Node(genericType key)
	{
		data = key;
	}

	// Deconstructors
	~Node()
	{
		left = NULL;
		right = NULL;
	}

	// Getters
	Node * getLeft()
	{
		return left;
	}
	Node * getRight()
	{
		return right;
	}
	genericType getData()
	{
		return data;
	}
	// Setters
	void setLeft(Node & newLeft)
	{
		left = newLeft;
	}
	void setRight(Node & newRight)
	{
		right = newRight;
	}
	void setData(genericType newData)
	{
		data = newData;
	}
};

// Class for the tree itself
template <typename genericType>
class Tree
{
private:
	// Attributes
	Node * root;
public:
	// Methods
	// Constructor
	Tree()
	{
		root = NULL;
	}
	// Insert some data to the tree
	Node* insert(Node* currentNode, genericType dataToAdd)
	{
		if (root == NULL)
		{
			root = new Node(dataToAdd)
		}
		if (currentNode == NULL)
		{
			currentNode = new Node(dataToAdd)
		}
		if (dataToAdd < currentNode->data)
		{
			insert(currentNode->left, dataToAdd)
		}
		if (dataToAdd > currentNode->data)
		{
			insert(currentNode->right, dataToAdd)
		}
	}
	// Delete some data from the tree & Restructure tree accordingly
	Node* destroy(Node* currentNode, genericType dataToDestroy)
	{
		// 1. Leaf node 
		//    Just delete
		// 2. A node that has both left and right children
		//	  Replace the node with it's predecessor
		// 3. A node that has only one child
		//	  The child replaces the parent
	}
	// Find maximum value in tree
	genericType maximum(Node* currentNode)
	{

	}

	Node* createNewNode(genericType dataToAdd)
	{
		
	}

	// Find data in tree
	genericType find(Node* currentNode, genericType valueToFind)
	{
		if (currentNode == NULL)
		{
			return false;
		}
		else if(currentNode->data == valueToFind)
		{
			return currentNode;
		}
		else if (valueToFind < currentNode->data)
		{
			return(find(currentNode->left, valueToFind));
		}
		else
		{
			return (find(currentNode->right, valueToFind));
		}
	}

	// Extra Credit
	// Performance Analysis Testing
	// Self Balancing Tree
};