#include <iostream>
#include "prefeito.h"
#include "politico.h"
#include "presidente.h"
#include "governador.h"
#include <string>

using namespace std;

int main()
{
	Politico *vetPol[3];
	int opcao;

	cout << "1-Presidente\n2-Governador\n3-Prefeito" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Escolha o cargo do vetor " << i + 1 << ": " << endl;
		cin >> opcao;
		switch (opcao)
		{
		case 1:
			vetPol[i] = new Presidente("Lulinha", "PT", 2003, "Brasil");
			break;
		case 2:
			vetPol[i] = new Governador("AecioPó", "PSDB", 2011, "Brasil", "MinasGerais");
			break;
		case 3:
			vetPol[i] = new Prefeito("Rodriguinho", "NS", 2016, "Brasil", "MinasGerais", "Itajuba");
			break;
		}
	}

	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		vetPol[i]->imprimeDados();
		cout << endl;
	}
}
