/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/27/22
// Problem 3: Recursive function 
// Purpose: Use a recursive function to add up string pairs
///////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


/*****************************************************************
* Name: countPairs
* Description: This function uses recursion to iterate through a string and compare two elements to find pairs.
* Inputs: the string to use for finding pairs
* Returned value: The number of pairs found in the string (i.e axa has one pair and axax 2 and axaxa has 3)
*****************************************************************/
int countPairs(char* str)
{
	//base case: if string reaches end return 0 since characters can't be equal.
	if (*str == '\0' || *(str + 2) == '\0')
		return 0;

	//recursive function goes through each element and compares to the element + 2,
	//if characters are equal it adds one, else keeps calling until \0 is reached.
	if (*str == *(str + 2))
		return 1 + countPairs(str + 1);
	else
		return countPairs(str + 1);
}

int main()
{
	char str[30]; //string to hold for counting pairs.
	int numPairs; // holds the number of pairs found from countPairs

	printf("Enter a string: ");
	fgets(str, 30, stdin);

	//eliminates end-of-line char for fgets
	str[strlen(str) - 1] = '\0';

	//calls recursive function for counting pairs.
	numPairs = countPairs(str);

	printf("Number of Pairs: %d\n", numPairs);
	
	return 0;
}