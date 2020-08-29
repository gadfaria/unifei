#ifndef COMPLEXO_H
#define COMPLEXO_H

class Complexo
{
private:
	double p_Real;
	double p_Imaginaria;

public:
	static int count;
	Complexo();
	Complexo(double, double);
	~Complexo();

	Complexo Somar(Complexo numComp);
	Complexo Subtrair(Complexo numComp);
	Complexo Multiplicar(Complexo numComp);
	Complexo Dividir(Complexo numComp);

	double Modulo();
	double Angulo();
	Complexo PolarImaginario(double, double);
	void Imprime();
	static void Contador();
};

#endif
