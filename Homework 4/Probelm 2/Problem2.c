/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/27/22
// Problem 2: Recursive function warmup
// Purpose: Use the recursive binary search algorithm to find words in a large list
///////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "search.h"

int main()
{
	char wordList[87337][30];//word list pointer to store words from text file.
	char s[30]; //stores each word temporarily 
	char userWord[30]; //word that user enters to search in list.
	int match; //boolean if there is a match or not.

	//set up a pointer to the beggining of the words.txt, 
	//and prints error message if file isn't able to be read. 
	FILE* fp;
	fp = fopen("words.txt", "r");
	if (fp == NULL)
	{
		printf("Can't read file.\n");
		return 0;
	}

	int i = 0; //used to iterate through code.
	while (fgets(s, 30, fp)) //iterates through each word and stores them in the wordList array.
	{
		s[strlen(s) - 1] = '\0';
		strcpy(wordList[i], s);
		i++;
	}
	fclose(fp);

	//prompts user for word to search
	printf("Enter word: ");
	fgets(userWord, 30, stdin);
	userWord[strlen(userWord) - 1] = '\0';

	//function call
	match = WordFinder(wordList, userWord, 0, 87336);
	if (match == -1)
		printf("Word Not Found\n");
	else
		printf("Word Found!\n");
	return 0;
}