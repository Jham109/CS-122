#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cout;
using std::cin;
using std::fstream;
using std::string;
using std::endl;



class FitnessAppWrapper
{
public:
	FitnessAppWrapper();
	FitnessAppWrapper(const FitnessAppWrapper &copy);
	~FitnessAppWrapper();

	//load streams
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);

	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(ExercisePlan EP);
	void displayDailyPlan(DietPlan DP);

	void displayWeeklyplan(DietPlan weeklyPlan[]);
	void displayWeeklyplan(ExercisePlan weeklyPlan[]);

	void storeDailyPlan(fstream &fstr, DietPlan DP);
	void storeDailyPlan(fstream &fstr, ExercisePlan EP);

	void storeWeeklyPlan(fstream &fstr, DietPlan DP[]);
	void storeWeeklyPlan(fstream &fstr, ExercisePlan EP[]);

	int displayMenu();

	void runApp();

	DietPlan getDietPlan() const;
	ExercisePlan getExercisePlan()const;
	

	void setDietPlan(DietPlan newDP[]);
	void setExercisePlan(ExercisePlan newEP[]);
	

private:
	DietPlan mDP[7];
	ExercisePlan mEP[7];
	fstream DPstr;
	fstream EPstr;

};