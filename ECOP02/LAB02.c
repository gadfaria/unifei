#include <stdio.h>
#include <string.h>
#define MAX 30

typedef enum
{
    false,
    true
} bool;

typedef struct no
{
    int mat, prox;
    char nome[20];
    float imc;
} noAluno;

noAluno info[MAX];

int prim = -1;
int dispo = 0;

void inicializaLista();
bool insereAluno(noAluno aux);
void imprimeLista();
int buscaAluno(int numero);

int main(int argc, char *argv[])
{
    int i, posicao, numero;
    noAluno aux;
    inicializaLista();

    for (i = 0; i < 3; i++)
    {
        printf("\nDigite o numero da matricula !\n");
        scanf("%d", &aux.mat);

        if (buscaAluno(aux.mat) == -1)
        {
            printf("\nDigite o nome e o imc do aluno %d !\n", aux.mat);
            scanf("%s", &aux.nome);
            scanf("%f", &aux.imc);
            insereAluno(aux);
        }
        else
        {
            printf("\nNumero de matricula ja existente !\n");
        }
    }

    imprimeLista();

    printf("\nDigite o numero de matricula do aluno para pesquisa !\n");
    scanf("%d", &numero);
    posicao = buscaAluno(numero);
    printf("\n%s\n", info[posicao].nome);

    return 0;
}

void inicializaLista()
{
    int i;
    for (i = 0; i < MAX - 1; i++)
    {
        info[i].prox = i + 1;
    }
    info[i].prox = -1;
}

bool insereAluno(noAluno aux)
{
    int ant, atual, novo;

    if (dispo == -1)
    {
        return false;
    }
    else
    {
        ant = -1;
        atual = prim;
        novo = dispo;

        while ((atual != -1) && (info[atual].mat < aux.mat))
        {
            ant = atual;
            atual = info[atual].prox;
        }

        dispo = info[dispo].prox;

        if (ant == -1)
        {
            prim = novo;
        }
        else
        {
            info[ant].prox = novo;
        }

        info[novo].mat = aux.mat;
        strcpy(info[novo].nome, aux.nome);
        info[novo].imc = aux.imc;
        info[novo].prox = atual;
        return true;
    }
}

void imprimeLista()
{
    int i = 0;
    int pos = prim;

    while (pos != -1)
    {
        printf("%s %d %f %d \n", info[pos].nome, info[pos].mat, info[pos].imc, pos);
        pos = info[pos].prox;
    }
}

int buscaAluno(int numero)
{
    int pos = prim;

    while ((pos != -1) && (info[pos].mat != numero))
    {
        pos = info[pos].prox;
    }
    return pos;
}
