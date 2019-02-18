// Frederick Wittman
// Robin Hill
// Lab01_numbers
// 18 February 2019

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 2) { return EXIT_FAILURE; }
	ifstream file(argv[1]);
	if (!file) { cout << "file open fail" << endl; return EXIT_FAILURE; }

	double x;
	int count = 0;
	int count1 = 0;
	double first = 0;
	double last = 0;
	double penultimate = 0;

	while (file >> x)
	{

		count++;

	}

	file.close();
	file.open(argv[1]);

	while (file >> x)

	{


		if (count1 == 0) { first = x; }
		if (count1 == count - 1) { last = x; }
		if (count1 == count - 2) { penultimate = x; }

		count1++;

	}

	cout << "There are " << count << " numbers in the file." << endl << "The first number is " << first << "." << endl << "The last number is " << last << "." << endl << 
		"The penultimate number is " << penultimate << ".";
	return 0;
}