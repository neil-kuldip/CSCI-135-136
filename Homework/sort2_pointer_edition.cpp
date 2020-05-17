/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.1 - Sort 2 (Pointers)

This program has function void sort2(double *p, double* q) that receives two pointers
and sorts the values to which they point to. 
*/
#include <iostream>
using namespace std;

void sort2(double* p, double* q) 
{
	double larger = 0; //Temporary holding variable
	if (*p > *q) //Dereferencing to compare address's object values
	{
		larger = *p; //Larger will have the value of x
		*p = *q; //x will have the value of y
		*q = larger; //q will have the value of x
	}
}

int main()
{
	double x = 0; 
	double y = 0; 
	cout << "Enter the first number (x): ";
	cin >> x; 
	cout << "Enter the second number (y): ";
	cin >> y;

	sort2(&x, &y); //Calls on the sorting function defined ealrier with the addresses of the variables

	cout << "The value of x is: " << x << endl;
	cout << "The value of y is: " << y << endl;
}