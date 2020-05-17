/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 3 - Task B

This program after reading the entire current reservoir tsv file,
will find the the minimum and the maximum storage levels for the entire year.
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

	double max = 0; //Sets initial max value to 0 to be compared to
	double min = 100; //Sets initial min value to 100 to be compared to

	string date; //String for the dates cataloged in the file
	double eastSt; //Double variable for the East Basin storage
	double eastEl; //Double variable for the East Basin elevation
	double westSt; //Double variable for the West Basin storage
	double westEl; //Double variable for the West Basin elevation

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) //Reading each column's values
	{
		fin.ignore(INT_MAX, '\n'); //Skips to the end of line, ignorring the remaining columns

		while (eastSt < min) //Loops and compares the smaller of the two
		{
			min = eastSt; //Replaces the min value with the smaller number
		}

		while (eastSt > max) //Loops and compares the larger of the two
		{
			max = eastSt; //Replaces the max value with the larger number
		}

	}
	cout << "Minimum storage in East bin is: " << min << endl; //Prints maximum value
	cout << "Maximum storage in East bin is: " << max << endl; //Prints minimum value
	fin.close(); //Closes the stream
	return 0;
}