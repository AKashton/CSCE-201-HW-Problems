//////////////////////////////////////////////////////
// CSCE A201
// Ashton Curry
// problem 3b
// 1/28/22
// Purpose: Convert a Fahrenheit Temp to Celsius
//////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

int main()
{
        int celsius;
        int fahrenheit;

        printf("Enter a temperature in Fahrenheit. \n");
        scanf("%d", &fahrenheit);
        celsius = ((fahrenheit - 32) * 5) / 9;
        printf("%d in Fahrenheit is %d in Celsius.\n",fahrenheit, celsius);
}