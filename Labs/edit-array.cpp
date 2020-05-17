/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 2 - Task C

This program creates an array of 10 integers, and provides the 
user with an interface to edit any of its elements.
*/

#include <iostream>
using namespace std;

int main()
{
	int myData[10]; //Creates an array, "myData", with 10 integers

	for (int j = 0; j < 10; j++)
	{
		myData[j] = 1; //For loop sets each element in array to integer value of 1
	}

	int i = 1;
	int v = 1;

	do { //Runs the statements at least once
		myData[i] = v; //Sets the selected index's value to the new value, v

		for (int j = 0; j < 10; j++)
		{
			cout << myData[j] << " "; //For loop reads and prints each element 
		}
		cout << endl; 

		cout << "Input index: "; //Asks the user for the specific index, i
		cin >> i;

		cout << "Input value: "; //Asks the user for the new value of the specified index
		cin >> v;

	} while(i >= 0 && i < 10); //If the index falls within range, the loop will continue

	cout << endl;
	cout << "Index out of range. Exit." << endl; //If the index is out-of-bounds, 
	                                             //the program will exit

	return 0;
}
