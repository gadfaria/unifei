#ifndef EQUACAO_H
#define EQUACAO_H

#include <iostream>
using namespace std;

class Equacao
{
private:
	int a, b, c;

public:
	//CONTRUTORES E DESTRUTORES
	Equacao()
	{
		a = 1;
		b = 1;
		c = 1;
	}
	~Equacao();

	float Delta();
	void Raiz();

	//IN - OUT
	friend ostream &operator<<(ostream &out, Equacao &eq);
	friend istream &operator>>(istream &in, Equacao &eq);
};

#endif
