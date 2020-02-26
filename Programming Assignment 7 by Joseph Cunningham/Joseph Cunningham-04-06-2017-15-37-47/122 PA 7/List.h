#pragma once

#include "Node.h"

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

class List
{
public:
	List();
	List(const List &copy);
	~List();

	bool insertAtFront(const int newRec, const int newID, const string newName, const string newEmail, const int newUnits, const string newProgram, const string newLevel, const int absences = 0);

	Node* getFrontPtr()const;

	void setFrontPtr(Node* const newPtr);
	void destroyList();

private:
	Node * mList;

	Node * makeNode(const int newRec, const int newID, const string newName, const string newEmail, const int newUnits, const string newProgram, const string newLevel, const int absences);
	void destroyListHelper(Node * const pMem);
	                      
};

fstream & operator << (fstream &lhs, List &rhs);