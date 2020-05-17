/*
Author: Neil Kuldip
Course: CSCI -135
Instructor: Genady Mayash
Assignment: Project 2 - Task C

This program calculates the Hamming distance between two strings. Given two strings of equal length,
the Hamming distance is the number of positions at which the two strings differ. For each pair in mutations.txt,
output to the console the Hamming distance followed by “yes” or “no” whether the substitution caused a change in structure.
*/

#include <fstream>
#include <iostream>
#include <string>
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

string dictionary_read(ifstream& dict, string codon) //Function to find correpsonding amino acid
{
	string key, value;
	dict.clear(); // reset error state
	dict.seekg(0); // return file pointer to the beginning
	while (dict >> key >> value)
	{
		if (codon == key)
		{
			return value; //Returns the amino acid
		}
	}
}

string mRNA_to_amino(ifstream& dict, string mRNA)
{
	string codon, amino_chain, lookup;
	bool start = false;
	char hypen = '-';
	for (int i = 0; i < mRNA.length(); i += 3)
	{
		codon = mRNA.substr(i, 3); //DNA strands are multiples of 3
		lookup = dictionary_read(dict, codon); //Calls the dictionary function for the tsv file
		if (codon == "AUG")
		{
			start = true; //Bool condition for start of translation
		}
		if (start && !((codon == "UAA") || (codon == "UGA") || (codon == "UAG"))) //If condition is met and not an end condon 
		{
			if (amino_chain.length() > 0)
			{
				amino_chain += hypen; //If the length of the growing string is greater than 0, each amino will have an hypen
			} //except the last one
			amino_chain += lookup;
		}
		else if ((codon == "UAA") || (codon == "UGA") || (codon == "UAG"))
		{
			break; //Ends the line
		}
	}
	return amino_chain; //Returns the corresponding amino acids
}

int Hamming(string line1, string line2)
{
	int dist = 0;
	int length = line1.length();

	for (int i = 0; i < length; i++)
	{
		if (line1[i] != line2[i]) //If the DNA sequence are not the same in corresponding index
		{
			dist++; //Increase hamming distance counter
		}
	}
	return dist; //Returns the distance
}

int main()
{
	ifstream dict;
	dict.open("codons.tsv");
	if (dict.fail()) //If the file fails to open
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	ifstream DNA;
	DNA.open("mutations.txt");
	if (DNA.fail()) //If the file fails to open
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	string line1, line2;
	string amino1, amino2;
	string sub = " no";
	while (DNA >> line1 >> line2) 
	{
		amino1 = mRNA_to_amino(dict, DNA_to_mRNA(line1)); //Converts DNA to amino acid
		amino2 = mRNA_to_amino(dict, DNA_to_mRNA(line2)); //Comverts DNA to amino acid
		
		if (amino1 != amino2)
		{
			sub = " yes"; //Subsitution did occur
		}
		cout << Hamming(line1, line2) << sub << endl; //Calls Hamming distance formula on the DNA strands
	}

	DNA.close(); //Closes the text file
	dict.close(); //Closes the tsv file
	return 0;
}