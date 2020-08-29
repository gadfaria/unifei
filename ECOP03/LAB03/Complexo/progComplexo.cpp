#include <iostream>
#include "Complexo.h"

using namespace std;

int main()
{
	Complexo num1(5, 2);
	Complexo num2;
	Complexo resultado;

	Complexo::Contador();

	//SOMA
	num1.Imprime();
	cout << " + ";
	num2.Imprime();
	cout << " = ";
	resultado = num1.Somar(num2);
	resultado.Imprime();
	cout << endl;

	//SUBTRA��O
	num1.Imprime();
	cout << " - ";
	num2.Imprime();
	cout << " = ";
	resultado = num1.Subtrair(num2);
	resultado.Imprime();
	cout << endl;

	//MULTIPLICA��O
	num1.Imprime();
	cout << " * ";
	num2.Imprime();
	cout << " = ";
	resultado = num1.Multiplicar(num2);
	resultado.Imprime();
	cout << endl;

	//DIVIS�O
	num1.Imprime();
	cout << " / ";
	num2.Imprime();
	cout << " = ";
	resultado = num1.Dividir(num2);
	resultado.Imprime();
	cout << "\n"
		 << endl;

	//MODULO
	num1.Imprime();
	cout << " modulo = " << num1.Modulo() << endl;
	cout << " angulo = " << num1.Angulo() << endl;

	cout << endl;

	num2.Imprime();
	cout << " modulo = " << num2.Modulo() << endl;
	cout << " angulo = " << num2.Angulo() << endl;
}
