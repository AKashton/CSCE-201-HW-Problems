/******************************************
* Ashton Curry
* Assignment 1
* Problem 4
* Date Completed 1/28/22
* Description: Find when Fahrenheit is equivalent to Celsius
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"

int main()
{
	double celsius = 0.0;
	double fahrenheit;
	for (fahrenheit = -100; fahrenheit <= 100; ++fahrenheit) {
		celsius = ((5 * (fahrenheit - 32)) / 9); //fahrenheit to celsius conversion.

		if (fabs(fahrenheit - celsius) < 0.001) { //prints out value where fahrenheit and celsius are equal.
			printf("%.1lf\n", celsius);
		}
	}
}