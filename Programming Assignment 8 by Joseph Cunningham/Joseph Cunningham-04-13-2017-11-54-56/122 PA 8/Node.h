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
	Node(string newData = "");
	virtual ~Node();

	string getData()const;
	Node *& getLeft();
	Node *& getRight();

	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);
	void setData(const string data);

	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;

};