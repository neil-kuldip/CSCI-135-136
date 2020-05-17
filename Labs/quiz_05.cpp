//Author: Neil Kuldip
//Course: CSCI-136
//Instructor: Melissa Lynch
//Assignment: Quiz #5

#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 6; i++) //Per each row (6 rows)
	{
		for (int j = 0; j < 5; j++) //Per each column (5 columns
		{
			if (j == 4)
			{
				cout << "*"; //Prints stars 
			}
			else
			{
				cout << "* "; //Prints stars and spaces
			}
		}
		cout << endl; //Ends each line and starts new line
	}
	return 0;
}