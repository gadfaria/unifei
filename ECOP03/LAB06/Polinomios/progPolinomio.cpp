#include <iostream>
#include "cvetor.h"

using namespace std;

int main()
{
	CVetor polinomio;

	cout << "Digite os valores para o polinomio: " << endl;
	cin >> polinomio;

	cout << "POLINOMIO: " << endl;
	cout << polinomio;

	cout << "Raiz aproximada do polinomio: " << polinomio.encontraRaiz() << endl;
}
