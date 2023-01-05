/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/27/22
// Problem 1: Vowel search
// Purpose: find the number of consecutive vowels in words and compare them
///////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdio.h"


int main()
{
	//set up a pointer to the beggining of the words.txt, 
	//and prints error message if file isn't able to be read. 
	FILE* fp;
	fp = fopen("words.txt", "r");
	if (fp == NULL)
	{
		printf("Can't read file.\n");
		return 0;
	}

	char s[30]; // temp storage for word to compare with
	int largestVowels = 0;// stores the number of largest vowels in each word
	char wordWithMostVowels[30]; //stores word with greatest consecutive vowels
	
	while (fgets(s, 30, fp)) //iterates through each word of words.txt 
	{
		s[strlen(s) - 1] = '\0';

		int numVowels = 1;// used to temporarily store vowel number and compare to largestVowels
						  // starts at 1 to represent first vowel
		
		for (int i = 0; i < (strlen(s) - 1); i++) //iterates through string
		{
			//checks for consecuitve vowels, adds 1 if the next letter is a consecutive vowel
			//if not, the remaining letters of the word is iterated through and checked for 
			//even longer length of vowels. word is then saved if it has the largest amount of vowels
			// and so is the largest vowel count to compare to future words in document.
			if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') &&
				(s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u') && i < strlen(s) - 2)
			{
				numVowels++; 
			}
			else
			{
				if (numVowels > largestVowels) {
					largestVowels = numVowels;
					strcpy(wordWithMostVowels, s);
				}
				numVowels = 1;
			}
		}
	}
	fclose(fp);

	printf("A word with the most consecutive vowels: %s", wordWithMostVowels);
	return 0;
	
}