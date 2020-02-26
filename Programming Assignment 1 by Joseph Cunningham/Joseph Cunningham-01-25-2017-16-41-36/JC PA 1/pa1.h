#ifndef  PA1_H
#define PA1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleeplevel;
}FitbitData;

void read_data(FILE *infile, FitbitData data[]);
double calories_burned(FitbitData data[]);
double distance_walked(FitbitData data[]);
int floors_walked(FitbitData data[]);
int steps_taken(FitbitData data[]);
double avg_hrtr8(FitbitData data[]); // Average Heartrate
int max_steps(FitbitData data[]);
int poor_sleep(FitbitData data[], char *end, char *start);
void output(FILE *outfile, double calories, double distance, int floors, int steps, double HeartRate, int max_steps, char start[], char end[]);



#endif // ! PA1_H
