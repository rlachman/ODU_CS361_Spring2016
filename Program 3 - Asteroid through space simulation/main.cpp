//Ryan Lachman
//CS 361 - Asteroid Project
//4/27/2016

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "apex.h"
#include "apexPath.h"

using namespace std;

int main()
{
    fstream file;
	file.open("input.txt");
	apexPath testApexPath;
	testApexPath.createPath(file);
	testApexPath.displayPath(cout);
	file.close();
	fstream outfile;
	outfile.open("apexes.txt", ios::out);
	for (int k = 0; k < 1; k++)
        testApexPath.createTri();
	testApexPath.displayPath_to_file(outfile);
    system("gnuplot command.txt");
    system("pause");
	return 0;
}
