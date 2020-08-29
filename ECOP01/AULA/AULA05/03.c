#include <stdio.h>

int main(int argc, char *argv[])
{
	int a1, a2, ida, idm, idd, ids;

	printf("Digite o ano nascimento \n");
	scanf("%d", &a1);

	printf("Digite o ano de atual \n");
	scanf("%d", &a2);

	ida = a2 - a1;
	idm = ida * 12;
	idd = idm * 30;
	ids = idd * 4;

	printf("\n");
	printf("Idade em anos %d\n", ida);
	printf("Idade em meses %d\n", idm);
	printf("Idade em dias %d\n", idd);
	printf("Idade em semanas %d\n", ids);

	return 0;
}
