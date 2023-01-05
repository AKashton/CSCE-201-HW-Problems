#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXENTRIES 100
#define STRMAX 50
//struct for the ID and name of the database.
typedef struct Product
{
	int ID;
	char name[STRMAX];
} Product;

/*****************************************************************
* Name: AddProducts
* Description: Adds a user entered product name and ID to array.
* Inputs: product struct and pass by pointer the number of current products
* Returned value: new number of product. 
*****************************************************************/
int AddProducts(Product products[], int numProducts);

/*****************************************************************
* Name: DeleteProducts
* Description: Removes a product name and ID from the array.
* Inputs: product struct and pass by pointer the numProducts.
* Returned value: Nothing is returned.
*****************************************************************/
void DeleteProducts(Product products[], int* numProducts);

/*****************************************************************
* Name: PrintProducts
* Description: prints out the list of products. 
* Inputs: product struct and the number of products.
* Returned value: nothing is returned.
*****************************************************************/
void PrintProducts(Product products[], int numProducts);

/*****************************************************************
* Name: FindProductNameByID
* Description: Finds a product in the database by a user inputed ID.
* Inputs: product struct and the numProducts
* Returned value: a pointer array that is either NULL or the address for the product name.
*****************************************************************/
char* FindProductNameByID(Product products[], int numProducts);

/*****************************************************************
* Name: SortInventoryByID
* Description: Sorts the inventory list by ID in acending order 
* Inputs: product struct and the numProducts
* Returned value: a pointer array that is either NULL or the address for the product name.
*****************************************************************/
void SortInventoryByID(Product products[], int numProducts);