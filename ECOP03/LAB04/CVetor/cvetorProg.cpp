#include <iostream>
#include "cvetor.h"

using namespace std;

int main()
{
	cout << "DIGITE O TAMANHO IGUAL PARA OS DOIS VETORES PARA PODER COMPARAR OS VALORES\n"
		 << endl;

	int maior;
	CVetor vetor1, vetor2;

	for (int i = 0; i < (vetor1.tamanho); i++)
	{
		cout << "Digite um numero para a posicao " << i << " do vetor 1: " << endl;
		cin >> vetor1[i];
	}
	cout << endl;

	for (int i = 0; i < (vetor2.tamanho); i++)
	{
		cout << "Digite um numero para a posicao " << i << " do vetor 2: " << endl;
		cin >> vetor2[i];
	}
	cout << endl;

	cout << "COMPARAÇÃO DOS VALORES DE CADA POSICAO DOS VETORES" << endl;
	for (int i = 0; i < (vetor1.tamanho); i++)
	{
		if (vetor1[i] > vetor2[i])
			cout << vetor1[i] << " maior que " << vetor2[i] << endl;
		else if (vetor1[i] < vetor2[i])
			cout << vetor1[i] << " menor que " << vetor2[i] << endl;

		if (vetor1[i] == vetor2[i])
			cout << vetor1[i] << " igual ao " << vetor2[i] << endl;
		else if (vetor1[i] != vetor2[i])
			cout << vetor1[i] << " diferente de " << vetor2[i] << endl;

		if (vetor1[i] >= vetor2[i])
			cout << vetor1[i] << " maior ou igual ao " << vetor2[i] << endl;
		else if (vetor1[i] <= vetor2[i])
			cout << vetor1[i] << " menor ou igual ao " << vetor2[i] << endl;

		cout << endl;
	}
}
