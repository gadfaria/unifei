#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 20
#define TAM_TELEFONE 10

typedef enum
{
    false,
    true
} bool;

typedef struct no
{
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    struct no *prox;
    struct no *ant;
} noContato;

noContato *prim = NULL;
noContato *ult = NULL;

bool insereContatoNaAgenda(noContato *aux);
void imprimeAgenda();
bool removeContatoDaAgenda(noContato *aux);
void destroi();

int main(int argc, char *argv[])
{
    int i = 0;
    char telefone[TAM_TELEFONE];
    noContato *aux;

    aux = (noContato *)malloc(sizeof(noContato));

    while (i != 4)
    {
        printf("\n>> 1 para inserir um novo contato na agenda !");
        printf("\n>> 2 para remover um contato na agenda !");
        printf("\n>> 3 para listar todos os contatos da agenda !");
        printf("\n>> 4 para sair da agenda !\n");
        scanf("%d", &i);
        getchar();
        switch (i)
        {
        case 1:
            printf("\nDigite o telefone e o nome a ser inserido !\n");
            scanf("%s", aux->telefone);
            scanf("%s", aux->nome);
            getchar();
            if (insereContatoNaAgenda(aux) == true)
            {
                printf("\nContato inserido com sucesso !\n");
            }
            else
            {
                printf("\nFalha ao inserir contato, telefone ja consta na lista\n");
            }
            i = 0;
            break;
        case 2:
            printf("\nDigite o telefone para remo��o !\n");
            scanf("%s", aux->telefone);
            getchar();
            if (removeContatoDaAgenda(aux) == true)
            {
                printf("\nContato removido com sucesso !\n");
            }
            else
            {
                printf("\nContato nao encontrado\n");
            }
            i = 0;
            break;
        case 3:
            imprimeAgenda();
            i = 0;
            break;
        }
    }
    destroi();
    return 0;
}

bool insereContatoNaAgenda(noContato *teste)
{
    noContato *aux = NULL;
    noContato *atual = prim;
    noContato *pesquisa = prim;
    noContato *novo;

    novo = (noContato *)malloc(sizeof(noContato));

    while ((pesquisa != NULL) && (strcmp(atual->telefone, teste->telefone) != 0))
    {
        pesquisa = pesquisa->prox;
    }
    if (pesquisa != NULL)
    {
        return false;
    }

    while ((atual != NULL) && (strcmp(atual->nome, teste->nome) < 0))
    {
        aux = atual;
        atual = atual->prox;
    }

    if (aux == NULL)
    {
        prim = novo;
    }
    else
    {
        aux->prox = novo;
    }

    if (atual == NULL)
    {
        ult = novo;
    }
    else
    {
        atual->ant = novo;
    }

    strcpy(novo->nome, teste->nome);
    strcpy(novo->telefone, teste->telefone);
    novo->prox = atual;
    novo->ant = aux;

    return true;
}

void imprimeAgenda()
{
    noContato *atual = prim;

    while (atual != NULL)
    {
        printf("\n%s , %s", atual->telefone, atual->nome);
        atual = atual->prox;
    }
}

bool removeContatoDaAgenda(noContato *teste)
{
    noContato *aux = NULL;
    noContato *atual = prim;

    while ((atual != NULL) && (strcmp(atual->telefone, teste->telefone) != 0))
    {
        aux = atual;
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
            aux->prox = atual->prox;
        }
        if (atual == ult)
        {
            ult = aux;
        }
        else
        {
            atual->prox->ant = aux;
        }
        free(atual);
        return true;
    }
}

void destroi()
{
    noContato *atual = prim;
    noContato *apaga;

    while (atual != NULL)
    {
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}
