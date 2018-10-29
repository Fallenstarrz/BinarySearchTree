#pragma once
#include <memory>

// Class for nodes
template <typename genericType>
class Node
{
private:
	// Attributes
	genericType data;
	Node* left = nullptr;
	Node* right = nullptr;
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
		data = NULL;
		left = nullptr;
		right = nullptr;
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
	// Constructor
	Tree()
	{
		root = nullptr;
	}

	// Methods

	// insert Overload 1
	// Insert some data to the tree
	void insert(genericType dataToAdd)
	{
		// start at root
		Node<genericType>* currentNode = root;
		// if no root exists
		if (root == nullptr)
		{
			// create a new node to store in root if no root exists
			root = new Node<genericType>(dataToAdd);
		}
		// if greater than
		else if (dataToAdd > currentNode->getData())
		{
			// check if right of currentNode is null
			if (currentNode->getRight() == nullptr)
			{
				// if it is null create a new node and set currentNode's right to that node
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setRight(nodeToAdd);
			}
			// if currentNode is not null
			else 
			{
				// recurse down the tree, sending currentNode's right as a parameter and dataToAdd as the other
				insert(currentNode->getRight(), dataToAdd);
			}
		}
		// if less than
		else if (dataToAdd < currentNode->getData())
		{
			// if currentNode's left is null
			if (currentNode->getLeft() == nullptr)
			{
				// create a node and set currentNode's left pointer to it
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setLeft(nodeToAdd);
			}
			// if currentNode's left isn't null
			else
			{
				// recurse down the tree, sending currentNode's left as a parameter and dataToAdd as the other
				insert(currentNode->getLeft(), dataToAdd);
			}
		}
	}
	// insert Overload 2
	// Insert some data to the tree
	void insert(Node<genericType>* currentNode, genericType dataToAdd)
	{
		// if greater than
		if (dataToAdd > currentNode->getData())
		{
			// check if right of currentNode is null
			if (currentNode->getRight() == nullptr)
			{
				// if it is null create a new node and set currentNode's right to that node
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setRight(nodeToAdd);
			}
			// if currentNode is not null
			else
			{
				// recurse down the tree, sending currentNode's right as a parameter and dataToAdd as the other
				insert(currentNode->getRight(), dataToAdd);
			}
		}
		// if less than
		else if (dataToAdd < currentNode->getData())
		{
			// if currentNode's left is null
			if (currentNode->getLeft() == nullptr)
			{
				// create a node and set currentNode's left pointer to it
				Node<genericType>* nodeToAdd = new Node <genericType>(dataToAdd);
				currentNode->setLeft(nodeToAdd);
			}
			// if currentNode's left isn't null
			else
			{
				// recurse down the tree, sending currentNode's left as a parameter and dataToAdd as the other
				insert(currentNode->getLeft(), dataToAdd);
			}
		}
	}

	// Function to delete values from the tree. Accepts 1 parameter and deletes it then reconstructs the tree, to prevent data loss.
	void destroy(genericType dataToDestroy)
	{
		Node<genericType>* nodeToDelete = this->find(dataToDestroy);
		Node<genericType>* nodeToDeleteParent = this->findParent(dataToDestroy);

		// As long as we don't try to delete a nullptr
		if (nodeToDelete != nullptr)
		{
			// No child
			if (nodeToDelete->getRight() == nullptr && nodeToDelete->getLeft() == nullptr)
			{
				if (nodeToDelete->getData() > nodeToDeleteParent->getData())
				{
					nodeToDeleteParent->setRight(nullptr);
				}
				else if (nodeToDelete->getData() < nodeToDeleteParent->getData())
				{
					nodeToDeleteParent->setLeft(nullptr);
				}
				delete nodeToDelete;
			}
			// if 2 children
			else if (nodeToDelete->getRight() != nullptr && nodeToDelete->getLeft() != nullptr)
			{
				Node<genericType>* replacement = this->minimum(nodeToDelete->getRight());
				Node<genericType>* replacementParent = this->findParent(replacement->getData());
				if (nodeToDelete->getData() <= root->getData())
				{
					if (replacement->getData() > replacementParent->getData())
					{
						// because replacement is on the right, my parents right is now open when replacement is deleted
						// fill that void with anything on the right side of replacement.
						replacementParent->setRight(replacement->getRight());
					}
					else if (replacement->getData() < replacementParent->getData())
					{
						// because replacement is on the left, my parents left is now open when replacement is deleted
						// fill that void with anything on the left side of replacement.
						replacementParent->setLeft(replacement->getLeft());
					}
				}
				else if (nodeToDelete->getData() > root->getData())
				{
					if (replacement->getData() > replacementParent->getData())
					{
						// because replacement is on the right, my parents right is now open when replacement is deleted
						// fill that void with anything on the right side of replacement.
						replacementParent->setRight(replacement->getRight());
					}
					else if (replacement->getData() < replacementParent->getData())
					{
						// because replacement is on the left, my parents left is now open when replacement is deleted
						// fill that void with anything on the left side of replacement.
						replacementParent->setLeft(replacement->getLeft());
					}
				}

				nodeToDelete->setData(replacement->getData());
				delete replacement;
			}
			// if 1 child
			else
			{
				// If nodeToDelete's left isn't empty
				if (nodeToDelete->getLeft() != nullptr)
				{
					if (nodeToDelete == root)
					{
						root = nodeToDelete->getLeft();
					}
					// check if the nodeToDelete was on the left side of the parent
					if (nodeToDeleteParent->getLeft()->getData() == dataToDestroy)
					{
						// if it was on the left, set the parents node to the none-empty side of the node we are about to delete
						nodeToDeleteParent->setLeft(nodeToDelete->getLeft());
					}
					// check if the nodeToDelete was on the right side of the parent
					else
					{
						// if it was on the right, set the parents node to the none-empty side of the node we are about to delete
						nodeToDeleteParent->setRight(nodeToDelete->getLeft());
					}
				}
				// If nodeToDelete's Right side isn't empty
				else if (nodeToDelete->getRight() != nullptr)
				{
					if (nodeToDelete == root)
					{
						root = nodeToDelete->getLeft();
					}
					// check if the nodeToDelete was on the left side of the parent
					else if (nodeToDeleteParent->getLeft()->getData() == dataToDestroy)
					{
						// if it was on the left, set the parents node to the none-empty side of the node we are about to delete
						nodeToDeleteParent->setLeft(nodeToDelete->getRight());
					}
					// check if the nodeToDelete was on the right side of the parent
					else
					{
						// if it was on the right, set the parents node to the none-empty side of the node we are about to delete
						nodeToDeleteParent->setRight(nodeToDelete->getRight());
					}
				}
				delete nodeToDelete;
			}
		}
	}

