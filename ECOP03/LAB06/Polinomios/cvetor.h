#ifndef CVETOR_H
#define CVETOR_H

#include <iostream>
using namespace std;

class CVetor
{
private:
	static int count;
	int *dados;
	void aloca_memoria();

public:
	int tamanho;
	int &operator[](int);

	//CONTRUTORES E DESTRUTORES
	CVetor();
	CVetor(int);
	~CVetor();

	//IN - OUT
	friend istream &operator>>(istream &, CVetor &);
	friend ostream &operator<<(ostream &, CVetor &);

	//COMPARADORES
	int operator>(CVetor);
	int operator<(CVetor);
	int operator==(CVetor);
	int operator!=(CVetor);
	int operator>=(CVetor);
	int operator<=(CVetor);

	//OPERAÇÕES ARITMETICAS
	int operator+(CVetor &);
	int operator-(CVetor);

	//METODOS
	double encontraRaiz();
	double soma(double);
	double somaDerivada(double);
};
#endif
