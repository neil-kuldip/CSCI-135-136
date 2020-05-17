/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Quiz #7

This program contains the function remove_e to remove all letter 'e' from the sentence
*/

#include <iostream>
#include <string>
using namespace std;

void remove_e(string& sentence) //Reference to the sentence
{
	string new_sentence;
	int length = sentence.length();
	for (int i = 0; i < length; i++)
	{
		if (sentence[i] != 'e') 
		{
			new_sentence += sentence[i];
		}
	}
	sentence = new_sentence; //Changes the orginal sentence 
}

int main()
{
	string sentence;
	cout << "Please enter a sentence: "; //Take user's input
	getline(cin, sentence); //Retrieves the whole line

	remove_e(sentence); //Calls the function

	cout << sentence << endl;

	return 0;
}