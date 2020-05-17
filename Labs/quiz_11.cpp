/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab Quiz #11
*/

#include <iostream>
using namespace std;

class Money {
public: 
	int dollars;
	int cents;
};

Money add_money(Money x, Money y)
{
	Money total;
	total.dollars = x.dollars + y.dollars;
	total.cents = x.cents + y.cents;
	if (total.cents >= 100) //Cents can never be value of 100 since it'll increment the dollar amount
	{
		total.dollars++;
		total.cents = total.cents - 100;
	}
	return total;
}

int main()
{
	int a, b, c, d = 0;
	cout << "Enter first amount: ";
	cin >> a >> b;
	cout << "Enter second amount: ";
	cin >> c >> d;

	Money m1 = { a , b };
	Money m2 = { c , d };
	Money m3 = add_money(m1, m2);
	cout << "The total is: $" << m3.dollars << "." << m3.cents << endl;
}