#include <stdio.h>

int main(int argc, char *argv[])
{
	int count, exame = 0, reprovado = 0, aprovado = 0;
	float nota1, nota2, media, total = 0;

	for (count = 0; count < 5; count++)
	{
		printf("Digite duas notas do aluno \n");
		scanf("%f", &nota1);
		scanf("%f", &nota2);

		media = 0;
		media = (nota1 + nota2) / 2;
		total = total + media;

		if (media < 3)
		{
			reprovado = reprovado + 1;
		}
		else if ((media >= 3) && (media <= 7))
		{
			exame = exame + 1;
		}
		else if (media > 7)
		{
			aprovado = aprovado + 1;
		}
	}
	total = total / 5;
	printf("Media total igual a %f \n", total);
	printf("Aprovados igual a %d \n", aprovado);
	printf("Reprovados igual a %d\n", reprovado);
	printf("Exame igual a %d\n", exame);

	return 0;
}
