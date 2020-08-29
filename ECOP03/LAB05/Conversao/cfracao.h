#ifndef ID_CFRACAO
#define ID_CFRACAO
#include <iostream>
#include "complexo.h"
using namespace std;

class CFracao
{
protected:
	int m_numerador;
	int m_denominador;

	CFracao Reduzida(void);

public:
	//CONSTRUTURES
	CFracao(void)
	{
		m_numerador = 1;
		m_denominador = 1;
	}

	CFracao(int Num, int Denom) : m_numerador(Num),
								  m_denominador(Denom){};
	CFracao(const CFracao &f)
	{
		m_numerador = f.m_numerador;
		m_denominador = f.m_denominador;
	}

	//DESTRUTOR
	~CFracao(void){};

	//CONVERSAO
	operator Complexo();

	//GET
	int getNumerador(void) { return m_numerador; }
	int getDenominador(void) { return m_denominador; }

	//OPERA��ES ARITMETICAS
	CFracao operator+(CFracao &_Fracao);
	CFracao operator-(CFracao &_Fracao);
	CFracao operator/(CFracao &_Fracao);
	CFracao operator*(CFracao &_Fracao);

	//COMPARA��O
	int operator<(CFracao &_Fracao);
	int operator>(CFracao &_Fracao);
	int operator==(CFracao &_Fracao);
	int operator!=(CFracao &_Fracao);
	int operator>=(CFracao &_Fracao);
	int operator<=(CFracao &_Fracao);

	float ComoFloat(void);

	//OUT - IN
	friend ostream &operator<<(ostream &out, const CFracao &_Fracao);
	friend istream &operator>>(istream &in, CFracao &_Fracao);
};
#endif
