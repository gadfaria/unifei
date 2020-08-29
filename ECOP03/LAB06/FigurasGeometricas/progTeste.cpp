#include <iostream>
#include "cilindro.h"

using namespace std;

int main()
{
	Cilindro c1;

	cout << "Digite x, y, raio e a altura para o cilindro: " << endl;
	cin >> c1;

	cout << c1 << endl;
	cout << "Area da base do cilindro: " << c1.area() << endl;
	cout << "Volume do cilindro: " << c1.volume() << endl;
}
