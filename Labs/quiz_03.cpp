//Author: Neil Kuldip
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Quiz #3

//This program contains an array of numbers, from 1-10, and prints each number on a seperate line

#include <iostream>
using namespace std;

int main()
{
	int num[10];

	for (int i = 1; i < 11; i++)
	{
		num[i - 1] = i;
	}

	for (int j = 0; j < 10; j++)
	{
		cout << num[j] << endl;
	}

}