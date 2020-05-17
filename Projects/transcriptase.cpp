/*
Auhtor: Neil Kuldip
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 2 - Task A

This program reads a text file called dna.txt that contains one DNA strand per line,
and outputs to the console (terminal) the corresponding mRNA strands.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char DNAbase_to_mRNAbase(char nucleobase) //Conversion function of DNA to mRNA bases for each character in strand
{
	if (nucleobase == 'A')
	{
		nucleobase = 'U';
	}
	else if (nucleobase == 'T')
	{
		nucleobase = 'A';
	}
	else if (nucleobase == 'C')
	{
		nucleobase = 'G';
	}
	else if (nucleobase == 'G')
	{
		nucleobase = 'C';
	}
	return nucleobase;
}

string DNA_to_mRNA(string strand) //Function that reads each nucleobase in each DNA strand
{
	int length = strand.length();
	string mRNA;
	for (int i = 0; i < length; i++)
	{
		char c = strand[i];
		mRNA = mRNA + DNAbase_to_mRNAbase(toupper(c)); //Creates mRNA strand after calling conversion function
	}
	return mRNA;
}

int main()
{
	ifstream DNA;
	DNA.open("dna.txt");

	if (DNA.fail()) //If the file fails to open
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	string strand;
	while (getline(DNA, strand)) //Reads each line until the end
	{
		string mRNA = DNA_to_mRNA(strand);
		cout << mRNA << endl;
	}
	DNA.close(); //Closes the text file
	return 0;
}



