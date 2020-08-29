#include <iostream>
#include "retangulo.h"
using namespace std;

Retangulo::Retangulo(int larg, int comp)
{
    largura = larg;
    comprimento = comp;
    cout << "construindo objeto ..." << endl;
}

Retangulo::~Retangulo()
{
    cout << "destruindo objeto ..." << endl;
}

int Retangulo::area()
{
    return largura * comprimento;
}

int Retangulo::perimetro()
{
    return 2 * (largura + comprimento);
}

bool Retangulo::quadrado()
{
    return (largura == comprimento ? true : false);
}

void Retangulo::desenhaRetangulo()
{
    char charBorda, charPreenchi, preenchimento;

    cout << "Digite o caracter para a borda e preenchimento :" << endl;
    cin >> charBorda;
    cin >> charPreenchi;

    cout << "Digite 's' para preenchimento ou 'n' caso contrario :" << endl;
    cin >> preenchimento;

    for (int i = 0; i < comprimento; i++)
    {
        cout << "\n";
        for (int j = 0; j < largura; j++)
        {
            if (i == 0 || i == comprimento - 1)
            {
                cout << charBorda;
            }
            else
            {
                if (j == 0 || j == largura - 1)
                {
                    cout << charBorda;
                }
                else
                {
                    if (preenchimento == 's')
                    {
                        cout << charPreenchi;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
    }
    cout << endl;
}

void Retangulo::dados()
{
    int larg, comp;

    cout << "Digite os valores de largura e comprimento:" << endl;
    cin >> larg;
    cin >> comp;

    set_comprimento(comp);
    set_largura(larg);
}

void Retangulo::set_comprimento(int comp)
{
    if (comp >= 0 && comp <= 20)
        comprimento = comp;
}

void Retangulo::set_largura(int larg)
{
    if (larg >= 0 && larg <= 20)
        largura = larg;
}

int Retangulo::get_comprimento()
{
    return comprimento;
}

int Retangulo::get_largura()
{
    return largura;
}
