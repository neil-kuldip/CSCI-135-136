/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 7 - Task B

This program reads the input line by line, it should also count the number of open and 
closed { } in it, and keep track of how many blocks is currently open at the beginning of each line.
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

int countChar(string line, char c)
{
	int count = 0;
	int length = line.length();
	for (int i = 0; i < length; i++)
	{
		if (line[i] == c)
		{
			count ++;
		}
	}
	return count;
}

int main()
{
	string line;
	int indent = 0;
	while (getline(cin, line))
	{
		line = removeLeadingSpaces(line); //Removes leading spaces from line
		if (line[0] == '}') //If the starting character is a closing brace
		{
			indent--; //Decrement the indent
		}

		for (int i = 0; i < indent; i++)
		{
			cout << '\t'; //Print indent per line
		}
		cout << line << endl; //Prints well-formatted line

		indent += countChar(line, '{'); //Increments indent if open brace
		if (line[0] != '}')
		{
			indent -= countChar(line, '}'); //Decrements but in the case if it's the first char
		}
	}
	return 0;
}
