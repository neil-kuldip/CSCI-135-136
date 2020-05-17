/*
Author: Neil Kuldip
Course: CSCI-135
Instuctor: Gennady Maryash
Assignment: Homework E5.14 - Sort 2

This program includes the function void sort2(int a, int b) that swaps the value of a and b if the 
value of a is greater than b. Otherwise the values are left unchanged.
*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b) //Function that swaps values if a > b, otherwise stays the same 
{
	int larger = 0; //Variable to hold the value of a temporarily 
	if (a > b)
	{
		larger = a;
		a = b;
		b = larger;
	}
}

int main()
{
	int a = 0; //Asks user for input
	int b = 0; //2nd input
	cout << "Enter a number (value of a): ";
	cin >> a; //Reference parameter 
	cout << "Enter another number (value of b): ";
	cin >> b; //Reference parameter
	sort2(a, b); //Calls on the sorting function defined ealrier

	cout << "The value of a is: " << a << endl;
	cout << "The value of b is: " << b << endl;
}