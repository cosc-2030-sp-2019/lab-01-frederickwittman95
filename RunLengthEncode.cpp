// Frederick Wittman
// Robin Hill
// Lab 01
// COSC 2030-01
// 18 February 2019


// CPP program to implement run length encoding
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmpr.txt");
	if (pixf_full.is_open()) cout << "Input pixf_full is open.";
	// Read into pix_list.
	i = 0;
	// Get each new line, while there is one, and store it in string "line".  Add "line" to the next slot in the vector.  Increment the pixel count.
	while (getline(pixf_full, line))
	{
		cout << line;
		// 2.  (Explain statement below.)
		// Adds the the parameter "line" to the end of the vector
		pix_list.push_back(line);
		i = i + 1;
	}
	n = pix_list.size();
	cout << "Length of pix_list is " << n << " ; i = " << i << "\n";
	// Go through list, testing whether next pixel is the same as the current one.
	// The loop condition needs to be ( n - 1 ) to read through the entire vector without causing an out of bounds error.
	for (i = 0; i < (n - 1); i++)
	{
		// If the current element of the vector is not the same as the next one, write the current element to the compressor.
		if (pix_list[i + 1] != pix_list[i])
		{
			pixf_cmpr << pix_list[i] << "\n";
			// If last two pixels are different, write the last pixel to the compressor as well.
			if (i == n - 2) {
				pixf_cmpr << pix_list[n - 1] << "\n";
			}
		}
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			// I had to force the substring to be 1 character longer.  I'm not sure why.
			pixf_cmpr << "flag " << pix_list[i].substr(0, 1 + pix_list[i].find_last_not_of(whitespace));
			// 5. Moves through the pixels until a new pixel is encountered.  Counts the number of repeated, adjacent pixels.  Increments i each cycle so 
			// that the outer loop is up-to-date and encounters a new pixel when the inner loop is complete.
			count = 1;
			while (i < n - 1 && pix_list[i] == pix_list[i + 1])
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}

	}
	// Compare the size of the array to the number of pixels in the list and print to stdout.  Already done.
	pixf_full.close();
	pixf_cmpr.close();
	return 0;
}