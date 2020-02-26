#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits)
{
	mData = newData;
	mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{

}

int TransactionNode::getUnits() const
{
	return mUnits;
}

void TransactionNode::setUnits(const int newUnits) 
{
	mUnits = newUnits;
}

void TransactionNode::printData()
{
	cout <<mUnits<< mData << endl;

}