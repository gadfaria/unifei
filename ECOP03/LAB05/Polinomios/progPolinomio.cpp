#include <iostream>
#include "cvetor.h"

using namespace std;

int main()
{
	/*
TIVE PROBLEMAS PARA IMPRIMIR O POLINOMIO COM O X^N POIS SOBRECARREGANDO O '[]' O OPERADOR DE SAIDA OUT NAO 
ERA USADO.
*/
	cout << "DIGITAR O MESMO TAMANHO PARA OS DOIS POLINOMIOS!!\n"
		 << endl;
	CVetor polinomio1, polinomio2;

	for (int i = 0; i < (polinomio1.tamanho); i++)
	{
		cout << "Digite um numero para a posicao " << i << " do polinomio 1: " << endl;
		cin >> polinomio1[i];
	}
	cout << endl;

	for (int i = 0; i < (polinomio2.tamanho); i++)
	{
		cout << "Digite um numero para a posicao " << i << " do polinomio 2: " << endl;
		cin >> polinomio2[i];
	}
	cout << endl;

	for (int i = 0; i < (polinomio1.tamanho); i++)
	{
		cout << polinomio1[i] << "x^" << i << " + " << polinomio2[i] << "x^" << i << " = " << polinomio1[i] + polinomio2[i] << "x^" << i << endl;
	}
	cout << endl;
	for (int i = 0; i < (polinomio1.tamanho); i++)
	{
		cout << polinomio1[i] << "x^" << i << " - " << polinomio2[i] << "x^" << i << " = " << polinomio1[i] - polinomio2[i] << "x^" << i << endl;
	}
}
