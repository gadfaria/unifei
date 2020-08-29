#include <iostream>
#include <cmath>
#include "cvetor.h"

using namespace std;
int CVetor::count = 0;

void CVetor::aloca_memoria()
{
	if (tamanho > 0)
		dados = new int[tamanho];
	else
		dados = NULL;
}

int &CVetor::operator[](int pos)
{
	return dados[pos];
}

//CONTRUTORES E DESTRUTORES
CVetor::CVetor()
{
	count++;
	int tam;
	cout << "Digite o tamanho do polinomio " << count << " :" << endl;
	cin >> tam;
	if (tam < 0)
		tam = 0;
	tamanho = tam;
	aloca_memoria();
}

CVetor::CVetor(int tam)
{
	if (tam < 0)
		tam = 0;
	tamanho = tam;
	aloca_memoria();
}

CVetor::~CVetor()
{
	if (dados != NULL)
		delete[] dados;
}

//IN - OUT
istream &operator>>(istream &in, CVetor &vetor)
{
	for (int i = 0; i < vetor.tamanho; i++)
		in >> vetor.dados[i];

	return in;
}

ostream &operator<<(ostream &out, CVetor &vetor)
{
	for (int i = 0; i < vetor.tamanho; i++)
		out << vetor.dados[i] << "x^" << i << " + ";

	out << endl;
	return out;
}

//COMPARADORES
int CVetor::operator>(CVetor vetor)
{
	return (dados > vetor.dados);
}

int CVetor::operator<(CVetor vetor)
{
	return (dados < vetor.dados);
}

int CVetor::operator==(CVetor vetor)
{
	return (dados == vetor.dados);
}

int CVetor::operator!=(CVetor vetor)
{
	return (dados != vetor.dados);
}

int CVetor::operator>=(CVetor vetor)
{
	return (dados >= vetor.dados);
}

int CVetor::operator<=(CVetor vetor)
{
	return (dados <= vetor.dados);
}

//OPERAÇÕES ARITMETICAS
int CVetor::operator+(CVetor &vetor)
{
	int *valor1, *valor2, valor;
	valor1 = vetor.dados;
	valor2 = dados;
	valor = *valor1 + *valor2;
	return (valor);
}

int CVetor::operator-(CVetor vetor)
{
	return (dados - vetor.dados);
}

//METODOS
double CVetor::encontraRaiz()
{
	double raiz = 3;

	for (int i = 1; i <= tamanho; i++)
	{
		raiz = raiz - (soma(raiz) / somaDerivada(raiz));
	}
	return raiz;
}

double CVetor::soma(double valor)
{
	double total = 0;
	for (int i = 0; i < tamanho; i++)
	{
		total = total + (dados[i] * pow(valor, i));
	}
	return total;
}

double CVetor::somaDerivada(double valor)
{
	double total = 0;
	for (int i = 1; i < tamanho; i++)
	{
		total = total + (i * dados[i] * pow(valor, i - 1));
	}
	return total;
}
