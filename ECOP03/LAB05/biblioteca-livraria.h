#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>>
using namespace std;

class Biblioteca
{
private:
	string nome, autor, editora, nome_emprestado;	 //nome de quem pegou o livro
	int edicao, n_cadastro, d_devolucao, quantidade; //numero de cadastro do livro - data de devolu��o

public:
	Biblioteca();
	~Biblioteca();

	friend istream &operator>>(istream &, Biblioteca &);	   //Definir os dados do livro
	friend ostream &operator<<(ostream &, const Biblioteca &); //Imprimir os dados do livro
	void verificaQuantidade(string);						   //Verifica quantos livros tem disponivel para emprestar
	bool emprestaLivro();									   //Verifica se a pessoa esta cadastrada e o livro esta disponivel, ent�o empresta o livro
	void renovaLivro();										   //Renova a data de entrega do livro para a pessoa que o pegou
};
#endif

#ifndef LIVRARIA_H
#define LIVRARIA_H
#include <iostream>
#include <string>>
using namespace std;

class Livraria
{
private:
	string nome, autor, editora;
	int edicao, n_cadastro, quantidade;
	float preco;

public:
	Biblioteca();
	~Biblioteca();

	friend istream &operator>>(istream &, Livraria &);		 //Definir os dados do livro
	friend ostream &operator<<(ostream &, const Livraria &); //Imprimir os dados do livro
	void verificaQuantidade();								 //Verifica quantos livros tem disponivel para venda
	int precoFinal();										 //Verifica o pre�o final com os atributos(impostos etc)
};
#endif
