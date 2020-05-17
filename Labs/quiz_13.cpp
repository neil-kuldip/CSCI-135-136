/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab Quiz #13

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n)
{
	vector<int> result;
	if (n < 0)
	{
		return result;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			result.push_back(i);
		}
		return result;
	}
}

int main()
{
	int num = 0;
	cout << "Please enter a number: ";
	cin >> num;

	vector<int> result = makeVector(num);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

}