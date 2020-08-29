#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FILAS 3
#define TAM_NOME 50

typedef enum
{
    false,
    true
} bool;

typedef struct no
{
    float tamanho;
    char nome[TAM_NOME];
    int prioridade;
    struct no *prox;
} noProcesso;

noProcesso *fila[NUM_FILAS];

void inicializaFila();
void inicializaPrioridades();
void insereFila(float tamanho, char nome[TAM_NOME], int prioridade);
void imprimeDados();
bool removeFila(int indice);

int main(int argc, char *argv[])
{
    inicializaFila();

    insereFila(1, "BrOfficeCalc", 3);
    insereFila(2.3, "CodeBlocks", 9);
    insereFila(0.5, "Calculadora", 1);
    insereFila(6.4, "Firefox", 7);
    insereFila(3.1, "PhpMyAdmin", 2);
    insereFila(2.9, "Kile", 4);
    insereFila(4.5, "Gimp", 9);
    insereFila(5.5, "BrOfficeWriter", 6);
    insereFila(5.8, "GCC", 2);

    imprimeDados();

    removeFila(2);

    imprimeDados();

    return 0;
}

void inicializaFila()
{
    int i;

    for (i = 0; i < NUM_FILAS; i++)
    {
        fila[i] = NULL;
    }
}

void insereFila(float tamanho, char nome[TAM_NOME], int prioridade)
{
    noProcesso *novo;
    noProcesso *atual;
    noProcesso *ant = NULL;
    novo = (noProcesso *)malloc(sizeof(noProcesso));

    if (prioridade < 4)
    {
        if (fila[0] == NULL)
        {
            fila[0] = novo;
            novo->prox = NULL;
            novo->tamanho = tamanho;
            novo->prioridade = prioridade;
            strcpy(novo->nome, nome);
        }
        else
        {
            atual = fila[0];

            while (atual != NULL)
            {
                ant = atual;
                atual = atual->prox;
            }

            ant->prox = novo;
            novo->prox = atual;
            novo->tamanho = tamanho;
            novo->prioridade = prioridade;
            strcpy(novo->nome, nome);
        }
    }
    else
    {
        if (prioridade < 7)
        {
            if (fila[1] == NULL)
            {
                fila[1] = novo;
                novo->prox = NULL;
                novo->tamanho = tamanho;
                novo->prioridade = prioridade;
                strcpy(novo->nome, nome);
            }
            else
            {
                atual = fila[1];

                while (atual != NULL)
                {
                    ant = atual;
                    atual = atual->prox;
                }

                ant->prox = novo;
                novo->prox = atual;
                novo->tamanho = tamanho;
                novo->prioridade = prioridade;
                strcpy(novo->nome, nome);
            }
        }
        else
        {
            if (fila[2] == NULL)
            {
                fila[2] = novo;
                novo->prox = NULL;
                novo->tamanho = tamanho;
                novo->prioridade = prioridade;
                strcpy(novo->nome, nome);
            }
            else
            {
                atual = fila[2];

                while (atual != NULL)
                {
                    ant = atual;
                    atual = atual->prox;
                }

                ant->prox = novo;
                novo->prox = atual;
                novo->tamanho = tamanho;
                novo->prioridade = prioridade;
                strcpy(novo->nome, nome);
            }
        }
    }
}

void imprimeDados()
{
    noProcesso *atual;
    float tam = 0;
    int num = 0, i;

    printf("\n");
    for (i = 0; i < 3; i++)
    {
        atual = fila[i];

        while (atual != NULL)
        {
            printf("%s - %f - %d\n", atual->nome, atual->tamanho, atual->prioridade);
            num = num + 1;
            tam = tam + atual->tamanho;
            atual = atual->prox;
        }
    }
    printf("Numero de processos = %d, tamanho dos processos = %f\n", num, tam);
}

bool removeFila(int indice)
{
    noProcesso *atual;

    if (indice == 0)
    {
        atual = fila[0];
        if (atual == NULL)
        {
            return false;
        }
        else
        {
            fila[0] = atual->prox;
            free(atual);
            return true;
        }
    }
    else
    {
        if (indice == 1)
        {
            atual = fila[1];
            if (atual == NULL)
            {
                return false;
            }
            else
            {
                fila[1] = atual->prox;
                free(atual);
                return true;
            }
        }
        else
        {
            if (indice == 2)
            {
                atual = fila[2];
                if (atual == NULL)
                {
                    return false;
                }
                else
                {

                    fila[2] = atual->prox;
                    free(atual);
                    return true;
                }
            }
        }
    }
}
