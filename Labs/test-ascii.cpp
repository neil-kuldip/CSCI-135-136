/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 6 - Task A

This program asks the user to input a line of text (which may possibly include spaces). 
Then report all characters from the input line together with their ASCII codes.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cout << "Input: ";
	getline(cin, input); //Extracts all characters, symbols, and spaces until end of the line
	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i]; //Loops through each character in the string array
		cout << c << " " << (int)c << endl; //Prints the character and it's integer code
	}
	return 0;
}