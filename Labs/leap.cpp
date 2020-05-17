/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 1C

This program asks the user to input an integer representing a year number. 
If the input year is a leap year it should print Leap year, otherwise, print Common year.
*/

#include <iostream>
using namespace std;

int main()
{
	//User's input for the year
	int year = 0;
	cout << "Enter year: ";
	cin >> year;

	//Determing leap year
	if (year % 4 != 0)
	{
		cout << endl << endl << "Common Year" << endl;
	}
	else if (year % 100 != 0)
	{
		cout << endl << endl << "Leap Year" << endl;
	}
	else if (year % 400 != 0)
	{
		cout << endl << endl << "Common Year" << endl;
	}
	else
	{
		cout << endl << endl << "Leap Year" << endl;
	}
	return 0;
}