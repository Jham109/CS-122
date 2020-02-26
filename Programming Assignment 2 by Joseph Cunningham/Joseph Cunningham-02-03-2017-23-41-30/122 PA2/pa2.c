#include "pa2.h"

int menu(void)
{
	int option = 0;
	do
	{
		printf("(1) Load\n");
		printf("(2) Store\n");
		printf("(3) Display\n");
		printf("(4) Insert\n");
		printf("(5) Delete\n");
		printf("(6) Edit\n");
		printf("(7) Sort\n");
		printf("(8) Rate\n");
		printf("(9) Play\n");
		printf("(10) Shuffle\n");
		printf("(11) Exit\n");
		printf("Select an option\n");
		scanf("%d", &option);
		system("cls");
	} while (option < 1 || option > 12);

	return option;
}

Node *makeNode(char *newArtist, char *newAlbulm, char *newTitle, char *newGenre, int minutes, int seconds, int played, int rate)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));
	strcpy(pMem->data.album, newAlbulm);
	strcpy(pMem->data.artist, newArtist);
	strcpy(pMem->data.title, newTitle);
	strcpy(pMem->data.genre, newGenre);
	pMem->data.Length.minutes = minutes;
	pMem->data.Length.seconds = seconds;
	pMem->data.times_played = played;
	pMem->data.Rating = rate;

	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}

void load(FILE *infile, Node **pList)
{
	int minutes = 0, seconds = 0, played = 0, rating = 0;
	char line[100] = "", artist[50] = "", albulm[50] = "", title[50] = "", genre[50] = "", time[50] = "";
	Node *pMem = NULL, *pCur = NULL, *pPrev = NULL;

	infile = fopen("musicPlayList.csv", "r");

	if (infile != NULL)
	{
		fgets(line, 100, infile);

		while (!feof(infile))
		{

			strcpy(artist, strtok(line, "\""));

			if (strlen(artist) > 25) // what artist has more characters than 20?
			{
				strcpy(artist, strtok(line, ","));
			}
			strcpy(albulm, strtok(NULL, ","));
			strcpy(title, strtok(NULL, ","));
			strcpy(genre, strtok(NULL, ","));
			strcpy(time, strtok(NULL, ","));
			played = atoi(strtok(NULL, ","));
			rating = atoi(strtok(NULL, ","));
			minutes = atoi(strtok(time, ":"));
			seconds = atoi(strtok(NULL, ","));

			// create space for the new node
			pMem = makeNode(artist, albulm, title, genre, minutes, seconds, played, rating);

			// code from Andy O'Fallon's function insertatFront
			if (pMem != NULL)
			{
				pMem->pNext = *pList; // or = pCur
									  // Is the list empty?
				if (*pList != NULL) // no
				{
					(*pList)->pPrev = pMem;
				}
				else // yes
				{
					// nothing else to be done!
				}
				*pList = pMem;
			}
			fgets(line, 100, infile);
		}
	}
	else
	{
		printf("Error opening file \"infile\" for reading");
	}

	fclose(infile);

}

void store(FILE *outfile, Node *pList)
{
	Node * pCur = NULL;

	outfile = fopen("musicPlayList.csv", "w");

	pCur = pList;

	if (outfile != NULL)
	{
		while (pCur != NULL)
		{
			// advance thru list
			fprintf(outfile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
			pCur = pCur->pNext;			
		}
		printf("files loaded");
	}
	else
	{
		printf("Error opening file \"outfile\" for writing");
	}

	putchar('\n');
	system("pause");
	fclose(outfile);
}

void display(Node *pList)
{
	char option[25];
	Node *pCur = NULL;

	pCur = pList;


	printf("Enter an artist(case sensitive) or enter \"all\" for the whole list: ");
	scanf("%s", &option);


	if (strcmp(option, "all") == 0)
	{
		while (pCur != NULL)
		{
			printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
			pCur = pCur->pNext;
		}
	}
	else
	{
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.artist, option) == 0)
			{
				printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
				pCur = pCur->pNext;
			}
			else
			{
				pCur = pCur->pNext;				
			}
		}
	}

	putchar('\n');
	system("Pause");
}

