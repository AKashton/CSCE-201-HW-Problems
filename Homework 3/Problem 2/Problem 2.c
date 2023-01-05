/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Date: 4/8/2022
// Problem 2: double pointers
// Purpose: Use a double pointer to pass concatenated string back to main
///////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//concatenate function prototype
char* concatenate(char s1[], char s2[]);

/*****************************************************************
* Name: concatenate
* Description: This function concatenates two strings into one.
* Inputs: Two strings of characters and a double pointer.
* Returned value: returns pointer to concatenated string.
*****************************************************************/
char* concatenate(char** p, char s1[], char s2[])
{
    *p = (char*)malloc(((strlen(s1) + strlen(s2)) * sizeof(char)) + 1); //allocates memory for both strings

    strcpy(*p, s1); //copys s1 to pointer
    strcat(*p, s2); // concatenateds s2 to s1.

    return p;
}
int main()
{
    char s1[3] = "hi";
    char s2[6] = "there";
    char* p = NULL;

    concatenate(&p, s1, s2);
    printf("%s\n", p);  // Should print hithere

    free(p);
}