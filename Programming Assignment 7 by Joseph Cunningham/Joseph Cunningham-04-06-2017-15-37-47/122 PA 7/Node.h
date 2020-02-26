#pragma once

#include "Stack.h"

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class Node
{
public:
	Node(int newRec, int newID, string newName, string newEmail, int newUnits, string newProgram, string newLevel, int absencse = 0);
	Node(const Node &copy);
	~Node();

	int geRecordNum()const;
	int getID()const;
	string getName()const;
	string getEmail()const;
	int getUnits()const;
	string getProgram()const;
	string getLevel()const;
	int getAbsences()const;
	Node* getPtr()const;
	Stack & getStack();

	void setAbsences(const int newAbsences);
	void seRecordNum(const int newRecordNum);
	void setID(const int newID);
	void setName(const string newName);
	void setEmail(const string newEmail);
	void setUnits(const int newUnits);
	void setProgram(const string newProgram);
	void setLevel(const string newLevel);
	void setPtr(Node * const newPtr);
private:
	int mRecordNumber;
	int mID;
	string mName;
	string mEmail;
	int mUnits;
	string mProgram;
	string mLevel;
	Stack theStack;
	int mAbsences;
	Node *mNext;
};

