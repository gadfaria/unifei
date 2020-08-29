#ifndef POLIGONOS_H
#define POLIGONOS_H

class Poligonos
{

private:
	int comprimento;
	int numeroLados;

public:
	Poligonos(int = 3, int = 1);
	~Poligonos();

	int area();
	int perimetro();
	void nome();
	void dados();
	void set_comprimento(int);
	void set_largura(int);
};

#endif
