#include <stdio.h>

int soma(int a, int b)
{
	int x, soma;

	for (x = a; x < b; x++)
	{
		soma = soma + x;
	}

	return (soma);
}

int main(int argc, char *argv[])
{
	int n1, n2, a, b, s;

	printf("Digite dois numeros inteiro e positivos\n");
	scanf("%d", &n1, &n2);

	if (n1 > n2)
	{
		a = n2;
		b = n1;
	}
	else
	{
		a = n1;
		b = n2;
	}
	s = soma(a, b);
	printf("Soma dos numeros igual a %d \n", s);
	return 0;
}
