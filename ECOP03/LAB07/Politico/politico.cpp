#include "politico.h"
#include <iostream>
#include <string>

using namespace std;

Politico::Politico(string n, string part, int a_entrada) : nome{n}, partido{part}, ano_entrada{a_entrada}
{
	cout << "PASSANDO POR POLITICO" << endl;
}

void Politico::imprimeDados()
{
	cout << "NOME: " << nome << "\nPARTIDO: " << partido << "\nANO DE ENTRADA: " << ano_entrada << endl;
}
