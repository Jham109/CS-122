// Joseph Cuningham cpts 122 PA 6
// program reads in text from a file and converts it to morse code
#include "BST.h"

int main(void)
{
	
	BST tree;
	fstream message;
	char letter;

	message.open("Convert.txt");
	
	tree.PrintInorder();
	
	while (!message.eof())
	{
		message.get(letter);

		if (letter >= 97 && letter <= 122)
		{
			letter -= 32;
		}

		if (letter == 32 || letter == '\n') // whitespace and new lines
		{
			cout << letter;
		}
		else
		{
			tree.search(letter);
		}

	}
	cout << endl;
	

	return 0;
}