#include "BSTNode.h"

Node::Node(string newCode, char newChar)
{
	mCode = newCode;
	mChar = newChar;
	mLeft = nullptr;
	mRight = nullptr;
}
Node::~Node()
{
	//the destructor of Node
}

string Node::getCode() const
{
	return mCode;
}
char Node::getChar() const
{
	return mChar;
}

Node *& Node::getLeft()
{
	return mLeft;
}
Node *& Node::getRight()
{
	return mRight;
}

void Node::setChar(const char newChar)
{
	mChar = newChar;
}

void Node::setCode(const string newData)
{
	mCode = newData;
}

void Node::setLeft(Node * const newLeft)
{
	mLeft = newLeft;
}
void Node::setRight(Node * const newRight)
{
	mRight = newRight;
}