#include "Node.h"

Node::Node(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{

}

string Node::getData()const
{
	return mData;
}
Node *& Node::getLeft() 
{
	return mpLeft;
}
Node *& Node::getRight() 
{
	return mpRight;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}
void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}
void Node::setData(const string data)
{
	mData = data;
}