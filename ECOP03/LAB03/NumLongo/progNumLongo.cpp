#include <iostream>
#include "NumLongo.h"

using namespace std;

int main()
{
	cout << "PRIMEIRO NUMERO RESERVADO PARA SINAL, 1 PARA POSITIVO E 0 PARA NEGATIVO\n"
		 << endl;
	cout << "SINAL DIFERENTE NAS VARIAVEIS DEU PROBLEMA" << endl;

	NumLongo t1;
	NumLongo t2;
	cout << endl;

	cout << "Numero 1 + Numero 2 = " << endl;
	t1.somar(t2);

	cout << "Numero 1 - Numero 2 = " << endl;
	t1.subtrair(t2);

	cout << "Numero 1 = " << endl;
	t1.imprimir();
}
