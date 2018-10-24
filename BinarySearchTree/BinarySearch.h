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
	void setLeft(Node * newLeft)
	{
		left = newLeft;
	}
	void setRight(Node * newRight)
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
	Node<genericType> * root;
public:
	// Methods
	// Constructor
	Tree()
	{
		root = NULL;
	}
	// Insert some data to the tree
	void insert(genericType dataToAdd)
	{
		auto currentNode = root;
		// if no root exists
		if (root == NULL)
		{
			root = new Node<genericType>(dataToAdd);
		}
		// if greater than
		else if (dataToAdd > currentNode->getData())
		{
			if (currentNode->getRight() == nullptr)
			{
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setRight(nodeToAdd);
			}
			else 
			{
				this->insert(currentNode, dataToAdd);
			}
		}
		// if less than
		else if (dataToAdd < currentNode->getData())
		{
			if (currentNode->getLeft() == nullptr)
			{
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setLeft(nodeToAdd);
			}
			else
			{
				this->insert(currentNode->getLeft(), dataToAdd);
			}
		}
		// throw error, because node already exists
		else if (currentNode->getData() == dataToAdd)
		{
			// This should throw an error, because it is already in the table
		}
	}
	void insert(Node<genericType>* currentNode, genericType dataToAdd)
	{
		if (dataToAdd > currentNode->getData())
		{
			if (dataToAdd > currentNode->getData())
			{
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setRight(nodeToAdd);
			}
			else
			{
				insert(currentNode, dataToAdd);
			}
		}
		// if less than
		else if (dataToAdd < currentNode->getData())
		{
			if (currentNode->getLeft() == nullptr)
			{
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setLeft(nodeToAdd);
			}
			else
			{
				insert(currentNode->getLeft(), dataToAdd);
			}
		}
		// throw error, because node already exists
		else if (currentNode->getData() == dataToAdd)
		{
			// This should throw an error, because it is already in the table
		}
	}
	// Delete some data from the tree & Restructure tree accordingly
	Node<genericType>* destroy(Node<genericType>* currentNode, genericType dataToDestroy)
	{
		// 1. Leaf node 
		//    Just delete
		// 2. A node that has both left and right children
		//	  Replace the node with it's predecessor
		// 3. A node that has only one child
		//	  The child replaces the parent
	}
	// Find maximum value in tree
	genericType maximum(Node<genericType>* currentNode)
	{

	}

	// Find data in tree
	genericType find(genericType valueToFind)
	{
		auto currentNode = root;
		if (currentNode == NULL)
		{
			return false;
		}
		else if (currentNode->getData() == valueToFind)
		{
			return currentNode;
		}
		else if (valueToFind < currentNode->getData())
		{
			return(find(currentNode->getLeft(), valueToFind));
		}
		else
		{
			return (find(currentNode->getRight(), valueToFind));
		}
	}
	genericType find(Node<genericType>* currentNode, genericType valueToFind)
	{
		if (currentNode == NULL)
		{
			return false;
		}
		else if(currentNode->getData() == valueToFind)
		{
			return currentNode;
		}
		else if (valueToFind < currentNode->getData())
		{
			return(find(currentNode->getLeft(), valueToFind));
		}
		else
		{
			return (find(currentNode->getRight(), valueToFind));
		}
	}

	// Extra Credit
	// Performance Analysis Testing
	// Self Balancing Tree
};