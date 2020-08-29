#include <stdio.h>

int main(int argc, char *argv[])
{
	int codEstado, codCarga;
	float peso, carga, valor = 0, valorTotal = 0, valorI = 0;

	printf("Digite o codigo de estado de origem !");
	scanf("%d", &codEstado);

	printf("Digite o peso da carga !");
	scanf("%f", &peso);

	printf("Digite o codigo de carga !");
	scanf("%d", &codCarga);

	peso = peso * 1000;

	if ((codCarga >= 10) && (codCarga <= 20))
	{
		valor = peso * 100;
		carga = 100;
	}
	else if ((codCarga > 20) && (codCarga <= 30))
	{
		valor = peso * 250;
		carga = 250;
	}
	else if ((codCarga > 30) && (codCarga <= 40))
	{
		valor = peso * 340;
		carga = 340;
	}

	if (codEstado == 1)
	{
		valorI = valor * 0.35;
		valorTotal = valorI + valor;
		carga = carga * 1.35;
	}
	else if (codEstado == 2)
	{
		valorI = valor * 0.25;
		valorTotal = valorI + valor;
		carga = carga * 1.25;
	}
	else if (codEstado == 3)
	{
		valorI = valor * 0.15;
		valorTotal = valorI + valor;
		carga = carga * 1.15;
	}
	else if (codEstado == 4)
	{
		valorI = valor * 0.05;
		valorTotal = valorI + valor;
		carga = carga * 1.05;
	}
	else if (codEstado == 5)
	{
		valorTotal = valor;
	}

	printf("Peso em quilogramas %f\n", peso);
	printf("Valor do imposto %f\n", valorI);
	printf("Valor total %f\n", valorTotal);
	printf("Carga mais os impostos %f\n", carga);

	return 0;
}
