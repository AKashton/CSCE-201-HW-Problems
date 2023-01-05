/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/27/22
// Problem 4: Recursion with dropoff words
// Purpose: Use the recursive binary search algorithm to find words in a large list
///////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "search.h"

int DropOffWord(char wordList[87337][30], char userWord[], int length)
{
	int valid; // checks word validity, not valid if value returned is -1.
	valid = WordFinder(wordList, userWord, 0, 87336);
	if (length == 1) //word gets down to the final element (should automatically be a or i)
		return 1;
	if (valid == -1) //word invalid, return 0
		return 0;

	char tmpWord[30]; //stores the current word in the list temporarily to edit and pass to the recursive call. 
	strcpy(tmpWord, userWord);

	int deletePos = 0; //holds the current element to delete in searching for dropoff

	while (deletePos < length) // iterates through all element deletion possibilites of the current word to see if its a DropOff word.
	{
		for (int i = deletePos; i < length; i++) //deletes a single element starting at the first element
		{
			tmpWord[i] = tmpWord[i + 1];
		}

		if (WordFinder(wordList, tmpWord, 0, 87336) == -1) //if the word isn't valid after the element is deleted the iteration continues with a new element.
		{
			strcpy(tmpWord, userWord);
			deletePos++;
			continue;
		}
		else
		{
			//recusively goes through all words, if the recursive function reaches one then it 
			//proves its a dropoff word and returns 1 to the rest of the recusive calls
			//which then returns 1 to main. 
			if (DropOffWord(wordList, tmpWord, strlen(tmpWord)) == 1)
			{
				//prints off sequence for each dropoffword, commented out for sanity.
				//printf("%s\n", userWord); 
				return 1;
			}
			else //retries same word if the previous recursive function did not find a
			{
				strcpy(tmpWord, userWord);
				deletePos++;
			}
		}
	}
	return 0; //returns 0 if the while loop is unable to validate a dropoff word
}

int main()
{
	char wordList[87337][30];//word list to store words from text file.
	char s[30]; //stores each word temporarily 
	char userWord[30]; //word that user enters to search in list.
	//int match; //boolean if there is a valid word match or not.

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

	int longestDrop = 0; //checks for longest dropOff word
	char longestWord[30]; //stores longest word
	for (int i = 0; i < 87337; i++) //iterates through all words in the word list file. 
	{
		int dropWord = 0;
		dropWord = DropOffWord(wordList, wordList[i], strlen(wordList[i])); // if 1, dropoff function found dropoff word
		
		if (dropWord == 1) // compares the length of the sequence of dropoff word that is found
		{
			
			
			if (longestDrop <= strlen(wordList[i]))
			{
				longestDrop = strlen(wordList[i]); //stores largest sequence found of dropoff words.
				strcpy(longestWord, wordList[i]); //stores the current longest dropoff word. 
				
			}
		}

	}
	printf("Longest Drop off word: %s\nlength: %d\n", longestWord, longestDrop); //prints out the longest dropoff word and its sequence length.
	//the longest word I chose to sequence was restating. Its sequence goes:
	// i, in, tin, ting, sting, sating, stating, estating, restating, restarting
	return 0;
}
