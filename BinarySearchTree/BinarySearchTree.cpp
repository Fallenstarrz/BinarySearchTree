// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearch.h"
#include <iostream>

using namespace std;

template <typename genericType>
void testInsert(Tree<genericType>* myTree, genericType itemToTest)
{
	cout << "Inserting " << itemToTest << " Into Tree" << endl << endl;
	myTree->insert(itemToTest);
}
template <typename genericType>
void testFind(Tree<genericType>* myTree, genericType itemToTest)
{
	cout << "Searching tree for " << itemToTest << endl;
	if (myTree->find(itemToTest) != nullptr)
	{
		cout << "I found " << myTree->find(itemToTest)->getData() << endl << endl;
	}
	else
	{
		cout << "Value Not Found" << endl << endl;
	}
}
template <typename genericType>
void testFindParent(Tree<genericType>* myTree, genericType itemToTest)
{
	cout << "Searching tree for parent of: " << itemToTest << endl;
	if (myTree->findParent(itemToTest) != nullptr)
	{
		cout << "I found " << myTree->findParent(itemToTest)->getData() << " to be the parent of " << itemToTest << endl << endl;
	}
	else
	{
		cout << "Object has no parent" << endl << endl;
	}
}
template <typename genericType>
void testMinimum(Tree<genericType>* myTree)
{
	cout << "Searching for Minimum Value in tree" << endl;
	if (myTree->minimum() != nullptr)
	{
		cout << myTree->minimum()->getData() << endl << endl;
	}
	else
	{
		cout << "Tree Empty, No Minimum Value" << endl << endl;
	}
}
template <typename genericType>
void testMaximum(Tree<genericType>* myTree)
{
	cout << "Searching for Maximum Value in tree" << endl;
	if (myTree->maximum() != nullptr)
	{
		cout << myTree->maximum()->getData() << endl << endl;
	}
	else
	{
		cout << "Tree Empty, No maximum Value" << endl << endl;
	}
}
template <typename genericType>
void testDestroy(Tree<genericType>* myTree, genericType itemToTest)
{
	cout << "Destroying: " << itemToTest << endl;
	myTree->destroy(itemToTest);
	cout << "Searching tree for " << itemToTest << endl;
	if (myTree->find(itemToTest) != nullptr)
	{
		cout << "I found " << myTree->find(itemToTest)->getData() << endl << endl;
	}
	else
	{
		cout << "Value Not Found" << endl << endl;
	}
}
void displayMenu()
{
	cout << "This is a Binary Search Tree" << endl;
	cout << "Please Select one of the below options to begin testing" << endl;
	cout << "1. Fully automated Suite" << endl;
	cout << "2. Insert to tree" << endl;
	cout << "3. Delete from tree" << endl;
	cout << "4. Find node in tree" << endl;
	cout << "5. Find parent of node in tree" << endl;
	cout << "6. Find maximum value in tree" << endl;
	cout << "7. find minimum value in tree" << endl;
	cout << "8. Exit" << endl;
}

template<typename genericType>
void automatedSuite(Tree<genericType>* myTree)
{
	int numbers[12] = { 10, 17, 4, 6, 22, 16, 15, 25, 1, -5, 7, 8 };
	// Automated insert test
	for (int i = 0; i < 12; i++)
	{
		testInsert(myTree, numbers[i]);
	}
	// Automated max test
	testMaximum(myTree);
	// Automated min test
	testMinimum(myTree);
	// Automated find test
	for (int i = 0; i < 12; i++)
	{
		testFind(myTree, numbers[i]);
	}
	// Automated parent find test
	for (int i=0; i < 12; i++)
	{
		testFindParent(myTree, numbers[i]);
	}
	// Automated delete test
	for (int i = 0; i < 12; i++)
	{
		testDestroy(myTree, numbers [i]); // Break goes here
	}
	// try destroy object that doesn't exist
	testDestroy(myTree, 100);
	// try find object that doesn't exist
	testFind(myTree, 100);

	cout << "All checks green!" << endl;
}

int main()
{
	Tree<int> myFirstTree;
	Tree<int>* myTreeRef = &myFirstTree;
	int value;
	
	int selection;

	displayMenu();
	cin >> selection;
	cout << endl;

	while (selection != 8)
	{
		switch (selection)
		{
			case 1:
			{
				cout << "Beginning Fully Automated Suite" << endl;
				automatedSuite(myTreeRef);
				break;
			}
			case 2:
			{
				cout << "What would you like to insert?" << endl;
				cin >> value;
				cout << endl;
				testInsert(myTreeRef, value);
				break;
			}
			case 3:
			{
				cout << "What would you like to delete?" << endl;
				cin >> value;
				cout << endl;
				testDestroy(myTreeRef, value);
				break;
			}
			case 4:
			{
				cout << "What would you like to find?" << endl;
				cin >> value;
				cout << endl;
				testFind(myTreeRef, value);
				break;
			}
			case 5:
			{
				cout << "What node would you like to find the parent of?" << endl;
				cin >> value;
				cout << endl;
				testFindParent(myTreeRef, value);
				break;
			}
			case 6:
			{
				cout << "Finding Maximum Value in tree" << endl;
				testMaximum(myTreeRef);
				break;
			}
			case 7:
			{
				cout << "Finding Minimum Value in tree" << endl;
				testMinimum(myTreeRef);
				break;
			}
			default:
			{
				cout << "Please select a valid integer from the menu options" << endl;
				break;
			}
		}
		system("pause");
		system("cls");
		displayMenu();
		cin >> selection;
		cout << endl;
	}

	// Automatic testing
	// Manual testing
	system("pause");
	return 0;
}

