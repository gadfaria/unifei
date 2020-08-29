#include "point.h"
#include <iostream>

using namespace std;

Point::Point(int xx, int yy) : x{xx}, y{yy} {}

// operações do tipo Point + Point
Point Point::operator+(Point &p)
{
	int xx = x + p.x;
	int yy = y + p.y;
	return Point{xx, yy};
}

// operações do tipo Point + int
Point Point::operator+(int value)
{
	int xx = x + value;
	int yy = y + value;
	return Point{xx, yy};
}

// Função global: operações do tipo int + Point
Point operator+(int value, Point &p)
{
	int xx = p.x + value;
	int yy = p.y + value;
	return Point{xx, yy};
}

// operadores unários
bool Point::operator!() const
{
	if (x == 0 && y == 0)
		return true;
	return false;
}

Point &Point::operator++()
{
	x++;
	y++;
	return *this;
}

Point Point::operator++(int value)
{
	Point temp = *this;
	++(*this);
	return temp;
}

// operador unário friend
Point operator--(Point &p, int value)
{
	Point temp = p;
	--p;
	return temp;
}

// operador unário friend
Point &operator--(Point &p)
{
	p.x--;
	p.y--;
	return p;
}

ostream &operator<<(ostream &out, Point &p)
{
	out << p.x << ", " << p.y;
	return out;
}

istream &operator>>(istream &in, Point &p)
{
	in >> p.x >> p.y;
	return in;
}
