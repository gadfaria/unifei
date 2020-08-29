#include <iostream>
#include "complexo.h"
#include "cfracao.h"

using namespace std;

int main()
{

	CFracao f;
	Complexo c;
	cout << "Digite um valor para a fracao: " << endl;
	cin >> f;
	c = Complexo(f);

	cout << "Valor convertido em complexo: " << c << endl;
}
