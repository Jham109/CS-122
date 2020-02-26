/*	Name: Joseph Cunningham
Date: 1/25/17
Description: write a program that reads in fitbit data, organizes it, and prints it too a file
*/
#include "pa1.h"



int main(void)
{
	FitbitData data[1440];
	char end[100], start[100];
	double calories = 0, distance = 0, HeartRate = 0;
	int floors = 0, steps = 0, maxSteps = 0;
	FILE *infile = NULL, *outfile = NULL;
	 
	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w");
	
	if (infile == NULL)
	{
		printf("nigga nooooooo!!!!");
	}
	else
	{
		read_data(infile, data);
		calories = calories_burned(data);
		distance = distance_walked(data);
		floors = floors_walked(data);
		steps = steps_taken(data);
		HeartRate = avg_hrtr8(data);
		maxSteps = max_steps(data);
		poor_sleep(data, end, start);
		output(outfile, calories, distance, floors, steps, HeartRate, max_steps, start, end);

	}
	
	

	fclose(infile);
	fclose(outfile);


	return 0;
}