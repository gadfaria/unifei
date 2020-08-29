#include <stdio.h>

int main(int argc, char *argv[])
{
	int v1[] = {1, 2, 3, 4, 5};
	int v2[] = {1, 2, 3, 4, 5};
	int vSoma[5], vMult[5], vUniao[10], i, j;

	for (i = 0; i < 5; i++)
	{
		vSoma[i] = v1[i] + v2[i];
		vMult[i] = v1[i] * v2[i];
	}
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			vUniao[i] = v1[i];
		}
		else if (i >= 5)
		{
			j = i - 5;
			vUniao[i] = v2[j];
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("Vetor soma posição %d %d \n", i, vSoma[i]);
		printf("Vetor multiplição posição %d %d \n", i, vMult[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d \n", vUniao[i]);
	}
	return 0;
}
