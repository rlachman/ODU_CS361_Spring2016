#include <iostream>

#pragma once

using namespace std;

class apex
{
public:
	apex();
	~apex();
	void display_apex(ostream& out);
	float geta_Coord(); float getb_Coord(); float getc_Coord();
private:
	float a_Coord; float b_Coord; float c_Coord;
public:
	apex(float a_A, float b_B, float c_C);
	void seta_Coordb_Coordc_Coord(float a_A, float b_B, float c_C);
};

