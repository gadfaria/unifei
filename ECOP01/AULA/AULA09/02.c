#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char frase[256], c = 0, tam, i;

	printf("Digite uma frase: \n");
	gets(frase);

	tam = strlen(frase);

	for (i = 0; i < tam; i++)
	{
		if (frase[i] == ' ')
		{
			c++;
		}
	}

	printf("Quantidade de palavras = %d \n", c + 1);

	return 0;
}
