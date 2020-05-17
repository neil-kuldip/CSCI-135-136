/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 4 - Task G

This program asks the user to input width and height and prints a checkerboard of 3-by-3 squares.
*/

#include <iostream>
using namespace std;

int main()
{
	int width = 0; //Asks the user for the width
	cout << "Enter width: ";
	cin >> width;

	int height = 0; //Asks the user for height
	cout << "Enter height: ";
	cin >> height;
	cout << endl;
	cout << "Shape: " << endl;

	for (int row = 1; row <= height; row++) //Rows
	{
		for (int col = 1; col <= width; col++) //Columns
		{	
			if (((row % 3 == 0) && (row % 2 != 0)) || (((row + 1) % 3 == 0) && ((row + 1) % 2 != 0)) || (((row + 2) % 3 == 0) && ((row + 2) % 2 != 0)))
			{ //If a row value is divisible by 3 and isn't even, then that row should start with stars 
			  //If there are two rows behind this row, both of those shall also start with stars
				if ((col % 3 == 0) && (col % 2 != 0)) 
				{
					cout << "*"; //If col is divisble by 3 and not even, must print a star
				}
				else if (((col + 1) % 3 == 0) && ((col + 1) % 2 != 0))
				{
					cout << "*"; //Previous row must print star
				}
				else if (((col + 2) % 3 == 0) && ((col + 2) % 2 != 0))
				{
					cout << "*"; //2nd previous row must also print star
				}
				else
				{
					cout << " "; //Prints space
				}
			}
			else if (((row % 3 == 0) && (row % 2 == 0)) || (((row + 1) % 3 == 0) && ((row + 1) % 2 == 0)) || (((row + 2) % 3 == 0) && ((row + 2) % 2 == 0)))
			{ //If a row value is divisible by 3 and isn even, then that row should start with spaces
			  //If there are two rows behind this row, both of those shall also start with spaces
				if ((col % 3 == 0) && (col % 2 != 0))
				{
					cout << " "; //If col is divisble by 3 and even, must print a space
				}
				else if (((col + 1) % 3 == 0) && ((col + 1) % 2 != 0))
				{
					cout << " "; //Previous row must print space
				}
				else if (((col + 2) % 3 == 0) && ((col + 2) % 2 != 0))
				{
					cout << " "; //2nd previous row must also print space
				}
				else
				{
					cout << "*"; //Prints a star
				}
			}
		}
		cout << endl; //Ends each line after width is reached
	}
	return 0;
}