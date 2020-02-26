#include "List.h"

List::List()
{
	mList = nullptr;
}
List::List(const List &copy)
{
	this->mList = copy.getFrontPtr();
}
List::~List()
{
	//delete the list
	destroyList();
}

bool List::insertAtFront(const int newRec, const int newID, const string newName, const string newEmail, const int newUnits, const string newProgram, const string newLevel, const int absences)
{
	Node *pMem = makeNode(newRec, newID, newName, newEmail, newUnits, newProgram, newLevel, absences);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;
		pMem->setPtr(mList);
		mList = pMem;
	}
	
	return success;
}

Node* List::getFrontPtr()const
{
	return this->mList;
}

void List::setFrontPtr(Node* const newPtr)
{
	this->mList = newPtr;
}

// following funciton from Andy O'fallon's List.cpp
// deletes each node to free memory; will call in the destructor
void List::destroyList()
{
	destroyListHelper(mList);
	mList = nullptr;
}



//private functions

Node * List::makeNode(const int newRec, const int newID, const string newName, const string newEmail, const int newUnits, const string newProgram, const string newLevel, const int absences)
{
	Node * pMem = new Node(newRec, newID, newName, newEmail, newUnits, newProgram, newLevel, absences);

	pMem->setPtr(nullptr);

	return pMem;
}

// following funciton from Andy O'fallon's List.cpp
// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(Node * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}


// non-memeber functions

fstream & operator << (fstream &lhs, List &rhs)
{
	Node * pCur = rhs.getFrontPtr();
	while (pCur != nullptr)
	{
		lhs << pCur->geRecordNum() << "," << pCur->getID() << ",\"" << pCur->getName() << "\"," << pCur->getEmail() << ","
			<< pCur->getUnits() << "," << pCur->getProgram() << "," << pCur->getLevel() << "," << pCur->getAbsences()<< endl;
		pCur = pCur->getPtr(); // print out list by going through next pointers.
	}

	return lhs;
}