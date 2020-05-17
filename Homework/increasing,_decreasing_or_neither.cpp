//Author: Neil Kuldip 
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Homework E3.5 - Increasing, Decreasing, or Neither

//This program that asks the user for three numbers, and prints if the numbers are increasing if in increasing order,
//decreasing if in decreasing order or neither


#include <iostream>
using namespace std;

int main()
{
	int num1 = 0;
	cout << "Enter the first number: ";
	cin >> num1;

	int num2 = 0;
	cout << "Enter a second number: ";
	cin >> num2;

	int num3 = 0;
	cout << "Enter a third number: ";
	cin >> num3;
	cout << endl;

	if (num1 < num2 && num2 < num3 && num1 < num3) //Increasing compared to the rest of numbers
	{
		cout << "Increasing" << endl;
	}
	else if (num1 > num2 && num2 > num3 && num1 > num3) //Decreasing compared to the other numbers
	{
		cout << "Decreasing" << endl;
	}
	else
	{
		cout << "Neither" << endl;
	}
	return 0;
}