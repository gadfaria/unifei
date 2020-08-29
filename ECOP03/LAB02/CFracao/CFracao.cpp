#include "CFracao.h"
#include <iostream>
using namespace std;
//
// M�todos Protegidos da classe CFracao
//
CFracao CFracao::Reduzida(void)
{
	int gcd = 1;
	int minimo = m_numerador;
	if (m_numerador > m_denominador)
		minimo = m_denominador;
	for (int i = 1; i <= minimo; i++)
	{
		if ((m_numerador % i == 0) && (m_denominador % i == 0))
			gcd = i;
	}
	m_numerador /= gcd;
	m_denominador /= gcd;
	return (*this);
}
//
// M�todos Aritm�ticos da classe CFracao
//
// retorna uma nova Fracao que � a soma do receptor com _Fracao
CFracao CFracao::Somar(CFracao _Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_denominador +
					 m_denominador * _Fracao.m_numerador,
				 m_denominador * _Fracao.m_denominador);
	return temp.Reduzida();
}
// retorna uma nova Fracao que � a subtra��o do receptor com _Fracao
CFracao CFracao::Subtrair(CFracao _Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_denominador -
					 m_denominador * _Fracao.m_numerador,
				 m_denominador * _Fracao.m_denominador);
	return temp.Reduzida();
}
// retorna uma nova Fracao que o produto do receptor e _Fracao
CFracao CFracao::Multiplicar(CFracao _Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_numerador,
				 m_denominador * _Fracao.m_denominador);
	return temp.Reduzida();
}
// retorna uma nova Fracao que o quociente do receptor e _Fracao
CFracao CFracao::Dividir(CFracao _Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_denominador,
				 m_denominador * _Fracao.m_numerador);
	return temp.Reduzida();
}
//
// M�todos de compara��o da classe CFracao
//
// devolve verdadeiro se receptor menor que _Fracao
int CFracao::MenorQue(CFracao _Fracao)
{
	return (m_numerador * _Fracao.m_denominador <
			m_denominador * _Fracao.m_numerador);
}
// devolve verdadeiro se receptor maior que _Fracao
int CFracao::MaiorQue(CFracao _Fracao)
{
	return (m_numerador * _Fracao.m_denominador >
			m_denominador * _Fracao.m_numerador);
}
// devolve verdadeiro se receptor igual a _Fracao
int CFracao::Igual(CFracao _Fracao)
{
	return (m_numerador * _Fracao.m_denominador ==
			m_denominador * _Fracao.m_numerador);
}
//
// M�todos de convers�o
//
// devolve o valor da fra��o como float
float CFracao::ComoFloat(void)
{
	return ((float)m_numerador / (float)m_denominador);
}
//
// M�todos de impress�o
//
// mostrar o receptor no formato m_numerador/m_denominador
void CFracao::Print(void)
{
	cout << m_numerador << "/" << m_denominador;
}
