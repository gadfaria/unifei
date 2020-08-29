#include <stdio.h>

int multiplica(int n)
{
	int matriz[n][n], i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			k = (i + 1) * (j + 1);
			printf(" %d ", k);
		}
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	int n;

	printf("Digite um numero inteiro entre 1 e 9 \n");
	scanf("%d", &n);

	multiplica(n);

	return 0;
}
