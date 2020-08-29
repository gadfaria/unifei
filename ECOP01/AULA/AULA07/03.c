#include <stdio.h>

int main(int argc, char *argv[])
{
	int m[5][7], i, j, k, maior = -9999, menor = 9999;

	printf("Digite os valores da matriz \n");
	for (i = 0; i < 5; i++)
	{
		printf("Linha %d \n", i);
		for (j = 0; j < 7; i++)
		{
			scanf("%d", &m[i][j]);
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (m[i][j] < menor)
			{
				menor = m[i][j];
			}
			for (k = 0; k < 5; k++)
			{
				if (m[k][j] > maior)
				{
					maior = m[i][j];
				}
				if (menor == maior)
				{
					printf("Ponto de sela igual a %d\n", menor);
					printf("Posição igual de linha %d e coluna %d", i, j);
				}
			}
		}
	}
	return 0;
}
