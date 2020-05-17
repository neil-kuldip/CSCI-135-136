/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 6 - Task G

This program reads a PGM image from the file "inImage.pgm", and outputs a modified image to "outImage.pgm". This modified image 
implements a horizontal edge detection operation and filters the original image.
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
	int height, width;

	readImage(img, height, width);
	int out[MAX_H][MAX_W]; //Modified image array

	int a, b, c, d, e, f, g, h, i, pixel = 0;
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			//Sets border around image to black
			out[row][col] = img[row][col];
			//Detect Horizontal Edges function f(a,b,c,d,e,f,g,h,i) = (g+2h+i)-(a+2b+c) applied to each neighboring pixel
			a = -1 * img[row - 1][col - 1];
			b = -2 * img[row - 1][col];
			c = -1 * img[row - 1][col + 1];
			d = img[row][col - 1];
			e = img[row][col];
			f = img[row][col + 1];
			g = img[row + 1][col - 1];
			h = 2 * img[row + 1][col];
			i = img[row + 1][col + 1];

			if ((row == 0) && (col == 0)) //Upper left-hand corner
			{
				pixel = h + i;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((col > 0) && (col < width - 1) && (row == 0)) //First row
			{
				pixel = g + h + i;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((row == 0) && (col == width - 1)) //Upper right-hand corner
			{
				pixel = d + g + h;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((row > 0) && (row < height - 1) && (col == 0)) //Left-side boundary
			{
				pixel = b + c + h + i;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((row > 0) && (row < height - 1) && (col == width - 1)) //Right-side boundary
			{
				pixel = a + b + g + h;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((row == height - 1) && (col == 0)) //Lower left-hand corner
			{
				pixel = b + c + f;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((col > 0) && (col < width - 1) && (row == height - 1)) //Bottom row
			{
				pixel = a + b + c + f + g;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((row == height - 1) && (col == width - 1)) //Lower right-hand corner
			{
				pixel = a + b + d;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
			if ((row > 0) && (row < height - 1) && (col > 0) && (col < width - 1)) //The remaining middle body
			{
				pixel = a + b + c + g + h + i;
				if (pixel > 255)
				{
					out[row][col] = 255;
				}
				else if (pixel < 0)
				{
					out[row][col] = 0;
				}
				else
				{
					out[row][col] = pixel;
				}
			}
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, height, width);
}