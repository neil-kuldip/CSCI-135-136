/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 9 - Tasks D

This program should still keep creating poems, but all dynamically allocated memory should get deleted when it is not needed.
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() 
{
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() 
{
    while (true) 
    {
        string *p = nullptr;
        p = createAPoemDynamically();
        //assume that the poem p is not needed at this point
        delete p;
    }
}