#include <iostream>
#include "governador.h"
#include <string>

using namespace std;

Governador::Governador(string n, string part, int a, string p, string e) : Presidente{n, part, a, p}, estado{e}
{
	cout << "PASSANDO POR GOVERNADOR" << endl;
}

void Governador::imprimeDados()
{
	Presidente::imprimeDados();
	cout << "ESTADO: " << estado << endl;
}
