#ifndef PILHA_H
#define PILHA_H

#include <new>
#include <iostream>

using namespace std;

template <typename T>
class CPilha
{
private:
	T *m_dados;			   // ponteiro para dados da pilha
	int m_ponteirodaPilha; // apontador do topo da pilha
	int m_tamanho;		   // espa�o de mem�ria reservado para o objeto

public:
	CPilha(int);					// construtor
	CPilha();						// construtor sem par�metros
	~CPilha() { delete[] m_dados; } // destrutor

	bool pop(T &); // puxar dados da pilha
	bool push(T);  // empurrar dados para a pilha

	template <typename T1>
	friend ostream &operator<<(ostream &, CPilha<T> &);
	template <typename T1>
	friend istream &operator>>(istream &, CPilha<T> &);
};

#endif

template <typename T>
CPilha<T>::CPilha(int sz)
{
	try
	{
		m_dados = new T[sz];
	}
	catch (bad_alloc &ba)
	{
		cout << "bad_alloc capturada: " << ba.what() << endl;
	}
	m_ponteirodaPilha = -1;
	m_tamanho = sz;
}

template <typename T>
CPilha<T>::CPilha()
{
	m_dados = new T[10]; //tamanho fico em 10
	m_ponteirodaPilha = -1;
}

template <typename T>
bool CPilha<T>::pop(T &valor)
{
	if (m_ponteirodaPilha != -1)
	{
		valor = m_dados[m_ponteirodaPilha];
		m_ponteirodaPilha--;
		return true;
	}
	return false;
}

template <typename T>
bool CPilha<T>::push(T valor)
{
	if (m_ponteirodaPilha != m_tamanho - 1)
	{
		m_ponteirodaPilha++;
		m_dados[m_ponteirodaPilha] = valor;
		return true;
	}
	return false;
}

template <typename T>
ostream &operator<<(ostream &out, CPilha<T> &p)
{
	for (int i = 0; i <= p.m_ponteirodaPilha; i++)
	{
		out << p.pilha[i] << " ";
	}
	return out;
}

template <typename T>
istream &operator>>(istream &in, CPilha<T> &p)
{
	T valor;
	in >> valor;
	p.push(valor);

	return in;
}
