#pragma once

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
	Node(string newCode = "" , char newChar = '\0');
	~Node();

	string getCode() const;
	char getChar() const;
	Node *& getLeft();
	Node *& getRight();


	void setCode(const string newData);
	void setChar(const char newChar);
	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);
private:
	string mCode;
	char mChar;
	Node *mLeft;
	Node *mRight;
};
