#include <vector>
#include <iostream>
#include <fstream>

#pragma once

#include "apex.h"

using namespace std;

class apexPath
{
public:
	apexPath();
	~apexPath();
	void createPath(fstream& infile);
	void displayPath(ostream& out);
	void displayPath_to_file(fstream& outfile);
	void createTri();
	void computeDistance(int tempK);
private:
	vector<apex> apex_Path;
	vector<apex>::iterator path_Iteration;
public:
	void advance_centerOfmass_forPath();
};

