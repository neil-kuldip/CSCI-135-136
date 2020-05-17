/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Homework E7.18 - Triangle Perimeter

This program includes functions double distance(Point a, Point b) that computes the distance
from a to b, and classes Triangle and Point to compute the perimeter of a triangle. 
Write a program that reads the coordinates of the points, calls your function, and displays the result.
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

class Triangle
{
public:
	Point A; //The thee vertices of a triangle
	Point B;
	Point C;
};

double distance(Point a, Point b)
{
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)); //Distance formula
} 

double perimeter(Triangle a)
{
	double perim = distance(a.A, a.B) + distance(a.B, a.C) + distance(a.C, a.A);
	return perim;
}

int main()
{
	double x1, x2, x3, y1, y2, y3 = 0;
	cout << "Enter first point coordinates: ";
	cin >> x1 >> y1;
	cout << "Enter second point coordinates: ";
	cin >> x2 >> y2;
	cout << "Enter third point coordinates: ";
	cin >> x3 >> y3;

	Point A = { x1, y1 }; //Initalizes all three objects of class Point
	Point B = { x2, y2 };
	Point C = { x3, y3 };
	Triangle perim = { A, B, C };

	cout << "The perimeter of the triangle is: " << perimeter(perim); //Calls funtion and prints it
}