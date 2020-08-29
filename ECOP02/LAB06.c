#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 20

typedef enum
{
    false,
    true
} bool;

typedef struct no
{
    char nome[TAM_NOME];
    int matricula, turma;
    float coef;
    struct no *prox;
    struct no *ant;
} noAluno;

noAluno *prim = NULL;
noAluno *ult = NULL;

bool insereAluno(noAluno *aux);
void imprimeLista();
bool removeAluno(int mat);
bool buscaMatricula(int mat);
void destroiLista();

int main(int argc, char *argv[])
{
    int mat, i = 0;
    noAluno *aux;
    aux = (noAluno *)malloc(sizeof(noAluno));

    while (i < 3)
    {
        printf("\nDigite os dados do aluno\n");
        printf("Nome: ");
        scanf("%s", aux->nome);
        printf("\nMatricula: ");
        scanf("%d", &aux->matricula);
        printf("\nTurma: ");
        scanf("%d", &aux->turma);
        printf("\nCoef: ");
        scanf("%f", &aux->coef);
        getchar();

        mat = aux->matricula;

        if (buscaMatricula(mat) == false)
        {
            if (insereAluno(aux) == true)
            {
                printf("\nAluno inserido\n");
                i++;
            }
            else
            {
                printf("\nFalha ao inserir\n");
            }
        }
        else
        {
            printf("\nAluno j� existente\n");
        }
    }
    imprimeLista();

    printf("\nDigite a matricula de um aluno para remover: ");
    scanf("%d", &mat);
    getchar();

    if (removeAluno(mat) == true)
    {
        printf("\nAluno removido\n");
    }
    else
    {
        printf("\nAluno n�o encontrado\n");
    }

    imprimeLista();

    destroiLista();

    return 0;
}

bool insereAluno(noAluno *aluno)
{
    noAluno *atual = prim;
    noAluno *aux = NULL;
    noAluno *novo;

    novo = (noAluno *)malloc(sizeof(noAluno));

    if (prim == NULL)
    { //Caso a lista esteja vazia
        prim = novo;
        ult = novo;
        prim->prox = novo;
        prim->ant = novo;
        novo->matricula = aluno->matricula;
        novo->turma = aluno->turma;
        novo->coef = aluno->coef;
        strcpy(novo->nome, aluno->nome);
    }
    else
    {
        while (strcmp(atual->nome, aluno->nome) < 0)
        {
            aux = atual;
            atual = atual->prox;

            if (atual == prim)
            {
                break;
            }
        }

        if (aux == NULL)
        { //Caso seja para inserir na primeira posi��o
            prim = novo;
            ult->prox = prim;
            atual->ant = prim;
            aux = ult;
        }
        else
        {
            aux->prox = novo;
            atual->ant = novo;
        }

        novo->matricula = aluno->matricula;
        novo->turma = aluno->turma;
        novo->coef = aluno->coef;
        strcpy(novo->nome, aluno->nome);
        novo->prox = atual;
        novo->ant = aux;

        if (atual == prim)
        { //Caso seja para inserir na ultima posi��o
            ult = novo;
        }
    }
    return true;
}

void imprimeLista()
{
    noAluno *aux = ult;

    while (1)
    {
        printf("\n%s - %d - %d - %f\n", aux->nome, aux->matricula, aux->turma, aux->coef);
        aux = aux->ant;
        if (aux == ult)
            break;
    }
}

bool removeAluno(int matricula)
{
    noAluno *atual = prim;
    noAluno *aux = NULL;

    while (atual->matricula != matricula)
    {
        aux = atual;
        atual = atual->prox;

        if (atual == prim)
        {
            break;
        }
    }
    if (atual->matricula != matricula)
    {
        return false;
    }

    if (atual == prim)
    {
        prim = atual->prox;
        ult->prox = prim;
        prim->ant = ult;
    }
    else
    {
        atual->prox->ant = aux;
        aux->prox = atual->prox;
    }
    if (atual == ult)
    {
        ult = aux;
    }
    free(atual);
    return true;
}

bool buscaMatricula(int mat)
{
    noAluno *atual = prim;

    if (atual == NULL)
    {
        return false;
    }
    else
    {
        while (atual->matricula != mat)
        {
            atual = atual->prox;
            if (atual == prim)
            {
                break;
            }
        }

        if (atual->matricula != mat)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

void destroiLista()
{
    noAluno *atual = prim;
    noAluno *apaga;

    if (atual != NULL)
    {
        while (true)
        {
            apaga = atual;
            atual = atual->prox;
            free(apaga);

            if (atual == prim)
            {
                break;
            }
        }
    }
}
