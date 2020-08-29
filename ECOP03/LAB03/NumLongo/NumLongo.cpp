#include "NumLongo.h"
#include <iostream>
#define T_NUM 30
using namespace std;

//PRIMEIRO NUMERO RESERVADO PARA SINAL, 1 PARA POSITIVO E 0 PARA NEGATIVO

int NumLongo::count = 0;
NumLongo::NumLongo()
{
	count++;
	digitar();
}

NumLongo::~NumLongo()
{
	count--;
}

void NumLongo::somar(NumLongo numT)
{
	int resultado[T_NUM], resto = 0;
	int aux = 0;

	if ((num[0] == 0) && (numT.num[0] == 0))
	{
		resultado[0] = 0;
	}
	else
	{
		resultado[0] = 1;
	}
	for (char i = (T_NUM - 1); i > 0; i--)
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
		cout << "overflow" << endl;
	}
	else
	{
		if (resultado[0] == 0)
		{
			cout << "-";
		}
		else
		{
			cout << "+";
		}
		for (char i = 1; i < T_NUM; i++)
			cout << resultado[i];
	}
	cout << endl;
}

void NumLongo::subtrair(NumLongo numT)
{
	int resultado[T_NUM];
	int aux = 0, cond = 1, falta = 0;

	if ((num[0] == 0) && (numT.num[0] == 0))
	{
		resultado[0] = 0;
	}
	else
	{
		resultado[0] = 1;
	}

	for (char i = (T_NUM - 1); i > 0; i--)
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
		cout << "deu errado" << endl;
	}
	else
	{
		if (resultado[0] == 0)
		{
			cout << "-";
		}
		else
		{
			cout << "+";
		}
		for (char i = 1; i < T_NUM; i++)
			cout << resultado[i];
	}
	cout << endl;
}

void NumLongo::imprimir()
{
	if (num[0] == 0)
	{
		cout << "-";
	}
	else
	{
		cout << "+";
	}
	for (char i = 1; i < T_NUM; i++)
	{
		cout << num[i];
	}
	cout << endl;
}

void NumLongo::digitar()
{
	char c[T_NUM + 1];
	cout << "\nDigite um numero para a classe " << count << ": " << endl;
	cin >> c;

	for (int i = 0; i < T_NUM; i++)
	{
		num[i] = c[i] - 48;
	}
}
