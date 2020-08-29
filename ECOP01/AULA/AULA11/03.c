#include <stdio.h>

float produto(float a, int b);

int main(int argc, char *argv[])
{
	float a, produtoT;
	int b;
	printf("Digite dois numeros");
	scanf("%f", &a);
	scanf("%d", &b);

	produtoT = produto(a, b);

	printf("%f", produtoT);

	return 0;
}

float produto(float a, int b)
{

	if (b == 1)
		return (a);
	else
		return (a * produto(a, b - 1));
}