	// find() overload1
	// Find data in tree
	Node <genericType>* find(genericType valueToFind)
	{
		// Start at root
		Node<genericType>* currentNode = root;
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if value to find belongs to currentNode, return currentNode
		if (valueToFind == currentNode->getData())
		{
			return currentNode;
		}
		// check if valueToFind is greater than the currentNode's data
		else if (valueToFind > currentNode->getData())
		{
			// check is the rightside is null, if it is we return nullptr
			if (currentNode->getRight() == nullptr)
			{
				// NOT FOUND
				return nullptr;
			}
			// if right is not node null, we recurse down the tree using the right as our next node to check
			else
			{
				// recurse down the tree passing valueToFind and the greater than node from the current node as parameters
				find(currentNode->getRight(), valueToFind);
			}
		}
		// check if the valueToFind is less than the currentNode's data
		else if (valueToFind < currentNode->getData())
		{
			// check is the leftside null, if it is we return nullptr
			if (currentNode->getLeft() == nullptr)
			{
				// NOT FOUND
				return nullptr;
			}
			// if left side node is not null recurse down the tree using left as our next node to check
			else
			{
				// recurse down the tree passing valueToFind and the lesser than node from the currentNode as parameters
				find(currentNode->getLeft(), valueToFind);
			}
		}
	}

	// find() overload 2
	// This function takes a node pointer as a parameter in addition to the same valueToFind from overload 1.
	Node <genericType>* find(Node<genericType>* currentNode, genericType valueToFind)
	{
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if value to find belongs to currentNode, return currentNode
		if (valueToFind == currentNode->getData())
		{
			return currentNode;
		}
		// check if valueToFind is greater than the currentNode's data
		else if (valueToFind > currentNode->getData())
		{
			// check is the rightside is null, if it is we return nullptr
			if (currentNode->getRight() == nullptr)
			{
				// NOT FOUND
				return nullptr;
			}
			// if right is not node null, we recurse down the tree using the right as our next node to check
			else
			{
				// recurse down the tree passing valueToFind and the greater than node from the current node as parameters
				find(currentNode->getRight(), valueToFind);
			}
		}
		// check if the valueToFind is less than the currentNode's data
		else if (valueToFind < currentNode->getData())
		{
			// check is the leftside null, if it is we return nullptr
			if (currentNode->getLeft() == nullptr)
			{
				// NOT FOUND
				return nullptr;
			}
			// if left side node is not null recurse down the tree using left as our next node to check
			else
			{
				// recurse down the tree passing valueToFind and the lesser than node from the currentNode as parameters
				find(currentNode->getLeft(), valueToFind);
			}
		}
	}

