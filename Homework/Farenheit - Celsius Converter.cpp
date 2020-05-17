//Name: Neil Kuldip
//Email: neil.kuldip26@myhunter.cuny.edu
//Date: November 24, 2019
//This program converts farenheit to celsius. Your program should prompt the user for the degrees in farenheit and then print out the temperature in celsius.

#include <iostream>
using namespace std;

int main()
{
	{
		float farenheit;
		cout << fixed << "Please enter the temperature in Farenheit:";
		cin >> farenheit;

		float celsius;
		cout << fixed << (farenheit - 32.0) * (5.0 / 9.0);
		cin >> celsius;
		cout << "Your temperature in Celsius is:" << celsius << ".\n\n";
		return 0;
	}
}