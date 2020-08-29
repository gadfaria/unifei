#include <stdio.h>

float percentual(float a, float b)
{
	float p;

	p = 100 * (a / b);
	p = p - 100;

	return p;
}

int main(int argc, char *argv[])
{
	float ValorAnt, ValorAtu, p;

	printf("Digite o valor antigo e o atual de um produto \n");
	scanf("%f", &ValorAnt, &ValorAtu);

	p = percentual(ValorAnt, ValorAtu);

	printf("Aumento igual a %f \n", p);

	return 0;
}
