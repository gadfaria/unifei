#ifndef PONTO_H
#define PONTO_H
#include <iostream>

using namespace std;

class Ponto
{
protected:
	double x, y;

public:
	Ponto(double = 0, double = 0);
	~Ponto() {}

	friend ostream &operator<<(ostream &, Ponto &);
	friend istream &operator>>(istream &, Ponto &);
};

#endif
