/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 3/4/22
// Homework #2: Problem 2: Inventory
// Purpose: add an option to read a name and return an ID.
///////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"


int main()
{
	const int MAXENTRIES = 100;
	const int STRMAX = 50;
	const int EMPTY = -1;

	int prodIDs[MAXENTRIES];
	char prodNames[MAXENTRIES][STRMAX];
	int choice = 0;
	int numProducts = 0;

	do
	{
		printf("\n1. Add product\n");
		printf("2. Delete by ID\n");
		printf("3. Print products\n");
		printf("4. Find product name by ID\n");
		printf("5. Find product ID by name\n");
		printf("0. Quit");
		printf("\n");

		scanf("%d", &choice);
		if (choice == 1)
		{
			if (numProducts < MAXENTRIES)
			{
				printf("Enter ID and name (one word)\n");
				scanf("%d%s", &prodIDs[numProducts], prodNames[numProducts]);
				numProducts++;
			}
		}
		else if (choice == 2)
		{
			printf("Enter the ID of the product to delete\n");
			int targetID;
			scanf("%d", &targetID);
			for (int i = 0; i < numProducts; i++)
			{
				if (prodIDs[i] == targetID)
				{
					prodIDs[i] = prodIDs[numProducts - 1];
					strcpy(prodNames[i], prodNames[numProducts - 1]);
					numProducts--;
					break;
				}
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < numProducts; i++)
			{
				printf("%d %s\n", prodIDs[i], prodNames[i]);
			}
		}
		else if (choice == 4)
		{
			printf("Enter the ID of the product to find the name\n");
			int targetID;
			scanf("%d", &targetID);
			for (int i = 0; i < numProducts; i++)
			{
				if (prodIDs[i] == targetID)
				{
					printf("The product name is %s\n", prodNames[i]);
				}
			}
		}
		else if (choice == 5) //new choice to input a name to get an ID number.
		{
			printf("Enter the name of the product to find the ID\n");
			char targetName[STRMAX]; //one array with same length of list of options.
			int nameFound = 0; //bool flag
			scanf("%s", &targetName); //scans for name
			for (int i = 0; i < numProducts; i++) //iterates through list and compares input name with list names. 
			{
				if (strcmp(prodNames[i], targetName) == 0)
				{
					printf("The product ID is %d\n", prodIDs[i]); //prints out ID if name is found in the list.
					nameFound = 1; //flag is set to "true" as name has been found.
					break;
				}
			}
			if (nameFound == 0) //if name is not found, message will be this.
			{
				printf("The name was not found\n");
			}
		}
	} while (choice != 0);

	return 0;
}