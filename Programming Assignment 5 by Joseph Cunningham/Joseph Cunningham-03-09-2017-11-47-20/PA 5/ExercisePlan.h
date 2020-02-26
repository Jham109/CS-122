#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;


class ExercisePlan // used to represent a daily exercise plan
{
public:
	ExercisePlan();
	ExercisePlan(const ExercisePlan &copy); // shallow copy
	~ExercisePlan();

	int getSteps()const;
	string getPlanName()const;
	string getDate()const;

	void editGoal();

	void setSteps(int NewSeps);
	void setPlanName(string NewName);
	void setDate(string NewDate);

private:
	int mGoalSteps; // number of desired steps in a day
	string mPlanName;
	string mDate;

};

fstream & operator >> (fstream &lhs, ExercisePlan &rhs);
std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs);
fstream & operator <<(fstream &lhs, ExercisePlan &rhs);