#include "BST.h"

BST::BST()
{
	string code;
	char newChar;
	mRoot = nullptr;
	fstr.open("MorseTable.txt");
	

	while (!fstr.eof())
	{
		fstr >> newChar;
		fstr >> code;
		//std::getline(fstr, code);

		//Node *data = new Node(code, newChar);
		insert(newChar, code);
	}
	fstr.close();
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

void BST::insert(char newChar, string code)
{
	insert(this->mRoot, newChar, code);
	
}

void BST::PrintInorder()
{
	PrintInorder(this->mRoot);
}

void BST::search(char letter)
{

	search(this->mRoot, letter);
}


//private functions 
void BST::insert(Node *& pTree, char newChar, string code)
{
	// modified code from andy O'fallon's BST insert
	if (pTree == nullptr) 
	{
		pTree = new Node(code, newChar);
	}
	else if (newChar < pTree->getChar())
	{
		insert(pTree->getLeft(), newChar, code);
	}
	else if (newChar > pTree->getChar())
	{
		insert(pTree->getRight(), newChar, code);
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
		cout << pTree->getChar() << pTree->getCode() << endl;
		PrintInorder(pTree->getRight());
	}
}

void BST::search(Node *&pTree, char letter)
{

	if (pTree == nullptr)
	{
		cout << "not in fam";
	}
	else if (letter < pTree->getChar())
	{
		search(pTree->getLeft(), letter);
	}
	else if (letter > pTree->getChar())
	{
		search(pTree->getRight(), letter);
	}
	else
	{
		cout << pTree->getCode();
	}
}