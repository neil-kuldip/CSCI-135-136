/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 2 - Task B

This program asks the user to input two integers L and U 
(representing the lower and upper limits of the interval), 
and print out all integers in the range L ≤ i < U separated by spaces. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int L = 0; //Asks the user for the lower limit
	cout << "Please enter L: ";
	cin >> L;

	int U = 0; //Asks the user for the upper limit
	cout << "Please enter U: ";
	cin >> U;

	for (int j = L; j < U; j++) //Initializes and increases the value of j 
	{
		cout << j << " "; //Continues printing each value of j until value reaches upper limit
	}
	return 0;
}