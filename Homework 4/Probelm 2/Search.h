//This file contains the search function for the binary algorithim

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/*****************************************************************
* Name: WordFinder
* Description: This function uses the binary search algorithm to find the users word.
* Inputs: the array of words to search, and the two values that represent the range of the list.
* Returned value: The item position in the array. anything other than -1 means it is in the list. 
* Preconditions: word file must be correctly read in. 
*****************************************************************/
int WordFinder(char wordList[87337][30], char userWord[30], int lowVal, int highVal) 
{
	int midVal;        // Midpoint of low and high values
	int itemPos;       // Position where item found
	int rangeSize;     // Remaining range of values to search for match

	itemPos = -1;      // -1 if not found
	rangeSize = (highVal - lowVal) + 1;
	midVal = (highVal + lowVal) / 2;

	if (strcmp(wordList[midVal], userWord) == 0) {   // Base case 1: item found at midVal position
		itemPos = midVal;
	}
	else if (rangeSize == 1) {                           // Base case 2: match not found
		itemPos = -1;
	}
	else {                                               // Recursive case: search lower or upper half
		if (strcmp(userWord, wordList[midVal]) < 0) { // Search lower half, recursive call
			itemPos = WordFinder(wordList, userWord, lowVal, midVal);
		}
		else {                                            // Search upper half, recursive call
			itemPos = WordFinder(wordList, userWord, midVal + 1, highVal);
		}
	}

	return itemPos;
}
