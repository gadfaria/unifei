#ifndef TRIANGULO_H
#define TRIANGULO_H

class Triangulo
{
private:
	int hipotenusa;
	int cateto1;
	int cateto2;

public:
	Triangulo(int, int, int);
	~Triangulo();

	bool verificaTriangulo();
	static void imprimeTriangulos();
	void get_dados(int, int, int);
};

#endif
