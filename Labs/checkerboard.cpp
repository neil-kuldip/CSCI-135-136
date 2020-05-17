/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 4 - Task B

This program asks the user to input width and height and
prints a rectangular checkerboard of the requested size 
using asterisks and spaces (alternating).
*/

#include <iostream>
using namespace std;

int main()
{
	int width = 0; //User's desired width
	cout << "Input width: ";
	cin >> width;

	int height = 0; //User's desired height
	cout << "Input height: ";
	cin >> height;

	cout << endl;
	cout << "Shape:" << endl;

	for (int row = 1; row <= height; row++)
	{
		if (row % 2 != 0) //Rows start with asterisk
		{
			for (int col = 1; col <= width; col++)
			{
				if (col % 2 != 0) //Odd column --> asterisk
				{
					cout << "*";
				}
				else if (col % 2 == 0) //Even column --> space
				{
					cout << " ";
				}
			}
		}
		else if (row % 2 == 0) //Rows start with space
		{
			for (int col = 1; col <= width; col++)
			{
				if (col % 2 != 0) //Odd column --> space
				{
					cout << " ";
				}
				else if (col % 2 == 0) //Even column --> asterisk
				{
					cout << "*";
				}
			}
		}
		cout << endl; //Ending each line after execution
	} 
	return 0;
}

