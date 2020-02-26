#pragma once

#include "Node.h"


class TransactionNode : public Node
{
public:
	TransactionNode(string newData = "", int newUnits = 0);
	~TransactionNode();

	int getUnits()const;

	void setUnits(int const newUnits);

	void printData();
	
private:
	int mUnits;
};