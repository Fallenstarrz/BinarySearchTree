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

	myFirstTree.find(2);
}

