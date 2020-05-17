/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task D

This is a calculator program that can understand squared numbers. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num = 0; //Numbers in .txt file
	char after; //Current Operation
	char before = '+'; //Previous Operation
	int sum = 0; //Total per line
	cin >> num; //Reads first number in the first line

	while (cin >> after) //Reads and loops through each operator and number in .txt 
	{
		if (after == '^') //Detects exponent
		{
			num = pow(num, 2); 
			cin >> after; //Reads for the next operator after
		}
		if (before == '+') //Detects addition
		{
			sum = sum + num; 
		}
		else if (before == '-') //Detects subtraction
		{
			sum = sum - num; 
		}

		before = after; 
		cin >> num; //Reads the next number

		if (after == ';') //Detects the end of the line
		{
			cout << sum << endl; 
			sum = 0; //Resets the sum
			before = '+'; //Resets the before value
		}
	}
	return 0;
}
