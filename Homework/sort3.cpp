/*
Author: Neil Kuldip
Course: CSCI-135
Instuctor: Gennady Maryash
Assignment: Homework E5.15 - Sort 3

This program includes the function void sort3(int a, int b) that swaps its three arguments and arranges them 
in sorted order.
*/

#include <iostream>
using namespace std;

void sort3(int& a, int& b, int& c) //Function that swaps values into ordered set
{
	int larger = 0; //Variables to hold the values temporarily
	int middle = 0;
	int smaller = 0;
	if ((a > b) && (a > c))
	{
		larger = a;
		if (b > c)
		{
			middle = b;
			smaller = c;
		}
		else if (c > b)
		{
			middle = c;
			smaller = b;
		}
	}
	if ((b > a) && (b > c))
	{
		larger = b;
		if (a > c)
		{
			middle = a;
			smaller = c;
		}
		else if (c > a)
		{
			middle = c;
			smaller = a;
		}
	}
	if ((c > a) && (c > b))
	{
		larger = c;
		if (a > b)
		{
			middle = a;
			smaller = b;
		}
		else if (b > a)
		{
			middle = b;
			smaller = a;
		}
	}
	a = smaller;
	b = middle;
	c = larger;
}

int main()
{
	int a = 0; //Asks user for input
	int b = 0; //2nd input
	int c = 0; //3rd input
	cout << "Enter a number (value of a): ";
	cin >> a;
	cout << "Enter another number (value of b): ";
	cin >> b;
	cout << "Enter one last number (value of c): ";
	cin >> c;
	sort3(a, b, c); //Calls on the sorting function defined ealrier

	cout << "The value of a is: " << a << endl;
	cout << "The value of b is: " << b << endl;
	cout << "The value of c is: " << c << endl;
}