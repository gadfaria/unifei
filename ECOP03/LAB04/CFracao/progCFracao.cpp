#include <iostream>
#include "CFracao.h"

using namespace std;

int main()
{
	CFracao fracao1;
	CFracao fracao2;
	CFracao resultado;

	cout << "Digite o numerador e denominador da fracao 1 : " << endl;
	cin >> fracao1;

	cout << "Digite o numerador e denominador da fracao 2 : " << endl;
	cin >> fracao2;

	//SOMA
	resultado = fracao1 + fracao2;
	cout << fracao1 << " + " << fracao2 << " = " << resultado << endl;

	//SUBTRA��O
	resultado = fracao1 - fracao2;
	cout << fracao1 << " - " << fracao2 << " = " << resultado << endl;

	//MULTIPLICA��O
	resultado = fracao1 * fracao2;
	cout << fracao1 << " * " << fracao2 << " = " << resultado << endl;

	//DIVIS�O
	resultado = fracao1 / fracao2;
	cout << fracao1 << " / " << fracao2 << " = " << resultado << endl;

	//MAIOR OU MAIOR
	if (fracao1 < fracao2)
	{
		cout << fracao1 << " menor que " << fracao2 << endl;
	}
	else
	{
		if (fracao1 > fracao2)
		{
			cout << fracao1 << " maior que " << fracao2 << endl;
		}
	}

	//IGUAL OU DIFERENTE
	if (fracao1 != fracao2)
	{
		cout << fracao1 << "diferente de " << fracao2 << endl;
	}
	else
	{
		if (fracao1 == fracao2)
		{
			cout << fracao1 << " igual a" << fracao2 << endl;
		}
	}

	//MAIOR OU IGUAL, MENOR OU IGUAL
	if (fracao1 <= fracao2)
	{
		cout << fracao1 << " menor ou igual que " << fracao2 << endl;
	}
	else
	{
		if (fracao1 >= fracao2)
		{
			cout << fracao1 << " maior ou igual que " << fracao2 << endl;
		}
	}

	//IMPRIMIR COMO FLOAT
	cout << fracao1 << " como float " << fracao1.ComoFloat() << endl;
	cout << fracao2 << " como float " << fracao2.ComoFloat() << endl;
}
