/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 2 - Task D

This program uses an array of ints to compute and print all 
Fibonacci numbers from F(0) to F(59).
*/

#include <iostream>
using namespace std;

int main()
{
	int fib[60]; //Creates the fibonacci array, fib, with 60 integers
	fib[0] = 0; //Value of the first number in the sequence is 0
	fib[1] = 1; //Value of the second number in the sequence is 1

	cout << fib[0] << endl;
	cout << fib[1] << endl;

	for (int i = 2; i < 60; i++) //For loop for index values 2 - 59 in the sequence
	{
		fib[i] = fib[i-1] + fib[i-2]; //Sum of previous two numbers for the current value
		cout << fib[i] << endl;
	//Approaching two billion, the maximum value for integer type was breached,
	//causing the value to loop back the integer type minimum value. 
	}
	return 0;
}