#include "CFracao.h"
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////
CFracao CFracao::operator+(CFracao &_Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_denominador +
					 m_denominador * _Fracao.m_numerador,
				 m_denominador * _Fracao.m_denominador);
	return temp.Reduzida();
}
/////////////////////////////////////////////////////////////////////////////////
CFracao CFracao::operator-(CFracao &_Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_denominador -
					 m_denominador * _Fracao.m_numerador,
				 m_denominador * _Fracao.m_denominador);
	return temp.Reduzida();
}
/////////////////////////////////////////////////////////////////////////////////
CFracao CFracao::operator*(CFracao &_Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_numerador,
				 m_denominador * _Fracao.m_denominador);
	return temp.Reduzida();
}
/////////////////////////////////////////////////////////////////////////////////
CFracao CFracao::operator/(CFracao &_Fracao)
{
	CFracao temp(m_numerador * _Fracao.m_denominador,
				 m_denominador * _Fracao.m_numerador);
	return temp.Reduzida();
}
/////////////////////////////////////////////////////////////////////////////////
int CFracao::operator<(CFracao &_Fracao)
{
	return (m_numerador * _Fracao.m_denominador <
			m_denominador * _Fracao.m_numerador);
}
/////////////////////////////////////////////////////////////////////////////////
int CFracao::operator>(CFracao &_Fracao)
{
	return (m_numerador * _Fracao.m_denominador >
			m_denominador * _Fracao.m_numerador);
}
/////////////////////////////////////////////////////////////////////////////////
int CFracao::operator==(CFracao &_Fracao)
{
	return (m_numerador * _Fracao.m_denominador ==
			m_denominador * _Fracao.m_numerador);
}
/////////////////////////////////////////////////////////////////////////////////
int CFracao::operator!=(CFracao &_Fracao)
{
	return (m_numerador * _Fracao.m_denominador !=
			m_denominador * _Fracao.m_numerador);
}
/////////////////////////////////////////////////////////////////////////////////
int CFracao::operator>=(CFracao &_Fracao)
{
	return (m_numerador * _Fracao.m_denominador >=
			m_denominador * _Fracao.m_numerador);
}
/////////////////////////////////////////////////////////////////////////////////
int CFracao::operator<=(CFracao &_Fracao)
{
	return (m_numerador * _Fracao.m_denominador <=
			m_denominador * _Fracao.m_numerador);
}
/////////////////////////////////////////////////////////////////////////////////
float CFracao::ComoFloat(void)
{
	return ((float)m_numerador / (float)m_denominador);
}
/////////////////////////////////////////////////////////////////////////////////
ostream &operator<<(ostream &out, const CFracao &_Fracao)
{
	out << _Fracao.m_numerador << "/" << _Fracao.m_denominador;
	return out;
}
/////////////////////////////////////////////////////////////////////////////////
istream &operator>>(istream &in, CFracao &_Fracao)
{
	in >> _Fracao.m_numerador >> _Fracao.m_denominador;
	return in;
}
