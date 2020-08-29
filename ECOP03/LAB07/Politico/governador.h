#ifndef GOVERNADOR_H
#define GOVERNADOR_H

#include "presidente.h"
#include <string>

class Governador : public Presidente
{
protected:
	string estado;

public:
	Governador();
	Governador(string, string, int, string, string);
	~Governador() {}

	void imprimeDados();
};

#endif
