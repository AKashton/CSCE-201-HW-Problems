/******************************************
* Ashton Curry
* Assignment 1
* Problem 5
* Date Completed 1/29/22
* Description: Simulate probability of winning game
* The program proves that statistically its much better to choose a new door then to remain at your door to win.
* I'd choose a new door to optimize my chances of winning.
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main()
{
	int cashDoor = 0;
	int playerDoor = 0;
	int playerMoveDoor = 0; // new door player moves to
	int doorReveal = 0; //door that is revealed to player
	int winsStay = 0; // win tracker for staying at door
	int winsMove = 0; // win tracker for moving to new door

	srand((int)time(0)); //unique seed everytime you run the program (so that you don't get the same sequence)
	
	for (int i = 0; i < 1000; ++i) { // computes 1000 iterations of player staying at same door.
		
		cashDoor = (rand() % 3);
		playerDoor = (rand() % 3);

		while ( doorReveal == playerDoor || doorReveal == cashDoor) { // gives the revealed door a value that isn't the cash or player door.
			doorReveal = (rand() % 3);
			continue;
		}

		if (playerDoor == cashDoor) {
			winsStay += 1;
		}
	}
	printf("wins if player doesn't move: %d\n", winsStay);

	for (int i = 0; i < 1000; ++i) { //computes 1000 iterations of player changing doors.
		
		cashDoor = (rand() % 3);
		playerDoor = (rand() % 3);
		
		while ( doorReveal == playerDoor || doorReveal == cashDoor) { // gives the revealed door a value that isn't the cash or player door.
			doorReveal = (rand() % 3);
			continue;
		}

		playerMoveDoor = (rand() % 3); // choose a new door

		while (playerMoveDoor == doorReveal || playerMoveDoor == playerDoor) { // rechooses a new door if new player door is the same as the door that is revealed or original door. 
			playerMoveDoor = (rand() % 3);
			continue;
		}

		if (playerMoveDoor == cashDoor) {
			winsMove += 1;
		}
	}
	printf("wins if player moves: %d", winsMove);
}