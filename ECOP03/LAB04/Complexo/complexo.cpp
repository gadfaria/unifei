#include "complexo.h"
#include <iostream>
#include <cmath>
using namespace std;

int Complexo::count = 0;

//CONSTRUTORES E DESTRUTORES
Complexo::Complexo()
{
	p_Real = 1;
	p_Imaginaria = 1;
	count++;
}

Complexo::Complexo(double real, double img)
{
	p_Real = real;
	p_Imaginaria = img;
	count++;
}

Complexo::~Complexo()
{
	count--;
}

//OPERA��ES ARITMETICAS
Complexo Complexo::operator+(Complexo &numComp)
{
	Complexo resultado(p_Real + numComp.p_Real, p_Imaginaria + numComp.p_Imaginaria);
	return resultado;
}

Complexo Complexo::operator-(Complexo &numComp)
{
	Complexo resultado(p_Real - numComp.p_Real, p_Imaginaria - numComp.p_Imaginaria);
	return resultado;
}

Complexo Complexo::operator*(Complexo &numComp)
{

	double z1 = Modulo();
	double z2 = numComp.Modulo();
	double o1 = Angulo();
	double o2 = numComp.Angulo();
	Complexo resultado = PolarImaginario(z1 * z2, o1 + o2);

	return resultado;
}

Complexo Complexo::operator/(Complexo &numComp)
{
	double z1 = Modulo();
	double z2 = numComp.Modulo();
	double o1 = Angulo();
	double o2 = numComp.Angulo();
	Complexo resultado = PolarImaginario(z1 / z2, o1 - o2);

	return resultado;
}

//COMPARADORES
int Complexo::operator>(Complexo &numComp)
{
	return (Modulo() > numComp.Modulo());
}

int Complexo::operator<(Complexo &numComp)
{
	return (Modulo() < numComp.Modulo());
}

int Complexo::operator==(Complexo &numComp)
{
	return (Modulo() == numComp.Modulo());
}

int Complexo::operator!=(Complexo &numComp)
{
	return (Modulo() != numComp.Modulo());
}

int Complexo::operator<=(Complexo &numComp)
{
	return (Modulo() <= numComp.Modulo());
}

int Complexo::operator>=(Complexo &numComp)
{
	return (Modulo() >= numComp.Modulo());
}

//OUT - IN
ostream &operator<<(ostream &out, const Complexo &numComp)
{
	out << "( " << numComp.p_Real << " + " << numComp.p_Imaginaria << "i )";
	return out;
}

istream &operator>>(istream &in, Complexo &numComp)
{
	in >> numComp.p_Real >> numComp.p_Imaginaria;
	return in;
}

//AUXILIARES
double Complexo::Modulo(void)
{
	double z = (pow(p_Real, 2) + pow(p_Imaginaria, 2));
	return sqrt(z);
}

double Complexo::Angulo(void)
{
	double o = atan(p_Imaginaria / p_Real);
	return o;
}

Complexo Complexo::PolarImaginario(double z, double o)
{
	Complexo resultado(z * cos(o), z * sin(o));
	return resultado;
}

void Complexo::Contador(void)
{
	cout << "Contador: " << count << "\n"
		 << endl;
}
