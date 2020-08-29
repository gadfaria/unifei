#include "ponto.h"
#include <iostream>

using namespace std;

Ponto::Ponto(double xx, double yy) : x{xx}, y{yy} {}

ostream &operator<<(ostream &out, Ponto &p)
{
	out << "Origem: ( " << p.x << ", " << p.y << " )" << endl;
	return out;
}

istream &operator>>(istream &in, Ponto &p)
{
	in >> p.x >> p.y;
	return in;
}
