#pragma once
#include "BST.h"

#include <string.h>

using std::ifstream;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();


private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile();
	void readFile();
	void displayContent();
	void fillTrees(int units, string type, string transaction);
	void stats();
};