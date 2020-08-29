#include <iostream>
#include "equacao.h"

using namespace std;

int main()
{
	Equacao eq;
	cout << "Digite o valor de a, b e c para a equacao de segundo grau: " << endl;
	cin >> eq;
	cout << endl;

	cout << eq;
	eq.Raiz();
}
