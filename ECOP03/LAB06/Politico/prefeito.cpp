#include <iostream>
#include "prefeito.h"
#include <string>

using namespace std;

Prefeito::Prefeito(string n, string part, int a, string p, string e, string c) : Governador{n, part, a, p, e}, cidade{c}
{
	cout << "PASSANDO POR PREFEITO" << endl;
}

void Prefeito::imprimeDados()
{
	Governador::imprimeDados();

	cout << "CIDADE: " << cidade << endl;
}
