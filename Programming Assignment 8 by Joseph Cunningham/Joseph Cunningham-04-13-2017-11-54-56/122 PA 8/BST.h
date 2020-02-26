#pragma once

#include "Node.h"
#include "TransactionNode.h"

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;

class BST
{
public:
	BST();
	~BST();

	void setRoot(Node * const newRoot);

	Node *& getRoot();

	void insert(int newUnits, string Data);
	void PrintInorder();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();

private:
	Node *mRoot;

	void insert(Node *& pTree, int newUnits, string Data);
	void PrintInorder(Node *& pTree);
	void destroyTree(Node *& pTree);
};