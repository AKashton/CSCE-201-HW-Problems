/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 3/4/22
// Homework #2: Problem 5: Functions
// Purpose: read a string and convert it to an int
///////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"


/*****************************************************************
* Name: safeReadInt
* Description: converts a valid user defined string into an integer, and checks the string to ensure it is valid.
* Inputs: none
* Returned value: a integer converted from a string.
*****************************************************************/
int safeReadInt()
{
	char userInput[50];
	int strToInt;
	int invalidInput = 0;
	
	do { //takes user input, checks to see if each character is a integer, then loops if not and gets a new input.
		printf("type a number:\n"); 
		scanf("%s", userInput);
		
		for (int i = 0; i < strlen(userInput); i++)
		{
			if (userInput[i] > '9' || userInput[i] < '0')
			{
				printf("\nplease enter an actual number...\n\n");
				invalidInput = 1; //flag to redo loop.
				break;
			}
			else
			{
				invalidInput = 0; //resets flag to zero in case last input was invalid.
			}
		}
	} while(invalidInput == 1);
	
	strToInt = atoi(userInput);  //converts string to integer.
	return strToInt; //returns new integer.
}

int main()
{
	int strConvert;
	strConvert = safeReadInt();
	printf("\nstring to integer: %d\n", strConvert);
	return 0;
}