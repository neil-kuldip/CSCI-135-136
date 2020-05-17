/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 3 - Task A

This program reads the current reservoir tsv file, asks the user to input a string 
representing the date (in MM/DD/YYYY format), and prints out the East basin storage 
on that day.
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
	string date; //String for the dates cataloged in the file
	string input_date; //User's desired date
	cout << "Enter date (MM/DD/YYYY): "; 
	cin >> input_date;
	double eastSt; //Double variable for the East Basin storage
	double eastEl; //Double variable for the East Basin elevation
	double westSt; //Double variable for the West Basin storage
	double westEl; //Double variable for the West Basin elevation

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) //Reading each column's values
	{
		fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns
		if (input_date == date) //If the user's date matches one in the tsv file
		{
			cout << "East basin storage: " << eastSt << " " << "billion gallons" << endl;
		} //Prints the message and the corresponding east basin storage value
	}
	fin.close(); //Closes the stream
	return 0;
}