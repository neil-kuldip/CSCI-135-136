//Author: Neil Kuldip	
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Quiz #1

//This program prompts the user for a number using 'cin ..' 
//and returns that number of lines that all say 'I love C++'

#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	cout << "Enter a number:" << endl;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cout << "I love C++" << endl;
	}
	return 0;
}
