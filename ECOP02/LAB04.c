#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

typedef struct no
{
    int mat;
    char nome[20];
    char disc[5];
    float coef;
    struct no *prox;
} noAluno;

noAluno *prim = NULL;
noAluno *ult = NULL;

bool insereAlunoLista(noAluno *aux);
bool removeAluno(int matricula);
void imprimeLista();
bool buscaMatricula(int matricula);
void destroiLista();

int main(int argc, char *argv[])
{
    int i = 0;
    int matricula;
    noAluno *aux = (noAluno *)malloc(sizeof(noAluno));

    while (i < 2)
    {

        printf("\nDigite as informa��es dos aluno !\n");
        printf("Nome\n");
        scanf("%s", aux->nome);
        printf("Disciplina\n");
        scanf("%s", aux->disc);
        printf("Matricula\n");
        scanf("%d", &aux->mat);
        printf("Coeficiente\n");
        scanf("%f", &aux->coef);

        matricula = aux->mat;

        if (buscaMatricula(matricula) == true)
        {
            printf("\nMatricula ja existente");
            printf("\nDigite a matricula novamente\n");
            scanf("%d", &aux->mat);
            if (insereAlunoLista(aux) == true)
            {
                i++;
            }
        }
        else
        {
            if (insereAlunoLista(aux) == true)
            {
                i++;
            }
        }
    }
    imprimeLista();
    printf("\nDigite um numero de matricula para remo��o\n");
    scanf("%d", &matricula);
    if (removeAluno(matricula) == true)
    {
        printf("\nAluno removido com sucesso\n");
    }
    else
    {
        printf("\nAluno n�o removido\n");
    }
    imprimeLista();
    destroiLista();
    return 0;
}

bool insereAlunoLista(noAluno *aux)
{
    noAluno *ant = NULL;
    noAluno *atual = prim;

    noAluno *novo = (noAluno *)malloc(sizeof(noAluno));

    while ((atual != NULL) && (atual->nome < aux->nome))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (ant == NULL)
    {
        prim = novo;
    }
    else
    {
        ant->prox = novo;
    }

    novo->mat = aux->mat;
    novo->coef = aux->coef;
    strcpy(novo->disc, aux->disc);
    strcpy(novo->nome, aux->nome);
    novo->prox = atual;

    if (atual == NULL)
    {
        ult = novo;
    }
    return true;
}

bool removeAluno(int matricula)
{
    noAluno *ant = NULL;
    noAluno *atual = prim;

    while ((atual != NULL) && (atual->mat != matricula))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        return false;
    }
    else
    {
        if (atual == prim)
        {
            prim = atual->prox;
        }
        else
        {
            ant->prox = atual->prox;
            if (atual == ult)
            {
                ult = ant;
            }
        }
        free(atual);
        return true;
    }
}

void imprimeLista()
{
    noAluno *atual = prim;

    while (atual != NULL)
    {
        printf("\n%s %s %d %f\n", atual->nome, atual->disc, atual->mat, atual->coef);
        atual = atual->prox;
    }
}

bool buscaMatricula(int matricula)
{
    noAluno *ant = NULL;
    noAluno *atual = prim;

    while ((atual != NULL) && (atual->mat != matricula))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void destroiLista()
{
    noAluno *atual = prim;
    noAluno *apaga;

    while (atual != NULL)
    {
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}
