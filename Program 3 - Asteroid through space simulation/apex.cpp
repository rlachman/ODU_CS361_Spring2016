#include "apex.h"

apex::apex()
{
	a_Coord = 0.0f; b_Coord = 0.0f; c_Coord = 0.0f;
}
apex::~apex()
{
}
void apex::display_apex(ostream& out)
{
	out << geta_Coord() << " "
        << getb_Coord() << " "
        << getc_Coord() << " " << endl;
}
float apex::geta_Coord()
{
	return a_Coord;
}
float apex::getb_Coord()
{
	return b_Coord;
}
float apex::getc_Coord()
{
	return c_Coord;
}
apex::apex(float a_A, float b_B, float c_C)
{
	a_Coord = a_A; b_Coord = b_B; c_Coord = c_C;
}
void apex::seta_Coordb_Coordc_Coord(float a_A, float b_B, float c_C)
{
	a_Coord = a_A; b_Coord = b_B; c_Coord = c_C;
}
