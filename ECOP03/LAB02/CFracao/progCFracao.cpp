#include <iostream>
#include "CFracao.h"

using namespace std;

int main()
{
	CFracao fracao1(9, 2);
	CFracao fracao2(5, 3);
	CFracao resultado(1, 1);

	//SOMA
	fracao1.Print();
	cout << " + ";
	fracao2.Print();
	resultado = fracao1.Somar(fracao2);
	cout << " = ";
	resultado.Print();
	cout << endl;

	//SUBTRA��O
	fracao1.Print();
	cout << " - ";
	fracao2.Print();
	resultado = fracao1.Subtrair(fracao2);
	cout << " = ";
	resultado.Print();
	cout << endl;

	//MULTIPLICA��O
	fracao1.Print();
	cout << " x ";
	fracao2.Print();
	resultado = fracao1.Multiplicar(fracao2);
	cout << " = ";
	resultado.Print();
	cout << endl;

	//DIVIS�O
	fracao1.Print();
	cout << " / ";
	fracao2.Print();
	resultado = fracao1.Dividir(fracao2);
	cout << " = ";
	resultado.Print();
	cout << endl;

	//MAIOR, MAIOR OU IGUAL
	if (fracao1.MenorQue(fracao2) == 1)
	{
		fracao1.Print();
		cout << " menor que ";
		fracao2.Print();
		cout << endl;
	}
	else
	{
		if (fracao1.MaiorQue(fracao2) == 1)
		{
			fracao1.Print();
			cout << " maior que ";
			fracao2.Print();
			cout << endl;
		}
		else
		{
			if (fracao1.Igual(fracao2) == 1)
			{
				fracao1.Print();
				cout << " igual a ";
				fracao2.Print();
				cout << endl;
			}
		}
	}

	//IMPRIMIR COMO FLOAT
	fracao1.Print();
	cout << " como float " << fracao1.ComoFloat() << endl;
	fracao2.Print();
	cout << " como float " << fracao2.ComoFloat() << endl;
}
