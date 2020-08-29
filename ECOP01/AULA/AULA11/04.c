#include <stdio.h>

int tribonacci(int num);

int main(int argc, char *argv[])
{
	int num, i;

	printf("Digite a a quantidade");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		printf(" %d ", tribonacci(i + 1));
	}
}
int tribonacci(int num)
{

	if (num == 1 || num == 2)
		return 1;
	else
		return (tribonacci(num - 1) + tribonacci(num - 2) + tribonacci(num - 3));
}
