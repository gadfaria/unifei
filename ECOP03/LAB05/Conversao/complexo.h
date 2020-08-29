#ifndef COMPLEXO_H
#define COMPLEXO_H
#include <iostream>
using namespace std;

class Complexo
{
private:
	double p_Real;
	double p_Imaginaria;

public:
	static int count;
	//CONSTRUTURES E DESTRUTORES
	Complexo();
	Complexo(double, double);
	~Complexo();

	//OPERA��ES ARITM�TICAS
	Complexo operator+(Complexo &numComp);
	Complexo operator-(Complexo &numComp);
	Complexo operator*(Complexo &numComp);
	Complexo operator/(Complexo &numComp);

	//COMPARA��O
	int operator>(Complexo &numComp);
	int operator<(Complexo &numComp);
	int operator==(Complexo &numComp);
	int operator!=(Complexo &numComp);
	int operator>=(Complexo &numComp);
	int operator<=(Complexo &numComp);

	//OUT - IN
	friend ostream &operator<<(ostream &out, const Complexo &numComp);
	friend istream &operator>>(istream &in, Complexo &numComp);

	//AUXILIARES
	double Modulo();
	double Angulo();
	Complexo PolarImaginario(double, double);
	static void Contador();
};

#endif
