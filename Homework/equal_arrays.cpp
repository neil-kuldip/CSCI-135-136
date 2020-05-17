/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework 6.8 - Equal Arrays

This program contains the function: bool equals(int a[], int a_size, int b[], int b_size), which will check two arrays
if they have the same elements in the same order
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size)
{
	if (a_size != b_size) 
	{
		return false;
	}
	for (int i = 0; i < a_size; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	const int SIZE = 10;
	int first[SIZE];
	int second[SIZE];
	
	for (int i = 0; i < SIZE; i++) //Take's user's input for the first array
	{
		cout << "Enter elements for the first array: ";
		cin >> first[i];
	}
	for (int j = 0; j < SIZE; j++) //Take's user's input for the second array
	{
		cout << "Enter elements for the second array: ";
		cin >> second[j];
	}

	bool congruent = equals(first, SIZE, second, SIZE); //Sets new bool variable to hold the value of the function's return value
	if (!congruent)
	{
		cout << "Not the same" << endl;
	}
	else
	{
		cout << "It's the same" << endl;
	}
	return 0;
}