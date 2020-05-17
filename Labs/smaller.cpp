//Author: Neil Kuldip
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Lab 1A

//This program asks the user to input two integer numbers
//and prints out the smaller of the two.

#include <iostream>
using namespace std;

int main()
{
	//First integer
	int x = 0;
	cout << "Enter  the first number: ";
	cin >> x;

	//Second integer
	int y = 0;
	cout << "Enter the second number: ";
	cin >> y;

	if (x > y)
	{
		cout << endl << endl << "The smaller of the two is " << y << endl;
	}
	else
	{
		cout << endl << endl << "The smaller of the two is " << x << endl;
	}
	return 0;
}