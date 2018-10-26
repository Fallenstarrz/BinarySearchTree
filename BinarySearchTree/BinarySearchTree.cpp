// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearch.h"
#include <iostream>

using namespace std;


void main()
{
	Tree<int> myFirstTree;
	myFirstTree.insert(5);
	myFirstTree.insert(10);
	myFirstTree.insert(1);
	myFirstTree.insert(2);
	myFirstTree.insert(7);
	myFirstTree.insert(0);
	myFirstTree.insert(20);

	// print the value found
	cout << myFirstTree.find(5)->getData() << endl;;
	cout << myFirstTree.find(10)->getData() << endl;;
	cout << myFirstTree.find(1)->getData() << endl;;
	cout << myFirstTree.find(2)->getData() << endl;;
	cout << myFirstTree.find(7)->getData() << endl;;
	cout << myFirstTree.find(0)->getData() << endl;;
	cout << myFirstTree.find(20)->getData() << endl;;

	cout << "Maximum: " << myFirstTree.maximum()->getData() << endl;;

}

