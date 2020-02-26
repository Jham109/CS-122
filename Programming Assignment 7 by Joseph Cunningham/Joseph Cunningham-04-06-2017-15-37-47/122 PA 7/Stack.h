#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	int getSize()const;

	

	bool push(string   &newItem);
	bool pop(string   &poppedItem);
	bool peek(string  &item);



	bool isEmpty();


private:
	int mSize;
	int mMaxSize;
	string * mTop;
};