/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 6 - Task B

This program functions implements Caesar cipher encryption by asking the user for the shift number and
uses the functions char shiftChar(char c, int rshift); and string encryptCaesar(string plaintext, int rshift);
to encrypt accordingly 
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift)
{
	if (isalpha(c)) //Function that checks if the character is alphabetic
	{
		if (((int)c >= 65) && ((int)c <= 90)) //Within the integer code range of uppercase letters 
		{
			if ((int)c + rshift > 90)
			{
				c = ((int)c + rshift) - 26; //If exceeds range, wraps the right shift back to the range
			}
			else
			{
				c += rshift;
			}
				
		}
		else if (((int)c >= 97) && ((int)c <= 122)) //Within the integer code range of lowercase letters
		{
			if ((int)c + rshift > 122) 
			{
				c = ((int)c + rshift) - 26; //If exceeds range, wraps the right shift back to the range 
			}
			else
			{
				c += rshift;
			}
		}
		return c;
	}
	else
	{
		return c; //Symbols and spaces remained unecrypted 
	}
}

string encryptCaesar(string plaintext, int rshift)
{
	string new_message;
	for (int i = 0; i < plaintext.length(); i++) //For each letter in the message
	{
		char code = shiftChar(plaintext[i], rshift); //Calls the encryption function 
		new_message = new_message + code; //Attaches each encrypted letter to empty string 
	}
	return new_message;
}

int main()
{
	string plaintext; //Prompts user for message
	cout << "Enter plaintext: ";
	getline(cin, plaintext); //Reads the whole line

	int shift = 0;
	cout << "Enter shift: ";
	cin >> shift;

	string encrypt = encryptCaesar(plaintext, shift);
	cout << "Ciphertext: " << encrypt << endl; //Prints the encrypted message 

	return 0;
}