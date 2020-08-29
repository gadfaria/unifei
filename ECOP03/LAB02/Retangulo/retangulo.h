#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo
{

private:
	int comprimento;
	int largura;

public:
	Retangulo(int = 1, int = 1);
	~Retangulo();

	int area();
	int perimetro();
	bool quadrado();
	void desenhaRetangulo();
	void dados();
	void set_comprimento(int);
	void set_largura(int);
	int get_comprimento();
	int get_largura();
};

#endif
