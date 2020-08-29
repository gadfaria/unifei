#include <stdio.h>

int main(int argc, char *argv[])
{
    char email[50];
    int dia, mes, ano;
    float altura, peso, imc;

    printf("Digite email: ");
    scanf("%s", email);

    printf("Data nascimento (DD/MM/AA)");
    scanf("%d%d%d", &dia, &mes, &ano);

    printf("Digite a altura(metro): ");
    scanf("%f", &altura);

    printf("Digite peso (kg): ");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    printf("Email: %s\n", email);
    printf("Nascimento: %d%d%d\n", dia, mes, ano);
    printf("IMC: %f\n", imc);
    return 0;
}
