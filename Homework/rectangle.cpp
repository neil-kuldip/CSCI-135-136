/*
Author: Neil Kuldip
Course: CSCI-135
Professor: Genady Maryash
Assignment: Homework E9.5 - Rectangle

This program implements class Rectangle with member functions: get_perimeter, get_area, and 
void resize(double factor) to construct a rectangle with a given width and height and its properties. 
*/
#include <iostream>
using namespace std;

class Rectangle {
public:
	Rectangle(double input_w, double input_h);
	double get_perimeter();
	double get_area();
	void resize(double factor);
private:
	double width;
	double height;
};

double Rectangle::get_perimeter() //P = 2h + 2w
{
	double perimeter = (height * 2) + (width * 2);
	return perimeter;
}

double Rectangle::get_area() //A = h * w
{
	double area = height * width;
	return area;
}

void Rectangle::resize(double factor) //Resizes the area of the rectangle
{
	height = height * factor;
	width = width * factor;
}

Rectangle::Rectangle(double input_w, double input_h)
{
	width = input_w;
	height = input_h;
}


int main()
{
	double a, b, c = 0;
	cout << "Enter width: ";
	cin >> a;
	cout << "Enter height: ";
	cin >> b;
	cout << "Enter doubling factor: ";
	cin >> c;

	Rectangle A = Rectangle(a, b);
	cout << "Area is: " << A.get_area() << endl;
	cout << "Perimeter is: " << A.get_perimeter() << endl;
	A.resize(c);
	cout << "Area is: " << A.get_area() << endl;
	cout << "Perimeter is: " << A.get_perimeter() << endl;

}