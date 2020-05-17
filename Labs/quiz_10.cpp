/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Quiz #10

The program will modify the original image to be a checkerboard of black pixels and original images' pixels
*/

if ((row == 0) || (row % 2 == 0))
{
	if ((col == 0) || (col % 2 == 0))
	{
		out[row][col] = 0; //Pixel will be black
	}
	else if (col % 2 != 0)
	{
		out[row][col] = img[row][col]; //Pixel will be the original image's pixel
	}
}
else 
{
	if ((col == 0) || (col % 2 == 0))
	{
		out[row][col] = 0; //Pixel will be black
	}
	else if (col % 2 != 0)
	{
		out[row][col] = img[row][col]; //Pixel will be the original image's pixel
	}
}