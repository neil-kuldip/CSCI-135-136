/*
Author: Neil Kuldip
Course: CSCI-135
Instuctor: Genady Maryash
Assignment: Project 2 - Task B

This program uses the given strands of DNA (taken from dna2b.txt) and dictionary file: codons.tsv, to produce
outputs to the console with the corresponding amino-acid chain
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
	DNA.open("dna2b.txt");
	if (DNA.fail()) //If the file fails to open
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	string strand;
	while (getline(DNA, strand)) //Reads each line until the end
	{
		string mRNA = DNA_to_mRNA(strand);
		cout << mRNA_to_amino(dict, mRNA) << endl; //Calls the translation to amino acid function and prints the result
	}

	DNA.close(); //Closes the text file
	dict.close(); //Closes the tsv file
	return 0;
}