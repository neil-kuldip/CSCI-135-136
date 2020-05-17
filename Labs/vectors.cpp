/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 12 - Task A

This program contains the function: program a function called vector<int> makeVector(int n) 
that returns a vector of n integers that range from 0 to n-1
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n)
{
	vector<int> result; //Contains list of sequential integers up to n-1 
	for (int i = 0; i < n; i++)
	{
		result.push_back(i);
	}
	return result;
}

int main()
{
	int num = 0;
	cout << "Please enter a number: ";
	cin >> num;

	vector<int> result = makeVector(num); //Calls function and contains the result
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " "; //Prints each element in vector
	}
}