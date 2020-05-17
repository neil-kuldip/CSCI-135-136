/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 3 - Task D

This program asks the user to input two dates (earlier date then later date). 
The program should report the West basin elevation for all days in the interval 
in the reverse chronological order (from the later date to the earlier).
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

	string earlier; //String for user's earlier date
	cout << "Enter earlier date (MM/DD/YYYY): ";
	cin >> earlier;

	string later; //String for user's later date
	cout << "Enter later date (MM/DD/YYYY): ";
	cin >> later;
	cout << endl;

	string date; //String for the dates cataloged in the file
	double eastSt; //Double variable for the East Basin storage
	double eastEl; //Double variable for the East Basin elevation
	double westSt; //Double variable for the West Basin storage
	double westEl; //Double variable for the West Basin elevation
	string datearry[400]; //Array for the cataloged dates
	double elevate[400]; //Array for the elevation values
	int x = 0; //Starting value of 0 for the arrays

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) //Reading each column's values
	{
		fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns

		if (earlier <= date && date <= later) //If the dates fit within this range
		{
			datearry[x] = date; //Sets the array's values to the dates
			elevate[x] = westEl; //Sets the array's calues to the west basin elevation
			x++; //Increments the x value with each date that satifies the criteria
		}
	}
	for (int i = x-1; i >= 0; i--) //Arranges the values from highest to lowest and decreasing 
	{
		cout << datearry[i] << " " << elevate[i] << endl; //Prints the date and the elevation value
	}

	fin.close(); //Closes the stream
	return 0;
}