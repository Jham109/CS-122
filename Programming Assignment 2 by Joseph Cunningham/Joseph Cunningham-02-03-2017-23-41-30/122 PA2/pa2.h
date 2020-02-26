#ifndef PA2_H
#define PA2_H

#define LOAD 1
#define STORE 2
#define DISPLAY 3
#define INSERT 4
#define DELETE 5
#define EDIT 6
#define SORT 7
#define RATE 8
#define PLAY 9
#define SHUFFLE 10
#define EXIT 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct duration
{
	int seconds;
	int minutes;
}Duration;

typedef struct record
{
	char artist[25];
	char album[25];
	char title[25];
	char genre[25];
	Duration Length;
	int times_played;
	int Rating;
}Record;

typedef struct node
{
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;

int menu(void);
Node *makeNode(char *newArtist, char *newAlbulm, char *newTitle, char *newGenre, int minutes, int seconds, int played, int rate);
void load(FILE *infile, Node **pList);
void store(FILE *outfile, Node *pList);
void display(Node *pList);
void edit(Node *pList);
int get_field(Node *pCur);
void rating(Node *pList);
void play(Node *pList);



#endif // !PA2_H
