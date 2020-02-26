#include "pa1.h"

void read_data(FILE *infile, FitbitData data[])
{
	char *pTemp = NULL, *pData = NULL;
	char f_bit[2000];
	int count = 0;
	double cal = 0;

	fgets(f_bit, 2000, infile);
	fgets(f_bit, 2000, infile);
	
	while(!feof(infile))
	{ 
		pData = strtok(f_bit, ",");

		while (pData != NULL)
		{		
			strcpy(data[count].minute,pData);
			pData = strtok(NULL, ",");
			if (pData == NULL)
			{
				pData = "0";
			}
			data[count].calories = atof(pData);
			pData = strtok(NULL, ",");
			if (pData == NULL)
			{
				pData = "0";
			}
			data[count].distance = atof(pData);
			pData = strtok(NULL, ",");
			if (pData == NULL)
			{
				pData = "0";
			}
			data[count].floors = atoi(pData);
			pData = strtok(NULL, ",");
			if (pData == NULL)
			{
				pData = "0";
			}
			data[count].heartRate = atoi(pData);
			pData = strtok(NULL, ",");
			if (pData == NULL)
			{
				pData = "0";
			}
			data[count].steps = atoi(pData);
			pData = strtok(NULL, ",");
			if (pData == NULL)
			{
				pData = "0";
			}
			data[count].sleeplevel = atoi(pData);
			pData = strtok(NULL, ",");
			++count;
		}
		fgets(f_bit, 2000, infile);
	}	
}

double calories_burned(FitbitData data[])
{
	double burned = 0;

	for (int i = 0; i < 1440; i++)
	{
		burned += data[i].calories;
	}
	//printf("calories :%lf\n", burned);
	return burned;
}

double distance_walked(FitbitData data[])
{
	double walked = 0;

	for (int i = 0; i < 1440; i++)
	{
		walked += data[i].distance;
	}
	//printf("Distanced walked :%lf\n", walked);
	return walked;
}

int floors_walked(FitbitData data[])
{
	int walked = 0;

	for (int i = 0; i < 1440; i++)
	{
		walked += data[i].floors;
	}
	//printf("Floors walked :%d\n", walked);
	return walked;
}

int steps_taken(FitbitData data[])
{
	int step = 0;

	for (int i = 0; i < 1440; i++)
	{
		step += data[i].steps;
	}
	//printf("steps :%d\n", step);
	return step;
}

double avg_hrtr8(FitbitData data[])
{
	double hrtr8 = 0, average = 0;

	for (int i = 0; i < 1440; i++)
	{
		hrtr8 += data[i].heartRate;
	}
	average = hrtr8 / 1440;
	//printf("Average Heartrate :%lf\n", average);
	return average;
}

int max_steps(FitbitData data[])
{
	int max = data[0].steps;
	for (int i = 0; i < 1440; i++)
	{
		if (data[i].steps >= max)
		{
			max = data[i].steps;
		}
	}
	//printf("Max steps %d\n", max);
	return max;
}

int poor_sleep(FitbitData data[], char *end, char *start)
{
	int range = 0, rangesub = 0;
	//char *start = NULL, *end = NULL;
	char fin[100], begin[100];
	for (int i = 0; i < 1440; i++)
	{
		if(data[i].sleeplevel > 1)
		{
			rangesub += data[i].sleeplevel;
			if (rangesub <= 3)
			{
				strcpy(begin,data[i].minute);
			}
			if (data[i + 1].sleeplevel <= 1 )
			{
				strcpy(fin,data[i].minute);
			}
		}
		if (rangesub > range) //updates the max range
		{
			strcpy(start, begin);
			strcpy(end, fin);
			range = rangesub;
		}
		if (data[i].sleeplevel < 1) //resets the range count
		{
			rangesub = 0;
		}
	}
	
	return range;
}

void output(FILE *outfile, double calories, double distance, int floors, int steps, double HeartRate, int max_steps, char start[], char end[])
{
	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps,Sleep\n");
	fprintf(outfile, "%lf, %lf, %d, %d, %lf, %d, %s:%s", calories, distance, floors, steps, HeartRate, max_steps, start, end);
}
