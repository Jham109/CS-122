#include "FitnessAppWrapper.h"


FitnessAppWrapper::FitnessAppWrapper()
{
	mDP[7] = {};
	mEP[7] = {};
	DPstr.open("DietPlans.txt");
	EPstr.open("ExercisePlans.txt");
}

FitnessAppWrapper::FitnessAppWrapper(const FitnessAppWrapper &copy)
{
	mDP[7] = copy.getDietPlan();
	mEP[7] = copy.getExercisePlan();
}
FitnessAppWrapper::~FitnessAppWrapper()
{
	DPstr.close();
	EPstr.close();
}

DietPlan FitnessAppWrapper::getDietPlan()const
{
	return mDP[7];
}

ExercisePlan FitnessAppWrapper::getExercisePlan()const
{
	return mEP[7];
}

void FitnessAppWrapper::setExercisePlan(ExercisePlan newEP[])
{
	mEP[7] = newEP[7];
}

void FitnessAppWrapper::setDietPlan(DietPlan newDP[])
{
	mDP[7] = newDP[7];
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	int index = 0;
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, weeklyPlan[index]);
		index++;
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[])
{
	int index = 0;
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, weeklyPlan[index]);
		index++;
	}
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan EP)
{
	cout << EP;
}
void FitnessAppWrapper::displayDailyPlan(DietPlan DP)
{
	cout << DP;
}

void FitnessAppWrapper::displayWeeklyplan(DietPlan weeklyPlan[])
{
	int index = 0;
	for (index; index < 7; index++)
	{
		displayDailyPlan(weeklyPlan[index]);
		cout << endl;
	}
}
void FitnessAppWrapper::displayWeeklyplan(ExercisePlan weeklyPlan[])
{
	int index = 0;
	for (index; index < 7; index++)
	{
		displayDailyPlan(weeklyPlan[index]);
		cout << endl;
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream &fstr, DietPlan DP)
{
	fstr << DP << endl;
}

void FitnessAppWrapper::storeDailyPlan(fstream &fstr, ExercisePlan EP)
{
	fstr << EP << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fstr, DietPlan DP[])
{
	for (int index = 0; index < 7; index++)
	{
		storeDailyPlan(fstr, DP[index]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fstr, ExercisePlan EP[])
{
	for (int index = 0; index < 7; index++)
	{
		storeDailyPlan(fstr, EP[index]);
	}
}

int FitnessAppWrapper::displayMenu()
{
	int option = 0;

	do
	{
		cout << "1.    Load weekly diet plan from file." << endl;
		cout << "2.    Load weekly exercise plan from file." << endl;
		cout << "3.    Store weekly diet plan to file." << endl;
		cout << "4.    Store weekly exercise plan to file." << endl;
		cout << "5.    Display weekly diet plan to screen." << endl;
		cout << "6.    Display weekly exercise plan to screen." << endl;
		cout << "7.    Edit daily diet plan." << endl;
		cout << "8.    Edit daily exercise plan." << endl;
		cout << "9.    Exit." << endl;
		cin >> option;
		system("cls");
	} while (option < 1 || option > 9);

	return option;
}

void FitnessAppWrapper::runApp()
{
	int option = 0, plan = 0;

	do 
	{
		option = displayMenu();


		switch (option)
		{
		case 1: // loads weekly diet plan
			loadWeeklyPlan(DPstr, mDP);
			DPstr.close();
			DPstr.open("DietPlans.txt");
			break;
		case 2: // loads weekly exercise plan
			loadWeeklyPlan(EPstr, mEP);
			EPstr.close();
			EPstr.open("ExercisePlans.txt");
			break;
		case 3: // stores weekly dietplan in a file
			storeWeeklyPlan(DPstr, mDP);
			DPstr.close();
			DPstr.open("DietPlans.txt");
			break;
		case 4: // stores weekly exerciseplan in a file
			storeWeeklyPlan(EPstr, mEP);
			EPstr.close();
			EPstr.open("ExercisePlans.txt");
			break;
		case 5: // displays weekly dietplan to screen
			displayWeeklyplan(mDP);
			break;
		case 6: // displays weekly exerciseplan to screen
			displayWeeklyplan(mDP);
			break;
		case 7: // edit daily dietplan
			cout << "Which plan would you like to edit?(1-7): ";
			cin >> plan;
			mDP[plan - 1].editGoal();
			break;
		case 8: // edit daily exerciseplan
			cout << "Which plan would you like to edit?(1-7): ";
			cin >> plan;
			mEP[plan - 1].editGoal();
			break;
		case 9: // exit
			cout << "Goodbye.....saving files" << endl;
			storeWeeklyPlan(DPstr, mDP);
			storeWeeklyPlan(EPstr, mEP);
			break;
		}

	} while (option != 9);
}