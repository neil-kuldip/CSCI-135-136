//Author: Neil Kuldip
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Homework E4.8 - 1 Character per line

//This program asks the user for a word, and the program then prints each character of the word
//on a seperate line

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cout << "Enter your word: ";
	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		cout << word[i] << endl;
	}

	return 0;
}