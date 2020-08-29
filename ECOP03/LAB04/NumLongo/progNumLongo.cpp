#include <iostream>
#include "numLongo.h"

using namespace std;

int main()
{
	cout << "APENAS NUMEROS POSITIVOS E NUMERO DE 30 DIGITOS\n"
		 << endl;

	NumLongo t1;
	NumLongo t2;

	cout << "Digite o valor para o numero 1: " << endl;
	cin >> t1;
	cout << "Digite o valor para o numero 2: " << endl;
	cin >> t2;
	cout << endl;

	cout << t1 << " + " << t2 << " = ";
	t1 + t2;
	cout << t1 << " - " << t2 << " = ";
	t1 - t2;
	cout << endl;

	if (t1 > t2)
	{
		cout << t1 << " maior que " << t2 << endl;
	}
	else
	{
		if (t1 < t2)
		{
			cout << t1 << " menor que " << t2 << endl;
		}
	}

	if (t1 != t2)
	{
		cout << t1 << " diferente de " << t2 << endl;
	}
	else
	{
		if (t1 == t2)
		{
			cout << t1 << " igual a " << t2 << endl;
		}
	}

	if (t1 >= t2)
	{
		cout << t1 << " maior ou igual a " << t2 << endl;
	}
	else
	{
		if (t1 <= t2)
		{
			cout << t1 << " menor ou igual a " << t2 << endl;
		}
	}
}
