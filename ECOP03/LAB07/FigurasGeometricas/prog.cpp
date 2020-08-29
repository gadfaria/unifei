#include <iostream>
#include "cilindro.h"
#include "ponto.h"
#include "circulo.h"

using namespace std;

int main()
{
	Ponto *vetPot[3];
	int opcao;

	cout << "1-Ponto\n2-Circulo\n3-Cilindro" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Escolha uma opcao para o vetor " << i + 1 << ": " << endl;
		cin >> opcao;
		switch (opcao)
		{
		case 1:
			vetPot[i] = new Ponto(100, 100);
			break;
		case 2:
			vetPot[i] = new Circulo(2, 2, 2);
			break;
		case 3:
			vetPot[i] = new Cilindro(5, 5, 5, 5);
			break;
		}
	}

	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		vetPot[i]->imprimeDados();
		cout << "Area: " << vetPot[i]->area() << endl;
		cout << "Volume: " << vetPot[i]->volume() << endl;
		;
		cout << endl;
	}
}
