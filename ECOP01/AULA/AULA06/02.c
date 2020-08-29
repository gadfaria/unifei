#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	double raizQ1, raizQ2, raizC1, raizC2, q1;
	float num1, num2;

	printf("Digite dois \n");
	scanf("%f", &num1);
	scanf("%f", &num2);

	if ((num1 >= 0) && (num2 >= 0))
	{
		q1 = pow(num1, num2);
		raizQ1 = sqrt(num1);
		raizQ2 = sqrt(num2);
		raizC1 = cbrt(num1);
		raizC2 = cbrt(num2);
	}
	else
	{
		printf("Opção invalida \n");
	}

	return 0;
}
