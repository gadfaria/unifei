#include <stdio.h>

int multiplica(int num1, int num2);

int main(int argc, char *argv[])
{
	int num1, num2, soma;

	printf("\nDigite dois numeros inteiros !\n");
	scanf("%d", &num1);
	scanf("%d", &num2);

	soma = multiplica(num1, num2);

	printf(" \n%d ", soma);
	return 0;
}

int multiplica(int num1, int num2)
{
	int soma, valor;

	if (num1 == 1)
		return num2;
	else
		return (num2 + multiplica(num1 - 1, num2));
}
