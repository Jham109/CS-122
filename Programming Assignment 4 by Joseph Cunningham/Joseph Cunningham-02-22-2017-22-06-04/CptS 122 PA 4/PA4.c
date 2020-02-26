#include "PA4.h"

QueueNode * makeNode(int newCustmerNum, int newServiceTime, int newTotalTime)
{
	QueueNode *pMem = NULL;
	pMem = (QueueNode *)malloc(sizeof(QueueNode));

	pMem->customerNumber = newCustmerNum;
	pMem->serviceTime = newServiceTime;
	pMem->totalTime = newTotalTime;
	pMem->pNext = NULL;

	return pMem;
}

void enqueue(Queue *Line, int newCustmerNum, int newServiceTime, int newTotalTime, char *line, int arrival)
{
	QueueNode *pMem = NULL;

	pMem = makeNode(newCustmerNum, newServiceTime, newTotalTime);

	if (pMem != NULL)
	{
		if (Line->pHead == NULL)
		{
			Line->pHead = pMem;
			Line->pTail = pMem;
		}
		else
		{
			Line->pTail->pNext = pMem;
			Line->pTail = pMem;
		}
		printf("Customer #%d has arrived in the %s at minute %d\n", pMem->customerNumber, line, arrival);
	}
	
}

void dequeue(Queue *Line, char *line)
{
	QueueNode *pTemp = NULL;

	pTemp = Line->pHead;

	if (Line->pHead == Line->pTail)
	{
		Line->pHead = NULL;
		Line->pTail = NULL;
	}
	else
	{	
		Line->pHead = Line->pHead->pNext;
	}
	printf("Customer #%d has been checked out after %d minutes in the %s line \n", pTemp->customerNumber, pTemp->serviceTime, line);
	free(pTemp);
}

void printqueue(Queue *Line, char *line)
{
	QueueNode *pCur = NULL;
	pCur = Line->pHead;
	
	puts(line);
	while (pCur != NULL)
	{
		printf("Customer #%d", pCur->customerNumber);
		printf("->");
		pCur = pCur->pNext;
	}
}

int isEmpty(Queue Line)
{
	return (Line.pHead == NULL);
}