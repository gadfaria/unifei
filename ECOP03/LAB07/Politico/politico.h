#ifndef POLITICO_H
#define POLITICO_H
#include <iostream>
#include <string>

using namespace std;

class Politico
{
protected:
	string nome, partido;
	int ano_entrada;

public:
	Politico();
	Politico(string n, string p, int a);
	~Politico() {}

	virtual void imprimeDados();
};

#endif
