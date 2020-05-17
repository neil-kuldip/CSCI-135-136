/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 3 - Task C

This program asks the user to input two dates (the beginning and the end of the interval). 
The program should check each day in the interval and report which basin had higher elevation 
on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
	ifstream fin("Current_Reservoir_Levels.tsv"); //Reads the tsv file
	if (fin.fail()) //Failsafe if the tsv file is not found or is corrupted
	{
		cerr << "File cannot be opened for reading" << endl; //Prints error message
		exit(1); //Exits if fail to open
	}

	string junk; //New string variable
	getline(fin, junk); //Skips one line to read the actual data

	string begin; //String for user's beginning date
	cout << "Enter starting date (MM/DD/YYYY): ";
	cin >> begin;

	string end; //String for user's ending date
	cout << "Enter ending date (MM/DD/YYYY): ";
	cin >> end;
	cout << endl; //Skips a line

	string date; //String for the dates cataloged in the file
	double eastSt; //Double variable for the East Basin storage
	double eastEl; //Double variable for the East Basin elevation
	double westSt; //Double variable for the West Basin storage
	double westEl; //Double variable for the West Basin elevation

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) //Reading each column's values
	{
		fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns

		if (begin <= date && date <= end) //If the dates in the catalog fit this range
		{								  
			if (eastEl < westEl) 
			{
				cout << date << " " << "West" << endl;
			}
			else if (eastEl > westEl)
			{
				cout << date << " " << "East" << endl;
			}
			else if (eastEl == westEl)
			{
				cout << date << " " << "Equal" << endl;
			}
		} //Compares east and west basin, proceeds to print the date and the name of the basin
	}
	fin.close(); //Closes the stream
	return 0;
}