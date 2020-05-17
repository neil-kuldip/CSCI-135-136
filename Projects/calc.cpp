/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task B

This program is a simple calculator that can add and subtract integers, 
and will accept arbitrarily long mathematical formulas composed of symbols +, -, 
and non-negative integer numbers.
*/

#include <iostream>
using namespace std;

int main()
{
	int num = 0; //Initalizes num variable
	char oper; //Initalizes oper variable

	cin >> num; //Reads the num variable value from formula.txt
	int sum = num; //Sets the sum to the first number 

	while (cin >> oper >> num) //Reads and loops through each operator and number in .txt 
	{
		if (oper == '+') //Identifies addition symbol
		{
			sum = sum + num; //If addition, then adds the number to the sum
		}
		else if (oper == '-') //Identifies subtraction symbol
		{
			sum = sum - num; //If subtraction, then subtracts the number from the sum
		}
	}
	cout << sum << endl; //Prints the sum
}