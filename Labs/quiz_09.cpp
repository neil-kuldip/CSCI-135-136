/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Quiz #9

This program returns the difference of unbalanced open and closed blocks of brackets in the input.
*/
#include <iostream>
#include <string>
using namespace std;

int unbalanced_brackets(string input)
{
	int total = 0;
	int length = input.length();
	for (int i = 0; i < length; i++) //Iterates through the whole string
	{
		if (input[i] == '{') //Open brace adds to the total
		{
			total++;
		}
		else if (input[i] == '}') //Closed brace deducts from the total
		{
			total--;
		}
	}
	return total;
}

int main()
{
	string input;
	cout << "Please enter a string: ";
	getline(cin, input);

	int difference = unbalanced_brackets(input); //Calls the function
	cout << "The difference is " << difference << endl;

	return 0;
}