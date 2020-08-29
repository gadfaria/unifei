#include <stdio.h>

int menorelem(int matriz[6][6])
{
	int i, y = 5, k = 0, menor = 9999;

	for (i = 0; i < 6; i++)
	{
		y = y - k;
		if (matriz[i][y] < menor)
		{
			menor = matriz[i][y];
		}
		k = k + 1;
	}
	return menor;
}

int main(int argc, char *argv[])
{
	int matriz[6][6], i, j, menor;

	printf("Digite os valores da matriz \n");
	for (i = 0; i < 6; i++)
	{
		printf("Linha %d\n", i);
		for (j = 0; j < 6; j++)
		{
			scanf("%d", &matriz[i][j]);
		}
	}

	menor = menorelem(matriz);

	printf("Menor valor da diagonal secundaria igual a %d\n", menor);

	return 0;
}
