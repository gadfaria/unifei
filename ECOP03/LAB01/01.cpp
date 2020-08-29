#include <iostream>

using namespace std;

void fatorial();
void primos();
bool testaPrimos(int num);
void conversao();
void printInt(int n, int base);
void retangulo();
void somatorio();
int calculoSomatorio(int num);
void mdc();
int testaMDC(int numX, int numY);

int main()
{
	int opcao = 1;

	while (opcao != 0)
	{
		cout << "\n0 - Para sair do programa \n1 - Para calcular fatorial \n";
		cout << "2 - Para verificar os 20 primeiros numeros primos \n3 - Converter decimal para hexadecimal \n";
		cout << "4 - Para criar um retangulo \n5 - Calcular somatorio\n";
		cout << "6 - Calcular MDC\n";
		cin >> opcao;
		switch (opcao)
		{
		case 0:
			break;
		case 1:
			fatorial();
			break;
		case 2:
			primos();
			break;
		case 3:
			conversao();
			break;
		case 4:
			retangulo();
			break;
		case 5:
			somatorio();
			break;
		case 6:
			mdc();
			break;
		default:
			cout << "Numero invalido \n";
			break;
		}
	}
}

void fatorial()
{
	int fat = 1, num;

	cout << "Digite um numero : ";
	cin >> num;

	while (num > 0)
	{
		fat = fat * num;
		num--;
	}

	cout << "Fatorial igual : " << fat << "\n";
}

void primos()
{
	int numPrimos[20], c = 0, num = 2;

	while (c < 20)
	{
		if (testaPrimos(num) == true)
		{
			numPrimos[c] = num;
			c++;
			num++;
		}
		else
		{
			num++;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		cout << " " << numPrimos[i] << " ";
	}
	cout << "\n";
}

bool testaPrimos(int num)
{
	int c = 0, teste = 1;

	while (teste <= num)
	{
		if (num % teste == 0)
		{
			c++;
		}
		if (c > 2)
		{
			return false;
		}
		teste++;
	}
	return true;
}

void conversao()
{
	int n;
	cout << "Digite o numero para ser convertido:\n";
	cin >> n;
	printInt(n, 16);
	cout << "\n";
}

void printInt(int n, int base)
{
	char Array[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
					  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	if (n >= base)
		printInt(n / base, base);
	cout << Array[n % base];
}

void retangulo()
{
	int largura, altura;
	char charBorda, charPreenchi, preenchimento;

	cout << "Digite a largura e a altura do retangulo : \n";
	cin >> largura;
	cin >> altura;

	cout << "Digite o caracter para a borda e preenchimento : \n";
	cin >> charBorda;
	cin >> charPreenchi;

	cout << "Digite 's' para preenchimento ou 'n' caso contrario : \n";
	cin >> preenchimento;

	for (int i = 0; i < altura; i++)
	{
		cout << "\n";
		for (int j = 0; j < largura; j++)
		{
			if (i == 0 || i == altura - 1)
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

	cout << "\n";
}

void somatorio()
{
	int num, soma = 0;

	cout << "Digite um numero : \n";
	cin >> num;

	soma = calculoSomatorio(num);
	cout << "Soma do numero de 1 ate " << num << " igual a " << soma << "\n";
}

int calculoSomatorio(int num)
{
	if (num == 0)
	{
		return num;
	}
	else
	{
		return (num + calculoSomatorio(num - 1));
	}
}

void mdc()
{
	int numX, numY, mdc;

	cout << "Digite dois numeros inteiros : \n";
	cin >> numX;
	cin >> numY;

	mdc = testaMDC(numX, numY);

	cout << "MDC igual a " << mdc << "\n";
}

int testaMDC(int numX, int numY)
{
	if (numY == 0)
	{
		return numX;
	}
	else
	{
		return (testaMDC(numY, numX % numY));
	}
}
