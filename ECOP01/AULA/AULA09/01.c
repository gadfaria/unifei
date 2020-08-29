#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char frase[256], fraseR[512], palavra[100];
	int c, i, tam;

	printf("Frase \n");
	gets(frase);

	tam = strlen(frase);
	strcpy(palavra, '\0');
	strcpy(fraseR, '\0');
	c = 0;

	for (i = 0; i < tam; i++)
	{

		if ((frase[i] != ' ') && (frase[i] != '\0'))
		{
			palavra[c] = frase[i];
			c++;
		}
		else
		{
			palavra[c] = '\0';
			strcat(fraseR, palavra);
			strcat(fraseR, " ");
			strcat(fraseR, palavra);
			strcat(fraseR, " ");
			strcpy(palavra, '\0');
			c = 0;
		}
	}

	printf(" %s ", fraseR);

	return 0;
}
