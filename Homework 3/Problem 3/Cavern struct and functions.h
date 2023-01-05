/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/8/22
// Homework #3: Problem 3: Lost Underground Adventure
// Purpose: use Link lists to create a small game.
///////////////////////////////////////////////////////////////////
//This header file contains the struct and function prototypes used for the maze game.
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Cavern //holds position, and pointers to adjacent positions. 
{
	char position;
	struct Cavern* north;
	struct Cavern* south;
	struct Cavern* east;
	struct Cavern* west;
} Cavern;


/*****************************************************************
* Name: DirChoices
* Description: This function determines which directions the user can choose from and prints them out.
* Inputs: posPlayer pointer to the current cave
* Returned value: Nothing is returned.
*****************************************************************/
void DirChoices(Cavern* posPlayer);

/*****************************************************************
* Name: PlayerChoice
* Description: This function checks to see the players choice, and reassigns the pointer to the new passage.
* Inputs: posPlayer pointer to the current passage.
* Returned value: the posPlayer pointer assigned to a new passage.
*****************************************************************/
Cavern* PlayerChoice(Cavern* posPlayer);