//Functions for inventory using structs. 

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "Inventory.h"

int AddProducts(Product products[], int numProducts)
{
	printf("Enter ID and name (one word)\n");
	scanf("%d%s", &products[numProducts].ID, products[numProducts].name);
	return numProducts + 1;
}

void DeleteProducts(Product products[], int* numProducts)
{
	printf("Enter the ID of the product to delete\n");
	int targetID;
	scanf("%d", &targetID);
	for (int i = 0; i < numProducts; i++)
	{
		if (products[i].ID == targetID)
		{
			products[i].ID = products[(*numProducts) - 1].ID;
			strcpy(products[i].name, products[(*numProducts) - 1].name);
			(*numProducts)--;
			break;
		}
	}
}

void PrintProducts(Product products[], int numProducts)
{
	if (numProducts > 0)
	for (int i = 0; i < numProducts; i++)
	{
		printf("%d %s\n", products[i].ID, products[i].name);
	}
	else
	{

	}
}

char* FindProductNameByID(Product products[], int numProducts)
{
	printf("Enter the ID of the product to find the name\n");
	int targetID;
	scanf("%d", &targetID);
	for (int i = 0; i < numProducts; i++)
	{
		if (products[i].ID == targetID)
		{
			return products[i].name;
		}
	}
	return NULL;
}

void SortInventoryByID(Product products[], int numProducts)
{
	if (numProducts > 0)
	{
		Product temp[1];
		for (int i = 0; i < numProducts - 1; i++)
		{
			int invSmallest = i;
			for (int j = i + 1; j < numProducts; j++)
			{
				if (products[j].ID < products[invSmallest].ID)
				{
					invSmallest = j;
				}
			}
			temp[0] = products[i];
			products[i] = products[invSmallest];
			products[invSmallest] = temp[0];
		}
	}
	else
	{
		printf("No items currently in inventory.\n");
	}
}