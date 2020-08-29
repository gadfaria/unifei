#include <iostream>
#include "presidente.h"
#include <string>

Presidente::Presidente(string n, string part, int a_entrada, string p) : Politico{n, part, a_entrada}, pais{p}
{
	cout << "PASSANDO POR PRESIDENTE" << endl;
}

void Presidente::imprimeDados()
{
	Politico::imprimeDados();
	cout << "PAIS: " << pais << endl;
}
