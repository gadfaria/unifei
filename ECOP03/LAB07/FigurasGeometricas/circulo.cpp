#include <iostream>
#include "circulo.h"

using namespace std;

Circulo::Circulo(double xx, double yy, double r) : Ponto{xx, yy}, raio{r} {}

void Circulo::imprimeDados()
{
	Ponto::imprimeDados();
	cout << "Raio: " << raio << endl;
}

ostream &operator<<(ostream &out, Circulo &c)
{
	out << "Origem: ( " << c.x << ", " << c.y << " )" << endl;
	out << "Raio: " << c.raio << endl;
	return out;
}

istream &operator>>(istream &in, Circulo &c)
{
	in >> c.x >> c.y >> c.raio;
	return in;
}
