/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 6 - Task E

This program reads a PGM image from the file "inImage.pgm", and outputs a modified image to "outImage.pgm". This modified image is a
200% scaled version of the original image.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int& height, int& width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr >> ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int main()
{
	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w);
	int out[MAX_H][MAX_W]; //Modified image array

	int scaleh = h * 2;
	int scalew = w * 2;

	for (int row = 0; row < scaleh; row++)
	{
		for (int col = 0; col < scalew; col++)
		{
			if ((row == 0) && (col == 0)) //First 2x2 square
			{
				out[row][col] = img[row][col]; //First pixel color in array is the same as original
				out[row][col + 1] = img[row][col]; //Other pixels in 2x2 must have the same pixel color
				out[row + 1][col] = img[row][col];
				out[row + 1][col + 1] = img[row][col];
			}

			else if ((col == 0) || (col % 2 == 0)) //Arrays 0-indexed have 2x2 squares starting in even intervals
			{
				out[row][col] = img[row / 2][col / 2]; //Corresponding pixels have a scaling factor by 2 as width the height and width
				out[row][col + 1] = out[row][col]; //Other pixels in 2x2 must have the same pixel color
				out[row + 1][col] = out[row][col];
				out[row + 1][col + 1] = out[row][col];
			}
		}
	}
	// and save this new image to file "outImage.pgm"
	writeImage(out, scaleh, scalew);
}