#include "equacao.h"
#include <iostream>
#include <cmath>

using namespace std;

Equacao::~Equacao()
{
}

float Equacao::Delta()
{
	return ((b * b) - (4 * a * c));
}

void Equacao::Raiz()
{
	if (sqrt(Delta()) > 0)
	{
		cout << "Raiz 1 = " << (-b + sqrt(Delta())) / (2 * a) << endl;
		cout << "Raiz 2 = " << (-b - sqrt(Delta())) / (2 * a) << endl;
	}
	else
	{
		if (sqrt(Delta()) == 0)
		{
			cout << "Raiz unica = " << -b / (2 * a) << endl;
		}
		else
		{
			cout << "Nao tem raiz" << endl;
		}
	}
}

//IN - OUT
ostream &operator<<(ostream &out, Equacao &eq)
{
	out << "(" << eq.a << ")x^2 + (" << eq.b << ")x + (" << eq.c << ")" << endl;
	return out;
}

istream &operator>>(istream &in, Equacao &eq)
{
	in >> eq.a >> eq.b >> eq.c;
	return in;
}
