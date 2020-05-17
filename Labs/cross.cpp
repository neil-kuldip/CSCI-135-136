/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 4 - Task C

This program asks the user to input the shape size, 
and prints a diagonal cross of that dimension.
*/

#include <iostream>
using namespace std;

int main()
{
	int size = 0; //Asks user for desired size
	cout << "Input size: ";
	cin >> size;
	cout << endl;
	cout << "Shape:" << endl;

	for (int row = 1; row <= size; row++) //Rows of shape
	{
		for (int col = 1; col <= size; col++) //Columns of shape
		{
			if ((col == row) || (col == size - row + 1) ) //First asterisk in diagonal moving forward if 
														  //col and row number are the same
			{
				cout << "*";
			}
			else
			{
				cout << " "; //Second asterisks moving diagonally back with
				             //the space in-between asterisks decrements by 1
			}
		}
		cout << endl;
	}

}