void edit(Node *pList)
{
	int songs = 0;
	char get = '\0';
	char option[25], song[25];
	Node *pCur = NULL, *pEdit = NULL;

	pCur = pList;

	printf("Enter the name of an artist's record to edit(case sensitive): ");
	get = getchar();
	gets(option);

	while (pCur != NULL)
	{
		if (strcmp(pCur->data.artist, option) == 0)
		{
			printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
			pEdit = pCur;
			pCur = pCur->pNext;
			++songs;
		}
		else
		{
			pCur = pCur->pNext;
		}
	}
	if (songs > 1)
	{
		printf("Enter name of song to edit: ");
		gets(song);
		
		pCur = pList;
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.title, song) == 0)
			{
				printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
				get_field(pCur);
				pCur = pCur->pNext;
			}
			else
			{
				pCur = pCur->pNext;
			}
		}
	}
	else
	{
		get_field(pEdit);
	}

		
}

int get_field(Node *pCur)
{
	int field = 0, minutes = 0, seconds = 0, times_played = 0, rating = 0;
	char artist[20], albulm[20], song[20], genre[20], empty = '\0';
	
	do
	{
		printf("(1) Artist\n");
		printf("(2) Albulm Title\n");
		printf("(3) Song Title\n");
		printf("(4) Genre\n");
		printf("(5) Minutes\n");
		printf("(6) Seconds\n");
		printf("(7) Times Played\n");
		printf("(8) Rating\n");
		printf("(9) Exit back to main menu\n");
		printf("Enter the field to edit: ");
		scanf("%d", &field);

		if (field != 9)
		{
			printf("Enter new data: ");
		}

		switch (field)
		{
		case 1:
			//scanf("%s", &artist);
			empty = getchar();
			gets(artist);
			strcpy(pCur->data.artist, artist);
			break;
		case 2:
			//scanf("%s", &albulm);
			empty = getchar();
			gets(albulm);
			strcpy(pCur->data.album, albulm);
			break;
		case 3:
			//scanf("%s", &song);
			empty = getchar();
			gets(song);
			strcpy(pCur->data.title, song);
			break;
		case 4:
			//scanf("%s", &genre);
			empty = getchar();
			gets(genre);
			strcpy(pCur->data.genre, genre);
			break;
		case 5:
			scanf("%d", &minutes);
			pCur->data.Length.minutes = minutes;
			break;
		case 6:
			scanf("%d", &seconds);
			pCur->data.Length.seconds = seconds;
			break;
		case 7:
			scanf("%d", &times_played);
			pCur->data.times_played = times_played;
			break;
		case 8:
			scanf("%d", &rating);
			pCur->data.Rating = rating;
			break;
		case 9:
			printf("New Record:\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
			system("pause");
			system("cls");
			break;
		default:
			break;
			system("cls");
		}
	} while (field != 9);

	
}

void rating(Node *pList)
{
	char song_title[25];
	int rating = 0;
	Node *pCur = NULL;

	pCur = pList;

	printf("Select a song to rate(case sensitive): ");
	getchar();
	gets(song_title);

	while (pCur != NULL)
	{
		if (strcmp(song_title, pCur->data.title) == 0)
		{
			do {
				printf("Enter a new rating(1-5): ");
				scanf("%d", &rating);
			} while (rating < 1 && rating > 6);

			pCur->data.Rating = rating;
			pCur = pCur->pNext;
		}
		else
		{
			pCur = pCur->pNext;
		}
	}
}

void play(Node *pList)
{
	char song_title[25];
	int found = 0;
	Node *pCur = NULL;

	pCur = pList;

	printf("Enter a song name to start playing: ");
	getchar();
	gets(song_title);

	while (!found)
	{
		if (strcmp(song_title, pCur->data.title) == 0)
		{
			printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
			pCur = pCur->pNext;
			found = 1;
		}
		else
		{
			pCur = pCur->pNext;
		}
	}
	while (pCur != NULL)
	{
		printf("Playing next song.....");
		system("pause");
		system("cls");
		printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre, pCur->data.Length.minutes, pCur->data.Length.seconds, pCur->data.times_played, pCur->data.Rating);
		pCur = pCur->pNext;
	}

	printf("End of song list......");
	system("pause");
	system("cls");

}