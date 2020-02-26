#include "ExercisePlan.h"

ExercisePlan::ExercisePlan()
{
	mGoalSteps = 0;
	mPlanName = "";
	mDate = "";
}

ExercisePlan:: ExercisePlan(const ExercisePlan &copy)
{
	mDate = copy.getDate();
	mPlanName = copy.mPlanName;
	mGoalSteps = copy.mGoalSteps;
}

ExercisePlan::~ExercisePlan()
{
	//does nothin
}
int ExercisePlan::getSteps()const
{
	return mGoalSteps;
}
string ExercisePlan::getPlanName()const
{
	return mPlanName;
}
string ExercisePlan::getDate()const
{
	return mDate;
}

void ExercisePlan::editGoal()
{
	int newGoal = 0;

	cout << "Set a new goal: ";
	cin >> newGoal;

	setSteps(newGoal);

	cout << "New Plan: " << this;
}

void ExercisePlan::setSteps(int NewCalories)
{
	mGoalSteps = NewCalories;
}
void ExercisePlan::setPlanName(string NewName)
{
	mPlanName = NewName;
}
void ExercisePlan::setDate(string NewDate)
{
	mDate = NewDate;
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs)
{
	string Name = "", Date = "";
	int goal = 0;

	std::getline(lhs, Name);
	lhs >> goal;
	std::getline(lhs, Date);

	rhs.setDate(Name);
	rhs.setSteps(goal);
	rhs.setDate(Date);

	return lhs;
}

std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

fstream & operator <<(fstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}