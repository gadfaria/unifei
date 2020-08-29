#include <iostream>
#include "point.h"

using namespace std;

int main()
{
	Point p1;
	Point p2;
	Point p3, p4;

	cout << "Digite valor para p1: " << endl;
	cin >> p1;
	cout << "Digite valor para p2: " << endl;
	cin >> p2;

	cout << "pos-Incrementar p1 e pos-Descrementar p2" << endl;
	p1++;
	p2--;

	cout << "p1: (" << p1 << ")" << endl;
	cout << "p2: (" << p2 << ")" << endl;

	p3 = p1 + p2;
	p4 = p1 + p2;
	cout << "p3 igual a p1+p2 e depois Pré-Decremento" << endl;
	cout << "p4 igual a p1+p2 e depois Pré-Incremento" << endl;
	--p3;
	++p4;
	cout << "p3: (" << p3 << ")" << endl;
	cout << "p4: (" << p4 << ")" << endl;
}
