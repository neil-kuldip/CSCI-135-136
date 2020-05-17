/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E3.1 - Positive or Zero or Negative

This program asks the user for a number and depending on the integer value above, below, or equal to zero
the program will print if the user's integer is positive, negative, or zero
*/

#include <iostream>
using namespace std;

int main()
{
	int num = 0; //Asks for user's integer
	cout << "Enter a integer: ";
	cin >> num;

	cout << "The integer is "; 
	if (num > 0) //If number greater than 0, then it's positive
	{
		cout << "positive" << endl;
	}
	else if (num == 0) //If the number is equal to 0, then it's zero
	{
		cout << "zero" << endl;
	}
	else if (num < 0) //if the number is less than 0, then it's negative
	{
		cout << "negative" << endl;
	}
	return 0;
}