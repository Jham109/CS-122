#include "Stack.h"


Stack::Stack(int newSize)
{
	mSize = newSize;
	mMaxSize = 100;
	mTop = new string[100];
}

Stack::~Stack()
{
	//delete[] mTop;
}

int Stack::getSize()const
{
	return mSize;
}

bool Stack::push(string &newItem)
{
	if (mSize < mMaxSize)
	{
		mTop[mSize] = newItem;
		this->mSize++;
		return true;
	}
	return false;
}
bool Stack::pop(string &poppedItem)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		poppedItem = mTop[mSize-1];
		mTop[mSize] = "";
		mSize--;
		return true;
	}
}
bool Stack::peek(string &item)
{
	if(isEmpty())
	{
		return false;
	}
	item = mTop[mSize - 1];
	return true;
}

bool Stack::isEmpty()
{
	if (mSize == 0)
	{
		return true;
	}
	return false;
}