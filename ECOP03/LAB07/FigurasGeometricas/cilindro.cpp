#include <iostream>
#include "cilindro.h"

using namespace std;

Cilindro::Cilindro(double xx, double yy, double r, double a) : Circulo{xx, yy, r}, altura{a} {}

void Cilindro::imprimeDados()
{
	Circulo::imprimeDados();
	cout << "Altura: " << altura << endl;
}

ostream &operator<<(ostream &out, Cilindro &c)
{
	out << "Origem: ( " << c.x << ", " << c.y << " )" << endl;
	out << "Raio: " << c.raio << endl;
	out << "Altura: " << c.altura << endl;
	return out;
}

istream &operator>>(istream &in, Cilindro &c)
{
	in >> c.x >> c.y >> c.raio >> c.altura;
	return in;
}
