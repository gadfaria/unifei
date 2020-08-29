#include <iostream>
#include "poligonos.h"
using namespace std;

int main()
{
	Poligonos teste;

	teste.dados();
	cout << "Area igual a: " << teste.area() << endl;
	cout << "Perimetro igual a: " << teste.perimetro() << endl;
	teste.nome();
}
