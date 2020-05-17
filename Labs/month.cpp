/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 1D

This program asks the user to input the year and the month (1-12) 
and prints the number of days in that month, taking into account leap years. 
*/

#include <iostream>
using namespace std;

int main()
{
	//User's input of year and month
	int year = 0;
	cout << "Enter year: ";
	cin >> year;

	int month = 0;
	cout << "Enter month: ";
	cin >> month;

	//Determining a leap year
	if (year % 4 != 0)
	{
		year = 0;
	}
	else if (year % 100 != 0)
	{
		year = 1;
	}
	else if (year % 400 != 0)
	{
		year = 0;
	}
	else
	{
		year = 1;
	}
	
	//Days by Month
	//Jan
	if (month == 1)
	{
		cout << endl << endl << "31 days" << endl;
	}
	//Feb
	else if (month == 2)
	{
		if (year == 1)
		{
			cout << endl << endl << "29 days" << endl;
		}
		else
		{
			cout << endl << endl << "28 days" << endl;
		}
	}
	//Mar
	else if (month == 3)
	{
		cout << endl << endl << "31 days" << endl;
	}
	//Apr
	else if (month == 4)
	{
		cout << endl << endl << "30 days" << endl;
	}
	//May
	else if (month == 5)
	{
		cout << endl << endl << "31 days" << endl;
	}
	//Jun
	else if (month == 6)
	{
		cout << endl << endl << "30 days" << endl;
	}
	//Jul
	else if (month == 7)
	{
		cout << endl << endl << "31 days" << endl;
	}
	//Aug
	else if (month == 8)
	{
		cout << endl << endl << "31 days" << endl;
	}
	//Sep
	else if (month == 9)
	{
		cout << endl << endl << "30 days" << endl;
	}
	//Oct
	else if (month == 10)
	{
		cout << endl << endl << "31 days" << endl;
	}
	//Nov
	else if (month == 11)
	{
		cout << endl << endl << "30 days" << endl;
	}
	//Dec
	else if (month == 12)
	{
		cout << endl << endl << "31 days" << endl;
	}
	return 0;
}