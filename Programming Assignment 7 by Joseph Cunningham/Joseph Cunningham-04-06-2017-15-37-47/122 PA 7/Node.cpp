#include "Node.h"
Node::Node(int newRec, int newID, string newName, string newEmail, int newUnits, string newProgram, string newLevel, int absences)
{
	this->mRecordNumber = newRec;
	this->mID = newID;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mUnits = newUnits;
	this->mProgram = newProgram;
	this->mLevel = newLevel;
	this->mAbsences = absences;
}

Node::Node(const Node &copy)
{
	
	this->mRecordNumber = copy.geRecordNum();
	this->mID = copy.getID();
	this->mName = copy.getName();
	this->mEmail = copy.getEmail();
	this->mUnits = copy.getUnits();
	this->mProgram = copy.getProgram();
	this->mLevel = copy.getLevel();
	this->mAbsences = copy.getAbsences();
	this->mNext = copy.mNext;
}

Node::~Node()
{
	//destructor
}

 //getters
int Node::geRecordNum()const
{
	return mRecordNumber;
}
int Node::getID()const
{
	return mID;
}
string Node::getName()const
{
	return mName;
}
string Node::getEmail()const
{
	return mEmail;
}
int Node::getUnits()const
{
	return mUnits;
}
string Node::getProgram()const
{
	return mProgram;
}
string Node::getLevel()const
{
	return mLevel;
}
int Node::getAbsences()const
{
	return mAbsences;
}
Node* Node::getPtr()const
{
	return mNext;
}
Stack & Node::getStack()
{
	return theStack;

}

//setters
void Node::setAbsences(const int newAbsences)
{
	this->mAbsences += newAbsences;
}
void Node::seRecordNum(const int newRecordNum)
{
	this->mRecordNumber = newRecordNum;
}
void Node::setID(const int newID)
{
	this->mID = newID;
}
void Node::setName(const string newName)
{
	this->mName = newName;
}
void Node::setEmail(const string newEmail)
{
	this->mEmail = newEmail;
}
void Node::setUnits(const int newUnits)
{
	this->mUnits = newUnits;
}
void Node::setProgram(const string newProgram)
{
	this->mProgram = newProgram;
}
void Node::setLevel(const string newLevel)
{
	this->mLevel = newLevel;
}
void Node::setPtr(Node* const newPtr)
{
	this->mNext = newPtr;
}