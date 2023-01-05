/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/8/22
// Homework #3: Problem 1: Inventory using structs
// Purpose: creates an inventory database using structs and functions.
///////////////////////////////////////////////////////////////////

// This version uses a struct to organize our product information
// and then we create an array of structs
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "Inventory.h"

int main()
{
	Product products[MAXENTRIES];
	int choice = 0;
	int numProducts = 0;

	do
	{
		printf("\n1. Add product\n");
		printf("2. Delete by ID\n");
		printf("3. Print products\n");
		printf("4. Find product name by ID\n");
		printf("5. Sort inventory by ID\n");
		printf("0. Quit");
		printf("\n");

		scanf("%d", &choice);
		if (choice == 1)
		{
			if (numProducts < MAXENTRIES)
			{
				numProducts = AddProducts(products, numProducts);
			}
			else
			{
				printf("Database is full.\n");
			}
		}
		else if (choice == 2)
		{
			DeleteProducts(products, &numProducts);
		}
		else if (choice == 3)
		{
			PrintProducts(products, numProducts);
		}
		else if (choice == 4)
		{
			char* check = NULL; // checks if the returned value is NULL, which indicated the ID is not on the list.
			check = FindProductNameByID(products, numProducts);
			if (check == NULL)
			{
				printf("Product not found.\n");
			}
			else
			{
				printf("The product name is %s\n", check); // if product is on the list, pointer has beggining address.
			}
		}
		else if (choice == 5)
		{
			SortInventoryByID(products, numProducts);
		}
	} while (choice != 0);

	return 0;
}

