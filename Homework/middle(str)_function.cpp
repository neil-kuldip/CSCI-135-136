/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E5.6 - middle(str) function

This program composes of a function middle(str), which returns a string containing the middle character in str
if the length of the str is odd, or the two middle characters if the length is even.
*/

#include <iostream>
#include <string>
using namespace std;

string middle(string str) //Middle string function
{
	int index = (str.length() / 2); //The middle section of string ---> start of substring
	int position = 0; //The length of the substring 
	if (str.length() % 2 != 0) //If the # of characters in the string is odd
	{
		position = 1;
	}
	else if (str.length() % 2 == 0) //If the # of characters in the string is even
	{
		index = index - 1;
		position = 2;
	}
	return str.substr(index, position); //Returns the middle section of the string
}

int main()
{
	string input; //Prompts the user for a word
	cout << "Enter word: ";
	cin >> input;

	string result = middle(input); //Calls middle string function with the string input
	cout << result << endl;

	return 0;
}