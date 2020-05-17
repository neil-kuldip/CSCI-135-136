/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 12 - Task C

This program implements the function void gogeta(vector<int> &goku, vector<int> &vegeta) 
that appends elements of the second vector into the first and empties the second vector. 
*/
#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int>& goku, vector<int>& vegeta)
{
	for (int i = 0; i < vegeta.size(); i++)
	{
		goku.push_back(vegeta[i]); //Appends vector to include first vector elements
	}
	vegeta.clear(); //Clears second vector of all elements
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

	gogeta(first, second); //Calls the function
	for (int j = 0; j < first.size(); j++)
	{
		cout << first[j] << " ";
	}
	if (second.empty()) //Checks if the second vector was cleared in function
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
}