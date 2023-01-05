/***********
squareroot.c
This file implements the functions from squareroot.h to
find the square root and absolute value of n.
************/

#define _CRT_SECURE_NO_WARNINGS
#include "squareroot.h"

/*****************************************************************
* Name: absoluteValue
* Description: finds the absolute value of n.
* Inputs: double n value retrieved from main.
* Returned value: n converted to the absolute value.
*****************************************************************/
double absoluteValue(double n)
{
	if (n < 0) //converts a negative number to its absolute value.
	{
		n *= -1.0;
	}
	return n;
}

/*****************************************************************
* Name: bablylonianSquareRoot
* Description: iterates through babylonian algorithm 1000 times.
* Inputs: double n value retrieved from main.
* Returned value: a double from iterating the n value 1000 times.
*****************************************************************/
double bablylonianSquareRoot(double n)
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
