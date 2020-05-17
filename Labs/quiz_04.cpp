//Author: Neil Kuldip
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Quiz #4

//This program opens a file stream to a file called "data.txt", 
//and reads the lines one by one and prints them out on screen. 
//Then the program will close the file stream.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main()
{
	ifstream fin("data.txt"); //Reads the data text file
	string colors; //Reads each line from the line

	while (getline(fin, colors)) //While there's lines to read from the file
	{
		cout << colors << endl; //Print the lines
	}
	fin.close(); //Closes the file

	return 0;
}