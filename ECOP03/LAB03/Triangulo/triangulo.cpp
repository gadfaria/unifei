#include "triangulo.h"
#include <cmath>
#include <iostream>

using namespace std;

Triangulo::Triangulo(int hip, int cat1, int cat2)
{
	hipotenusa = hip;
	cateto1 = cat1;
	cateto2 = cat2;
}

Triangulo::~Triangulo()
{
}

bool Triangulo::verificaTriangulo()
{
	if (pow(hipotenusa, 2) == (pow(cateto1, 2) + pow(cateto2, 2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Triangulo::imprimeTriangulos()
{
	int count = 0;
	Triangulo aux(1, 1, 1);
	for (int k = 1; k <= 200; k++)
	{
		for (int j = 1; j <= 200; j++)
		{
			for (int i = 1; i <= 200; i++)
			{
				aux.get_dados(k, j, i);
				if (aux.verificaTriangulo() == true)
				{
					if (count == 0)
					{
						cout << "Hip: " << k << " Cat1: " << j << " Cat2: " << i << endl;
						count = 1;
					}
					else
					{
						count = 0;
					}
				}
			}
		}
	}
}

void Triangulo::get_dados(int hip, int cat1, int cat2)
{
	hipotenusa = hip;
	cateto1 = cat1;
	cateto2 = cat2;
}
