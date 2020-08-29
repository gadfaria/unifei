#include <stdio.h>

int main(int argc, char *argv[])
{
	int num, suc, ant;

	printf("Digite um numero\n");
	scanf("%d", &num);

	ant = num - 1;
	suc = num + 1;

	printf("Antecessor = %d"
		   "\n",
		   ant);
	printf("Sucessor = %d"
		   "\n",
		   suc);

	return 0;
}
