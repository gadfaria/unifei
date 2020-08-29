#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[30], sexo[2];
    int idade;
    float altura, peso;
} stPaciente;

void informacoes(stPaciente pessoa[20]);

int main(int argc, char *argv[])
{
    stPaciente pessoa[20];
    int i, cPeso;
    float pesoID, pesado = -9999;

    for (i = 0; i < 20; i++)
    {
        pesoID = 0;
        if (pessoa[i].peso > pesado)
        {
            pesado = pessoa[i].peso;
            cPeso = i;
        }
        if (pessoa[i].sexo == 'm')
        {
            pesoID = 62, 1 * pessoa[i].altura - 44, 7;
        }
        if (pessoa[i].sexo == 'h')
        {
            pesoID = 72, 7 * pessoa[i].altura - 58;
        }
        if (pessoa[i].peso > pesoID)
        {
            printf("\n nome e idade \n%c%d", pessoa[i].nome, pessoa[i].idade);
        }
        if (pessoa[i].peso < pesoID)
        {
            pesoID = pesoID - pessoa[i].peso;
            printf("Nome e o peso que deverao adquirir %c,%f", pessoa[i].nome, pesoID);
        }
    }
    printf("Pessoa mais pesada igual a %c", pessoa[cPeso].nome);
    return 0;
}

void informacoes(stPaciente pessoa[20])
{
    int i;

    for (i = 0; i < 20; i++)
    {
        printf("\nDigite o dados dos pacientes \n");
    }
}
