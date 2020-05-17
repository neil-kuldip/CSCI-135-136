/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 4 - Task E

This program prints the top-right half of a square, given the side length by the user.
*/

#include <iostream>
using namespace std;

int main()
{
	int length = 0; //Asks user for the triangle side length (the rows)
	cout << "Input side length: ";
	cin >> length;
	cout << endl;
	int space = 0; //Spaces per each line before the asterisks
	cout << "Shape:" << endl;

	for (int row = 1; row <= length; row++) 
	{
		for (int col = 0; col < space; col++) 
		{
			cout << " ";
		}
		for (int col = length; col >= row; col--) //Asterisks decreases per row
		{
			cout << "*";
		}
		space++; //Spaces increases per row
		cout << endl;
	}
	return 0;
}