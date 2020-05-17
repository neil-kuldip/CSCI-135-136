/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task C
*/

#include <iostream>
using namespace std;

int main()
{
	int num = 0; //Initalizes num variable
	char oper; //Initalizes oper variable
	int sum = 0;
	cin >> sum; //Reads first number in the first line

	while (cin >> oper) //Reads and loops through each operator and number in .txt 
	{
		cin >> num;
		if (oper == ';') //Identifies the end of the line
		{
			cout << sum << endl; //Prints the sum
			sum = num; //Sets the sum as the first number in the second line
		}
		else if (oper == '+') //Identifies addition symbol
		{
			sum = sum + num; //If addition, then adds the number to the sum
		}
		else if (oper == '-') //Identifies subtraction symbol
		{
			sum = sum - num; //If subtraction, then subtracts the number from the sum
		}
	}
	return 0;
}