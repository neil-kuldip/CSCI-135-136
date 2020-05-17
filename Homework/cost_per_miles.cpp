/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash 
Assignment: Homework E2.10 - Cost Per 100 Miles

This program asks the user for criteria to print the cost per 100 miles 
and the remaining mileage of the car with the gas present in the tank.
*/

#include <iostream>
using namespace std;

int main()
{
	double gallons = 0.00;
	cout << "Enter the number of gallons of gas in your car tank: ";
	cin >> gallons;

	double mpg = 0.00;
	cout << "Enter the fuel efficiency in miles per gallon: ";
	cin >> mpg;

	double price = 0.00;
	cout << "Enter the price of gas per gallon: ";
	cin >> price;

	double cost_per_100 = (price * 100) / mpg;
	double remain_mileage = gallons * mpg;

	cout << "The cost per 100 miles is $" << cost_per_100 << endl;
	cout << "The car can go " << remain_mileage << " miles with the gas in the tank." << endl;

	return 0;
}