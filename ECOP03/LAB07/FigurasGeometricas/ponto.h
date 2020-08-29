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

	virtual void imprimeDados();
	virtual double area() { return 0; }
	virtual double volume() { return 0; }
	friend ostream &operator<<(ostream &, Ponto &);
	friend istream &operator>>(istream &, Ponto &);
};

#endif
