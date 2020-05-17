/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 4 - Task F

This program prints an upside-down trapezoid of given width and height.
*/

#include <iostream>
using namespace std;

int main()
{
	int width = 0; //Asks the user for width of each line
	cout << "Enter width: ";
	cin >> width;
	
	int height = 0; //Asks the user for the height of the trapezoid
	cout << "Enter height: ";
	cin >> height;
	cout << endl;

	int spaces = 0; //Spaces for the sides of the trapezoid
	int stars = width;

	if (height <= (width + 1) / 2)
	{
		cout << "Shape: " << endl;
		for (int row = 0; row < height; row++) 
		{
			for (int col = 0; col < spaces; col++)
			{
				cout << " "; //Spaces will increment to make the bottom smaller
			}
			for (int col1 = 0; col1 < stars; col1++)
			{
				cout << "*"; //Stars will decrease down the trapezoid
			}
			spaces += 1;
			stars -= 2;
			cout << endl;
		}
	}
	else
	{
		cout << "Impossible shape!" << endl; //If out of range, prints message
	}
	return 0;
}