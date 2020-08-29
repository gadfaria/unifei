#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    NENHUM,
    EMPRESA,
    SORTEREVES,
    PRISAO,
    TERRENO
} enumcasa;
typedef enum
{
    NINGUEM,
    JOGADOR1,
    JOGADOR2
} enumpeca;
typedef struct
{
    enumcasa tipocasa;
    enumpeca dono;
    int valor;
} tcasa;

void mostra(tcasa inicial[30], int posicao1, int posicao2);
void inicializa(tcasa inicia[30]);
void geratabuleiro(tcasa inicia[30]);

int main(int argc, char *argv[])
{
    tcasa inicia[30];
    int i, posicao1 = 0, posicao2 = 0, sorteio;

    inicializa(inicia);
    geratabuleiro(inicia);

    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        sorteio = rand() % 3;
        posicao1 = posicao1 + sorteio;

        sorteio = rand() % 3;
        posicao2 = posicao2 + sorteio;

        if (posicao1 >= 30)
            posicao1 = 0;

        if (posicao2 >= 30)
            posicao2 = 0;
        mostra(inicia, posicao1, posicao2);
    }

    return 0;
}

void inicializa(tcasa inicia[30])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        inicia[i].tipocasa = NENHUM;
        inicia[i].dono = NINGUEM;
        inicia[i].valor = 0;
    }
}

void geratabuleiro(tcasa inicia[30])
{
    int i, j, status, aux[30], c, valor;

    srand(time(NULL));
    for (i = 0; i < 30; ++i)
    {
        if (i < 10)
        {
            do
            {
                aux[i] = rand() % 30;
                c = aux[i];
                inicia[c].tipocasa = EMPRESA;
                status = 1;
                for (j = 0; (j < i) && (status == 1); j++)
                    if (aux[i] == aux[j])
                        status = 0;
            } while (status == 0);
        }

        if (i >= 10 && i < 15)
        {
            do
            {
                aux[i] = rand() % 30;
                c = aux[i];
                inicia[c].tipocasa = SORTEREVES;
                status = 1;
                for (j = 0; (j < i) && (status == 1); j++)
                    if (aux[i] == aux[j])
                        status = 0;
            } while (status == 0);
        }

        if (i >= 15 && i < 17)
        {
            do
            {
                aux[i] = rand() % 30;
                c = aux[i];
                inicia[c].tipocasa = PRISAO;
                status = 1;
                for (j = 0; (j < i) && (status == 1); j++)
                    if (aux[i] == aux[j])
                        status = 0;
            } while (status == 0);
        }
    }
    for (i = 0; i < 30; ++i)
    {
        if (inicia[i].tipocasa == NENHUM)
        {
            inicia[i].tipocasa = TERRENO;
            inicia[i].valor = rand() % 10;
        }
        if (inicia[i].tipocasa == EMPRESA)
        {
            valor = rand() % 2;
            if (valor = 0)
                inicia[i].valor = 10;
            else
                inicia[i].valor = 20;
        }
    }
}

void mostra(tcasa inicia[30], int posicao1, int posicao2)
{
    int i;
    int aux[30];

    for (i = 0; i < 15; i++)
        printf(" %2d ", i);

    printf("\n");
    for (i = 0; i < 15; i++)
    {
        if (inicia[i].tipocasa == EMPRESA)
            printf(" EM ");
        else if (inicia[i].tipocasa == SORTEREVES)
            printf(" SO ");
        else if (inicia[i].tipocasa == PRISAO)
            printf(" PR ");
        else if (inicia[i].tipocasa == TERRENO)
            printf(" TE ");
    }

    printf("\n");
    for (i = 0; i < 15; i++)
        printf(" %2d ", inicia[i].valor);

    printf("\n\n");
    for (i = 0; i < 15; i++)
    {
        if (i == posicao1)
            printf(" P1 ");
        else if (i == posicao2)
            printf(" P2 ");
        else
            printf(" [] ");
    }
    printf("\n");
    for (i = 15; i < 30; i++)
    {
        if (i == posicao1)
            printf(" P1 ");
        else if (i == posicao2)
            printf(" P2 ");
        else
            printf(" [] ");
    }

    printf("\n\n");
    for (i = 15; i < 30; i++)
        printf(" %2d ", i);

    printf("\n");
    for (i = 15; i < 30; i++)
    {
        if (inicia[i].tipocasa == EMPRESA)
            printf(" EM ");
        else if (inicia[i].tipocasa == SORTEREVES)
            printf(" SO ");
        else if (inicia[i].tipocasa == PRISAO)
            printf(" PR ");
        else if (inicia[i].tipocasa == TERRENO)
            printf(" TE ");
    }
    printf("\n");
    for (i = 15; i < 30; i++)
        printf(" %2d ", inicia[i].valor);

    printf("\n\n\n\n");
}
