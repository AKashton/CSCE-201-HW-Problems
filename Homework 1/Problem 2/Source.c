/******************************************
* Ashton Curry
* Assignment 1
* Program 2
* Date Completed: 1/28/22
* Description: Count binary up to 15 using loops.
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
int main()
{
	int threeBaseTwo = 0, twoBaseTwo = 0, oneBaseTwo = 0, zeroBaseTwo = 0; // represents each bit placement
	int binaryToNum; // represents binary to number conversion
	while (threeBaseTwo < 2) {
		twoBaseTwo = 0;
		while (twoBaseTwo < 2) {
			oneBaseTwo = 0;
			while (oneBaseTwo < 2) {
				zeroBaseTwo = 0;
				while (zeroBaseTwo < 2) {
					binaryToNum = (threeBaseTwo * 8) + (twoBaseTwo * 4) + (oneBaseTwo * 2) + (zeroBaseTwo * 1); //converts binary to a decimal
					printf("%d ", binaryToNum);
					printf("%d%d%d%d\n", threeBaseTwo, twoBaseTwo, oneBaseTwo, zeroBaseTwo);
					++zeroBaseTwo;
				}
				++oneBaseTwo;
			}
			++twoBaseTwo;
		}
		++threeBaseTwo;
	}
	return 0;
}