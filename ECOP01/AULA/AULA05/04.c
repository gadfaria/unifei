#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	float raio, comp, area, vol;

	printf("Digite o raio \n");
	scanf("%f", &raio);

	comp = 2 * 3.1415 * raio;
	printf("Comprimento = %f\n", comp);

	area = 3.1415 * pow(raio, 2);
	printf("Area = %f\n", area);

	vol = (3 / 4) * 3.1415 * pow(raio, 3);
	printf("Volume = %f\n", vol);

	return 0;
}
