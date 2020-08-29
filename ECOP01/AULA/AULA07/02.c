#include <stdio.h>

int main(int argc, char *argv[])
{
	int v[10];
	int i, j = 0;

	printf("Digite os 10 valores do vetor\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &v[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (v[i] > 50)
		{
			j = j + 1;
			printf("Posição %d valor %d \n", i, v[i]);
		}
	}
	if (j == 0)
	{
		printf("Nenhum numero superior a 50 \n");
	}
	return 0;
}
