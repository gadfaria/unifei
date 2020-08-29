#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char palavra[20];
	int tam;

	printf("PALAVRA \n");
	gets(palavra);

	tam = strlen(palavra);

	if (palavra[tam - 2] == 'a' && palavra[tam - 1] == 'r')
	{
		palavra[tam - 2] = 'o';
		palavra[tam - 1] = ' ';
	}

	printf("\n %s \n", palavra);

	return 0;
}
