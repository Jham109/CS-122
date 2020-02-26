#include "DietPlan.h"

DietPlan::DietPlan()
{
	mGoalCalories = 0;
	mPlanName = "";
	mDate = "";
}

DietPlan::DietPlan(const DietPlan &copy)
{
	mDate = copy.getDate();
	mPlanName = copy.mPlanName;
	mGoalCalories = copy.mGoalCalories;
}

DietPlan::~DietPlan()
{
	//does nuttin
}
int DietPlan::getCalories()const
{
	return mGoalCalories;
}
string DietPlan::getPlanName()const
{
	return mPlanName;
}
string DietPlan::getDate() const
{
	return mDate;
}

void DietPlan::editGoal()
{
	int newGoal = 0;

	cout << "Set a new goal: ";
	cin >> newGoal;

	setCalories(newGoal);

	cout << "New Plan: "<< this;
}

void DietPlan::setCalories(const int &NewCalories)
{
	mGoalCalories = NewCalories;
}
void DietPlan::setPlanName(const string &NewName)
{
	mPlanName = NewName;
}
void DietPlan::setDate(const string &NewDate)
{
	mDate = NewDate;
}

fstream & operator >> (fstream &lhs, DietPlan &rhs)
{
	string Name = "", Date = "";
	int goal = 0;

	std::getline(lhs, Name);
	lhs >> goal;
	std::getline(lhs, Date);

	rhs.setDate(Name);
	rhs.setCalories(goal);
	rhs.setDate(Date);

	return lhs;
}

std::ostream & operator << (std::ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

fstream & operator <<(fstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}