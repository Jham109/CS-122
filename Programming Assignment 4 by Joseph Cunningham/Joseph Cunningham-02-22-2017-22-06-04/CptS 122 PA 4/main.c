//Joseph Cunningham
// 2/13/17
// This programs simulates 2 grocery lines using queues as the lines

#include "PA4.h"

int main(void)
{
	Queue express_line = { NULL, NULL }, standard_line = { NULL, NULL };
	
	int express_arrival = 0, standard_arrival = 0, time_elapsed = 0, customer_number = 1, express_service = 0, standard_service = 0,
		express_totalTime = 0, standard_totalTime = 0, time_run = 0, express_time_count = 0, standard_time_count = 0,
		express_processed = 0 , standard_processed = 0;

	srand((int)time(NULL));


	printf("Enter the amount of time to run the simulation(units in minutes): ");
	scanf("%d", &time_run);

	//first customers
	express_arrival = rand() % 5 + 1;
	express_service = rand() % 5 + 1;

	standard_arrival = rand() % 6 + 3;
	standard_service = rand() % 6 + 3;

	while (time_run >= time_elapsed)
	{	


		//print each queue every 10 mins
		if (time_elapsed % 10 == 0 && time_elapsed != 0)
		{
			putchar('\n');
			printf("Minute %d.....\n", time_elapsed);
			putchar('\n');
			printf("[%d customers processed]\n", express_processed);
			printqueue(&express_line, "Express Line:  ");			
			putchar('\n');
			putchar('\n');
			printf("[%d customers processed]\n", standard_processed);
			printqueue(&standard_line, "Standard Line:  ");			
			putchar('\n');
			putchar('\n');
			system("pause");
			system("cls");
		}


		// puts customer into each line based on arrival time and generates
		// a new arrival time for the next customer
		if (express_arrival == time_elapsed)
		{
			express_totalTime += express_service;
			enqueue(&express_line, customer_number, express_service, express_totalTime, "express line", express_arrival);
			express_arrival = (rand() % 5 + 1) + time_elapsed;
			express_service = rand() % 5 + 1;
			++customer_number;
		}
		if (standard_arrival == time_elapsed)
		{
			standard_totalTime += standard_service;
			enqueue(&standard_line, customer_number, standard_service, standard_totalTime, "standard line", standard_arrival);
			standard_arrival = (rand() % 6 + 3) + time_elapsed;
			standard_service = rand() % 6 + 3;
			++customer_number;
		}
		
		
		 
		// checks to see if theres customers in each line then counts each service time
		if (!isEmpty(express_line))
		{
			++express_time_count;

			if (express_time_count == express_line.pHead->serviceTime)// dequeues the customer as soon as their service time runs out
			{
				dequeue(&express_line, "express");
				express_time_count = 0;
				++express_processed;
			}
		}
		if (!isEmpty(standard_line))
		{
			++standard_time_count;

			if (standard_time_count == standard_line.pHead->serviceTime)// dequeues the customer as soon as their service time runs out
			{
				dequeue(&standard_line, "standard");
				standard_time_count = 0;
				++standard_processed;
			}
		}
	
			
		++time_elapsed;
	}
	return 0;
}