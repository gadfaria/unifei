#include "numLongo.h"
#include <iostream>
#define T_NUM 30
using namespace std;

//APENAS NUMEROS POSITIVOS
//CONTRUTORES E DESTRUTORES
int NumLongo::count = 0;
NumLongo::NumLongo()
{
	count++;
}

NumLongo::~NumLongo()
{
	count--;
}

//OPERAÇÕES ARITMETICAS
void NumLongo::operator+(NumLongo &numT)
{
	int resultado[T_NUM], resto = 0;
	int aux = 0;

	for (char i = (T_NUM - 1); i >= 0; i--)
	{
		aux = num[i] + numT.num[i];
		aux = aux + resto;
		resto = 0;
		if (aux > 9)
		{
			aux = aux - 10;
			resto = 1;
		}
		resultado[i] = aux;
	}
	if (resto == 1)
	{
		cout << "overflow";
	}
	else
	{
		for (char i = 0; i < T_NUM; i++)
			cout << resultado[i];
	}
	cout << endl;
}

void NumLongo::operator-(NumLongo &numT)
{
	int resultado[T_NUM];
	int aux = 0, cond = 1, falta = 0;

	for (char i = (T_NUM - 1); i >= 0; i--)
	{
		aux = num[i] - numT.num[i];
		aux = aux - falta;
		falta = 0;
		if (aux < 0)
		{
			aux = aux + 10;
			falta = 1;
		}
		resultado[i] = aux;
	}
	if (falta == 1)
	{
		cout << "Resultado menor que zero!";
	}
	else
	{
		for (char i = 0; i < T_NUM; i++)
			cout << resultado[i];
	}
	cout << endl;
}

//COMPARAÇÕES
int NumLongo::operator>(NumLongo &numT)
{
	for (int i = 0; i < (T_NUM); i++)
	{
		if (num[i] < numT.num[i])
			return 0;
		if (num[i] > numT.num[i])
			return 1;
	}
	return 0;
}

int NumLongo::operator<(NumLongo &numT)
{
	for (int i = 0; i < (T_NUM); i++)
	{
		if (num[i] > numT.num[i])
			return 0;
		if (num[i] < numT.num[i])
			return 1;
	}
	return 0;
}

int NumLongo::operator==(NumLongo &numT)
{
	for (int i = 0; i < (T_NUM); i++)
	{
		if (num[i] != numT.num[i])
			return 0;
	}
	return 1;
}

int NumLongo::operator!=(NumLongo &numT)
{
	for (int i = 0; i < (T_NUM); i++)
	{
		if (num[i] != numT.num[i])
			return 1;
	}
	return 0;
}

int NumLongo::operator>=(NumLongo &numT)
{
	for (int i = 0; i < (T_NUM); i++)
	{
		if (num[i] < numT.num[i])
			return 0;
		if (num[i] > numT.num[i])
			return 1;
	}
	return 1;
}

int NumLongo::operator<=(NumLongo &numT)
{
	for (int i = 0; i < (T_NUM); i++)
	{
		if (num[i] > numT.num[i])
			return 0;
		if (num[i] < numT.num[i])
			return 1;
	}
	return 1;
}

//IN - OUT
ostream &operator<<(ostream &out, NumLongo &numT)
{
	for (char i = 0; i < T_NUM; i++)
	{
		out << numT.num[i];
	}
	return out;
}

istream &operator>>(istream &in, NumLongo &numT)
{
	char c[T_NUM + 1];
	in >> c;

	for (int i = 0; i < T_NUM; i++)
	{
		numT.num[i] = c[i] - 48;
	}
}
