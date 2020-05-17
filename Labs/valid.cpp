/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 2 - Task A

This program asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, the program should keep asking to re-enter 
until a valid number is input.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num = 0; //Initalizes the variable num
	cout << "Please enter an integer: "; //Ask user for input
	cin >> num;

	do //Ask the user to repeat entering a integer until 0 < num < 100 is met
	{
		cout << "Please re-enter: ";
		cin >> num;
	} while (num <= 0 || num >= 100); //While the number is less than 0 or greater than 100 

	if (0 < num < 100)
	{
		num = pow(num, 2); //Squares the final number
		cout << "Number sqaured is " << num << endl; //Prints the sentence
	}

	return 0;
}