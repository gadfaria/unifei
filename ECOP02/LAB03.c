#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int face1;
    int face2;
    struct no *prox;
} noPeca;

noPeca *priJog1 = NULL;
noPeca *priJog2 = NULL;
noPeca *priMesa = NULL;

int inicializa();
void imprime(noPeca *aux);
noPeca *removeJogador1(int face);
noPeca *removeJogador2(int face);
void insereInicioMesa(noPeca *aux);
void insereFimMesa(noPeca *aux);

int main(int argc, char *argv[])
{
    int ini = 6, fim = 6;
    int jogador = inicializa();
    noPeca *aux;

    while ((priJog1 != NULL) && (priJog2 != NULL))
    {

        printf("Jog1 = ");
        imprime(priJog1);
        printf("Jog2 = ");
        imprime(priJog2);
        printf("mesa = ");
        imprime(priMesa);
        getchar();

        if (jogador == 0)
        {
            aux = removeJogador1(ini);
            if (aux != NULL)
            {
                insereInicioMesa(aux);
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
            }
            else
            {
                aux = removeJogador1(fim);
                if (aux != NULL)
                {
                    insereFimMesa(aux);
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                }
            }
            jogador = 1;
        }
        else
        {
            aux = removeJogador2(ini);
            if (aux != NULL)
            {
                insereInicioMesa(aux);
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
            }
            else
            {
                aux = removeJogador2(fim);
                if (aux != NULL)
                {
                    insereFimMesa(aux);
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                }
            }
            jogador = 0;
        }
    }
    return 0;
}

int inicializa()
{
    int i, j, c1 = 0, c2 = 0, sor;
    noPeca *aux;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {

            aux = (noPeca *)malloc(sizeof(noPeca));
            aux->face1 = i;
            aux->face2 = j;

            if (c1 == 14)
            {
                sor = 1;
            }
            else
            {
                if (c2 == 14)
                {
                    sor = 0;
                }
                else
                {
                    sor = rand() % 2;
                }
            }

            if ((i == 6) && (j == 6))
            {
                aux->prox = priMesa;
                priMesa = aux;
            }
            else
            {
                if (sor == 0)
                {
                    aux->prox = priJog1;
                    priJog1 = aux;
                    c1++;
                }
                else
                {
                    aux->prox = priJog2;
                    priJog2 = aux;
                    c2++;
                }
            }
        }
    }
    if (c1 == 14)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void imprime(noPeca *aux)
{

    while (aux != NULL)
    {
        printf("%d - %d\n", aux->face1, aux->face2);
        aux = aux->prox;
    }
}

noPeca *removeJogador1(int face)
{
    noPeca *atual = priJog1;
    noPeca *ant = NULL;
    noPeca *proximo = NULL;

    while (atual != NULL)
    {
        if (atual->face1 == face)
        {
            if (atual == priJog1)
            {
                priJog1 = atual->prox;
            }
            else
            {
                ant->prox = atual->prox;
            }
            return atual;
        }
        else
        {
            if (atual->face2 == face)
            {
                if (atual == priJog1)
                {
                    priJog1 = atual->prox;
                }
                else
                {
                    ant->prox = atual->prox;
                }
                return atual;
            }
            else
            {
                ant = atual;
                atual = atual->prox;
            }
        }
    }
    return NULL;
}

noPeca *removeJogador2(int face)
{
    noPeca *atual = priJog2;
    noPeca *ant = NULL;

    while (atual != NULL)
    {
        if (atual->face1 == face)
        {
            if (atual == priJog2)
            {
                priJog2 = atual->prox;
            }
            else
            {
                ant->prox = atual->prox;
            }
            return atual;
        }
        else
        {
            if (atual->face2 == face)
            {
                if (atual == priJog1)
                {
                    priJog1 = atual->prox;
                }
                else
                {
                    ant->prox = atual->prox;
                }
                return atual;
            }
            else
            {
                ant = atual;
                atual = atual->prox;
            }
        }
    }
    return NULL;
}

void insereInicioMesa(noPeca *aux)
{
    noPeca *antMesa = NULL;
    noPeca *atualMesa = priMesa;

    while (atualMesa != NULL)
    {
        antMesa = atualMesa;
        atualMesa = atualMesa->prox;
    }

    antMesa->prox = aux;
    aux->prox = atualMesa;
}

void insereFimMesa(noPeca *aux)
{
    noPeca *antMesa = NULL;
    noPeca *atualMesa = priMesa;

    while (atualMesa != NULL)
    {
        antMesa = atualMesa;
        atualMesa = atualMesa->prox;
    }

    antMesa->prox = aux;
    aux->prox = atualMesa;
}
