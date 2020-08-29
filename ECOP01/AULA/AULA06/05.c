#include <stdio.h>

int main(int argc, char *argv[])
{
	float salJoao, salJose, pJoao, pJose;
	int c;

	printf("Digite o salario de Joao");
	scanf("%f", &salJoao);

	salJose = salJoao / 3;
	pJose = salJose * 1.05;
	pJoao = salJoao * 1.02;

	while (pJose > pJoao)
	{
		pJose = (pJose + salJose) * 1.05;
		pJoao = (pJoao + salJoao) * 1.02;
		c = c++;
	}
	c = c + 1;
	printf("Meses necessario igual a %d", c);

	return 0;
}
