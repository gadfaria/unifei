#ifndef PREFEITO_H
#define PREFEITO_H

#include "governador.h"
#include <string>

class Prefeito : public Governador
{
protected:
	string cidade;

public:
	Prefeito();
	Prefeito(string, string, int, string, string, string);
	~Prefeito() {}

	void imprimeDados();
};

#endif
