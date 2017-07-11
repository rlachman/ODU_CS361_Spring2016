#include "apexPath.h"

apexPath::apexPath()
{
}
apexPath::~apexPath()
{
}
void apexPath::createPath(fstream& infile)
{
	float a_A,
          b_B,
          c_C;
	float a_Temp = 0,
          b_Temp = 0,
          c_Temp = 0;
	int condition = 0;
	apex center_Of_mass,
         first,
         second,
         third;
	path_Iteration = apex_Path.begin();
	while (!infile.eof())
	{
		infile >> a_A
               >> b_B
               >> c_C;
        if (condition != 3)
		{
			a_Temp = a_Temp + a_A; b_Temp = b_Temp + b_B; c_Temp = c_Temp + c_C;
            if(condition==0)
            {
                first.seta_Coordb_Coordc_Coord(a_A, b_B, c_C);
                apex_Path.push_back(first);
            }
			if (condition == 1)
            {
                second.seta_Coordb_Coordc_Coord(a_A, b_B, c_C);
                apex_Path.push_back(second);
            }
			if (condition == 2)
            {
                third.seta_Coordb_Coordc_Coord(a_A, b_B, c_C);
                apex_Path.push_back(third);
            }
			condition++;
		}
		if (condition == 3)
		{
            a_Temp = a_Temp / condition; b_Temp = b_Temp / condition; c_Temp = c_Temp / condition;
            center_Of_mass.seta_Coordb_Coordc_Coord(a_Temp, b_Temp, c_Temp);
            apex_Path.push_back(center_Of_mass); apex_Path.push_back(first); apex_Path.push_back(second);
            apex_Path.push_back(center_Of_mass); apex_Path.push_back(second); apex_Path.push_back(third);
            apex_Path.push_back(center_Of_mass); apex_Path.push_back(first); apex_Path.push_back(third);
            condition = 0;
            a_Temp = 0; b_Temp = 0; c_Temp = 0;
		}
	}
}
void apexPath::displayPath(ostream& out)
{
	int tempL = 1;
	path_Iteration = apex_Path.begin();
	while (path_Iteration != apex_Path.end() - 1)
	{
		path_Iteration->display_apex(cout);
		if (tempL % 3 == 0)
        {
            out << endl;
		}
		tempL++;
		path_Iteration++;
	}
}
void apexPath::displayPath_to_file(fstream& outfile)
{
	path_Iteration = apex_Path.begin();
	int tempL = 1;
	while (path_Iteration != apex_Path.end()-1)
	{
		path_Iteration->display_apex(outfile); path_Iteration++;
		if (tempL % 3 == 0)
        {
            outfile << endl << endl;
        }
		tempL++;
	}
}
void apexPath::createTri()
{
	float a_Temp = 0, b_Temp = 0 , c_Temp = 0;
	fstream outputFile;
	outputFile.open("apexes.txt", ios::out);
	for (int tempM = 0; tempM < 1;)
	{
		for (int tempN = 0; tempN < 3; tempN++)
		{
			a_Temp += apex_Path[tempM].geta_Coord(); b_Temp += apex_Path[tempM].getb_Coord(); c_Temp += apex_Path[tempM].getc_Coord();
            tempM++;
		}
        a_Temp = a_Temp / 3; b_Temp = b_Temp / 3; c_Temp = c_Temp / 3;
        apex temp(a_Temp, b_Temp, c_Temp);
        path_Iteration = apex_Path.begin() + tempM;
        apex_Path.insert(path_Iteration, temp);
        a_Temp = 0;
        b_Temp = 0;
        c_Temp = 0;

	}
}
void apexPath::computeDistance(int m)
{
	apex_Path.resize(m);
}
