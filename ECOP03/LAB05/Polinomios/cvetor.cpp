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

/*ostream& operator<<(ostream& out, CVetor vetor)
{	
	out << vetor.dados << "x^" << vetor.topo << endl;
	return out;

}
*/
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
