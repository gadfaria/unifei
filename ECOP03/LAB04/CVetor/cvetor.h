#ifndef CVETOR_H
#define CVETOR_H

#include <iostream>
using namespace std;

class CVetor
{
private:
	static int count;
	int *dados;
	int topo;

	void aloca_memoria();

public:
	int tamanho;
	int &operator[](int);

	//CONTRUTORES E DESTRUTORES
	CVetor();
	~CVetor();

	//IN - OUT
	friend istream &operator>>(istream &, CVetor &);
	friend ostream &operator<<(ostream &, const CVetor);

	//COMPARADORES
	int operator>(CVetor);
	int operator<(CVetor);
	int operator==(CVetor);
	int operator!=(CVetor);
	int operator>=(CVetor);
	int operator<=(CVetor);
};
#endif
