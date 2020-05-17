/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 6 - Task C

This program implements Vigenere cipher encryption with the function:
string encryptVigenere(string plaintext, string keyword); and prompting the user 
for their message and a keyword to encrypt the message. 
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift)
{
	if (isalpha(c)) //Function that checks if the character is alphabetic
	{
		if (((int)c >= 65) && ((int)c <= 90)) //Uppercase letters
		{
			if (((int)c + rshift) > 90)
			{
				c = ((int)c + rshift) - 26; //Text wraps back to uppercase letters
			}
			else
			{
				c = (int)c + rshift;
			}
			return char((int)c);
		}
		else if (((int)c >= 97) && ((int)c <= 122)) //Lowercase letters
		{
			if (((int)c + rshift) > 122)
			{
				c = ((int)c + rshift) - 26; //Text wraps to lowercase letters
			}
			else
			{
				c = (int)c + rshift;
			}
			return char((int)c);
		}
	}
	else
	{
		return c; //Symbols and spaces remained unecrypted 
	}
}

string encryptVigenere(string plaintext, string keyword)
{
	string new_message;
	int key_index = 0;
	int SHIFT_MAX = keyword.length(); //Value to indicate when the index of the keyword's index should reset
	char encrypt;
	for (int i = 0; i < plaintext.length(); i++) //
	{
		int rshift = int(keyword[key_index]) - 97; //'z' is 122 so subtract 97 = 25 ---> (n-1) shift
		encrypt = shiftChar(plaintext[i], rshift);
		if (isalpha(plaintext[i])) //If the current value is a symbol or white-space the rshift won't change
		{
			key_index++;
		}
		if (key_index == SHIFT_MAX) //Resets the rshift determined by the keyword's index
		{
			key_index = 0;
		}
		new_message += encrypt;
	}
	return new_message;
}

int main()
{
	string plaintext;
	cout << "Enter plaintext: ";
	getline(cin, plaintext);

	string key;
	cout << "Enter keyword: ";
	getline(cin, key);

	string encrypt = encryptVigenere(plaintext, key);
	cout << "Ciphertext: " << encrypt << endl;

	return 0;
}