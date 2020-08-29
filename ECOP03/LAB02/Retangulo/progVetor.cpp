#include <iostream>
#include "retangulo.h"

using namespace std;

int main()
{

	Retangulo vet[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Para o retangulo " << i + 1 << ":" << endl;
		vet[i].dados();
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Para o retangulo " << i + 1 << ":" << endl;
		vet[i].desenhaRetangulo();
	}
}
