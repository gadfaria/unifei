#ifndef CVETOR_H
#define CVETOR_H

#include <iostream>
#include <new>
using namespace std;

template <typename T>
class CVetor
{
private:
	T *dados;
	int topo;

public:
	int tamanho;
	T &operator[](int);

	CVetor();
	~CVetor() { delete[] dados; }

	void ordena();

	template <typename T1>
	friend istream &operator>>(istream &, CVetor<T> &);
	template <typename T1>
	friend ostream &operator<<(ostream &, const CVetor<T>);
};
#endif

template <typename T>
T &CVetor<T>::operator[](int pos)
{
	return dados[pos];
}

template <typename T>
CVetor<T>::CVetor()
{
	int tam;
	cout << "Digite o tamanho do vetor:" << endl;
	cin >> tam;

	try
	{
		dados = new T[tam];
	}
	catch (bad_alloc &ba)
	{
		cout << ba.what() << endl;
	}
	tamanho = tam;
	topo = -1;
}

template <typename T>
void CVetor<T>::ordena()
{
	T aux;
	for (int i = 0; i < tamanho; i++)
		for (int j = 0; j < tamanho - 1; j++)
			if (dados[j + 1] < dados[j])
			{
				aux = dados[j];
				dados[j] = dados[j + 1];
				dados[j + 1] = aux;
			}
}

template <typename T>
istream &operator>>(istream &in, CVetor<T> &vetor)
{
	int valor;
	in >> valor;
	return in;
}

template <typename T>
ostream &operator<<(ostream &out, CVetor<T> &vetor)
{
	out << vetor.dados << endl;
	return out;
}
