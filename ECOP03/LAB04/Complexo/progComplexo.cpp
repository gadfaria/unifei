#include <iostream>
#include "complexo.h"

using namespace std;

int main()
{
	Complexo num1;
	Complexo num2;
	Complexo resultado;

	Complexo::Contador();

	cout << "Digite valores para o numero complexo 1: " << endl;
	cin >> num1;
	cout << "Digite valores para o numero complexo 2: " << endl;
	cin >> num2;

	//SOMA
	resultado = num1 + num2;
	cout << num1 << " + " << num2 << " = " << resultado << endl;

	//SUBTRA��O
	resultado = num1 - num2;
	cout << num1 << " - " << num2 << " = " << resultado << endl;

	//MULTIPLICA��O
	resultado = num1 * num2;
	cout << num1 << " * " << num2 << " = " << resultado << endl;

	//DIVIS�O
	resultado = num1 / num2;
	cout << num1 << " / " << num2 << " = " << resultado << endl;

	//COMPARA��O
	if (num1 > num2)
	{
		cout << num1 << " e maior que " << num2 << endl;
	}
	else
	{
		if (num1 < num2)
		{
			cout << num1 << " e menor que " << num2 << endl;
		}
	}

	if (num1 != num2)
	{
		cout << num1 << " e diferente " << num2 << endl;
	}
	else
	{
		if (num1 == num2)
		{
			cout << num1 << " e igual ao " << num2 << endl;
		}
	}

	if (num1 >= num2)
	{
		cout << num1 << " e maior ou igual que " << num2 << endl;
	}
	else
	{
		if (num1 <= num2)
		{
			cout << num1 << " e menor ou igual que " << num2 << endl;
		}
	}

	//MODULO
	cout << num1 << " modulo = " << num1.Modulo() << endl;
	cout << num1 << " angulo = " << num1.Angulo() << endl;

	cout << num2 << " modulo = " << num2.Modulo() << endl;
	cout << num2 << " angulo = " << num2.Angulo() << endl;
}
