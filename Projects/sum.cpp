/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task A

This program reads a sequence of integers from cin, and reports their sum.
*/

#include <iostream>
using namespace std;
int main()
{
	int num = 0;
	int sum = 0;
	while (cin >> num) //Reads the integers in numbers.txt
	{
		sum = sum + num; //Adds the integers together
	}
	cout << sum << endl; //Prints the sum
	return 0;
}
