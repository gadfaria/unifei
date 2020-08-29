#include <stdio.h>

int main(int argc, char *argv[])
{
	int m[10][10], i, j, k = 0, y = 9, n;

	printf("Digite os valores da matriz 10x10 \n");
	for (i = 0; i < 10; i++)
	{
		printf("Linha %d", i);
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}
	for (j = 0; j < 10; j++)
	{
		n = 0;
		n = m[2][j];
		m[2][j] = m[8][j];
		m[8][j] = n;
	}
	for (i = 0; i < 10; i++)
	{
		n = 0;
		n = m[i][4];
		m[i][4] = m[i][8];
		m[i][8] = n;
	}
	for (i = 0; i < 10; i++)
	{
		n = 0;
		y = y - k;
		n = m[i][y];
		m[i][y] = m[i][i];
		m[i][i] = n;
		k = k + 1;
	}
	return 0;
}
