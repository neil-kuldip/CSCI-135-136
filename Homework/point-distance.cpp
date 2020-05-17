/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Homework E7.16 - Point Distance

This program includes function double distance(Point a, Point b) that computes the distance 
from a to b. Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	double x; //x coordinate
	double y; //y coordinate
};

double distance(Point a, Point b)
{
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)); //Distance formula
}

int main()
{
	double x1, x2, y1, y2 = 0; 
	cout << "Enter first point coordinates: ";
	cin >> x1 >> y1;
	cout << "Enter second point coordinates: ";
	cin >> x2 >> y2;

	Point a = {x1, y1}; //Initalizes both objects of class Point
	Point b = {x2, y2};
	cout << "The distance between them is: " << distance(a, b); //Calls funtion and prints them
}