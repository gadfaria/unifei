#include <iostream>
#include <cmath>
#include "poligonos.h"
using namespace std;

Poligonos::Poligonos(int num, int comp)
{
	numeroLados = num;
	comprimento = comp;
	cout << "construindo objeto ...\n"
		 << endl;
}

Poligonos::~Poligonos()
{
	cout << "\ndestruindo objeto ..." << endl;
}

int Poligonos::area()
{
	int area;
	area = cos(3.14 / numeroLados) / sin(3.14 / numeroLados);
	area = area * numeroLados * comprimento * comprimento;
	area = area / 4;
	return area;
}

int Poligonos::perimetro()
{
	return numeroLados * comprimento;
}

void Poligonos::nome()
{
	cout << "Nome do triangulo: ";
	switch (numeroLados)
	{
	case 3:
		cout << "Triangulo" << endl;
		break;
	case 4:
		cout << "Quadrilatero" << endl;
		break;
	case 5:
		cout << "Pentagono" << endl;
		break;
	case 6:
		cout << "Hexagono" << endl;
		break;
	case 7:
		cout << "Heptagono" << endl;
		break;
	case 8:
		cout << "Octogono" << endl;
		break;
	case 9:
		cout << "Eneagono" << endl;
		break;
	case 10:
		cout << "Decagono" << endl;
		break;
	}
}

void Poligonos::dados()
{
	int num, comp;

	cout << "Digite o numero de lados e o comprimento dos lados:" << endl;
	cin >> num;
	cin >> comp;

	set_comprimento(comp);
	set_largura(num);
}

void Poligonos::set_comprimento(int comp)
{
	comprimento = comp;
}

void Poligonos::set_largura(int num)
{
	numeroLados = num;
}
