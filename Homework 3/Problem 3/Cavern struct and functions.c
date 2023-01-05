//function implimentations for cavern game.

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Cavern struct and functions.h"

void DirChoices(Cavern* posPlayer)
{
	if (posPlayer->north != NULL)
		printf(" North");
	if (posPlayer->south != NULL)
		printf(" South");
	if (posPlayer->east != NULL)
		printf(" East");
	if (posPlayer->west!= NULL)
		printf(" West");
	printf("\n");
}

Cavern* PlayerChoice(Cavern* posPlayer)
{
	char dirChosen; // players direction that they chose.
	int choice = 0;
	
	do
	{
		scanf(" %c", &dirChosen); //takes user input and then checks for validity. 

		if ((dirChosen == 'N' || dirChosen == 'n') && posPlayer->north != NULL)
		{
			return posPlayer->north; //returns the new pointer to the next area. 
			choice = 1; 
		}
		else if ((dirChosen == 'S' || dirChosen == 's') && posPlayer->south != NULL)
		{
			return posPlayer->south;
			choice = 1;
		}
		else if ((dirChosen == 'E' || dirChosen == 'e') && posPlayer->east != NULL)
		{
			return posPlayer->east;
			choice = 1;

		}
		else if ((dirChosen == 'W' || dirChosen == 'w') && posPlayer->west != NULL)
		{
			return posPlayer->west;
			choice = 1;
		}
		else
		{
			printf("Please enter a valid choice\n");
		}
	} while (choice != 1);

}