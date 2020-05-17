/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Homework E8.1 - File Writing

This program uses a text file called "hello.txt" and stores a message in the file,
and proceeds to store the message into a string from the same file
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ofstream out_file;
	out_file.open("hello.txt"); //Opens hello.txt
	
	out_file << "Hello, World!"; //Prints message to the file
	out_file.close(); //Closes the text file

	ifstream in_file; //Opens the same text file
	in_file.open("hello.txt");

	string string; //Intialized a string to be read from file
	getline(in_file, string); 
	cout << string << endl; //Prints the message

	return 0;
}