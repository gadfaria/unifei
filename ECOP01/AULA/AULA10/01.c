#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[30], sexo[1];
    int cpf;
    float altura, peso;
} stDadosPessoa;

void dados(stDadosPessoa pessoa[30]);

int main(int argc, char *argv)
{
    stDadosPessoa pessoa[30];
    int i, respCPF;
    float imc;

    dados(pessoa);

    printf("\n Digite o CPF da pessoa \n");
    scanf("%d", &respCPF);

    for (i = 0; i < 30; i++)
        ;
    {
        if (respCPF == pessoa[i].cpf)
        {
            imc = pessoa[i].peso / (pessoa[i].altura * pessoa[i].altura);
        }
    }

    printf("\n IMC igual a %d\n", imc);
}

void dados(stDadosPessoa pessoa[30])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        printf("\n Digite o nome da pessoa \n");
        gets(pessoa[i].nome);
        getchar();

        printf(" \n Digite o sexo \n");
        scanf("%c", &pessoa[i].sexo);
        getchar();

        printf(" \nDigite o cpf \n");
        scanf("%d", &pessoa[i].cpf);
        getchar();

        printf("\n Digite a altura \n");
        scanf("%f", &pessoa[i].altura);
        getchar();

        printf(" \nDigite o peso \n");
        scanf("%f", &pessoa[i].peso);
        getchar();
    }
}
