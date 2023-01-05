/******************************************
* Ashton Curry
* Assignment 1
* Problem 1
* 1/28/22
* Description: This program decodes Social Security Numbers
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

int main()
{
    int socialSecNum;
    int firstThreeDigits;

    scanf("%d", &socialSecNum); //input social security number

    firstThreeDigits = socialSecNum / 1000000; // gets the first 3 digits (division always rounds down)

    if (firstThreeDigits == 574) {
        printf("From Alaska");
    }
    else if (firstThreeDigits >= 531 && firstThreeDigits <= 539) {
        printf("From Washington.");
    }
    else if (firstThreeDigits >= 540 && firstThreeDigits <= 544) {
        printf("From Oregon.");
    }
    else if (firstThreeDigits >= 545 && firstThreeDigits <= 573) {
        printf("From California.");
    }
    else {
        printf("a state other than AK, CA, WA, OR.");
    }

    return 0;
}