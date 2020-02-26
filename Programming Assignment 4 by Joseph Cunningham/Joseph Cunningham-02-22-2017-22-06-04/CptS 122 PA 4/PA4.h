#ifndef PA4_H
#define PA4_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queueNode
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

void enqueue(Queue *Line, int newCustmerNum, int newServiceTime, int newTotalTime, char *line, int arrival);
QueueNode *makeNode(int newCustmerNum, int newServiceTime, int newTotalTime);
void dequeue(Queue *Line, char *line);
void printqueue(Queue *Line, char *line);
int isEmpty(Queue Line);

#endif // !PA4_H
