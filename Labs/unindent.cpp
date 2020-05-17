/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 7 - Task A

This program uses the function: string removeLeadingSpaces(string line); and
reads input from cin to print out each input line with leading spaces removed.
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string removeLeadingSpaces(string line)
{
	int length = line.length();
	int i = 0; //Finding the index for substring
	for (i = 0; i < length; i++)
	{
		if (!isspace(line[i])) //Getting the index of the first non-space character
		{
			break;
		}
	}
	return (line.substr(i, length)); //Prints the line without the beginning spaces
}

int main()
{
	string line;
	while (getline(cin, line)) //Retrieves line from input redirection
	{
		cout << removeLeadingSpaces(line) << endl; //Calls function and prints result
	}
	return 0;
}