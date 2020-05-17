/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 12 - Task D

This program implements the function vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) 
that returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments. 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int>& v1, vector<int>& v2) 
{
	vector<int> sum;
	int diff = 0;
	if (v1.size() > v2.size()) //Compares sizes for bigger vector
	{
		diff = v1.size() - v2.size();
		for (int i = 0; i < diff; i++)
		{
			v2.push_back(0); //Adds placeholders to later add index elements
		}
	}
	else
	{
		diff = v2.size() - v1.size();
		for (int i = 0; i < diff; i++)
		{
			v1.push_back(0);
		}
	}
	for (int i = 0; i < v1.size(); i++)
	{
		sum.push_back(v1[i] + v2[i]); //Adds the indexes together
	}
	return sum; //Returns single sum vector
}

int main()
{
	int input;
	cout << "Enter numbers for the first vector: ";
	vector<int> first;
	for (int i = 0; i < 6; i++) //Takes user input
	{
		cin >> input;
		first.push_back(input);
	}

	vector<int> second;
	cout << "Enter numbers for the second vector: ";
	for (int i = 0; i < 6; i++) //Takes user input
	{
		cin >> input;
		second.push_back(input);
	}

	vector<int> result = sumPairWise(first, second);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}