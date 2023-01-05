/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 3/4/22
// Homework #2: Problem 6: Seperate Compilation
// Purpose: demonstrate the usage of multiple files to run a single program.
///////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "squareroot.h"

int main()
{
	double userNumSquareRoot;
	double userNumAbsVal;
	printf("Enter the number you wish to find the square root of:\n");

	scanf("%lf", &userNumSquareRoot); //checks square root function
	printf("Square root function test: %lf\n", bablylonianSquareRoot(userNumSquareRoot));

	printf("\nEnter the number you wish to find the absolute value of:\n"); //checks absolute value function.
	scanf("%lf", &userNumAbsVal);
	printf("absolute value function test: %lf\n", absoluteValue(userNumAbsVal));
	return 0;
}