#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{

private:
	int x, y;

public:
	Point(int = 0, int = 0);
	~Point() {}
	int get_x() { return x; }
	int get_y() { return y; }

	// primeiro operando é do tipo Point
	Point operator+(Point &);
	Point operator+(int);

	// Primeiro operando é do tipo int
	friend Point operator+(int, Point &);

	// operadores unários
	bool operator!() const;
	Point &operator++(); //pre-incremento

	Point operator++(int);				   // pos-incremento
	friend Point operator--(Point &, int); //pos-decremento

	// operador unário friend
	friend Point &operator--(Point &); //pre-decremento

	//OUT - IN
	friend ostream &operator<<(ostream &, Point &);
	friend istream &operator>>(istream &, Point &);
};

#endif
