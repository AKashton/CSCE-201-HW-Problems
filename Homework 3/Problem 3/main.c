/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/8/22
// Homework #3: Problem 3: Lost Underground Adventure
// Purpose: use Link lists to create a small game.
///////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Cavern struct and functions.h"

int main()
{
	Cavern posA;
	Cavern posB;
	Cavern posC;
	Cavern posD;
	Cavern posE;
	Cavern posF;
	Cavern posG;
	Cavern posH;
	Cavern posI;

	//defined structs for each maze corridor.
	posA.position = 'A';
	posA.north = NULL;
	posA.south = &posB;
	posA.east = &posC;
	posA.west = NULL;

	posB.position = 'B';
	posB.north = &posA;
	posB.south = &posE;
	posB.east = &posC;
	posB.west = NULL;

	posC.position = 'C';
	posC.north = &posA;
	posC.south = &posE;
	posC.east = &posD;
	posC.west = NULL;

	posD.position = 'D';
	posD.north = &posF;
	posD.south = &posE;
	posD.east = &posG;
	posD.west = &posC;

	posE.position = 'E';
	posE.north = &posD;
	posE.south = NULL;
	posE.east = &posH;
	posE.west = &posB;

	posF.position = 'F';
	posF.north = NULL;
	posF.south = &posD;
	posF.east = NULL;
	posF.west = NULL;

	posG.position = 'G';
	posG.north = NULL;
	posG.south = &posH;
	posG.east = NULL;
	posG.west = &posD;

	posH.position = 'H';
	posH.north = &posG;
	posH.south = NULL;
	posH.east = &posI;
	posH.west = &posE;

	posI.position = 'I';
	posI.north = NULL;
	posI.south = NULL;
	posI.east = NULL;
	posI.west = NULL;

	Cavern *posPlayer = &posA; // pointer for player position.
	int finished = 0;
	printf("You awaken in a maze of twisty little passages, all alike.\n");
	printf("You can go:");
	DirChoices(posPlayer); //prints out the first choices the player has.
	posPlayer = PlayerChoice(posPlayer); // checks player choice and points to new area. 
	
	do //iterates through each part of the maze until the user reaches the end.
	{
		if (posPlayer->position != 'I') //doesn't quit until the player pointer is at cavern I.
		{
			printf("You are in a maze of twisty little passages, all alike\n");
			printf("You can go:");
			DirChoices(posPlayer);
			posPlayer = PlayerChoice(posPlayer);
		}
		else
		{
			printf("You found the exit!\n");
			finished = 1;
		}
	
	} while (!finished);

	return 0;
}