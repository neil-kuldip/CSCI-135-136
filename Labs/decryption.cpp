/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 6 - Task D

This program ask the user to input plaintext, then ask for a right shift for the 
Caesar cipher and report the ciphertext and its subsequent decryption. After that, 
it should do the same for the Vigenere cipher.
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
		return char((int)c); //Symbols and spaces remained unecrypted 
	}
}

char originalchar(char c, int rshift) //Mainly reverses the process of shiftChar
{
	if (isalpha(c))
	{
		if (((int)c >= 65) && ((int)c <= 90)) //Uppercase letters
		{
			if (((int)c - rshift) < 65)
			{
				c = ((int)c - rshift) + 26; //Text wraps back to uppercase letters
			}
			else
			{
				c = (int)c - rshift;
			}
		return char((int)c);
		}
		else if (((int)c >= 97) && ((int)c <= 122)) //Lowercase letters
		{
			if (((int)c - rshift) < 97)
			{
				c = ((int)c - rshift) + 26; //Text wraps to lowercase letters
			}
			else
			{
				c = (int)c - rshift;
			}
			return char((int)c);
		}
	}
	else
	{
		return char((int)c); //Symbols and spaces remain the same 
	}
}

string encryptCaesar(string plaintext, int rshift)
{
	string caesar_message;
	for (int i = 0; i < plaintext.length(); i++) //For each letter in the message
	{
		char code = shiftChar(plaintext[i], rshift); //Calls the encryption function 
		caesar_message = caesar_message + code; //Attaches each encrypted letter to empty string 
	}
	return caesar_message;
}
string decryptCaesar(string ciphertext, int rshift)
{
	string original_message;
	for (int i = 0; i < ciphertext.length(); i++)
	{
		char letter = originalchar(ciphertext[i], rshift);
		original_message = original_message + letter;
	}
	return original_message;
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

string decryptVigenere(string ciphertext, string keyword)
{
	string original_message;
	int key_index = 0;
	int SHIFT_MAX = keyword.length(); 
	char encrypt;
	for (int i = 0; i < ciphertext.length(); i++) 
	{
		int rshift = int(keyword[key_index]) - 97; 
		encrypt = originalchar(ciphertext[i], rshift);
		if (isalpha(ciphertext[i])) 
		{
			key_index++;
		}
		if (key_index == SHIFT_MAX) 
		{
			key_index = 0;
		}
		original_message += encrypt;
	}
	return original_message;
}


int main()
{
	string plaintext; //Prompts user for message
	cout << "Enter plaintext: ";
	getline(cin, plaintext); //Reads the whole line
	cout << endl << "= Caasar =" << endl;

	int shift = 0;
	cout << "Enter shift: ";
	cin >> shift; //Shift for Caesar

	string C_ciphertext = encryptCaesar(plaintext, shift);
	cout << "Ciphertext: " << C_ciphertext << endl; //Prints the encrypted Ceasar message 

	string decrypt = decryptCaesar(C_ciphertext, shift);
	cout << "Decrypted: " << decrypt << endl; //Prints the decrypted message (should be same as the plaintext)

	cout << endl << "= Vigenere =" << endl;
	string key;
	cout << "Enter keyword: ";
	cin >> key; //Keyword for the vigenere shifts

	string V_ciphertext = encryptVigenere(plaintext, key);
	cout << "Ciphertext: " << V_ciphertext << endl; //Prints the encrypted Vigenere message 

	string decrypt2 = decryptVigenere(V_ciphertext, key);
	cout << "Decrypted: " << decrypt2 << endl; //Prints the decrypted message (should be same as the plaintext)

	return 0;
}
