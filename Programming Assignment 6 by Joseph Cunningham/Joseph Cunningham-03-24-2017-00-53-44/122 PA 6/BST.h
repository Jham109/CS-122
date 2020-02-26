#pragma once

#include "BSTNode.h"

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

	

	void insert(char newChar, string code);
	void PrintInorder();
	void search(char letter);

private:
	fstream fstr;
	Node *mRoot;

	void insert(Node *& pTree, char newChar, string code);
	void PrintInorder(Node *& pTree);
	void search(Node *& pTree, char letter);
	void destroyTree(Node *& pTree);
};