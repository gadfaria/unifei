#include <stdio.h>

int main(int argc, char *argv[])
{
	int idade, menor = 0, maior = 0, x, y;
	float alt, peso, altTotal = 0, idadeTotal;

	for (x = 0; x <= 5; x++)
	{
		idadeTotal = 0;
		for (y = 0; y <= 11; y++)
		{
			peso = 0;
			alt = 0;
			idade = 0;
			printf("Digite a altura, o peso e a idade do jogador");
			scanf("%f", &alt);
			scanf("%f", &peso);
			scanf("%d", &idade);

			if (idade < 18)
			{
				menor = menor++;
			}

			idadeTotal = idadeTotal + idade;
			altTotal = altTotal + alt;

			if (peso > 80)
			{
				maior = maior++;
			}
			idadeTotal = idadeTotal / 11;
			printf("Media idade %f\n", idadeTotal);
			{
			}
			altTotal = altTotal / 55;
			printf("Media altura %f\n", altTotal);
			printf("Pesa mais que 80 %d\n", maior);
			printf("Menor que 18 %d\n", menor);

			return 0;
		}
	}
}
