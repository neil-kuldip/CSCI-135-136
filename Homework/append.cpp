/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E.18 - Append

This program writes a function: vector<int> append(vector<int> a, vector<int> b) that appends one vector after the other
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b)
{
	for (int i = 0; i < b.size(); i++)
	{
		a.push_back(b[i]);
	}
	return a;
}

int main()
{
	int input;
	vector<int>first;
	for (int i = 0; i < 6; i++)
	{
		cin >> input;
		first.push_back(input);
	}
	vector<int>second;
	for (int k = 0; k < 6; k++)
	{
		cin >> input;
		second.push_back(input);
	}
	vector<int>combined = append(first, second);
	for (int j = 0; j < combined.size(); j++)
	{
		cout << combined[j] << " ";
	}
}
