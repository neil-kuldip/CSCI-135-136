/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 12 - Task B

This program implements the function vector<int> goodVibes(const & vector<int> v); 
that, given a vector of integers, returns a vector with only the positive integers in the same order.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v)
{
	vector<int> result; //Positive integer only vector
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= 0) //Checks if the element is positive or 0
		{
			result.push_back(v[i]);
		}
	}
	return result;
}

int main()
{
	int input;
	cout << "Please enter numbers for the vector:" << endl;
	vector<int> result;

	for (int i = 0; i < 6; i++) //Takes user input
	{
		cin >> input;
		result.push_back(input);
	}
	result = goodVibes(result); //Calls function and stores result
	for (int i = 0; i < result.size(); i++) //Displays result
	{
		cout << result[i] << " ";
	}
}