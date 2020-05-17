/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab Quiz #8
*/

#include <iostream>
#include <string>
using namespace std;

class Date {
public:
	int year;
	int month;
	int day;
	string day_of_week;
};

void printDate(Date* input)
{
	cout << input->day_of_week << ", " << input->month << "/" << input->day << "/" << input->year << endl;
}

int main()
{
	int year, month, day = 0;
	string date;
	cout << "Please enter the date: ";
	cin >> year >> month >> day >> date;
	Date MyDate = { year, month, day, date };
	Date* ptr = &MyDate;
	printDate(ptr);
}