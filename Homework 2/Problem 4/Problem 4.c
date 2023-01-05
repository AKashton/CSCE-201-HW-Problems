/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 3/4/22
// Homework #2: Problem 4: Babylonian Algorithm
// Purpose: iterate through the babylonian algorithm given a number.
///////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

double babAlgo(double n);

/*****************************************************************
* Name: babAlgo
* Description: iterates through babylonian algorithm 1000 times.
* Inputs: double n value retrieved from main.
* Returned value: a double from iterating the n value 1000 times.
*****************************************************************/
double babAlgo(double n)
{
	double answer;
	answer = n / 2.0; //assigns value from n call.

	for (int i = 0; i < 1000; i++) //iterates through bab algo.
	{
		double r;
		r = n / answer;
		answer = (answer + r) / 2.0;
	}
	return answer;
}
int main() //calls three values then finds a value from user to call.
{
	double num1;
	printf("The square root of 26 is: %lf\n", babAlgo(26));
	printf("The square root of 67 is: %lf\n", babAlgo(67));
	printf("The square root of 1939 is: %lf\n", babAlgo(1939));
	printf("Enter a number to find its square root:\n");
	scanf("%lf", &num1);
	printf("The square root of %lf is: %lf\n", num1, babAlgo(num1));

}