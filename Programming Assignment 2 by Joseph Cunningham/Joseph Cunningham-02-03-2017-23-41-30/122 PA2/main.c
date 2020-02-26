#include "pa2.h"

int main(void)
{
	int option = 0;
	Node *pList = NULL;
	FILE *infile = NULL, *outfile = NULL;	
	
	do
	{
		option = menu();

		switch (option)
		{
		case LOAD:
			load(infile, &pList);
			break;
		case STORE:
			store(outfile, pList);
			break;
		case DISPLAY:
			display(pList);
			break;
		case INSERT:
			break;
		case DELETE:
			break;
		case EDIT:
			edit(pList);
			break;
		case SORT:
			break;
		case RATE:
			rating(pList);
			break;
		case PLAY:
			play(pList);
			break;
		case SHUFFLE:
			break;
		case EXIT:
			store(outfile, pList);
			printf("BYE.....\n");
			break;
		default:
			break;
		}
	} while (option != EXIT);
	
	return  0;
}
