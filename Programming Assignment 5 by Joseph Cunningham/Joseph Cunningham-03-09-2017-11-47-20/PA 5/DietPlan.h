#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;



class DietPlan // used to represent a daily diet plan
{
public:
	DietPlan();
	DietPlan(const DietPlan &copy); // shallow copy
	~DietPlan();

	int getCalories()const;
	string getPlanName()const;
	string getDate()const;

	void editGoal();

	void setCalories(const int &NewCalories);
	void setPlanName(const string &NewName);
	void setDate(const string &NewDate);


private:
	int mGoalCalories; // stores the maximum intake of calories for a day
	string mPlanName;
	string mDate;

};

fstream & operator >> (fstream &lhs, DietPlan &rhs);
std::ostream & operator << (std::ostream &lhs, DietPlan &rhs);
fstream & operator <<(fstream &lhs, DietPlan &rhs);