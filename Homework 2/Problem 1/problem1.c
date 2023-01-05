/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 3/4/22
// Homework #2: Problem 1: Arrays
// Purpose: use an array to randomly assign grades
///////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main(void)
{
	srand((int)time(0));
	char studentGrades[20];
	int randStu;

	for (int i = 0; i < 20; i++) //assigns all elements to Z
	{
		studentGrades[i] = 'Z';
	}

	for (int i = 0; i < 5; i++) // iterates to add 5 grades of A to 5 random students
	{
		randStu = rand() % 20;
		while (studentGrades[randStu] != 'Z') // checks to see if element is already assigned a grade and trys a new number
		{									  
			randStu = rand() % 20;
			continue;
		}
		studentGrades[randStu] = 'A';
	}
	
	for (int i = 0; i < 5; i++) // iterates to add 5 grades of B to 5 random students
	{
		randStu = rand() % 20;
		while (studentGrades[randStu] != 'Z') // checks to see if element is already assigned a grade and trys a new number
		{
			randStu = rand() % 20;
			continue;
		}
		studentGrades[randStu] = 'B';
	}

	for (int i = 0; i < 10; i++) // iterates to add 10 grades of C to 10 random students
	{
		randStu = rand() % 20;
		while (studentGrades[randStu] != 'Z') // checks to see if element is already assigned a grade and trys a new number
		{
			randStu = rand() % 20;
			continue;
		}
		studentGrades[randStu] = 'C';
	}

	for (int i = 0; i < 20; i++) //prints out all grades for each student
	{
		printf("Student %d: %c\n", i + 1, studentGrades[i]);
	}
	
}