	// findParent overload 1
	// This function will find the parent of the node holding the value you pass in as a parameter
	Node <genericType>* findParent(genericType valueToFind)
	{
		// start at root
		Node<genericType>* currentNode = root;
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// If currentNode's data is the data to find, then return root, because this is the root.
		if (currentNode->getData() == valueToFind)
		{
			return currentNode;
		}
		// if valueToFind is greater than the currentNode's data
		if (valueToFind > currentNode->getData())
		{
			// check if the right node is null
			if (currentNode->getRight() != nullptr)
			{
				// if the right node isn't null
				// check to see if the current node's right node's data is the value we are looking for
				if (currentNode->getRight()->getData() == valueToFind)
				{
					return currentNode;
				}
				// if it isn't the value we are looking for, recurse down the tree
				else
				{
					// send currentNode's right as a parameter and the valueToFind as the other parameter
					findParent(currentNode->getRight(), valueToFind);
				}
			}
		}
		// if valueToFind it less than the currentNode's data
		else if (valueToFind < currentNode->getData())
		{
			// check if left node is null
			if (currentNode->getLeft() != nullptr)
			{
				// if left node isn't null
				// check to see if the current node's left node's data is the value we are looking for
				if (currentNode->getLeft()->getData() == valueToFind)
				{
					return currentNode;
				}
				// if it isn't the value we are looking for, recurse down the tree
				else
				{
					// send currentNode's left as a parameter and the valueToFind as the other parameter
					findParent(currentNode->getLeft(), valueToFind);
				}
			}
		}
	}

	// findParent Overload 2
	// This function will find the parent of the node that holds the value we are looking for.
	Node <genericType>* findParent(Node<genericType>* currentNode, genericType valueToFind)
	{
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if valueToFind is greater than the currentNode's data
		if (valueToFind > currentNode->getData())
		{
			// check if the right node is null
			if (currentNode->getRight() != nullptr)
			{
				// if the right node isn't null
				// check to see if the current node's right node's data is the value we are looking for
				if (currentNode->getRight()->getData() == valueToFind)
				{
					return currentNode;
				}
				// if it isn't the value we are looking for, recurse down the tree
				else
				{
					// send currentNode's right as a parameter and the valueToFind as the other parameter
					findParent(currentNode->getRight(), valueToFind);
				}
			}
		}
		// if valueToFind it less than the currentNode's data
		else if (valueToFind < currentNode->getData())
		{
			// check if left node is null
			if (currentNode->getLeft() != nullptr)
			{
				// if left node isn't null
				// check to see if the current node's left node's data is the value we are looking for
				if (currentNode->getLeft()->getData() == valueToFind)
				{
					return currentNode;
				}
				// if it isn't the value we are looking for, recurse down the tree
				else
				{
					// send currentNode's left as a parameter and the valueToFind as the other parameter
					findParent(currentNode->getLeft(), valueToFind);
				}
			}
		}
	}

	// Maximum Overload 1
	// Find maximum value in tree
	Node<genericType>* maximum()
	{
		// start at root
		Node<genericType>* currentNode = root;
		// if currentNode is nullptr, tree is empty
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if currentNode's right is null
		if (currentNode->getRight() == nullptr)
		{
			// return currentNode, because it doesn't get any larger
			return currentNode;
		}
		// if currentNode's right is not null
		else
		{
			// send currentNode's right value as the new parameter to check
			maximum(currentNode->getRight());
		}
	}
	// Maximum OverLoad 2
	// Accepts a node pointer as a parameter
	// Find maximum value in tree
	Node<genericType>* maximum(Node<genericType>* currentNode)
	{
		// if currentNode is nullptr, tree is empty
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if currentNode's right is null
		if (currentNode->getRight() == nullptr)
		{
			// return currentNode, because it doesn't get any larger
			return currentNode;
		}
		else
		{
			// send currentNode's right value as the new parameter to check
			maximum(currentNode->getRight());
		}
	}

	// Minimum Overload 1
	// Find minimum value in tree
	Node<genericType>* minimum()
	{
		// start at root
		Node<genericType>* currentNode = root;
		// if currentNode is nullptr, tree is empty
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if currentNode's left is null
		if (currentNode->getLeft() == nullptr)
		{
			// return currentNode, because it doesn't get any smaller
			return currentNode;
		}
		// if currentNode's right is not null
		else
		{
			// send currentNode's left value as the new parameter to check
			minimum(currentNode->getLeft());
		}
	}
	// Minimum overload 2
	// accepts a node pointer as parameter
	// find minimum value in tree
	Node<genericType>* minimum(Node<genericType>* currentNode)
	{
		// if currentNode is nullptr, tree is empty
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// if currentNode's left is null
		if (currentNode->getLeft() == nullptr)
		{
			// return currentNode, because it doesn't get any smaller
			return currentNode;
		}
		// if currentNode's right is not null
		else
		{
			// send currentNode's left value as the new parameter to check
			minimum(currentNode->getLeft());
		}
	}
	
	
	// Extra Credit
	// Performance Analysis Testing
	// Self Balancing Tree
};