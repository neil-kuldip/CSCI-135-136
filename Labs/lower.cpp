/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 4 - Task D

This program prints the bottom-left half of a square, given the side length by the user.
*/

#include <iostream>
using namespace std;

int main()
{
	int length = 0; //Asks user for the triangle side length (the rows)
	cout << "Input side length: ";
	cin >> length;
	cout << endl;
	cout << "Shape:" << endl;

	for (int row = 1; row <= length; row++) //Loops for each row
	{
		for (int col = 0; col < row; col++) //As row increases by 1, each asterisk in each column will
											//increment by 1 as well
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}