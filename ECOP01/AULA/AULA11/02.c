#include <stdio.h>

int soma(int num);

int main(int argc, char *argv[])
{
	int num, somaT;

	printf("Digite um numero");
	scanf("%d", &num);

	somaT = soma(num);
	printf("%d", somaT);

	return 0;
}

int soma(int num)
{

	if (num == 1)
		return 1;
	else
		return (num + soma(num - 1));
}
