#include "DataAnalysis.h"

using std::ifstream;

// public functions
DataAnalysis::DataAnalysis()
{

}
DataAnalysis::~DataAnalysis()
{
	mCsvStream.close();
}

void DataAnalysis::runAnalysis()
{
	openFile();
	displayContent();
	stats();
}



//private functions
void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
}
void DataAnalysis::readFile()
{
	int units;
	string type, transaction, U;

	getline(mCsvStream, U, ',');
	if (U != "")
	{
		units = std::stoi(U);
		getline(mCsvStream, type, ',');
		getline(mCsvStream, transaction, '\n');

		fillTrees(units, type, transaction);
	}
}
void DataAnalysis::displayContent()
{
	string firstline;
	getline(mCsvStream, firstline, '\n'); // read in and do nothing with first line

	while (!mCsvStream.eof())
	{
		readFile();
	}
	cout << "Products Sold:" << endl;
	mTreeSold.PrintInorder();

	cout << endl << "Products Purchased: " << endl;
	mTreePurchased.PrintInorder();
}
void DataAnalysis::fillTrees(int units, string type, string transaction)
{
	if (transaction == "Sold")
	{
		mTreeSold.insert(units, type);
	}
	else
	{
		mTreePurchased.insert(units, type);
	}
}
void DataAnalysis::stats()
{
	TransactionNode largest, smallest;

	largest = mTreeSold.findLargest();
	smallest = mTreeSold.findSmallest();

	cout << endl << "Most sold: " << largest.getUnits() << ", " << largest.getData() << endl;
	cout << "least sold: " << smallest.getUnits() << ", " << smallest.getData() << endl;

	largest = mTreePurchased.findLargest();
	smallest = mTreePurchased.findSmallest();

	cout << endl <<"Most purchased: " << largest.getUnits() << ", " << largest.getData() << endl;
	cout << "least purchased: " << smallest.getUnits() << ", " << smallest.getData() << endl;

}