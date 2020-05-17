//Author: Neil Kuldip
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Lab 1B

//This program asks the user to input three integer numbers, 
//and prints out the smallest of the three.

#include <iostream>
using namespace std;

int main()
{
    //First integer
    int x = 0;
    cout << "Enter the first number: ";
    cin >> x;

    //Second integer
    int y = 0;
    cout << "Enter the second number: ";
    cin >> y;

    //Third integer
    int z = 0;
    cout << "Enter the third number: ";
    cin >> z;

    if (x < y)
    {
        x = x;
    }
    else
    {
        x = y;
    }

    if (x < z)
    {
        x = x;
    }
    else
    {
        x = z;
    }

    cout << endl << endl << "The smaller of the three is " << x << endl;
    return 0;
}
