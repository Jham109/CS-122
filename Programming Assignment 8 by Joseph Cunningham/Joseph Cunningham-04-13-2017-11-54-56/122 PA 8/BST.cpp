#include "BST.h"

BST::BST()
{
	mRoot = nullptr;
}
BST::~BST()
{
	//BURN THE TREE DOWN!!!!
	destroyTree(this->mRoot);

}

void BST::destroyTree(Node *& pTree)
{
	Node *pTemp = nullptr;


	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeft());
		pTemp = pTree->getRight();
		delete(pTree);
		destroyTree(pTemp);
	}
}

void BST::setRoot(Node * const newRoot)
{
	mRoot = newRoot;
}

Node *& BST::getRoot()
{
	return mRoot;
}

void BST::insert(int newUnits, string Data)
{
	insert(mRoot, newUnits, Data);

}

void BST::PrintInorder()
{
	PrintInorder(this->mRoot);
}

TransactionNode & BST::findSmallest()
{
	TransactionNode * pCur= dynamic_cast<TransactionNode *>(mRoot);
	TransactionNode * pMem;

	while (pCur != nullptr)
	{
		pMem = pCur;
		pCur = dynamic_cast<TransactionNode *>(pCur->getLeft());
	}

	return (*pMem);
}
TransactionNode & BST::findLargest()
{
	TransactionNode * pCur = dynamic_cast<TransactionNode *>(mRoot);
	TransactionNode * pMem;

	while (pCur != nullptr)
	{
		pMem = pCur;
		pCur = dynamic_cast<TransactionNode *>(pCur->getRight());
		
	}

	return (*pMem);
}

//private functions 
void BST::insert(Node *& pTree, int newUnits, string Data)
{
	// modified code from andy O'fallon's BST insert
	if (pTree == nullptr)
	{
		pTree = new TransactionNode(Data, newUnits);
	}
	else if (newUnits < dynamic_cast<TransactionNode *>(pTree)->getUnits())
	{
		insert(pTree->getLeft(), newUnits, Data);
	}
	else if (newUnits > dynamic_cast<TransactionNode *>(pTree)->getUnits())
	{
		insert(pTree->getRight(), newUnits, Data);
	}
	else
	{
		cout << "duplicate" << endl;
	}
}

void BST::PrintInorder(Node *& pTree)
{
	if (pTree != nullptr)
	{
		PrintInorder(pTree->getLeft());
		pTree->printData();
		PrintInorder(pTree->getRight());
	}
}

