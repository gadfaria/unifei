#ifndef CILINDRO_H
#define CILINDRO_H

#include <iostream>
#include "circulo.h"

using namespace std;

class Cilindro : public Circulo
{
protected:
	double altura;

public:
	Cilindro(double = 0, double = 0, double = 0, double = 0);
	~Cilindro() {}

	double volume() { return (Circulo::area() * altura); }

	friend ostream &operator<<(ostream &, Cilindro &);
	friend istream &operator>>(istream &, Cilindro &);
};

#endif
