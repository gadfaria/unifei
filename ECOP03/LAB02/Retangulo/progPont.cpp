#include <iostream>
#include "retangulo.h"

using namespace std;

int main()
{
	Retangulo *ptr;
	Retangulo teste;
	ptr = &teste;
	ptr->dados();
	ptr->desenhaRetangulo();
}
