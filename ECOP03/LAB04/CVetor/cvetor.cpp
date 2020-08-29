#include <iostream>
#include "cvetor.h"

using namespace std;
int CVetor::count = 0;

void CVetor::aloca_memoria()
{
	if (tamanho > 0)
		dados = new int[tamanho];
	else
		dados = nullptr;
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
	cout << "Digite o tamanho do vetor " << count << " :" << endl;
	cin >> tam;
	if (tam < 0)
		tam = 0;
	tamanho = tam;
	topo = -1;
	aloca_memoria();
}

CVetor::~CVetor()
{
	if (dados != nullptr)
		delete[] dados;
}

//IN - OUT
istream &operator>>(istream &in, CVetor &vetor)
{
	int valor;
	in >> valor;
	return in;
}

ostream &operator<<(ostream &out, CVetor vetor)
{
	out << vetor.dados << endl;
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
