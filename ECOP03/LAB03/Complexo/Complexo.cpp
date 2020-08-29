#include "Complexo.h"
#include <iostream>
#include <cmath>
using namespace std;

int Complexo::count = 0;

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

Complexo Complexo::Somar(Complexo numComp)
{
	Complexo resultado(p_Real + numComp.p_Real, p_Imaginaria + numComp.p_Imaginaria);
	return resultado;
}

Complexo Complexo::Subtrair(Complexo numComp)
{
	Complexo resultado(p_Real - numComp.p_Real, p_Imaginaria - numComp.p_Imaginaria);
	return resultado;
}

Complexo Complexo::Multiplicar(Complexo numComp)
{

	double z1 = Modulo();
	double z2 = numComp.Modulo();
	double o1 = Angulo();
	double o2 = numComp.Angulo();
	Complexo resultado = PolarImaginario(z1 * z2, o1 + o2);

	return resultado;
}

Complexo Complexo::Dividir(Complexo numComp)
{
	double z1 = Modulo();
	double z2 = numComp.Modulo();
	double o1 = Angulo();
	double o2 = numComp.Angulo();
	Complexo resultado = PolarImaginario(z1 / z2, o1 - o2);

	return resultado;
}

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

void Complexo::Imprime()
{
	cout << "( " << p_Real << " + " << p_Imaginaria << "i )";
}

void Complexo::Contador(void)
{
	cout << "Contador: " << count << "\n"
		 << endl;
}
