#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include <iostream>
#include "politico.h"
#include <string>

using namespace std;

class Presidente : public Politico
{
protected:
	string pais;

public:
	Presidente(string, string, int, string);
	~Presidente() {}

	void imprimeDados();
};

#endif
