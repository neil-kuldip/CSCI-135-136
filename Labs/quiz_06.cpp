//Author: Neil Kuldip
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Lab Quiz #6

//This program calls the function int max3(int a, int b, int c);
//and proceeds to print the largest of the three

#include <iostream>
using namespace std;

int max3(int a, int b, int c)
{
	if (a < b) //If 2nd num is larger than 1st num
	{
		a = b; //Value of a will remain the largest
	}
	if (a < c) //If 3rd is larger than the a value
	{
		a = c;
	}
	return a; //Returns the largest num
}

int main()
{
	int a = 0;
	cout << "Enter the first number: ";
	cin >> a;

	int b = 0;
	cout << "Enter the second number: ";
	cin >> b;

	int c = 0;
	cout << "Enter the third number: ";
	cin >> c;

	int largest = max3(a, b, c);
	cout << largest << endl;

	return 0;
}