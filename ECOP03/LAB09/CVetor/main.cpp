#include <iostream>
#include "cvetor.h"

using namespace std;

int main()
{
	CVetor<char> vetor;
	for (int i = 0; i < (vetor.tamanho); i++)
	{
		cout << "Digite um valor para a posicao " << i << " do vetor : " << endl;
		cin >> vetor[i];
	}

	vetor.ordena();

	for (int i = 0; i < (vetor.tamanho); i++)
	{
		cout << vetor[i] << " - ";
	}
	cout << endl;
}
