/////////////////////////////////////////////////////////////////// 
// CSCE A201
// Ashton Curry
// Due Date: 4/27/22
// Problem 5: Lab 5 but c++
// Purpose: use selection sort with string type and sort both numbers and string array.
///////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int celsius;
	int fahrenheit;
	string city;

	cout << "What city are you in?" << endl;
	cin >> city;
	cout << "What is the temperature in Fahrenheit?" << endl;
	cin >> fahrenheit;
	celsius = ((fahrenheit - 32) * 5) / 9;
	cout << "In " << city << " it is " << celsius << " in Celsius." << endl;
	


	/*
	int ids[10] = { 20, 30, 10, 40, 90, 80, 100, 70, 60, 50 };
	string names[10];
	names[0] = "utility belt";
	names[1] = "golden lasso";
	names[2] = "kryptonite";
	names[3] = "web fluid";
	names[4] = "virbranium";
	names[5] = "soul stone";
	names[6] = "ten rings";
	names[7] = "power rings";
	names[8] = "trident";
	names[9] = "spandex suit";
 
	for (int i = 0; i < 9; i++) //starts with first number entry and continues to second-to-last
	{
		int smallestNumIndex = i; // used to store 

		for (int j = i + 1; j < 10; j++) //starts with second entry to last entry.
		{
			if (ids[j] < ids[smallestNumIndex]) //compares elements to find the shortest
			{
				smallestNumIndex = j; 
			}
		}
		//sorts the smallest id and name to the front of list.
		int temp = ids[i];
		ids[i] = ids[smallestNumIndex];
		ids[smallestNumIndex] = temp;

		//sorts names to follow thier ID positions.
		string temp2;
		temp2 = names[i];
		names[i] = names[smallestNumIndex];
		names[smallestNumIndex] = temp2; 

	}
	for (int i = 0; i < 10; i++) //prints IDs followed by name in proper order
	{
		cout << ids[i] << " " << names[i] << endl;
	}
	*/
	return 0;
}