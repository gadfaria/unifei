#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include <cmath>
#include "ponto.h"

using namespace std;

class Circulo : public Ponto
{
protected:
	double raio;

public:
	Circulo(double = 0, double = 0, double = 0);
	~Circulo() {}

	double area() { return (pow(raio, 2) * 3.14); }
	friend ostream &operator<<(ostream &, Circulo &);
	friend istream &operator>>(istream &, Circulo &);
};

#endif
